#include "EllipseArtist.h"

EllipseArtist::EllipseArtist()
    : centre{0,0}, semiHorizontalLengthSquared{},semiVerticalLengthSquared{},strategy{}{}
EllipseArtist::EllipseArtist(EllipseStrat *strat)
    : centre{0,0}, semiHorizontalLengthSquared{},semiVerticalLengthSquared{},strategy{strat}{}

void EllipseArtist::setStrat(EllipseStrat *strat)
{
    this->strategy = strat;
}

void EllipseArtist::onMouseLeftDown(HDC hdc, int x, int y)
{
    utils::Point<int> vertix = {x,y};
    this->centre = vertix;
}

void EllipseArtist::onMouseLeftUp(HDC hdc, int x, int y)
{
    int dx = x - this->centre.x, dy = y - this->centre.y;
    this->semiHorizontalLengthSquared = dx * dx;
    this->semiVerticalLengthSquared = dy * dy;
    this->strategy->drawEllipse(hdc,this->centre,this->semiHorizontalLengthSquared,this->semiVerticalLengthSquared);
}

void EllipseArtist::handleConsole(HDC hdc)
{
    int x,y,a,b;
    std::cout << "Enter the centre coordinates of the ellipse: ";
    std::cin >> x >> y;
    std::cout << "Enter the semi-horizontal axis length: ";
    std::cin >> a;
    std::cout << "Enter the semi-vertical axis length: ";
    std::cin >> b;
    this->centre = {x,y}, this->semiHorizontalLengthSquared = a*a, this->semiVerticalLengthSquared = b*b;
    this->strategy->drawEllipse(hdc,this->centre,a*a,b*b);
}