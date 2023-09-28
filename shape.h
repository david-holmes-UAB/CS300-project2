/*
*   File: shape.h
*   ------------------------------------
*   Defines the shape class. The shape class has a simple
*   hierachy of graphical shape classes.
*   Implementation provided by Dr Wagner.
*/

#ifndef _shape_h
#define _shape_h

#include <string>
#include "include/gwindow.h"
// Uses the gwindow class provided from Stanford uni's cslib package

/*
*   Class: Shape
*   ---------------------------------
*   This class is the root of the hierarchy -- contains all shapes
*/
class Shape {

  public:

  /*
  * Method: setLocation
  * Usage: shape.setLocation(x, y);
  * ------------------------------------
  * Sets the x and y coordinates of the shape to the specified values
  * */
    void setLocation(double x, double y);

  /*
  * Method: move
  * Usage: shape.move(dx, dy);
  * ------------------------------------
  * Adds dx and dy to the coordinates of the shape
  * */
    void move(double x, double y);

  /*
  * Method: setColor
  * Usage: shape.setColor(color);
  * ------------------------------------
  * Sets the color of the shape. The names of the available colors are in the
  * gwindow.h interface
  * */
    void setColor(std::string color);

  /*
  * Abstract method: draw
  * Usage: shape.draw(gw)
  * ------------------------------------
  * Draws the shape on the GraphicsWindow specifiec by gw. This method is
  * implemented by the specific shape subclasses
  * */
    virtual void draw(GWindow & gw) = 0;

  /*
  * Abstract Method: contains
  * Usage: shape.contains(x, y)
  * -------------------------------------
  * For the Rect and Oval subclasses, returns true if the point is inside
  * the shape, and false if it is outside.
  * For the Line class, returns true if the point is within a half a pixel
  * distance of the line.
  */
    virtual bool contains(double x, double y) = 0;

  protected:
  /* The following methods and fields are available to the subclasses */
    Shape();                        /* Superclass constructor */
    std::string color;              /* Color of the object */
    double x, y;                    /* Coordinates of the object */
};

/*
* Subclass: Line
* --------------------------------
* The Line subclass represents a line segment on the window
*/
class Line : public Shape {

  public:
  
  /*
  * Constructor: Line
  * Usage: Line line(x1, y1, x2, y2);
  * ---------------------------------------------
  * Creates a line segment that extends from (x1, y1) to (x2, y2)
  */
    Line(double x1, double y1, double x2, double y2);

  /* Prototypes for the overridden virtual methods */
    virtual void draw(GWindow & gw);
    virtual bool contains(double x, double y);

  private:
    double dx;              /* Horizontal distance from x1 to x2 */
    double dy;              /* Vertical distance from y1 to y2 */

};

/*
* Subclass: Rect
* -----------------------------------------
* The Rect subclass repesents a solid rectangle
*/
class Rect : public Shape {
  
  public:

    /*
    * Constuctor: Rect
    * Usage: Rect rect(x, y, width, height);
    *        Rect *rec = new Rect(x, y, width, height)
    * ---------------------------------------------
    * Creates a rectangle of the specified size and upper left corner at (x, y)
    */
    Rect(double x, double y, double width, double height);

  /* Prototypes for the overidden virtual methods */
    virtual void draw(GWindow & gw);
    virtual bool contains(double x, double y);

  private:
    double width, height;           /* Dimensions of the rectangle */
};

/*
* Subclass: Oval
* --------------------------------
* The Oval subclass represents a solid oval defined by a bounding rectangle
*/
class Oval : public Shape {

  public:
  /*
  * Constructor: Oval
  * Usage: Oval oval(x, y, width, height);
  *        Oval *ov = new Oval(x, y, width, height)
  * ------------------------------------------
  * Creates an oval that fits inside the rectangle indicated by the arguments
  */
    Oval(double x, double y, double width, double height);

  /* Prototypes for the overridden virtual methods */
    virtual void draw(GWindow & gw);
    virtual bool contains(double x, double y);

  private:
    double width, height;           /* Dimensions of the binding rectangle */
};

/*
* Subclass: Square
* ---------------------------------
* The Square subclass represents a solid square
*/
class Square : public Rect {

  public:
  /*
  * Constructor: Square
  * Usage: Square square(double x, double y, double size) 
  *        Square *sq = new Square(double x, double y, double size)
  * ---------------------------------------------------------
  * Creates a square of the specifized size and upper left corner at (x, y)
  */
    Square(double x, double y, double size);
    
};

#endif