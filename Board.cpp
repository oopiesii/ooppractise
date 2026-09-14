#include <iostream>
#include "Board.h"
using namespace std;

void Board::draw()
{
    std::cout << std::string(width, '-') << std::endl;
    for (int i =0; i < height; i++)
    {
        std::cout << "|" << std::string(width - 2, ' ') << "|" << std::endl;
    }
    std::cout << std::string(width, '-') << std::endl;
}
// void Board::listallonboard() {
//     for (int i = 0; i < shapes.size(); i++) {
//         std::cout << shapes[i] << std::endl;
//     }
// // }
// void Board::addfigure() {
//
// }


