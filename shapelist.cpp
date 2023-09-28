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
#include "include/vector.h"

void ShapeList::moveToFront(Shape *sp) {
    int found = 0;
    int pos = 0;
    for (Shape *s : ShapeList()) {
        if (s == sp) {
            found = 1;
            break;
        }
        pos++;
    }

    if (found == 1) {
        Shape * temp = sp;
        // note: as this uses the stanford version of vector, erase isn't a
        // method that exists. Instead, it uses "removeAt()"
        ShapeList().removeAt(pos);
        ShapeList().insert(0, sp);
    }
    else {
        std::cout << "Error: the input shape was not found in the list.\n\n";
    }
}

void ShapeList::moveToBack(Shape *sp) {
    int found = 0;
    for (Shape *s : ShapeList()) {
        if (s == sp) {
            found = 1;
        }
    }

    if (found == 1) {

    }
    else {
        std::cout << "Error: the input shape was not found in the list.\n\n";
    }
}




void ShapeList::draw(GWindow & gw) const{
    for (Shape *sp : ShapeList()) {
        sp->draw(gw);
    }
}