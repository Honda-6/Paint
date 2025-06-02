#include "CircleFillingArtist.h"

void CircleFillingArtist::onMouseLeftDown(HDC hdc, int x, int y)
{
    this->centre = {x, y};
}

void CircleFillingArtist::onMouseLeftUp(HDC hdc, int x, int y)
{

    utils::Point<int> edge{x, y};
    int dy = std::abs(y - centre.y), dx = std::abs(x - centre.x);
    this->radius = std::sqrt(utils::distanceSquared(centre, edge));
    unsigned short oct1, oct2;
    if (dy > dx)
    {
        if (y > centre.y)
            oct1 = (x > centre.x) ? SECOND_OCTANT : THIRD_OCTANT;
        else
            oct1 = (x > centre.x) ? SEVENTH_OCTANT : SIXTH_OCTANT;
    }
    else
    {
        if (x > centre.x)
            oct1 = (y > centre.y) ? FIRST_OCTANT : EIGHTH_OCTANT;
        else
            oct1 = (y > centre.y) ? FOURTH_OCTANT : FIFTH_OCTANT;
    }
    oct2 = (oct1 + 4) % 8; // we will fill opposing octants only;
    this->fillCircle(hdc, radius, OCTANTS[oct1], OCTANTS[oct2]);
}

void CircleFillingArtist::handleConsole(HDC hdc)
{
    int x, y, r,g,b;
    unsigned short oct1, oct2;
    std::cout << "Enter the coordinates of the centre of a circle (X,Y): \n";
    std::cout << "X: ";
    std::cin >> x;
    std::cout << "Y: ";
    std::cout << "Enter the color of the circle (R G B): ";
    std::cin >> r >> g >> b;
    while(r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
    {
        std::cout << "Please Enter a valid color (0-255) : ";
        std::cin >> r >> g >> b;
    }
    this->color = RGB(r,g,b);
    std::cin >> y;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> this->radius;
    std::cout << "Enter two octants you wish to fill: ";
    std::cin >> oct1 >> oct2;
    while (oct1 > 8 || oct2 > 8 || oct1 < 1 || oct2 < 1 || oct1 == oct2)
    {
        std::cout << "Please Enter two valid different octants (1-8) : ";
        std::cin >> oct1 >> oct2;
    }
    this->centre = {x, y};
    this->fillCircle(hdc, radius, OCTANTS[oct1 - 1], OCTANTS[oct2 - 1]);
}
