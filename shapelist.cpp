/*
* File: shapelist.h
* ----------------------------------------------
* This file implements the the shapelist class defined in
* the file shapelist.h
*/

#include "shapelist.h"
#include "include/gwindow.h"
#include "shape.h"
#include <iostream>
#include <vector>

ShapeList::ShapeList() {
    std::vector<Shape *> shapes;
    int size = shapes.size();
}

void ShapeList::moveToFront(Shape *sp) {
    int found = 0;
    int pos = 0;
    for (Shape *s : shapes) {
        if (*s == *sp) {
            found = 1;
            break;
        }
        pos++;
    }

    if (found == 1) {
        Shape * temp = *sp;
        shapes.erase(pos);
        shapes.insert(shapes.begin(), *sp);
    }
    else {
        std::cout << "Error: the input shape was not found in the list.\n\n";
    }
}

void ShapeList::moveToBack(Shape *sp) {
    nt found = 0;
    for (Shape *s : shapes) {
        if (*s == *sp) {
            found = 1;
        }
    }

    if (found == 1) {

    }
    else {
        std::cout << "Error: the input shape was not found in the list.\n\n";
    }
}




void ShapeList::draw(GWindow & gw) {
    for (Shape *sp : shapes) {
        sp->draw(gw);
    }
}