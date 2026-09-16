#ifndef ASSIGNMENT1_RECTANGLE_H
#define ASSIGNMENT1_RECTANGLE_H
#include <__fwd/string.h>
#include "Shape.h"
#include<string>
#include <fstream>

class Canvas;
class Rectangle : public Shape{
    public:
        Rectangle(int id, const string& name, const string& color, const string& fillmode, int x, int y, int width, int height);
        void draw(Canvas& canvas) override;
        bool contains(int x,int y) override;
        int getWidth() override;
        void edit(int a = 0, int b = 0) override;
        int getHeight() override;
        int getLength() override {return 0;};
        int getRadius() override {return 0;};
        void save(ofstream& filename) const override;
    private:
        int width;
        int height;
};


#endif //ASSIGNMENT1_RECTANGLE_H
