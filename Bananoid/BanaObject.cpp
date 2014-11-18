#include "stdafx.h"
#include "BanaObject.h"

BanaObject::BanaObject()
{
    //ctor
}

BanaObject::~BanaObject()
{
    //dtor
}

void BanaObject::AddShape(BanaShape &shape)
{
    m_shapes.push_back(&shape);
}

void BanaObject::Collide(BanaObject &object)
{
    for(std::vector<BanaShape*>::iterator it = m_shapes.begin(); it != m_shapes.end(); ++it)
    {
        object.Collide( *(*it) );
    }
}

void BanaObject::Collide(BanaShape &shape)
{
    for(std::vector<BanaShape*>::iterator it = m_shapes.begin(); it != m_shapes.end(); ++it)
    {
        (*it)->Collide( shape );
    }
}
