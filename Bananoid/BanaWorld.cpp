#include "BanaWorld.h"

BanaWorld::BanaWorld()
{
    //ctor
}

BanaWorld::~BanaWorld()
{
    //dtor
}

void BanaWorld::AddObject(BanaObject &object)
{
    m_objects.push_back(&object);
}

void BanaWorld::Collide()
{
    for(std::vector<BanaObject*>::iterator it = m_objects.begin(); it != m_objects.end(); ++it)
    {
        for(std::vector<BanaObject*>::iterator itSec = m_objects.begin(); itSec != m_objects.end(); ++itSec)
        {
            if (it != itSec)
            {
                (*it)->Collide( *(*itSec) );
            }
        }
    }
}
