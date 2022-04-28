#include "Level.h"

extern std::vector<std::shared_ptr<game::Level>> levels;
extern std::shared_ptr<game::Level> active_level;

void game::Level::Draw() {
    for (const auto &sprite: sprites) {
        DrawTexture(sprite->texture,
                    sprite->pos_x, sprite->pos_y,
                    WHITE);
    }
}

void game::Level::Update() {

}