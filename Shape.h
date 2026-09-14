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
        Shape(int id, string color, string fillmode, int x, int y);
        virtual void draw(Canvas& canva) = 0;
        virtual bool contains(int x,int y) = 0;
        // virtual bool fits(int bwidth,int bheight) = 0;
        // virtual void move(int x1,int y1) = 0;
        // virtual void paint(string color) = 0;
        string getColor();
        void getCoo();
        int getId();
        string getFillMode();
    protected:
        int id;
        string color_;
        string fillmode_;
        int x_;
        int y_;
};


#endif //ASSIGNMENT1_SHAPE_H
