#include "EllipseArtist.h"

EllipseArtist::EllipseArtist()
    : centre{-1,-1}, semiHorizontalLengthSquared{},semiVerticalLengthSquared{},strategy{}{}
EllipseArtist::EllipseArtist(EllipseStrat *strat)
    : centre{-1,-1}, semiHorizontalLengthSquared{},semiVerticalLengthSquared{},strategy{strat}{}

void EllipseArtist::setStrat(EllipseStrat *strat)
{
    this->strategy = strat;
}

void EllipseArtist::onMouseLeftDown(HDC hdc, int x, int y)
{
    utils::Point vertix = {x,y};

    if(this->centre.x < 0)
        this->centre = vertix;
    else if(this->semiHorizontalLengthSquared == 0)
        this->semiHorizontalLengthSquared = utils::squareDistance(vertix,this->centre);
    else
    {
        this->semiVerticalLengthSquared = utils::squareDistance(vertix,this->centre);
        //this->drawEllipse(hdc);
        this->strategy->drawEllipse(hdc,this->centre,this->semiHorizontalLengthSquared,this->semiVerticalLengthSquared);
        this->centre = {-1,-1};
        this->semiVerticalLengthSquared = this->semiHorizontalLengthSquared = 0;
    }

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