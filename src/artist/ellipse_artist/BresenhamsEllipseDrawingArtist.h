#include "EllipseArtist.h"

class BresenhamsEllipseDrawingArtist : public EllipseArtist
{
private:
    void drawEllipse(HDC hdc) override;
public:
    ~BresenhamsEllipseDrawingArtist() = default;
};