#include "Level.h"

void game::Level::Draw() {
    for (const auto &sprite: sprites) {
        DrawTexture(sprite->texture,
                    sprite->pos_x, sprite->pos_y,
                    WHITE);
    }
}

void game::Level::Update() {
    // Achtung: Einziger Haken hier ist, wir durchlaufen den Vector 2x
    // einmal beim Update(), einmal beim Draw()
    // Kann man optimieren. Aber Vektoren zu durchlaufen ist etwas, das man
    // dauernd macht und nie ganz optimieren kann, zumindest nicht, ohne
    // das die Lesbarkeit des Codes deutlich leidet...
    for (const auto &sprite: sprites) {
        sprite->pos_x += 5;
    }
}