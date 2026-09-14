#include <iostream>
#include <string>
#include "Shape.h"

Shape::Shape(int id, string name, string color, string fillmode, int x, int y):
    id(id), name(name), color_(color), fillmode_(fillmode), x_(x), y_(y){}

string Shape::getColor()
    {
        return color_;
    }
void Shape::getCoo()
{
    cout << "X: " << x_ << ". Y: " << y_ << endl;
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
