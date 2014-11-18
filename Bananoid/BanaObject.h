#ifndef BANAOBJECT_H
#define BANAOBJECT_H

#include "BanaShape.h"
#include <vector>

class BanaObject
{
    public:
        BanaObject();
        virtual ~BanaObject();
        void AddShape(BanaShape &shape);
        void Collide(BanaObject &object);
        void Collide(BanaShape &shape);

    protected:
    private:
    std::vector<BanaShape*> m_shapes;
};

#endif // BANAOBJECT_H
