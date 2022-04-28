#include "Level_Menu.h"


extern std::vector<std::shared_ptr<game::Level>> levels;
extern std::shared_ptr<game::Level> active_level;

void game::Level_Menu::Update() {
    if(IsKeyPressed(KEY_ENTER))
        active_level = levels[1];

    // Achtung: Einziger Haken hier ist, wir durchlaufen den Vector 2x
    // einmal beim Update(), einmal beim Draw()
    // Kann man optimieren. Aber Vektoren zu durchlaufen ist etwas, das man
    // dauernd macht und nie ganz optimieren kann, zumindest nicht, ohne
    // das die Lesbarkeit des Codes deutlich leidet...
    for (const auto &sprite: sprites) {
        sprite->pos_x += 5;
    }

    Level::Update();
}

void game::Level_Menu::Draw() {
    Level::Draw();
    DrawText("Das ist das Menu Level", 50, 50, 50, BLACK);;
}
