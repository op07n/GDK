// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-31.
#include "Phy2DSceneGraph.h"
//gdk inc
#include "Math/Vector2.h"
#include "Physics2D/Common/b2Math.h"
#include "Physics2D/Dynamics/b2Body.h"
#include "Physics2D/Dynamics/Contacts/b2Contact.h"
#include "EntityComponentSystem/Physics2D/Collider.h"
#include "EntityComponentSystem/Physics2D/CollisionInfo.h"
#include "EntityComponentSystem/Physics2D/ComponentInterface.h"
#include "EntityComponentSystem/GameObject.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GDK::ECS;
using namespace GDK::ECS::Physics2D;

static constexpr char TAG[] = "Phy2DSceneGraph";

std::ostream &GDK::ECS::Physics2D::operator<<(std::ostream &s, const GDK::ECS::Physics2D::Phy2DSceneGraph &a)
{
    s.clear(); s
    << "{"
    << TAG << "'s: " << "operator<< has not been implemented"
    // << "m_Member: " << a.m_Member << ", "
    << "}";
    
    return s;
}

void ECS::Physics2D::Phy2DSceneGraph::fixedUpdate()
{
    m_B2DWorld.Step(c_UpdateInterval, 1, 1);
}

void ECS::Physics2D::Phy2DSceneGraph::OnComponentAddedToAGameObject(const std::weak_ptr<ECS::Component> &a)
{
    
}

void ECS::Physics2D::Phy2DSceneGraph::OnComponentRemovedFromAGameObject(const std::weak_ptr<ECS::Component> &a)
{
    
}

void ECS::Physics2D::Phy2DSceneGraph::invokeOnTriggerEnter(const std::weak_ptr<Collider> &aCollider,const GDK::Physics2D::CollisionInfo &aColisionInfo)
{
    if (auto spCollider = aCollider.lock())
        if (auto spGameObject = spCollider->getGameObject().lock())
            for(size_t i = 0, s = spGameObject->getComponentCount(); i < s; i++ )
                if (auto component = spGameObject->getComponent(i).lock())
                    if (auto colliderInterface = std::dynamic_pointer_cast<ComponentInterface>(component))
                        colliderInterface->OnTriggerEnter(aColisionInfo);
}

void ECS::Physics2D::Phy2DSceneGraph::invokeOnTriggerExit(const std::weak_ptr<Collider> &aCollider,const GDK::Physics2D::CollisionInfo &aColisionInfo)
{
    if (auto spCollider = aCollider.lock())
        if (auto spGameObject = spCollider->getGameObject().lock())
            for(size_t i = 0, s = spGameObject->getComponentCount(); i < s; i++ )
                if (auto component = spGameObject->getComponent(i).lock())
                    if (auto colliderInterface = std::dynamic_pointer_cast<ComponentInterface>(component))
                        colliderInterface->OnTriggerExit(aColisionInfo);
}

void ECS::Physics2D::Phy2DSceneGraph::invokeOnCollisionEnter(const std::weak_ptr<Collider> &aCollider,const GDK::Physics2D::CollisionInfo &aColisionInfo)
{
    if (auto spCollider = aCollider.lock())
        if (auto spGameObject = spCollider->getGameObject().lock())
            for(size_t i = 0, s = spGameObject->getComponentCount(); i < s; i++ )
                if (auto component = spGameObject->getComponent(i).lock())
                    if (auto colliderInterface = std::dynamic_pointer_cast<ComponentInterface>(component))
                        colliderInterface->OnCollisionEnter(aColisionInfo);
}

void ECS::Physics2D::Phy2DSceneGraph::invokeOnCollisionExit(const std::weak_ptr<Collider> &aCollider,const GDK::Physics2D::CollisionInfo &aColisionInfo)
{
    if (auto spCollider = aCollider.lock())
        if (auto spGameObject = spCollider->getGameObject().lock())
            for(size_t i = 0, s = spGameObject->getComponentCount(); i < s; i++ )
                if (auto component = spGameObject->getComponent(i).lock())
                    if (auto colliderInterface = std::dynamic_pointer_cast<ComponentInterface>(component))
                        colliderInterface->OnCollisionExit(aColisionInfo);
}

void ECS::Physics2D::Phy2DSceneGraph::handleContact(const bool isBegin, b2Contact *aContact)
{
    std::weak_ptr<Collider> colliderA = *static_cast<std::weak_ptr<Collider>*>(aContact->GetFixtureA()->GetUserData());
    std::weak_ptr<Collider> colliderB = *static_cast<std::weak_ptr<Collider>*>(aContact->GetFixtureB()->GetUserData());
    
    Math::Vector2 collisionNormal = {0,0}; //TODO: calculate these
    Math::Vector2 collisionPoint  = {0,0};
    
    GDK::Physics2D::CollisionInfo collisionInfoA(colliderA,colliderB,collisionPoint);
    GDK::Physics2D::CollisionInfo collisionInfoB(colliderB,colliderA,collisionPoint);
    
    if (aContact->GetFixtureA()->IsSensor() || aContact->GetFixtureB()->IsSensor())
    {
        if (isBegin)
        {
            invokeOnTriggerEnter(colliderA,collisionInfoA);
            invokeOnTriggerEnter(colliderB,collisionInfoB);
        }
        else
        {
            invokeOnTriggerExit(colliderA,collisionInfoA);
            invokeOnTriggerExit(colliderB,collisionInfoB);
        }
    }
    else
    {
        if (isBegin)
        {
            invokeOnCollisionEnter(colliderA,collisionInfoA);
            invokeOnCollisionEnter(colliderB,collisionInfoB);
        }
        else
        {
            invokeOnCollisionExit(colliderA,collisionInfoA);
            invokeOnCollisionExit(colliderB,collisionInfoB);
        }
    }
}

// Accessors
void ECS::Physics2D::Phy2DSceneGraph::setGraivty(const Math::Vector2 &a)
{
    m_B2DWorld.SetGravity({a.x, a.y});
}

// Constructors
ECS::Physics2D::Phy2DSceneGraph::Phy2DSceneGraph(Scene *a) : ECS::SceneGraph(a)
{
    m_ContactListener.ContactHandler = [this](const bool &isBegin, b2Contact *aContact){handleContact(isBegin,aContact);};
    m_B2DWorld.SetContactListener(&m_ContactListener);
    
    //Build origin body (used for rigidbody axis locking etc)
    b2BodyDef bodyDef;
    bodyDef.angle = 0;
    bodyDef.position = {0,0};
    bodyDef.type = b2BodyType::b2_staticBody;
    m_WorldOriginBody = m_B2DWorld.CreateBody(&bodyDef);
}
