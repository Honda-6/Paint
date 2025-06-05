#pragma once

#include "Core.h"
#include "Artist.h"
#include "Palette.h"
#include "Utils.h"
#include "ModifiedMidointCircleStrategy.h"
#include <iostream>
/*
    An array of pointer to function returning a point on an octant,
    they are ordered according to the octants i.e each index corresponds to the octant number in the Clockwise direction according to the coordinate system of the window.
*/
static utils::Point<int>(*OCTANTS[])(const utils::Point<int>&,int,int){
    []  (const utils::Point<int> &centre,int x,int y) -> utils::Point<int>{return {centre.x + x, centre.y + y};},      //===>>Point on Oct1
    []  (const utils::Point<int> &centre,int x,int y) -> utils::Point<int>{return {centre.x + y, centre.y + x};},      //===>>Point on Oct2
    []  (const utils::Point<int> &centre,int x,int y) -> utils::Point<int>{return {centre.x - y, centre.y + x};},      //===>>Point on Oct3
    []  (const utils::Point<int> &centre,int x,int y) -> utils::Point<int>{return {centre.x - x, centre.y + y};},      //===>>Point on Oct4
    []  (const utils::Point<int> &centre,int x,int y) -> utils::Point<int>{return {centre.x - x, centre.y - y};},      //===>>Point on Oct5
    []  (const utils::Point<int> &centre,int x,int y) -> utils::Point<int>{return {centre.x - y, centre.y - x};},      //===>>Point on Oct6
    []  (const utils::Point<int> &centre,int x,int y) -> utils::Point<int>{return {centre.x + y, centre.y - x};},      //===>>Point on Oct7
    []  (const utils::Point<int> &centre,int x,int y) -> utils::Point<int>{return {centre.x + x, centre.y - y};}       //===>>Point on Oct8
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

class CircleFillingArtist: public Artist {
protected:
    utils::Point<int> centre;
    unsigned int radius;
    virtual void fillCircle(HDC hdc, unsigned int radius, utils::Point<int> (*firstOctant)(const utils::Point<int>&,int,int),utils::Point<int> (*secondOctant)(const utils::Point<int>&,int,int)) = 0;
public:
    void onMouseLeftDown(HDC hdc, int x, int y) override;
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
    ~CircleFillingArtist() = default;
};
