#ifndef MENU_H
#define MENU_H

#include "Core.h"
#include "ColorPicker.h"
#include "Artist.h"
#include "FileManager.h"

using namespace std;

enum MenuType
{
    FILE_MENU_EXPORT = 1,
    FILE_MENU_IMPORT,

    COLOR_MENU_BACKGROUND,
    COLOR_MENU_SHAPE,

    CURSOR_MENU_ARROW,
    CURSOR_MENU_CROSS,
    CURSOR_MENU_WAIT,
    CURSOR_MENU_HAND,

    CLEAR_SCREEN,

    CONSOLE_INPUT,

    // Line algorithms
    SHAPES_LINE_DDA,
    SHAPES_LINE_MIDPOINT,
    SHAPES_LINE_PARAMETRIC,

    // Circle algorithms
    SHAPES_CIRCLE_DIRECT,
    SHAPES_CIRCLE_POLAR,
    SHAPES_CIRCLE_ITERATIVE_POLAR,
    SHAPES_CIRCLE_MIDPOINT,
    SHAPES_CIRCLE_MODIFIED_MIDPOINT,

    // Filling Circle algorithms
    SHAPES_FILLING_CIRCLE_LINES,
    SHAPES_FILLING_CIRCLE_CIRCLE,

    // Filling algorithms
    SHAPES_FILLING_CONVEX,
    SHAPES_FILLING_NON_CONVEX,
    SHAPES_FILLING_BEZIER_RECTANGLE,
    SHAPES_FILLING_HERMITE_SQUARE,

    // Flood Fill algorithms
    SHAPES_FLOOD_FILL_RECURSIVE,
    SHAPES_FLOOD_FILL_ITERATIVE,

    // Cardinal Splines (no algorithms specified)
    SHAPES_CARDINAL_SPLINES,

    // Ellipse algorithms
    SHAPES_ELLIPSE_DIRECT,
    SHAPES_ELLIPSE_POLAR,
    SHAPES_ELLIPSE_MIDPOINT,

    // Clipping Rectangle algorithms
    SHAPES_CLIPPING_RECTANGLE_POINT,
    SHAPES_CLIPPING_RECTANGLE_LINE,
    SHAPES_CLIPPING_RECTANGLE_POLYGON,

    // Clipping Square algorithms
    SHAPES_CLIPPING_SQUARE_POINT,
    SHAPES_CLIPPING_SQUARE_LINE,

    // Clipping Circle algorithms
    SHAPES_CLIPPING_CIRCLE_POINT,
    SHAPES_CLIPPING_CIRCLE_LINE,
};

class Menu
{
public:
    virtual bool handleEvent(HWND hwnd, WPARAM wp) = 0;
    virtual HMENU createMenu() = 0;
};

class FileMenu : public Menu
{
private:
    FileManager *fileManager;

public:
    FileMenu(FileManager *fileManager) : fileManager(fileManager) {}
    bool handleEvent(HWND hwnd, WPARAM wp) override;
    HMENU createMenu() override;
};

class ShapesMenu : public Menu
{
public:
    ShapesMenu(Artist **artist, COLORREF *color);
    bool handleEvent(HWND hwnd, WPARAM wp) override;
    HMENU createMenu() override;

private:
    COLORREF *color;
    Artist **artist;

    HMENU createLineMenu();
    HMENU createCircleMenu();
    HMENU createFillingCircleMenu();
    HMENU createFillingMenu();
    HMENU createFloodFillMenu();
    HMENU createEllipseMenu();
    HMENU createClippingRectMenu();
    HMENU createClippingSquareMenu();
    HMENU createClippingCircleMenu();
};

class CursorMenu : public Menu
{
public:
    bool handleEvent(HWND hwnd, WPARAM wp) override;
    HMENU createMenu() override;

private:
    void changeCursor(HWND hwnd, LPCTSTR oldCursor);
};

class ColorMenu : public Menu
{
public:
    ColorMenu(Artist **artist, COLORREF *color);
    bool handleEvent(HWND hwnd, WPARAM wp) override;
    HMENU createMenu() override;

private:
    COLORREF *color;
    Artist **artist;
    ColorPicker colorPicker;

    void changeBackgroundColor(HWND hwnd, COLORREF color);
};

#endif
