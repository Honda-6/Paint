//
// Created by hp on 6/3/2025.
//

#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <vector>

void FileManager::load(HDC hdc, std::string inFile, const unsigned &screenWidth, const unsigned &screenHeight)
{
    /* std::ifstream file(inFile, std::ios::binary);
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
    file.close(); */
    std::vector<BYTE> pixelData{};
    std::ifstream file("data.bin", std::ios::binary);
    if(!file.is_open()) {
        std::cout << "Error: file could not be opened\n";
        return;
    }
    pixelData.resize(screenWidth * screenHeight * 4);
    file.read(reinterpret_cast<char *>(pixelData.data()), pixelData.size());
    file.close();
    for (int y = 0; y < screenHeight; ++y)
    {
        for (int x = 0; x < screenWidth; ++x)
        {
            int index = (y * screenWidth + x) * 4;

            BYTE b = pixelData[index + 0];
            BYTE g = pixelData[index + 1];
            BYTE r = pixelData[index + 2];

            SetPixel(hdc, x, y, RGB(r, g, b));
        }
    }
}

void FileManager::save(HDC hdc, std::string outFile, const unsigned &screenWidth, const unsigned &screenHeight)
{
    /* std::ofstream file;
    file.open(outFile, std::ios::binary);
    if(!file.is_open()) {
        std::cout << "Error: file could not be opened\n";
        return;
    } */
    /* std::vector<unsigned char> pixels(screenHeight * screenWidth * 3);
    int i = 0;
    for (int y = 0; y < screenHeight; ++y) {
        for (int x = 0; x < screenWidth; ++x) {
            COLORREF c = GetPixel(hdc, x, y);
            pixels[i++] = GetRValue(c);
            pixels[i++] = GetGValue(c);
            pixels[i++] = GetBValue(c);
        }
    }
    file.write((char*)pixels.data(), pixels.size());
    file.close(); */
    HDC hMemoryDC = CreateCompatibleDC(hdc);

    
    HBITMAP hBitmap = CreateCompatibleBitmap(hdc, screenWidth, screenHeight);

    
    HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemoryDC, hBitmap);

    
    BitBlt(hMemoryDC, 0, 0, screenWidth, screenHeight, hdc, 0, 0, SRCCOPY);

    
    BITMAPINFOHEADER bi = {0};
    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = screenWidth;
    bi.biHeight = -screenHeight;
    bi.biPlanes = 1;
    bi.biBitCount = 32; 
    bi.biCompression = BI_RGB;

    std::vector<BYTE> pixels(screenWidth * screenHeight * 4);
    
    GetDIBits(hMemoryDC, hBitmap, 0, screenHeight, pixels.data(), (BITMAPINFO *)&bi, DIB_RGB_COLORS);

    std::ofstream file;
    file.open(outFile, std::ios::binary);
    if(!file.is_open()) {
        std::cerr << "Error: file could not be opened\n";
        return;
    }
    file.write(reinterpret_cast<char *>(pixels.data()), pixels.size());
    file.close();

    
    SelectObject(hMemoryDC, hOldBitmap);
    DeleteObject(hBitmap);
    DeleteDC(hMemoryDC);
}
