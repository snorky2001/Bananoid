#ifndef BANAWORLD_H
#define BANAWORLD_H

#include "BanaObject.h"
#include <vector>

class BanaWorld
{
    public:
        BanaWorld();
        virtual ~BanaWorld();
        void Collide();
        void AddObject(BanaObject &object);
    protected:
    private:
    std::vector<BanaObject*> m_objects;

};

#endif // BANAWORLD_H
