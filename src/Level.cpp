#include "Level.h"

void game::Level::Draw() {
    for (const auto &sprite: sprites) {
        DrawTexture(sprite->texture,
                    sprite->pos_x, sprite->pos_y,
                    WHITE);
    }
}

void game::Level::Update() {

}