// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-31.
#include "Rigidbody.h"
//gdk inc
#include "EntityComponentSystem/GameObject.h"
#include "EntityComponentSystem/Physics2D/SceneGraph.h"
#include "EntityComponentSystem/Physics2D/Collider.h"
#include "Physics2D/Dynamics/b2Body.h"
#include "Physics2D/Dynamics/Joints/b2PrismaticJoint.h"
#include "Math/Vector2.h"
#include "Math/Quaternion.h"
#include "Debug/Logger.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GDK::ECS;
using namespace GDK::Math;
using namespace GDK::ECS::Physics2D;

static constexpr auto TAG = "Rigidbody";

std::ostream& GDK::ECS::Physics2D::operator<<(std::ostream& s, const GDK::ECS::Physics2D::Rigidbody& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "Rigidbody's: " << "operator<< has not been implemented"
    << "}"; return s;

}

void Rigidbody::onOtherComponentAddedToMyGameObject(const std::weak_ptr<Component> &aNewComponent)
{
    buildFixtures();
    
}

void Rigidbody::onOtherComponentRemovedFromMyGameObject(const std::weak_ptr<Component> &aOtherComponent)
{
    buildFixtures();
    
}

void Rigidbody::initialize()
{
    buildFixtures();

}

void Rigidbody::update()
{


}
#include "Math/Trigonometry.h"
#include "Debug/Logger.h"
void Rigidbody::fixedUpdate()
{
    if (m_RebuildRequired)
        buildBody();
    
    if (auto gameObject = getGameObject().lock())
    {
        switch (m_Body->GetType())
        {
            case b2BodyType::b2_dynamicBody:
            {
                b2Vec2 b2Pos = m_Body->GetPosition();
                float  b2Rot = -m_Body->GetAngle();// * (Math::Trig::PI / 180.f);
                
                //b2Rot *= 360;
                
                Debug::log(TAG, "Rotation:", b2Rot);
                
                gameObject->setPosition(b2Pos.x,0,b2Pos.y);
                gameObject->setRotation(Quaternion({0,b2Rot,0}));
                
            } break;
            
            case b2BodyType::b2_kinematicBody:
            case b2BodyType::b2_staticBody:
            {
                Vector3 tPos = gameObject->getPosition();
                Vector3 tRot = gameObject->getRotation().toEuler();
            
                //Check for rotation changes
                if (tRot != m_RotationBuffer)
                    m_Body->SetTransform({tPos.x,tPos.z}, -tRot.y);
            
                m_RotationBuffer = tRot;
            
                //Check for translation changes
                if (tPos != m_PositionBuffer)
                    m_Body->SetTransform({tPos.x,tPos.z}, -tRot.y);
                
                m_PositionBuffer = tPos;
                m_RotationBuffer = tRot;
            
            } break;
            
        }
    
        Vector3 scale = gameObject->getScale();
    
        if (m_ScaleBuffer != scale)
            buildFixtures();
        
        m_ScaleBuffer = scale;
        
    }

}

void Rigidbody::buildBody()
{
    if (auto gameObject = getGameObject().lock())
    {
        m_RebuildRequired = false;
        
        Vector3 position = gameObject->getPosition();
        //Vector3 scale    = gameObject->getScale();
        Vector3 rotation = gameObject->getRotation().toEuler();
        
        //Create body data...
        {
            m_BodyDef.type = b2BodyType::b2_dynamicBody;
            m_BodyDef.linearDamping = 1.0f;
            m_BodyDef.angularDamping = 1.0f;
            m_BodyDef.fixedRotation = false;
            
            m_BodyDef.position = {position.x,position.z};
            m_BodyDef.angle = -rotation.y;
            
        }
    
        //Create the body in the world
        if (auto physcene = m_Physics2DScene.lock())
        {
            if (m_Body)
                physcene->m_B2DWorld.DestroyBody(m_Body);
    
            m_Body = physcene->m_B2DWorld.CreateBody(&m_BodyDef);
            
        }
        
        buildFixtures();
    
    }
    
}

void Rigidbody::buildFixtures()
{
    if (auto gameObject = getGameObject().lock())
    {
        std::vector<std::weak_ptr<Collider>> colliders = gameObject->getComponents<Collider>();
        
        //Reset fixture array
        deleteAndClearFixtures();
        
        //Build / Rebuild the fixtures
        for(size_t i = 0, s = colliders.size(); i < s; i++)
            if (auto currentCollider = colliders[i].lock())
            {
                std::vector<b2FixtureDef> fixtures =  currentCollider->getFixtures();
                
                for(size_t j = 0, t = fixtures.size(); j < t; j++)
                {
                    Debug::log(TAG, fixtures[j].friction);
                    fixtures[j].userData = new std::weak_ptr<Collider>(colliders[i]);
                    m_Fixtures.push_back(m_Body->CreateFixture(&fixtures[j]));
                    
                }
                
            }
        
    }
    
}

void Rigidbody::freezeAxis(const AxisFreezeMode &aAxisFreezeMode)
{
    if (auto physcene = m_Physics2DScene.lock())
    {
        if (m_AxisFreezeJoint)
        {
            physcene->m_B2DWorld.DestroyJoint(m_AxisFreezeJoint);
            delete m_AxisFreezeJoint;
        
        }
        
        if (aAxisFreezeMode == AxisFreezeMode::None)
            return;
        
        b2PrismaticJointDef prismaticJointDef;
        prismaticJointDef.bodyA = physcene->m_WorldOriginBody;
        prismaticJointDef.bodyB = m_Body;
        prismaticJointDef.collideConnected = false;
        prismaticJointDef.localAnchorA.Set(0,m_Body->GetPosition().y);
        
        if (aAxisFreezeMode == AxisFreezeMode::X)
            prismaticJointDef.localAxisA.Set(1,0);
                
        if (aAxisFreezeMode == AxisFreezeMode::Y)
            prismaticJointDef.localAxisA.Set(0,1);
        
        m_AxisFreezeJoint = dynamic_cast<b2PrismaticJoint*>(physcene->m_B2DWorld.CreateJoint(&prismaticJointDef));
        
    }
    
}

// Accessors
Vector2 Rigidbody::getVelocity() const
{
    b2Vec2 a = m_Body->GetLinearVelocity();
    return Vector2(a.x,a.y);

}

void Rigidbody::setVelocity(const GDK::Math::Vector2 &aVelocity){setVelocity(aVelocity.x,aVelocity.y);}
void Rigidbody::setVelocity(const float &aX,const float &aY){m_Body->SetLinearVelocity(b2Vec2(aX,aY));}

void Rigidbody::setVelocityX(const float &aX)
{
    b2Vec2 v = m_Body->GetLinearVelocity();
    v.x = aX;
    m_Body->SetLinearVelocity(v);
    
}

void Rigidbody::setVelocityY(const float aY)
{
    b2Vec2 v = m_Body->GetLinearVelocity();
    v.y = aY;
    m_Body->SetLinearVelocity(v);
    
}

void Rigidbody::normalizeVelocity()
{
    b2Vec2 v = m_Body->GetLinearVelocity();
    v.Normalize();
    m_Body->SetLinearVelocity(v);

}

void Rigidbody::scaleVelocity(const float &aScalar)
{
    b2Vec2 v = m_Body->GetLinearVelocity();
    v.x*=aScalar;
    v.y*=aScalar;
    m_Body->SetLinearVelocity(v);
    
}

void Rigidbody::applyImpulse(const float &aX,const float &aY)
{
    m_Body->ApplyLinearImpulse({aX,aY},{0,0},true);

}

void Rigidbody::applyForce(const Vector2 &aForce)
{
    m_Body->ApplyForceToCenter({aForce.x,aForce.y},true);

}

void Rigidbody::applyForce(const float &aX,const float &aY)
{
    m_Body->ApplyForceToCenter({aX,aY},true);

}

void Rigidbody::applyTorque(const float &aTorque)
{
    m_Body->ApplyTorque(-aTorque,true);

}

void Rigidbody::setType(const Type &aType)
{
    switch (aType)
    {
        case Type::Dynamic:
            m_Body->SetType(b2BodyType::b2_dynamicBody);
            break;
        
        case Type::Kinematic:
            m_Body->SetType(b2BodyType::b2_kinematicBody);
            break;
            
        case Type::Static:
            m_Body->SetType(b2BodyType::b2_staticBody);
            break;
        
    }
    
}

void Rigidbody::freezeRotation(const bool &aFreeze)
{
    m_Body->SetFixedRotation(aFreeze);

}

void Rigidbody::setLinearDamping(const float &aLinearDamping)
{
    m_Body->SetLinearDamping(aLinearDamping);

}

void Rigidbody::setAngularDamping(const float &aAngularDamping)
{
    m_Body->SetAngularDamping(aAngularDamping);

}

bool Rigidbody::isRotationFrozen()
{
    return m_Body->IsFixedRotation();

}

void Rigidbody::setLinearVelocity(const float &aX, const float &aY)
{
    m_Body->SetLinearVelocity({aX,aY});

}

void Rigidbody::setPosition(const float &aX,const float &aY,const float &aZ)
{
    m_Body->SetTransform({aX,aZ}, m_Body->GetAngle());
    
    if (auto g = getGameObject().lock())
        g->setPosition(aX,aY,aZ);
    
}

void Rigidbody::setPosition(const float &aX,const float &aY)
{
    m_Body->SetTransform({aX,aY}, m_Body->GetAngle());
    
    if (auto g = getGameObject().lock())
        g->setPosition(aX,g->getPosition().y,aY);
    
}

void Rigidbody::setGravityScale(const float &aScalar)
{
    m_Body->SetGravityScale(aScalar);

}

void Rigidbody::setRotation(const float &aRotation)
{
    m_Body->SetTransform(m_Body->GetPosition(), -aRotation);
    
    if (auto g = getGameObject().lock())
        g->setRotation(Quaternion({0,aRotation,0}));
    
}

void Rigidbody::clearForces()
{
    m_Body->SetLinearVelocity({0,0});
    m_Body->SetAngularVelocity(0);
    
}

void Rigidbody::deleteAndClearFixtures()
{
    for(size_t i = 0, s = m_Fixtures.size(); i < s; i++)
    {
        delete (std::weak_ptr<Collider>*)m_Fixtures[i]->GetUserData();
        m_Body->DestroyFixture(&*m_Fixtures[i]);
        
    }
    
    m_Fixtures.clear();
    
}

void Rigidbody::onAddedToGameObject(const std::weak_ptr<GameObject> &a)
{
    if (auto gameObject = a.lock())
        if (auto scene = gameObject->getScene().lock())
            m_Physics2DScene = scene->getSceneGraph<Physics2D::SceneGraph>().lock();
    
    if (auto gameObject = a.lock())
        if (auto scene = gameObject->getScene().lock())
            if (auto physcene = scene->getSceneGraph<Physics2D::SceneGraph>().lock())
                m_Body = physcene->m_B2DWorld.CreateBody(&m_BodyDef);
        
    m_BodyDef.userData = this;
        
    buildBody();
    
}

Rigidbody::~Rigidbody()
{
    deleteAndClearFixtures();
    
    if (m_Body)
        if (auto physcene = m_Physics2DScene.lock())
            physcene->m_B2DWorld.DestroyBody(m_Body);
    
    if (m_AxisFreezeJoint)
        delete m_AxisFreezeJoint;
    
}
