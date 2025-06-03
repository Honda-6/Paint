#include "IterativeFloodFill.h"
#include "Utils.h"
#include <queue>

void IterativeFloodFill::floodFill(HDC hdc, int x, int y, COLORREF fillColor, COLORREF initialColor) {
    std::queue<utils::Point<int>> fill_points;
    fill_points.push(utils::Point(x, y));

    while(!fill_points.empty()) {
        utils::Point curr = fill_points.front();
        fill_points.pop();
        COLORREF px = GetPixel(hdc, curr.x, curr.y);
        // stop if the color of current pixel is different from the initial pixel
        if(px != initialColor)
            continue;
        SetPixel(hdc, curr.x, curr.y, fillColor);
        fill_points.push(utils::Point(curr.x + 1, curr.y));
        fill_points.push(utils::Point(curr.x - 1, curr.y));
        fill_points.push(utils::Point(curr.x, curr.y + 1));
        fill_points.push(utils::Point(curr.x, curr.y - 1));
    }
}
