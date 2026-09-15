#ifndef ASSIGNMENT1_CANVAS_H
#define ASSIGNMENT1_CANVAS_H
#include <vector>
#include <set>
class Shape;
class Canvas {
public:
    Canvas();
    std::vector<std::vector<char>> canvas;
    std::vector<std::vector<std::string>> colors;
    std::set<std::string> allcolors = {"red", "blue", "green", "yellow", "magenta", "cyan", "white"};
    std::set<std::string> allfigures = {"circle", "line", "triangle", "rectangle"};
    void setbycoo(int x, int y, char C, std::string color);
    std::string getcolor(std::string color);
    void draw();
    void list();
    void clear(Canvas canvas);
    void save(std::string filename);
    void load(std::string filename);
    int getwidth();
    int getheight();
    char getChar(int x, int y);
    std::string getColorAt(int x, int y);
    int selectbycoo(int x, int y);
    int selectbyid(int id);
    void remove(int selectedid);
    std::vector<Shape*> shapes;
    int selected = -1;
    void move(int x, int y);
    void color(std::string color);
    void add(std::vector<std::string>params);
private:
    const int width = 120;
    const int height = 30;
};


#endif //ASSIGNMENT1_CANVAS_H
