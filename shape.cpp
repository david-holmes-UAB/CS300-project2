/*
* File: shape.cpp
* --------------------------------
* This file implements the shape.h interface.
*/

#include <string>
#include "include/gwindow.h"
#include "shape.h"
#include <stdlib.h>
#include <math.h>
#include <cmath>

/*
* Implementaion notes: Shape class
* --------------------------------------
* The constructor sets the color of all shapes to the default
* color of BLACK. The remaining methods set the instance variables.
*/

Shape::Shape() {
    setColor("BLACK");
}

void Shape::setLocation(double x, double y) {
    this->x = x;
    this->y = y;
}

void Shape::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Shape::setColor(std::string color) {
    this->color = color;
}

/*
* Implementation notes: Line class
* --------------------------------------------
* The constructor for the Line class has to change the specification of the
* line from the endpoints passed to the constructor to the representation that
* uses a starting point along with dx/dy values
*/

Line::Line(double x1, double y1, double x2, double y2) {
    this->x = x1;
    this->y = y1;
    this->dx = x2 - x1;
    this->dy = y2 - y1;
}

void Line::draw(GWindow & gw) {
    gw.setColor(color);
    gw.drawLine(x, y, x + dx, y + dy);
}

/*
* Implementation notes: Line::contains
* Usage: line.contains(double x, double y)
* ------------------------------------------
* This checks if a point is within 0.5 px of a line by using the 
* distance formula: (abs( ((x2 - x1) * (y1 - y0)) - ((x1 - x0) * (y2 - y1)) )) / 
*                   sqrt( ((x2 - x1)^2) + ((y2 - y1)^2) )
*/
bool Line::contains(double cx, double cy) {
    double x = this->x;
    double y = this->y;
    double dx = this->dx;
    double dy = this->dy;

    // Top portion of the distance formula (Dividend)
    double distTop = abs(((dx - x) * (y - cy)) - 
                        ((x - cx) * (dy - y)));
    // Bottom potion of the distance formula (Divisor)
    double equa = ((dx - x) * (dx - x)) + ((dy - y) * (dy - y));
    double distBottom = sqrt(equa);

    return (distTop / distBottom) <= 0.5;
}

/*
* Implementation notes: Rect and Oval, and Square classes
* -----------------------------------------------
* The constructors for these classes store their arguments in the 
* corresponding instance variables. The draw methos for the shape
* just forwards the request to the GWindow Class.
* Square is a subclass of Rect.
*/

Rect::Rect(double x, double y, double width, double height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Rect::draw(GWindow & gw) {
    gw.setColor(color);
    gw.fillRect(x, y, width, height);
}

/*
* Implementation notes: Rect::contains()
* Usage: rect.contains(double x, double y)
* ---------------------------------------------
* contains checks if the point is within the provided area using 
* the bounds of the top left point, and a bottom right point calculated
* by using the provided length and width
*/
bool Rect::contains(double cx, double cy) {
    double x = this->x;
    double y = this->y;
    double dx = x + this->width;
    double dy = y - this->height;
    if (x < cx && cx < dx && dy < cy && cy < y){
        return true;
    }
    else {
        return false;
    }
    
}

Oval::Oval(double x, double y, double width, double height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Oval::draw(GWindow & gw) {
    gw.setColor(color);
    gw.fillOval(x, y, width, height);
}

/*
* Implementation notes: Oval::contains()
* Usage: oval.contains(double x, double y)
* -------------------------------------------
* Checks if a point is inside a given oval by finding the center of the 
* oval using the width and height, then uses the found center point and 
* the provided point to plug into the inequality for a point in an oval
* Equation source: https://math.stackexchange.com/a/76463
*/
bool Oval::contains(double cx, double cy) {
    // Upper left corner of the encapsulating rectangle of the oval
    double x = this->x;
    double y = this->y;
    // Grabbing the width and height to get the semi major and minor axis
    double a = this->width / 2;         // Semi-major axis
    double b = this->height / 2;        // Semi-minor axis

    // Use half the width and height to find the mid point of the oval (h, k)
    double h = x + a;
    double k = y - b;

    // Utilize the ellipse equation and solve to see if less than 1
    double pt1 = (cx - h) * (cx - h);       // Dividend on left side of addition
    double pt2 = (cy - k) * (cy - k);       // Dividend on right side of addition

    // Solve ellipse/oval equation
    double res = (pt1 / (a * a)) + (pt2 / (b * b));

    // Compare to 1, point is in the circle if true. (res is less than or equal to 1)
    return res <= 1;
}

Square::Square(double x, double y, double size) 
    : Rect(x, y, size, size) {
    /* Empty */
}