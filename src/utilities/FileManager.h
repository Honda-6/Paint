//
// Created by hp on 6/3/2025.
//

#ifndef PAINT_FILEMANAGER_H
#define PAINT_FILEMANAGER_H

#include "Core.h"
#include <string>

class FileManager {
public:
    void load(HDC hdc, std::string inFile, const unsigned &screenWidth=600,const unsigned &screenHeight=400);

    void save(HDC hdc, std::string outFile, const unsigned &screenWidth=600,const unsigned &screenHeight=400);
};


#endif //PAINT_FILEMANAGER_H
