//
// Created by hp on 6/3/2025.
//

#include "FileManager.h"
#include <fstream>
#include <iostream>

void FileManager::load(HDC hdc, std::string inFile, const unsigned &screenWidth, const unsigned &screenHeight) {
    std::ifstream file(inFile, std::ios::binary);
    if(!file.is_open()) {
        std::cout << "Error: file could not be opened\n";
        return;
    }
    for (int y = 0; y < screenHeight; ++y) {
        for (int x = 0; x < screenWidth; ++x) {
            unsigned char r, g, b;
            file.read((char*)&r, sizeof(unsigned char));
            file.read((char*)&g, sizeof(unsigned char));
            file.read((char*)&b, sizeof(unsigned char));
            SetPixel(hdc, x, y, RGB(r, g, b));
        }
    }
    file.close();
}

void FileManager::save(HDC hdc, std::string outFile, const unsigned &screenWidth, const unsigned &screenHeight) {
    std::ofstream file;
    file.open(outFile, std::ios::binary);
    if(!file.is_open()) {
        std::cout << "Error: file could not be opened\n";
        return;

    }
    for (int y = 0; y < screenHeight; ++y) {
        for (int x = 0; x < screenWidth; ++x) {
            COLORREF c = GetPixel(hdc, x, y);
            unsigned char r = GetRValue(c);
            unsigned char g = GetGValue(c);
            unsigned char b = GetBValue(c);
            file.write((char*)&r, sizeof(unsigned char));
            file.write((char*)&g, sizeof(unsigned char));
            file.write((char*)&b, sizeof(unsigned char));
        }
    }
    file.close();
}
