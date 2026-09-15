#ifndef ASSIGNMENT1_LINE_H
#define ASSIGNMENT1_LINE_H
class Line : public Shape{
    public:
    Line(int id, string name, string color, string fillmode, int x, int y, int length);
    void draw(Canvas& canva) override;
    bool contains(int x,int y) override;
    void add(vector<string> params, Canvas& canvas) override;
    int getLength() override;
    int getHeight() override {return 0;};
    int getWidth() override {return 0;}
    int getRadius() override {return 0;}
private:
    int length;
};



#endif //ASSIGNMENT1_LINE_H
