//
// Created by Polina Stupak on 08.09.2026.
//
#include "Shape.h"
#include "Canvas.h"
#include "Line.h"
using namespace std;
#include <string>
Line::Line(int id, string color, string fillmode, int x, int y, int length):Shape(id, color, fillmode, x, y), length(length) {}
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