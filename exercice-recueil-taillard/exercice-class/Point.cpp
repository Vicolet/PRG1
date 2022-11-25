#include "Point.h"

void Point::printX() {
   std::cout << x << std::endl;
}

void Point::printY() {
   std::cout << y << std::endl;
}

void Point::replaceX(double abcisse) {
   x = abcisse;
}

void Point::replaceY(double ordonnee) {
   y = ordonnee;
}

void Point::deplaceXY(double deltaX, double deltaY) {
   x += deltaX;
   y += deltaY;
}

void Point::distance(double point) {

}
