#include "VertexFormat.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GFX;

// Special values
VertexFormat VertexFormat::Pos3uv2(
{
    VertexAttribute("a_Position",3),
    VertexAttribute("a_UV"      ,2)

});

VertexFormat VertexFormat::Pos3(
{
    VertexAttribute("a_Position",3)

});

std::ostream& GDK::GFX::operator<<(std::ostream& stream, const GFX::VertexFormat& aVertexFormat)
{
    stream.clear();
    stream << "{" << "VertexFormat's operator<< has not been implemented" << "}";
    return stream;

}

VertexFormat::VertexFormat(const std::vector<VertexAttribute> &aAttributes)
{
    m_NumberOfAttributes = (int)aAttributes.size();
    int attributeComponentCount = 0;

    //Process attribute data
    for(int i = 0, s = m_NumberOfAttributes; i < s; i++)
    {
        m_Format.insert(std::pair<std::string,int>(aAttributes[i].name, aAttributes[i].size));
        
        attributeComponentCount+= aAttributes[i].size;
        
    }
    
    m_TotalNumberOfAttributeComponents = attributeComponentCount;
    
}

int VertexFormat::getSumOfAttributeComponents() const {return m_TotalNumberOfAttributeComponents;}
int VertexFormat::getNumberOfAttributes(){return m_NumberOfAttributes;}
int VertexFormat::getAttributeSize(const std::string &aAttributeName){return m_Format.at(aAttributeName);}

std::vector<std::string> VertexFormat::getNames()
{
    std::vector<std::string> keys;// = new String[m_NumberOfAttributes];
    
    for(std::map<std::string,int>::iterator it = m_Format.begin(); it != m_Format.end(); ++it)
        keys.push_back(it->first);
    
    return keys;
    
}
