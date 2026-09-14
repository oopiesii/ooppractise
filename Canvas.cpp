//
// Created by Polina Stupak on 07.09.2026.
//
#include <fstream>
#include <iostream>
using namespace std;
#include "Canvas.h"
Canvas::Canvas() : width(120), height(30) {
//     canvas = vector<vector<char>>(width, vector<char>(height, ' '));
//     colors = vector<vector<string>>(width, vector<string>(height, ""));
}
std::string Canvas::getcolor(std::string colour) {
    if (colour == "red") return "\033[31m";
    else if (colour == "blue") return "\033[34m";
    else if (colour == "green") return "\033[32m";
    else if (colour == "yellow") return "\033[33m";
    else if (colour == "magenta") return "\033[35m";
    else if (colour == "cyan") return "\033[36m";
    else if (colour == "white") return "\033[37m";
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
void Canvas::clear(Canvas canva) {
    for (int i = 0; i < canva.getwidth(); i++) {
        for (int j = 0; j < canva.getheight(); j++) {
            canvas[i][j] = ' ';
            colors[i][j] = "";
        }
    }
    vector<Shape*>().swap(shapes);
}
void Canvas::save(Canvas canva, std::string filename) {
    ofstream file(filename);
    int i = 0;
    if (!file.is_open()) {
        cout << "Cannot be opened!" << endl;
        return;
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            file << canvas[j][i];
            if (canvas[j][i] != ' ') {
                file << "|" << colors[j][i];
            }
            file << ";";
        }
        file << endl;
    }
    file.close();
    cout << "All saved!" << endl;
}
void Canvas::load(std::string filename) { ifstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot be opened!" << endl;
        return;
    }
    canvas.assign(width, vector<char>(height, ' '));
    colors.assign(width, vector<string>(height, ""));
    string line;
    int y = 0;
    while (getline(file, line) && y < height) {
        int x = 0;
        int pointer = 0;
        while (pointer < line.size() && x < width) {
            int end = line.find(';', pointer);
            string cell = line.substr(pointer, end - pointer);
            if (!cell.empty()) {
                canvas[x][y] = cell[0];
                if (cell.size() > 2 && cell[1] == '|') {
                    colors[x][y] = cell.substr(2);
                }
            }
            pointer = end + 1;
            x++;
        }
        y++;
    }
    file.close();
    cout << "All loaded!" << endl;
}
int Canvas::selectbycoo(int x, int y) {
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
    Shape* shape = shapes[selectedid];
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (shape -> contains(i, j)) {
                canvas[i][j] = ' ';
                colors[i][j] = "";
            }
        }
    }
    cout << "Shape was removed!" << endl;
}