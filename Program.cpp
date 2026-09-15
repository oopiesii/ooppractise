//
// Created by Polina Stupak on 08.09.2026.
//
#include "Canvas.h"
#include "Program.h"
#include "Triangle.h"

#include <vector>
#include "Circle.h"
#include "Line.h"
#include <string>
#include <iostream>
#include <set>
#include <ostream>
#include <boost/algorithm/string.hpp>

#include "Rectangle.h"
using namespace std;
Program::Program() : canvas() {}
void Program::run() {
    string input;
    std::string command;
    std::set<std::string> commands = {"add", "draw", "list", "colors", "figures", "exit", "clear","remove", "save", "load", "select", "move"};
    cout << "Hi! Welcome to the BLACKBOARD by Polina Stupak!" << endl;
    cout << "Board size is: " << canvas.getwidth() << "X" << canvas.getheight() << endl;
    cout << "If you want to know all available figures print: figures, or colors print: colors. " << endl;
    cout << "Commands are 1. add, 2. draw, 3. list, 4. colors, 5. figures, 6. exit, 7. clear, 8. save, 9. load, 10. remove, 11. select, 12. move" << endl;
    cout << "Print what you want to illustrate(in sequence of command, figure, color, fill mode, coordinates and size)!" << endl;
    cout << "~Fill modes are frame and fill." << endl;
    while (command != "exit") {
        getline(cin, input);
        input = boost::to_lower_copy(input);
        vector<string> params;
        boost::split(params, input, boost::is_any_of(" "));
        command = params[0];
        try {
            if (!commands.contains(command)) {throw std::runtime_error("There is no such command!");}
            if (command == "add") {
                if (!canvas.allfigures.contains(params[1])) {throw std::runtime_error("There is no such figure!");}
                if (!canvas.allcolors.contains(params[2])) {throw std::runtime_error("There is no such color!");}
                if (stoi(params[4]) > canvas.getwidth() || stoi(params[5]) > canvas.getheight())  {throw std::runtime_error("Wrong coordinates!");}
                if (params[1] == "circle") {
                    if (params.size() != 7) {throw std::runtime_error("Wrong number of parameters for circle!");}
                    Circle* c = new Circle(canvas.shapes.size() + 1,"circle",params[2], params[3], stoi(params[4]), stoi(params[5]), stoi(params[6]));
                    canvas.shapes.push_back(c);
                    cout << "Figure successfully added!" << endl;
                    //add circle magenta fill 20 10 8 add rectangle red frame 23 16 5 6 add triangle blue fill 10 10 5
                }

                else if (params[1] == "line") {
                    if (params.size() != 7) {throw std::runtime_error("Wrong number of parameters for line!");}
                    Line* l = new Line(canvas.shapes.size() + 1,"line", params[2], params[3], stoi(params[4]), stoi(params[5]), stoi(params[6]));
                    canvas.shapes.push_back(l);
                    cout << "Figure successfully added!" << endl;
                }
                else if (params[1] == "triangle") {
                    if (params.size() != 7) {throw std::runtime_error("Wrong number of parameters for triangle!");}
                    Triangle* t = new Triangle(canvas.shapes.size() + 1,"triangle", params[2], params[3], stoi(params[4]), stoi(params[5]), stoi(params[6]));
                    canvas.shapes.push_back(t);
                    cout << "Figure successfully added!" << endl;
                }
                else if (params[1] == "rectangle") {
                    if (params.size() != 8) {throw std::runtime_error("Wrong number of parameters for rectangle!");}
                    Rectangle* r = new Rectangle(canvas.shapes.size() + 1, "rectangle", params[2], params[3], stoi(params[4]), stoi(params[5]), stoi(params[6]), stoi(params[7]));
                    canvas.shapes.push_back(r);
                    cout << "Figure successfully added!" << endl;
                }
            }
            if (command == "draw") {
                canvas.draw();
                continue;
            }
            if (command == "list") {
                canvas.list();
            }
            if (command == "colors") {
                int i = 1;
                for (string color: canvas.allcolors) {
                    cout << i << ". " << color << endl;
                    i++;
                }
            }
            if (command == "figures") {
                int i = 1;
                for (string figure : canvas.allfigures) {
                    cout << i << ". "<< figure << endl;
                    i++;
                }
            }
            if (command == "clear") {
                canvas.clear(canvas);
                cout << "Canva is clean!" << endl;
            }
            if (command == "save") {
                canvas.save(params[1]);
            }
            if (command == "load") {
                canvas.load(params[1]);
            }
            if (command == "select") {
                if (params.size() == 2) {
                    int result = canvas.selectbyid(stoi(params[1]));
                    if (result != -1) {
                        cout << "Figure is selected!" << endl;
                    }
                } else if (params.size() == 3) {
                    int result = canvas.selectbycoo(stoi(params[1]), stoi(params[2]));
                    if (result != -1) {
                        cout << "Figure is selected!" << endl;
                    }
                }
            }
            if (command == "remove") {
                canvas.remove(canvas.selected);
            }
            if (command == "move") {
                canvas.move(stoi(params[1]), stoi(params[2]));
            }
        }
        catch (std::exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}



