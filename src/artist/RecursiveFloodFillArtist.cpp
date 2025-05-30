//
// Created by hp on 5/30/2025.
//

#include "RecursiveFloodFillArtist.h"
#include "Palette.h"
#include <iostream>

void RecursiveFloodFillArtist::floodFill(HDC hdc, int x, int y, COLORREF fill_color) {
    COLORREF curr = GetPixel(hdc, x, y);
    // stop if the color of current pixel is different from the initial pixel
    if(curr != initialColor)
        return;
    SetPixel(hdc, x, y, fill_color);
    floodFill(hdc, x + 1, y, fill_color);
    floodFill(hdc, x - 1, y, fill_color);
    floodFill(hdc, x, y + 1, fill_color);
    floodFill(hdc, x, y - 1, fill_color);
}

void RecursiveFloodFillArtist::onMouseLeftUp(HDC hdc, int x, int y) {
    initialColor = GetPixel(hdc, x, y);
    floodFill(hdc, x, y, COLOR_CRIMSON_RED);
}

void RecursiveFloodFillArtist::handleConsole(HDC hdc) {
    int x, y;
    int r, g, b;
    std::cout << "Enter a point (x, y) inside a drawn shape: ";
    std::cin >> x >> y;
    std::cout << "Enter the filling color:\n";
    std::cout << "red intensity -> ";
    std::cin >> r;
    std::cout << "green intensity -> ";
    std::cin >> g;
    std::cout << "blue intensity -> ";
    std::cin >> b;
    fill_color = RGB(r,g,b);
    initialColor = GetPixel(hdc, x, y);
    floodFill(hdc, x, y, COLOR_CRIMSON_RED);
}
