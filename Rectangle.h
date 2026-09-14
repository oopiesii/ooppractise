//
// Created by Polina Stupak on 07.09.2026.
//

#ifndef ASSIGNMENT1_RECTANGLE_H
#define ASSIGNMENT1_RECTANGLE_H
#include <__fwd/string.h>
#include "Shape.h"
#include<string>
class Canvas;
class Rectangle : public Shape{
    public:
        Rectangle(int id, string name, string color, string fillmode, int x, int y, int width, int height);
        void draw(Canvas& canvas) override;
        bool contains(int x,int y) override;
        int getWidth() override;
        int getHeight() override;
        int getLength() override {return 0;};
        int getRadius() override {return 0;};
        // bool fits(int bwidth,int bheight) override;
        // void move(int x1,int y1) override;
        // void paint(string color) override;
    private:
        int width;
        int height;
};


#endif //ASSIGNMENT1_RECTANGLE_H
