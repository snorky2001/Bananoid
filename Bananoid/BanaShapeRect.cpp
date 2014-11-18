#include "BanaShapeRect.h"

#include <iostream>

#include "BanaShape.h"
#include "BanaShapeCircle.h"


BanaShapeRect::BanaShapeRect(std::string name) :BanaShape(name)
{
    //ctor
}

BanaShapeRect::~BanaShapeRect()
{
    //dtor
}

void BanaShapeRect::Collide(BanaShape &shape)
{
    shape.Collide(*this);
}

void BanaShapeRect::Collide(BanaShapeCircle &shape)
{
    std::cout << "Check rect " << GetName() << " with circle " << shape.GetName() << std::endl;
}

void BanaShapeRect::Collide(BanaShapeRect &shape)
{
    std::cout << "Check rect " << GetName() << " with rect " << shape.GetName() << std::endl;
}

