#include "Artist.h"
#include "Utils.h"
#include <vector>

class CardinalSplineArtist : public Artist {
private:
    std::vector<utils::Point<int>> control_points;
    int c = 1;

    void drawCardinalSpline(HDC hdc, std::vector<utils::Point<int>> pts, double c ,COLORREF color);

public:
    void onMouseLeftUp(HDC hdc, int x, int y) override;
    void onMouseRightDown(HDC hdc, int x, int y) override;
    void handleConsole(HDC hdc) override;
};
