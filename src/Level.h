#pragma once

#include <vector>

#include "Sprite.h"

namespace game {
    class Level {
    public:
        std::vector<std::shared_ptr<game::Sprite>> sprites;
    };
}
