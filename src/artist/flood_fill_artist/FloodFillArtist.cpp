#include "FloodFillArtist.h"
#include "Palette.h"
#include <iostream>

FloodFillArtist::FloodFillArtist(FloodFillStrategy* strat) : strategy(strat) {}

void FloodFillArtist::setStrategy(FloodFillStrategy *strat) {
    strategy= strat;
}

void FloodFillArtist::onMouseLeftUp(HDC hdc, int x, int y) {
    initialColor = GetPixel(hdc, x, y);
    strategy->floodFill(hdc, x, y, COLOR_CRIMSON_RED, initialColor);
}

void FloodFillArtist::handleConsole(HDC hdc) {
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
    strategy->floodFill(hdc, x, y, COLOR_CRIMSON_RED, initialColor);
}
