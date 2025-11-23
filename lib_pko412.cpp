#include "point2d.h"

int main()
{
    top::Point2d p1(10, 10);
    top::Point2d p2 = p1;
    p2 = p1 + p2;
    p1.print();
    p2.print();
    return 0;
}
