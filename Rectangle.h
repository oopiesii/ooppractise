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
        void edit(int a = 0, int b = 0) override;
        void save(ofstream& filename) override;
    private:
        int width;
        int height;
};


#endif //ASSIGNMENT1_RECTANGLE_H
