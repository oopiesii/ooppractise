#ifndef ASSIGNMENT1_CIRCLE_H
#define ASSIGNMENT1_CIRCLE_H
#include "Shape.h"

class Circle : public Shape {
public:
    Circle(int id, const string& name, const string& color, const string& fillmode, int x, int y, int radius);
    void draw(Canvas& canva) override;
    bool contains(int x,int y) override;
    int getRadius() override;
    int getHeight() override {return 0;};
    int getWidth() override {return 0;};
    int getLength() override {return 0;};
private:
    int radius;
};


#endif //ASSIGNMENT1_CIRCLE_H
