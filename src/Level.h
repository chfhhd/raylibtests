#pragma once

#include <vector>

#include "Sprite.h"

namespace game {
    class Level {
    public:

        virtual void Draw();

        virtual void Update();

        std::vector<std::shared_ptr<game::Sprite>> sprites;
    };
}
