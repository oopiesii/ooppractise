#include "Triangle.h"
Triangle::Triangle(int id, string name, string color, string fillmode, int x, int y, int height):Shape(id, name,color, fillmode, x, y), height(height) {}
void Triangle::draw(Canvas& canva) {
    for (int i = 0; i < height + 1; i++) {
        for (int j = -i; j <= i; j++) {
            bool border = (i == height || j == -i || j == i );
            if (fillmode_ == "fill" || border) {
                canva.setbycoo(x_ + j, y_ + i, 'T' , color_ );
            }
        }
    }
}
bool Triangle::contains(int x, int y) {
    int i = y - y_; // on which row from the vertex the point locates
    if (i < 0 || i > height) {return false;}
    return x >= x_ - i && x <= x_ + i; // if row is true if point in limits of triangle
}
int Triangle::getHeight() {
    return height;
}
