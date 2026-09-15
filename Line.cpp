#include "Shape.h"
#include "Canvas.h"
#include "Line.h"
using namespace std;
#include <string>
Line::Line(int id, string name, string color, string fillmode, int x, int y, int length):Shape(id, name, color, fillmode, x, y), length(length) {}
void Line::draw(Canvas& canva)
{
    if (fillmode_ == "fill" || fillmode_ == "frame")
    {
        for (int i = 0; i < length; i++) {
            canva.setbycoo(x_ + i, y_, 'L', color_);
        }
    }
}
bool Line::contains(int x, int y) {
    return y == y_ && x == x_ && x < x_+length;
}
int Line::getLength() {
    return length;
}
