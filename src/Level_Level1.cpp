#include "Level_Level1.h"


extern std::vector<std::shared_ptr<game::Level>> levels;
extern std::shared_ptr<game::Level> active_level;

void game::Level_Level1::Update() {
    Level::Update();
    // @todo - why the f... is this not working...
    if(IsKeyPressed(KEY_ENTER))
        active_level = levels[0];
}

void game::Level_Level1::Draw() {
    Level::Draw();
    DrawText("Das ist das Game Level", 50, 50, 50, BLACK);
}
