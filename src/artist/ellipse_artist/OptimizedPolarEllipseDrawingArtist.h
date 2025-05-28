#include "EllipseArtist.h"

class OptimizedPolarEllipseDrawingArtist : public EllipseArtist
{
private:
    void drawEllipse(HDC hdc) override;
public:
    ~OptimizedPolarEllipseDrawingArtist() = default;
};