#ifndef ASSIGNMENT1_SHAPE_H
#define ASSIGNMENT1_SHAPE_H
#include <iostream>
#include <string>
#include "Canvas.h"
using namespace std;
class Canvas;
class Shape {
    public:
        Shape(int id, const string& name, const string& color, const string& fillmode, int x, int y);
        virtual ~Shape() = default;
        virtual void draw(Canvas& canva) = 0;
        virtual void edit(int a = 0, int b = 0) = 0;
        virtual bool contains(int x,int y) = 0;
        virtual int getHeight() = 0;
        virtual int getWidth() = 0;
        virtual int getLength() = 0;
        virtual int getRadius() = 0;
        string getColor();
        int getX();
        int getY();
        int getId();
        void changecolor(const string& colo);
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
