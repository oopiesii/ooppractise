//
// Created by Polina Stupak on 08.09.2026.
//

#ifndef ASSIGNMENT1_TRIANGLE_H
#define ASSIGNMENT1_TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape {
public:
    Triangle(int id, string color, string fillmode, int x, int y, int height);
    void draw(Canvas& canva) override;
    bool contains(int x,int y) override;
    // bool fits(int bwidth,int bheight) override;
    // void move(int x1,int y1) override;
    // void paint(string color) override;
private:
    int height;
};


#endif //ASSIGNMENT1_TRIANGLE_H
