#include "Sprite.h"

void Sprite::Draw() const {
    DrawTexture(texture, pos_x, pos_y, WHITE);
}

Sprite::Sprite(int pos_x, int pos_y, Texture2D texture)
    : pos_x(pos_x), pos_y(pos_y), texture(texture) {
    Draw();
}

Sprite::~Sprite() {
    TraceLog(LOG_INFO, "Sprite destructor called");
    UnloadTexture(texture);
}
