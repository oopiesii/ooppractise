#ifndef ASSIGNMENT1_CIRCLE_H
#define ASSIGNMENT1_CIRCLE_H
#include "Shape.h"
#include <fstream>

class Circle : public Shape {
public:
    Circle(int id, const string& name, const string& color, const string& fillmode, int x, int y, int radius);
    void draw(Canvas& canva) override;
    bool contains(int x,int y) override;
    int getRadius() override;
    void edit(int a = 0, int b = 0) override;
    int getHeight() override {return 0;};
    int getWidth() override {return 0;};
    int getLength() override {return 0;};
    void save(ofstream& filename) const override;
private:
    int radius;
};


#endif //ASSIGNMENT1_CIRCLE_H
