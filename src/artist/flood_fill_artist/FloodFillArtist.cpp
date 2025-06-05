#include "FloodFillArtist.h"
#include "Palette.h"
#include <iostream>

FloodFillArtist::FloodFillArtist(FloodFillStrategy* strat) : strategy(strat) {}

void FloodFillArtist::setStrategy(FloodFillStrategy *strat) {
    strategy= strat;
}

void FloodFillArtist::onMouseLeftUp(HDC hdc, int x, int y) {
    initialColor = GetPixel(hdc, x, y);
    strategy->floodFill(hdc, x, y, color, initialColor);
}

void FloodFillArtist::handleConsole(HDC hdc) {
    int x, y;
    std::cout << "Enter a point (x, y) inside a drawn shape: ";
    std::cin >> x >> y;
    initialColor = GetPixel(hdc, x, y);
    strategy->floodFill(hdc, x, y, color, initialColor);
}

FloodFillArtist::~FloodFillArtist() {
    delete strategy;
}
