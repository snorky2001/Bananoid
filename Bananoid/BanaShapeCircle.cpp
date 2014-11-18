#include "stdafx.h"

#include "BanaShape.h"

#include <iostream>

#include "BanaShapeCircle.h"
#include "BanaShapeRect.h"


BanaShapeCircle::BanaShapeCircle(std::string name) :BanaShape(name)
{
    //ctor
}

BanaShapeCircle::~BanaShapeCircle()
{
    //dtor
}

void BanaShapeCircle::Collide(BanaShape &shape)
{
    shape.Collide(*this);
}


void BanaShapeCircle::Collide(BanaShapeCircle &shape)
{
    std::cout << "Check circle " << GetName() << " with circle " << shape.GetName() << std::endl;
}

void BanaShapeCircle::Collide(BanaShapeRect &shape)
{
    std::cout << "Check circle " << GetName() << " with rect " << shape.GetName() << std::endl;
}

