#ifndef BANASHAPECIRCLE_H
#define BANASHAPECIRCLE_H

#include "BanaShape.h"

class BanaShapeRect;

class BanaShapeCircle: public BanaShape
{
    public:
        BanaShapeCircle(std::string name);
        virtual ~BanaShapeCircle();
        void Collide(BanaShape &shape);
        void Collide(BanaShapeCircle &shape);
        void Collide(BanaShapeRect &shape);

    protected:
    private:
};

#endif // BANASHAPECIRCLE_H
