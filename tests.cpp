#include <stdlib.h>
#include <iostream>
#include <cmath>

bool lineContains(double cx, double cy) {
    // line from (2.00, 5.00) to (2.00, 17.00)
    double x = 2.00;
    double y = 5.00;
    double dx = 2.00;
    double dy = 17.00;

    // Top portion of the distance formula (Dividend)
    double distTop = abs(((dx - x) * (y - cy)) - 
                        ((x - cx) * (dy - y)));
    // Bottom potion of the distance formula (Divisor)
    double equa = ((dx - x) * (dx - x)) + ((dy - y) * (dy - y));
    double distBottom = sqrt(equa);

    return (distTop / distBottom) <= 0.5;
}

bool rectContains(double cx, double cy) {
    // Test for rect at point (3.00, 12.00) with width of 10 and height of 5
    double x = 3.00;
    double y = 12.00;
    double dx = x + 10;
    double dy = y - 5;
    if (x < cx && cx < dx && dy < cy && cy < y){
        return true;
    }
    else {
        return false;
    }
    
}


int main() {

    std::cout << "For Line: " << lineContains(2.50, 17.50) << "\n";
    std::cout << "For rect: " << rectContains(5.00, 8.00) << "\n";

    return 0;
}