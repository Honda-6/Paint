#pragma once

#include "Artist.h"

/// @brief An `Artist` that does absolutely nothing.
class NullArtist: public Artist {
public:
    void handleConsole() override;
};
