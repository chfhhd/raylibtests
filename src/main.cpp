#include <cstdlib>

#include "raylib.h"

#include "config.h"
#include "Sprite.h"

int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here
    // ...
    // ...

    Sprite s1(100, 100, LoadTexture("assets/graphics/testimage.png"));

    //Sprite* ps2 = new Sprite(10,10, LoadTexture("assets/graphics/testimage.png"));
    //delete ps2;


    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Updates that are made by frame are coded here
        // ...
        // ...

        BeginDrawing();
        // You can draw on the screen between BeginDrawing() and EndDrawing()
        // ...
        // ...
        ClearBackground(WHITE);
        s1.Draw();
        s1.pos_x += 5;

        EndDrawing();
    } // Main game loop end

    // De-initialization here
    // ...
    // ...


    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
