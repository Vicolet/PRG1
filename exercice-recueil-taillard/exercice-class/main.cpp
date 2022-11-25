#include "Point.h"
#include "Point.cpp"

Point pointSymetrique(const Point &point);

int main() {
   double coordonneeX = 0.0, coordonneeY = 0.0;
   Point coordonee(coordonneeX, coordonneeY);
   coordonee.printX();
   coordonee.printY();
   coordonee.replaceX(3.5);
   coordonee.replaceY(4.5);
   coordonee.printX();
   coordonee.printY();
   coordonee.deplaceXY(0.5, 1.5);
   coordonee.printX();
   coordonee.printY();

   return 0;
}

Point pointSymetrique(const Point &point) {

}