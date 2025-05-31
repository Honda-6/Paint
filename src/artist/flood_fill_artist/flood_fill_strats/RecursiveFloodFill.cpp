#include "RecursiveFloodFill.h"

void RecursiveFloodFill::floodFill(HDC hdc, int x, int y, COLORREF fillColor, COLORREF initialColor) {
    COLORREF curr = GetPixel(hdc, x, y);
    // stop if the color of current pixel is different from the initial pixel
    if(curr != initialColor)
        return;
    SetPixel(hdc, x, y, fillColor);
    floodFill(hdc, x + 1, y, fillColor, initialColor);
    floodFill(hdc, x - 1, y, fillColor, initialColor);
    floodFill(hdc, x, y + 1, fillColor, initialColor);
    floodFill(hdc, x, y - 1, fillColor, initialColor);
}
