#include "CircleFillingArtist.h"

/*
    An array of pointer to function returning a point on an octant,
    they are ordered according to the octants i.e each index corresponds to the octant number in the Anti-Clockwise direction.
*/
static utils::Point<int> (*OCTANTS[])(const utils::Point<int>&,int,int) {
    []  (const utils::Point<int> &centre,int x,int y) -> utils::Point<int> {return {centre.x + x, centre.y - y};},      //===>>Point on Oct1
    []  (const utils::Point<int> &centre,int x,int y) -> utils::Point<int> {return {centre.x - y, centre.y + x};},      //===>>Point on Oct2
    []  (const utils::Point<int> &centre,int x,int y) -> utils::Point<int> {return {centre.x - y, centre.y - x};},      //===>>Point on Oct3
    []  (const utils::Point<int> &centre,int x,int y) -> utils::Point<int> {return {centre.x - x, centre.y - y};},      //===>>Point on Oct4
    []  (const utils::Point<int> &centre,int x,int y) -> utils::Point<int> {return {centre.x - x, centre.y + y};},      //===>>Point on Oct5
    []  (const utils::Point<int> &centre,int x,int y) -> utils::Point<int> {return {centre.x + y, centre.y - x};},      //===>>Point on Oct6
    []  (const utils::Point<int> &centre,int x,int y) -> utils::Point<int> {return {centre.x + y, centre.y + x};},      //===>>Point on Oct7
    []  (const utils::Point<int> &centre,int x,int y) -> utils::Point<int> {return {centre.x + x, centre.y + y};}       //===>>Point on Oct8
};

enum Octant : unsigned short {
    FIRST_OCTANT,
    SECOND_OCTANT,
    THIRD_OCTANT,
    FOURTH_OCTANT,
    FIFTH_OCTANT,
    SIXTH_OCTANT,
    SEVENTH_OCTANT,
    EIGHTH_OCTANT
};

void CircleFillingArtist::onMouseLeftDown(HDC hdc, int x, int y) {
    this->centre = {x,y};
}

void CircleFillingArtist::onMouseLeftUp(HDC hdc, int x, int y) {

    utils::Point<int> edge {x,y};
    int dy = std::abs(y - centre.y), dx = std::abs(x - centre.x);
    this->radius = std::sqrt(utils::distanceSquared(centre,edge));
    unsigned short oct1,oct2;
    if(dy > dx)
    {
        if(y > centre.y)
            oct1 = (x > centre.x) ? SEVENTH_OCTANT : SIXTH_OCTANT;
        else
            oct1 = (x > centre.x) ? SECOND_OCTANT : THIRD_OCTANT;
    }
    else
    {
        if(x > centre.x)
            oct1 = (y > centre.y) ? EIGHTH_OCTANT : FIRST_OCTANT;
        else
            oct1 = (y > centre.y) ? FIFTH_OCTANT : FOURTH_OCTANT;
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
    while(oct1 > 8 || oct2 > 8 || oct1 < 1 || oct2 < 1 || oct1 == oct2)
    {
        std::cout << "Please Enter two valid different octants (1-8) : ";
        std::cin >> oct1 >> oct2;
    }
    this->centre = {x,y};
    this->fillCircle(hdc,radius,OCTANTS[oct1 - 1], OCTANTS[oct2 - 1], COLOR_TEAL);
}
