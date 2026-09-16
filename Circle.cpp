#include <cmath>
#include "Circle.h"
#include "Canvas.h"
Circle::Circle(int id, const string& name, const string& color, const string& fillmode, int centerx, int centery, int radius):Shape(id, name, color, fillmode, centerx, centery), radius(radius) {}
void Circle::draw(Canvas& canva) {
    for (int i = -radius; i < radius; i++) {
        for (int j = -radius; j < radius; j++) {
            double distance = sqrt(i * i + (j * 2)*(j * 3));
            if (fillmode_ == "fill") {
                if (distance<=radius) {
                    canva.setbycoo(x_ + i, y_ + j, 'C', color_);
                }
            }
            else if (fillmode_ == "frame") {
                if (distance<=radius && distance > radius - 1) {
                    canva.setbycoo(x_ + i, y_ + j, 'C', color_);

                }
            }
        }
    }
}
bool Circle::contains(int x, int y) {
    int xs = x - x_;
    int ys = y - y_;
    return xs*xs + ys*ys < radius*radius; //checks the distance to the centre
}
int Circle::getRadius() {
    return radius;
}
void Circle::edit(int a, int b) {
    radius = a;
}