#include "Sprite.h"

game::Sprite::Sprite(int pos_x, int pos_y, Texture2D texture)
    : pos_x(pos_x), pos_y(pos_y), texture(texture) {

}

game::Sprite::Sprite(int pos_x, int pos_y, const std::string& filename)
        : pos_x(pos_x), pos_y(pos_y), texture(LoadTexture(filename.c_str())) {

}

game::Sprite::Sprite(int pos_x, int pos_y, char* filename)
        : pos_x(pos_x), pos_y(pos_y), texture(LoadTexture(filename)) {

}

game::Sprite::~Sprite() {
    TraceLog(LOG_INFO, "Sprite destructor called");
    UnloadTexture(texture);
}
