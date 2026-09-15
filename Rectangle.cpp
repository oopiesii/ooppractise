#include "Canvas.h"
#include "Rectangle.h"
Rectangle::Rectangle(int id, string name, string color, string fillmode, int x, int y, int width, int height):Shape(id, name, color, fillmode, x, y), width(width), height(height) {}
void Rectangle::draw(Canvas& canvas)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (fillmode_ == "fill") {
                canvas.setbycoo(x_ + i, y_ + j, 'R', color_);
            }
            else if (fillmode_ == "frame")
            {
                bool isBorder = (i == 0 || i == width - 1 || j == 0 || j == height - 1 );
                if (isBorder)
                    canvas.setbycoo(x_ + i, y_ + j, 'R', color_);
            }
        }
    }
}
bool Rectangle::contains(int x, int y) {
    return x >= x_ && x <= x_ + width && y >= y_ && y <= y_ + height;
}
int Rectangle::getHeight() {
    return height;
}
int Rectangle::getWidth() {
    return width;
}
