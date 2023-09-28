#include <iostream>
#include "include/gwindow.h"
#include "shape.h"
#include "include/error.h"

int main() {
    GWindow gw;
    double width = gw.getWidth();
    double height = gw.getHeight();
    Line *ln = new Line(3.5, 2.0, 3.5, 28.0);
    ln->setColor("BLUE");
    ln->draw(gw);


    return 0;
}