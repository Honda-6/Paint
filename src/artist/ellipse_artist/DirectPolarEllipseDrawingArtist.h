#include "EllipseArtist.h"

class DirectPolarEllipseDrawingArtist: public EllipseArtist
{
private:
    void drawEllipse(HDC hdc) override;
public:
    ~DirectPolarEllipseDrawingArtist() = default;
};