#include <iostream>
#include <string>
#include "Shape.h"

Shape::Shape(int id, string name, string color, string fillmode, int x, int y):
    id(id), name(name), color_(color), fillmode_(fillmode), x_(x), y_(y){}

string Shape::getColor()
    {
        return color_;
    }
int Shape::getX()
{
    return x_;
}
int Shape::getY()
{
    return y_;
}
string Shape::getFillMode()
{
    return fillmode_;
}
int Shape::getId() {
    return id;
}
string Shape::getName() {
    return name;
}
