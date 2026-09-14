//
// Created by Polina Stupak on 07.09.2026.
//

#ifndef ASSIGNMENT1_CIRCLE_H
#define ASSIGNMENT1_CIRCLE_H
#include "Shape.h"


class Circle : public Shape {
public:
    Circle(int id, string color, string fillmode, int x, int y, int radius);
    void draw(Canvas& canva) override;
    bool contains(int x,int y) override;
    // bool fits(int bwidth,int bheight) override;
    // void move(int x1,int y1) override;
    // void paint(string color) override;
private:
    int radius;
};


#endif //ASSIGNMENT1_CIRCLE_H
