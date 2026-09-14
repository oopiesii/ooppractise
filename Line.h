//
// Created by Polina Stupak on 08.09.2026.
//

#ifndef ASSIGNMENT1_LINE_H
#define ASSIGNMENT1_LINE_H


class Line : public Shape{
    public:
    Line(int id, string name, string color, string fillmode, int x, int y, int length);
    void draw(Canvas& canva) override;
    bool contains(int x,int y) override;
    // bool fits(int bwidth,int bheight) override;
    // void move(int x1,int y1) override;
    // void paint(string color) override;
    int getLength() override;
    int getHeight() override {return 0;};
    int getWidth() override {return 0;}
    int getRadius() override {return 0;}
private:
    int length;
};



#endif //ASSIGNMENT1_LINE_H
