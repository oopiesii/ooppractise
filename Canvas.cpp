#include <fstream>
#include <iostream>
#include <sstream>
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;
#include "Canvas.h"
Canvas::Canvas() = default;
Canvas::~Canvas() {
    for (auto& shape : shapes) {
        delete shape;
    }
}
std::string Canvas::getcolor(const std::string& colour) {
    if (colour == "red") return "\033[31m";
    if (colour == "blue") return "\033[34m";
    if (colour == "green") return "\033[32m";
    if (colour == "yellow") return "\033[33m";
    if (colour == "magenta") return "\033[35m";
    if (colour == "cyan") return "\033[36m";
    if (colour == "white") return "\033[37m";
    return "\033[0m";
}
void Canvas::setbycoo(int x, int y, char C, std::string colour) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        canvas[x][y] = C;
        colors[x][y] = colour;
    }
}
int Canvas::getwidth() { return width; }
int Canvas::getheight() { return height; }
char Canvas::getChar(int x, int y) {
    return canvas[x][y];
}

std::string Canvas::getColorAt(int x, int y) {
    return colors[x][y];
}
void Canvas::draw() {
    canvas.assign(width, vector<char>(height, ' '));
    colors.assign(width, vector<string>(height, ""));
    for (auto& shape : shapes) {
        shape->draw(*this);
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            char ch = canvas[x][y];
            if (ch != ' ') {
                cout << getcolor(colors[x][y]) << ch << "\033[0m";
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }
}
void Canvas::list() {
    for (int i = 0; i < shapes.size(); i++)
        cout << i + 1 << ". "<< shapes[i]->getColor() << " " << shapes[i]->getName() << endl;
}
void Canvas::clear() {
    for (int i = 0; i < getwidth(); i++) {
        for (int j = 0; j < getheight(); j++) {
            canvas[i][j] = ' ';
            colors[i][j] = "";
        }
    }
    for (auto& shape : shapes) {
        delete shape;
    }
    shapes.clear();
    selected = -1;
}
void Canvas::save(const std::string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot be opened!" << endl;
        return;
    }
    for (auto& shape: shapes) {
        if (shape->getName() == "circle")
            {file << shape->getId() << " " << shape->getName() << " " << shape->getColor() << " " << shape->getFillMode() << " " << shape->getX()<< " " << shape->getY() << " " << shape->getRadius() << endl;}
        if (shape->getName() == "line")
            {file << shape->getId() << " " << shape->getName() << " " << shape->getColor() << " " << shape->getFillMode() << " " << shape->getX()<< " " << shape->getY() << " " << shape->getLength() << endl;}
        if (shape->getName() == "triangle")
            {file << shape->getId() << " " << shape->getName() << " " << shape->getColor() << " " << shape->getFillMode() << " " << shape->getX()<< " " << shape->getY() << " " << shape->getHeight() << endl;}
        if (shape->getName() == "rectangle")
            {file << shape->getId() << " " << shape->getName() << " " << shape->getColor() << " " << shape->getFillMode() << " " << shape->getX()<< " " << shape->getY() << " " << shape->getWidth() << " " << shape->getHeight() << endl;}
    }
    cout << "All saved!" << endl;
}
void Canvas::load(const std::string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot be opened!" << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        istringstream l(line);
        int id, x, y;
        string name, color, fillmode;
        l >> id >> name >> color >> fillmode >> x >> y;
        vector<int> pars;
        int i;
        while (l >> i) {
            pars.push_back(i);
        }
        if (name == "circle") {
            shapes.push_back(new Circle(id, name, color, fillmode, x, y, pars[0]));
        }
        if (name == "line") {
            shapes.push_back(new Line(id, name, color, fillmode, x, y, pars[0]));
        }
        if (name == "triangle") {
            shapes.push_back(new Triangle(id, name, color, fillmode, x, y, pars[0]));
        }
        if (name == "rectangle") {
            shapes.push_back(new Rectangle(id, name, color, fillmode, x, y, pars[0], pars[1]));
        }
    }
    file.close();
    cout << "All loaded!" << endl;
}
int Canvas::selectbycoo(int x, int y) {
    selected = -1;
    for (int i = shapes.size() - 1; i >= 0; i--) { //because overlapping better to check from the end
        if ( shapes[i] -> contains(x, y) ) {
            selected = i;
        return selected;
        }
    }
    if (selected == -1) {
        cout << "There is no figures on that coordinates!" << endl;
    }
    return selected;
}
int Canvas::selectbyid(int id) {
    selected = -1;
    for (int i = shapes.size() - 1; i >= 0; i--) { //because overlapping better to check from the end
        if ( shapes[i]->getId() == id ) {
            selected = i;
            return selected;
        }
    }
    if (selected == -1) {
        cout << "There is no figures on that coordinates!" << endl;
    }
    return selected;
}
void Canvas::remove(int selectedid) {
    if (selectedid < 0 || selectedid >= shapes.size()) {
        cout << "There is no figures on that coordinates!" << endl;
        selected = -1;
        return;
    }
    delete shapes[selectedid];
    shapes.erase(shapes.begin() + selectedid);
    selected = -1;
    cout << "Shape was removed!" << endl;
}
void Canvas::move(int x, int y) {
    shapes[selected]->move(x, y);
    cout << "Shape was moved!" << endl;
}
void Canvas::color(const string& color) {
    shapes[selected]->changecolor(color);
    cout << "Shape was colored!" << endl;
}
void Canvas::add(const vector<string>& params) {
                if (!allfigures.contains(params[1])) {throw std::runtime_error("There is no such figure!");}
                if (!allcolors.contains(params[2])) {throw std::runtime_error("There is no such color!");}
                if (stoi(params[4]) > getwidth() || stoi(params[5]) > getheight())  {throw std::runtime_error("Wrong coordinates!");}
                if (params[1] == "circle") {
                    if (params.size() != 7) {throw std::runtime_error("Wrong number of parameters for circle!");}
                    Circle* c = new Circle(shapes.size() + 1,"circle",params[2], params[3], stoi(params[4]), stoi(params[5]), stoi(params[6]));
                    shapes.push_back(c);
                    cout << "Figure successfully added!" << endl;
                }

                else if (params[1] == "line") {
                    if (params.size() != 7) {throw std::runtime_error("Wrong number of parameters for line!");}
                    Line* l = new Line(shapes.size() + 1,"line", params[2], params[3], stoi(params[4]), stoi(params[5]), stoi(params[6]));
                    shapes.push_back(l);
                    cout << "Figure successfully added!" << endl;
                }
                else if (params[1] == "triangle") {
                    if (params.size() != 7) {throw std::runtime_error("Wrong number of parameters for triangle!");}
                    Triangle* t = new Triangle(shapes.size() + 1,"triangle", params[2], params[3], stoi(params[4]), stoi(params[5]), stoi(params[6]));
                    shapes.push_back(t);
                    cout << "Figure successfully added!" << endl;
                }
                else if (params[1] == "rectangle") {
                    if (params.size() != 8) {throw std::runtime_error("Wrong number of parameters for rectangle!");}
                    Rectangle* r = new Rectangle(shapes.size() + 1, "rectangle", params[2], params[3], stoi(params[4]), stoi(params[5]), stoi(params[6]), stoi(params[7]));
                    shapes.push_back(r);
                    cout << "Figure successfully added!" << endl;
                }
}