#include "BanaShape.h"

BanaShape::BanaShape(std::string name) :m_Name(name)
{
    //ctor
}

BanaShape::~BanaShape()
{
    //dtor
}

std::string BanaShape::GetName()
{
    return m_Name;
}

