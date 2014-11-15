#ifndef BANASHAPE_H
#define BANASHAPE_H

#include <string>

class BanaShapeCircle;
class BanaShapeRect;

class BanaShape
{
    public:
        BanaShape(std::string name);
        virtual ~BanaShape();
        virtual void Collide(BanaShape &shape) = 0;
        virtual void Collide(BanaShapeCircle &shape) = 0;
        virtual void Collide(BanaShapeRect &shape) = 0;
        std::string GetName();

    protected:
    private:
        std::string m_Name;
};

#endif // BANASHAPE_H
