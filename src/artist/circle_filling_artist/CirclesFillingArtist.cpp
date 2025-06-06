#include "CirclesFillingArtist.h"

void CirclesFillingArtist::fillCircle(HDC hdc,unsigned int radius, utils::Point<int> (*firstOctant)(const utils::Point<int>&,int,int),utils::Point<int> (*secondOctant)(const utils::Point<int>&,int,int)) {
    for(int X {1}; X <= radius; ++X)
    {
        int y = 0, x = X;
        SetPixel(hdc,firstOctant(centre,x,y).x,firstOctant(centre,x,y).y,color);
        SetPixel(hdc,secondOctant(centre,x,y).x,secondOctant(centre,x,y).y,color);
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
                decisionVar += dNode;

            dOne += 2, dNode += 2;
            y++;
            SetPixel(hdc,firstOctant(centre,x,y).x,firstOctant(centre,x,y).y,color);
            SetPixel(hdc,secondOctant(centre,x,y).x,secondOctant(centre,x,y).y,color);
        }
    }
}
