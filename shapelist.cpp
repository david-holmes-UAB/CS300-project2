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
    int pos = 0;
    int found = 0;
    for (Shape *s : ShapeList()) {
        if (s == sp) {
            found = 1;
            break;
        }
        pos++;
    }

    if (found == 1) {
        Shape * temp = sp;
        ShapeList().removeAt(pos);
        ShapeList().push_back(sp);
    }
    else {
        std::cout << "Error: the input shape was not found in the list.\n\n";
    }
}

void ShapeList::moveForward(Shape *sp) {
    int pos = 0;
    int found = 0;
    for (Shape *s : ShapeList()) {
        if (s == sp) {
            found = 1;
            break;
        }
        pos++;
    }

    if (found == 1) {
        if (ShapeList().get(0) != sp) {
            Shape * temp = sp;
            Shape * old = ShapeList().get(pos - 1);
            ShapeList().removeAt(pos);
            ShapeList().insertAt(pos - 1, sp); /* Swaps the two items - 
                                           *  moves the object in the position it was pushed
                                           *  to, to the original position of sp */
            ShapeList().insertAt(pos, old);
        } 
        else {
            std::cout << "The inputted shape can't be moved any further forward.\n\n";
        }
    }
    else {
        std::cout << "Error: the input shape was not found in the list.\n\n";
    }

}

void ShapeList::moveBackward(Shape *sp) {

}

Shape * getShapeAt(double x, double y) {
    Shape *sp = nullptr;

    return sp;
}


void ShapeList::draw(GWindow & gw) const{
    for (Shape *sp : ShapeList()) {
        sp->draw(gw);
    }
}