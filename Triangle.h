#ifndef ASSIGNMENT1_TRIANGLE_H
#define ASSIGNMENT1_TRIANGLE_H
#include "Shape.h"
#include <fstream>

class Triangle : public Shape {
public:
    Triangle(int id, const string& name, const string& color, const string& fillmode, int x, int y, int height);
    void draw(Canvas& canva) override;
    bool contains(int x,int y) override;
    void edit(int a = 0, int b = 0) override;
    int getHeight() override;
    int getWidth() override {return 0;};
    int getLength() override {return 0;};
    int getRadius() override {return 0;};
    void save(ofstream& filename) const override;
private:
    int height;
};


#endif //ASSIGNMENT1_TRIANGLE_H
