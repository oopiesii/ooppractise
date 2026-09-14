//
// Created by Polina Stupak on 08.09.2026.
//

#include "Triangle.h"
#include <cmath>
Triangle::Triangle(int id, string color, string fillmode, int x, int y, int height):Shape(id, color, fillmode, x, y), height(height) {}
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
