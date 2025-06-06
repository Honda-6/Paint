#include "CircleLineFillingArtist.h"


void CircleLineFillingArtist::fillCircle(HDC hdc,unsigned int radius, utils::Point<int> (*firstOctant)(const utils::Point<int>&,int,int),utils::Point<int> (*secondOctant)(const utils::Point<int>&,int,int)) {
    LineStrategy* line = new LineMidpointStrategy();
    int x = radius, y = 0;
    line->draw(hdc,centre.x,centre.y,firstOctant(centre,x,y).x,firstOctant(centre,x,y).y,color);
    line->draw(hdc,centre.x,centre.y,secondOctant(centre,x,y).x,secondOctant(centre,x,y).y,color);
    int decisionVar = 1 - x, dNode = 3, dOne = 5 - 2 * x;
    while(y < x)
    {
        if(decisionVar >= 0)
        {
            decisionVar += dOne;
            dOne += 2;
            x--;
        }
        else
        {
            decisionVar += dNode;
        }
        dOne += 2, dNode += 2;
        y++;
        line->draw(hdc,centre.x,centre.y,firstOctant(centre,x,y).x,firstOctant(centre,x,y).y,color);
        line->draw(hdc,centre.x,centre.y,secondOctant(centre,x,y).x,secondOctant(centre,x,y).y,color);
    }
    delete line;
}
