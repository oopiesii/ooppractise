#include "Shape.h"
#include "Canvas.h"
#include "Line.h"
using namespace std;
#include <string>
#include <fstream>

Line::Line(int id, const string& name, const string& color, const string& fillmode, int x, int y, int length):Shape(id, name, color, fillmode, x, y), length(length) {}
void Line::draw(Canvas& canva)
{
    if (fillmode_ == "fill" || fillmode_ == "frame")
    {
        for (int i = 0; i < length; i++) {
            canva.setbycoo(x_ + i, y_, 'L', color_);
        }
    }
}
bool Line::contains(int x, int y) {
    return y == y_ && x == x_ && x < x_+length;
}

void Line::edit(int a, int b) {
    length = a;
}
void Line::save(ofstream& filename)  {
    filename << id << " " << name << " " << color_ << " " << fillmode_ << " " << x_ << " " << y_ << " " << length << endl;
}