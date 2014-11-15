#ifndef BANASHAPERECT_H
#define BANASHAPERECT_H

#include "BanaShape.h"
#include <string>

class BanaShapeCircle;

class BanaShapeRect: public BanaShape
{
    public:
        BanaShapeRect(std::string name);
        virtual ~BanaShapeRect();
        void Collide(BanaShape &shape);
        void Collide(BanaShapeCircle &shape);
        void Collide(BanaShapeRect &shape);

    protected:
    private:

};

#endif // BANASHAPERECT_H
