#include <cstdlib>
#include <memory>

#include "raylib.h"

#include "config.h"

#include "Sprite.h"
#include "Level.h"

int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // s1 liegt auf dem Stack, C++ sichert zu, dass der Destructor des
    // von Stack-Objekten aufgerufen wird, wenn das Objekt seinen
    // Scope verlässt.
    //Sprite s1(100, 100, LoadTexture("assets/graphics/testimage.png"));

    // Das Sprite liegt auf dem Heap, der Zeiger ps2 zeigt auf das Heap
    // Objekt. Der Speicher wird nur freigegeben, wenn explizit delete
    // aufgerufen wird. Gleiches gilt für den Aufruf des Destructors.
    //Sprite* ps2 = new Sprite(10,10, LoadTexture("assets/graphics/testimage.png"));
    //Sprite* ps3 = ps2;
    //delete ps2;

    // Der Shared Pointer kapselt in diesem Falle ein Sprite Objekt auf dem Heap.
    // Ein shared_ptr zählt die Referenzen auf ihn selbst.
    // Er ruft den Destructor auf und gibt den Speicher des Objektes frei,
    // wenn der Referenzzähler auf 0 steht.
    // In diesem Fall endet der Scope von s2 am Ende des Programms. Dort wird er ungültig,
    // damit erlischt die Referenz auf den Smartpointer, bzw. dessen Referenzzöhler wird decrementiert,
    // steht damit auf 0 und es erfolgt der Destructor Call und die Speicherfreigabe.

    // Achtung: Hier teilen 3 Sprites die selbe Textur! Wenn von einem Sprites der Destructor aufgerufen wird, wird
    // UnloadTexture aufgerufen und die Textur aus dem VRAM gelöscht. Das ist gaaaanz doof!
    Texture2D texture = LoadTexture("assets/graphics/testimage.png");

    std::shared_ptr<game::Sprite> s2 = std::make_shared<game::Sprite>(100,
                                                          100,
                                                          texture);

    std::shared_ptr<game::Sprite> s3 = std::make_shared<game::Sprite>(200,
                                                                      100,
                                                                      texture);

    std::shared_ptr<game::Sprite> s4 = std::make_shared<game::Sprite>(300,
                                                                      100,
                                                                      texture);

    game::Level level1;
    level1.sprites.push_back(s2);
    level1.sprites.push_back(s3);
    level1.sprites.push_back(s4);


    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        level1.Update();

        BeginDrawing();
        ClearBackground(WHITE);
        // Draw
        level1.Draw();
        EndDrawing();
    } // Main game loop end


    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
