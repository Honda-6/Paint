#include "CircleFillingArtist.h"

/*
    An array of pointer to function returning a point on an octant,
    they are ordered according to the octants.
*/
static utils::Point (*OCTANTS[])(utils::Point,int,int){
    []  (utils::Point centre,int x,int y) -> utils::Point {return {centre.x + x, centre.y - y};},      //===>>Point on Oct1
    []  (utils::Point centre,int x,int y) -> utils::Point {return {centre.x - y, centre.y + x};},      //===>>Point on Oct2
    []  (utils::Point centre,int x,int y) -> utils::Point {return {centre.x - y, centre.y - x};},      //===>>Point on Oct3
    []  (utils::Point centre,int x,int y) -> utils::Point {return {centre.x - x, centre.y - y};},      //===>>Point on Oct4
    []  (utils::Point centre,int x,int y) -> utils::Point {return {centre.x - x, centre.y + y};},      //===>>Point on Oct5
    []  (utils::Point centre,int x,int y) -> utils::Point {return {centre.x + y, centre.y - x};},      //===>>Point on Oct6
    []  (utils::Point centre,int x,int y) -> utils::Point {return {centre.x + y, centre.y + x};},      //===>>Point on Oct7
    []  (utils::Point centre,int x,int y) -> utils::Point {return {centre.x + x, centre.y + y};}       //===>>Point on Oct8
};


void CircleFillingArtist::onMouseLeftDown(HDC hdc, int x, int y) {
    this->centre = {x,y};
}

void CircleFillingArtist::onMouseLeftUp(HDC hdc, int x, int y) {

    utils::Point edge {x,y};
    int dy = std::abs(y - centre.y), dx = std::abs(x - centre.x);
    this->radius = std::sqrt(utils::distanceSquared(centre,edge));
    unsigned short oct1,oct2;
    if(dy > dx)
    {
        if(y > centre.y)
            oct1 = (x > centre.x) ? 6 : 5;
        else
            oct1 = (x > centre.x) ? 1 : 2;
    }
    else
    {
        if(x > centre.x)
            oct1 = (y > centre.y) ? 7 : 0;
        else
            oct1 = (y > centre.y) ? 4 : 3;
    }
    oct2 = (oct1 + 4) % 8;       //we will fill opposing octants only;
    this->fillCircle(hdc,radius,OCTANTS[oct1],OCTANTS[oct2], COLOR_TEAL);
}


void CircleFillingArtist::handleConsole(HDC hdc) {
    int x,y;
    unsigned short oct1,oct2;
    std::cout << "Enter the coordinates of the centre of a circle (X,Y): \n";
    std::cout << "X: ";
    std::cin >> x;
    std::cout << "Y: ";
    std::cin >> y;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> this->radius;
    std::cout << "Enter two octants you wish to fill: ";
    std::cin >> oct1 >> oct2;
    while(oct1 > 8 || oct2 > 8 || oct1 < 1 || oct2 < 2 || oct1 == oct2)
    {
        std::cout << "Please Enter two valid different octants (1-8) : ";
        std::cin >> oct1 >> oct2;
    }
    this->centre = {x,y};
    this->fillCircle(hdc,radius,OCTANTS[oct1 - 1], OCTANTS[oct2 - 1], COLOR_TEAL);
}