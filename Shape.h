//
// Created by Polina Stupak on 07.09.2026.
//

#ifndef ASSIGNMENT1_SHAPE_H
#define ASSIGNMENT1_SHAPE_H
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string>
#include "Canvas.h"
using namespace std;
class Canvas;
class Shape {
    public:
        Shape(int id, string name, string color, string fillmode, int x, int y);
        virtual ~Shape() = default;
        virtual void draw(Canvas& canva) = 0;
        virtual bool contains(int x,int y) = 0;
        virtual int getHeight() = 0;
        virtual int getWidth() = 0;
        virtual int getLength() = 0;
        virtual int getRadius() = 0;
        string getColor();
        int getX();
        int getY();
        int getId();
        void move(int newx, int newy);
        string getName();
        string getFillMode();
    protected:
        int id;
        string name;
        string color_;
        string fillmode_;
        int x_;
        int y_;
};
#endif //ASSIGNMENT1_SHAPE_H
