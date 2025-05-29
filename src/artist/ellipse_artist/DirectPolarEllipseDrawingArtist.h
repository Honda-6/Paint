#include "EllipseArtist.h"

class DirectPolarEllipseDrawingArtist: public EllipseArtist
{
private:
    void drawEllipse(HDC hdc,COLORREF color = RGB(0,0,0)) override;
public:
    ~DirectPolarEllipseDrawingArtist() = default;
};