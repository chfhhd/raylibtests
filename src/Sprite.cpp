#include "Sprite.h"

void Sprite::Draw() {
    DrawTexture(texture, pos_x, pos_y, WHITE);
}

Sprite::Sprite(int pos_x, int pos_y, Texture2D texture)
        : pos_x(pos_x), pos_y(pos_y), texture(texture) {
    // belieber weiterer Code hier...
    // was auch immer notwendig erscheint.
}

Sprite::~Sprite() {
    UnloadTexture(texture);
}
