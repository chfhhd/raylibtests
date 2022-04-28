#include "Sprite.h"

void game::Sprite::Draw() const {
    DrawTexture(texture, pos_x, pos_y, WHITE);
}

game::Sprite::Sprite(int pos_x, int pos_y, Texture2D texture)
    : pos_x(pos_x), pos_y(pos_y), texture(texture) {
    Draw();
}

game::Sprite::Sprite(int pos_x, int pos_y, std::string filename)
        : pos_x(pos_x), pos_y(pos_y), texture(LoadTexture(filename.c_str())) {
    Draw();
}

game::Sprite::Sprite(int pos_x, int pos_y, char* filename)
        : pos_x(pos_x), pos_y(pos_y), texture(LoadTexture(filename)) {
    Draw();
}

game::Sprite::~Sprite() {
    TraceLog(LOG_INFO, "Sprite destructor called");
    UnloadTexture(texture);
}
