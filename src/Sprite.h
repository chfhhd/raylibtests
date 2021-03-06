#pragma once

#include <string>

#include "raylib.h"

namespace game {
    class Sprite {
    public:
        int pos_x;
        int pos_y;
        Texture2D texture;

        Sprite() = delete;

        Sprite(int pos_x, int pos_y, Texture2D texture);

        Sprite(int pos_x, int pos_y, const std::string& filename);

        Sprite(int pos_x, int pos_y, char *filename);

        ~Sprite();
    };
}