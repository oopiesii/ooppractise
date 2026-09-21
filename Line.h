#ifndef ASSIGNMENT1_LINE_H
#define ASSIGNMENT1_LINE_H
#include <fstream>
class Line : public Shape{
    public:
    Line(int id, const string& name, const string& color, const string& fillmode, int x, int y, int length);
    void draw(Canvas& canva) override;
    bool contains(int x,int y) override;
    void edit(int a = 0, int b = 0) override;
    void save(ofstream& filename)  override;
private:
    int length;
};



#endif //ASSIGNMENT1_LINE_H
