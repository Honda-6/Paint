#include "Menu.h"
#include "BezierRectangleFillArtist.h"
#include "HermiteSquareFillArtist.h"
#include "ConvexFillArtist.h"
#include "CardinalSplineArtist.h"
#include "LineArtist.h"
#include "LineDDAStrategy.h"
#include "LineMidpointStrategy.h"
#include "LineParametricStrategy.h"
#include "GeneralPolygonFillArtist.h"
#include "circle_filling_artist/CirclesFillingArtist.h"
#include "circle_filling_artist/CircleLineFillingArtist.h"
#include "LineCircleWindowClippingArtist.h"
#include "PointCircleWindowClippingArtist.h"
#include "FloodFillArtist.h"
#include "FloodFillStrategy.h"
#include "RecursiveFloodFill.h"
#include "IterativeFloodFill.h"

using namespace std;

ShapesMenu::ShapesMenu(Artist **artist, COLORREF *color) : artist(artist), color(color) { }

HMENU ShapesMenu::createMenu()
{
    HMENU shapesMenu = CreateMenu();

    AppendMenu(shapesMenu, MF_STRING, SHAPES_CARDINAL_SPLINES, LPCSTR("Cardinal Splines"));
    AppendMenu(shapesMenu, MF_POPUP, (UINT_PTR)createLineMenu(), LPCSTR("Line"));
    AppendMenu(shapesMenu, MF_POPUP, (UINT_PTR)createCircleMenu(), LPCSTR("Circle"));
    AppendMenu(shapesMenu, MF_POPUP, (UINT_PTR)createFillingCircleMenu(), LPCSTR("Filling Circle"));
    AppendMenu(shapesMenu, MF_POPUP, (UINT_PTR)createFillingMenu(), LPCSTR("Filling"));
    AppendMenu(shapesMenu, MF_POPUP, (UINT_PTR)createFloodFillMenu(), LPCSTR("Flood Fill"));
    AppendMenu(shapesMenu, MF_POPUP, (UINT_PTR)createEllipseMenu(), LPCSTR("Ellipse"));
    AppendMenu(shapesMenu, MF_POPUP, (UINT_PTR)createClippingSquareMenu(), LPCSTR("Clipping Square"));
    AppendMenu(shapesMenu, MF_POPUP, (UINT_PTR)createClippingRectMenu(), LPCSTR("Clipping Rectange"));
    AppendMenu(shapesMenu, MF_POPUP, (UINT_PTR)createClippingCircleMenu(), LPCSTR("Clipping Circle"));

    return shapesMenu;
}

bool ShapesMenu::handleEvent(HWND hwnd, WPARAM wp)
{
    FloodFillStrategy* floodFillStrat;

    bool matches = true;
    switch (wp)
    {
    case SHAPES_LINE_DDA:
        // Handle LineDDAStrategy line drawing
        {
            LineStrategy *line = new LineDDAStrategy();
            *artist = new LineArtist(line);
        }
        break;
    case SHAPES_LINE_MIDPOINT:
        // Handle LineMidpointStrategy line drawing
        {
            LineStrategy *line = new LineMidpointStrategy();
            *artist = new LineArtist(line);
        }
        break;
    case SHAPES_LINE_PARAMETRIC:
        // Handle LineParametricStrategy line drawing
        {
            LineStrategy *line = new LineMidpointStrategy();
            *artist = new LineArtist(line);
        }
        break;
    case SHAPES_CIRCLE_DIRECT:
        // Handle Direct circle drawing
        break;
    case SHAPES_CIRCLE_POLAR:
        // Handle Polar circle drawing
        break;
    case SHAPES_CIRCLE_ITERATIVE_POLAR:
        // Handle Iterative Polar circle drawing
        break;
    case SHAPES_CIRCLE_MIDPOINT:
        // Handle Midpoint circle drawing
        break;
    case SHAPES_CIRCLE_MODIFIED_MIDPOINT:
        // Handle Modified Midpoint circle drawing
        break;
    case SHAPES_FILLING_CIRCLE_LINES:
        *artist = new CircleLineFillingArtist();
        // Handle Circle Filling with Lines
        break;
    case SHAPES_FILLING_CIRCLE_CIRCLE:
        *artist = new CirclesFillingArtist();
        // Handle Circle Filling with Circle
        break;
    case SHAPES_FILLING_CONVEX:
        *artist = new ConvexFillArtist();
        break;
    case SHAPES_FILLING_NON_CONVEX:
        // Handle Non-Convex filling
        *artist  = new GeneralPolygonFillArtist();
        break;
    case SHAPES_FILLING_BEZIER_RECTANGLE:
        // Handle Bezier Rectangle filling
        *artist = new BezierRectangleFillArtist();
        break;
    case SHAPES_FILLING_HERMITE_SQUARE:
        // Handle Hermit Square filling
        *artist = new HermiteSquareFillArtist();
        break;
    case SHAPES_FLOOD_FILL_RECURSIVE:
        floodFillStrat = new RecursiveFloodFill();
        *artist = new FloodFillArtist(floodFillStrat);
        break;
    case SHAPES_FLOOD_FILL_ITERATIVE:
        floodFillStrat = new IterativeFloodFill();
        *artist = new FloodFillArtist(floodFillStrat);
        break;
    case SHAPES_CARDINAL_SPLINES:
        *artist = new CardinalSplineArtist();
        break;
    case SHAPES_ELLIPSE_DIRECT:
        // Handle Direct Ellipse drawing
        break;
    case SHAPES_ELLIPSE_POLAR:
        // Handle Polar Ellipse drawing
        break;
    case SHAPES_ELLIPSE_MIDPOINT:
        // Handle LineMidpointStrategy Ellipse drawing
        break;
    case SHAPES_CLIPPING_RECTANGLE_POINT:
        // Handle Point Clipping in Rectangle
        break;
    case SHAPES_CLIPPING_RECTANGLE_LINE:
        // Handle LineStrategy Clipping in Rectangle
        break;
    case SHAPES_CLIPPING_RECTANGLE_POLYGON:
        // Handle Polygon Clipping in Rectangle
        break;
    case SHAPES_CLIPPING_SQUARE_POINT:
        // Handle Point Clipping in Square
        break;
    case SHAPES_CLIPPING_SQUARE_LINE:
        // Handle LineStrategy Clipping in Square
        break;
    case SHAPES_CLIPPING_CIRCLE_POINT:
        *artist = new PointCircleWindowClippingArtist();
        break;
    case SHAPES_CLIPPING_CIRCLE_LINE:
        *artist = new LineCircleWindowClippingArtist();
        break;
    default:
        matches = false;
        break;
    }

    (*artist)->setColor(*color);

    return matches;
}

HMENU ShapesMenu::createLineMenu()
{
    HMENU lineMenu = CreateMenu();

    AppendMenu(lineMenu, MF_STRING, SHAPES_LINE_DDA, LPCSTR("DDA"));
    AppendMenu(lineMenu, MF_STRING, SHAPES_LINE_MIDPOINT, LPCSTR("Midpoint"));
    AppendMenu(lineMenu, MF_STRING, SHAPES_LINE_PARAMETRIC, LPCSTR("Parametric"));

    return lineMenu;
}

HMENU ShapesMenu::createCircleMenu()
{
    HMENU circleMenu = CreateMenu();
    AppendMenu(circleMenu, MF_STRING, SHAPES_CIRCLE_DIRECT, LPCSTR("Direct"));
    AppendMenu(circleMenu, MF_STRING, SHAPES_CIRCLE_POLAR, LPCSTR("Polar"));
    AppendMenu(circleMenu, MF_STRING, SHAPES_CIRCLE_ITERATIVE_POLAR, LPCSTR("Iterative Polar"));
    AppendMenu(circleMenu, MF_STRING, SHAPES_CIRCLE_MIDPOINT, LPCSTR("Midpoint"));
    AppendMenu(circleMenu, MF_STRING, SHAPES_CIRCLE_MODIFIED_MIDPOINT, LPCSTR("Modified Midpoint"));
    return circleMenu;
}

HMENU ShapesMenu::createFillingCircleMenu()
{
    HMENU fillCircleMenu = CreateMenu();
    AppendMenu(fillCircleMenu, MF_STRING, SHAPES_FILLING_CIRCLE_LINES, LPCSTR("Lines"));
    AppendMenu(fillCircleMenu, MF_STRING, SHAPES_FILLING_CIRCLE_CIRCLE, LPCSTR("Circle"));
    return fillCircleMenu;
}

HMENU ShapesMenu::createFillingMenu()
{
    HMENU fillingMenu = CreateMenu();
    AppendMenu(fillingMenu, MF_STRING, SHAPES_FILLING_CONVEX, LPCSTR("Convex"));
    AppendMenu(fillingMenu, MF_STRING, SHAPES_FILLING_NON_CONVEX, LPCSTR("Non-Convex"));
    AppendMenu(fillingMenu, MF_STRING, SHAPES_FILLING_BEZIER_RECTANGLE, LPCSTR("Bezier Rectangle"));
    AppendMenu(fillingMenu, MF_STRING, SHAPES_FILLING_HERMITE_SQUARE, LPCSTR("Hermite Square"));
    return fillingMenu;
}

HMENU ShapesMenu::createFloodFillMenu()
{
    HMENU floodFillMenu = CreateMenu();
    AppendMenu(floodFillMenu, MF_STRING, SHAPES_FLOOD_FILL_RECURSIVE, LPCSTR("Recursive"));
    AppendMenu(floodFillMenu, MF_STRING, SHAPES_FLOOD_FILL_ITERATIVE, LPCSTR("Iterative"));
    return floodFillMenu;
}

HMENU ShapesMenu::createEllipseMenu()
{
    HMENU ellipseMenu = CreateMenu();
    AppendMenu(ellipseMenu, MF_STRING, SHAPES_ELLIPSE_DIRECT, LPCSTR("Direct"));
    AppendMenu(ellipseMenu, MF_STRING, SHAPES_ELLIPSE_POLAR, LPCSTR("Polar"));
    AppendMenu(ellipseMenu, MF_STRING, SHAPES_ELLIPSE_MIDPOINT, LPCSTR("Midpoint"));
    return ellipseMenu;
}

HMENU ShapesMenu::createClippingRectMenu()
{
    HMENU clipRectMenu = CreateMenu();
    AppendMenu(clipRectMenu, MF_STRING, SHAPES_CLIPPING_RECTANGLE_POINT, LPCSTR("Point"));
    AppendMenu(clipRectMenu, MF_STRING, SHAPES_CLIPPING_RECTANGLE_LINE, LPCSTR("Line"));
    AppendMenu(clipRectMenu, MF_STRING, SHAPES_CLIPPING_RECTANGLE_POLYGON, LPCSTR("Polygon"));
    return clipRectMenu;
}

HMENU ShapesMenu::createClippingSquareMenu()
{
    HMENU clipSquareMenu = CreateMenu();
    AppendMenu(clipSquareMenu, MF_STRING, SHAPES_CLIPPING_SQUARE_POINT, LPCSTR("Point"));
    AppendMenu(clipSquareMenu, MF_STRING, SHAPES_CLIPPING_SQUARE_LINE, LPCSTR("Line"));
    return clipSquareMenu;
}

HMENU ShapesMenu::createClippingCircleMenu()
{
    HMENU clipCircleMenu = CreateMenu();
    AppendMenu(clipCircleMenu, MF_STRING, SHAPES_CLIPPING_CIRCLE_POINT, LPCSTR("Point"));
    AppendMenu(clipCircleMenu, MF_STRING, SHAPES_CLIPPING_CIRCLE_LINE, LPCSTR("Line"));
    return clipCircleMenu;
}
