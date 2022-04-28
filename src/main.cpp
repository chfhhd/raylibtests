#include <cstdlib>
#include <memory>

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
    std::shared_ptr<Sprite> s2 = std::make_shared<Sprite>(100,
                                                          100,
                                                          LoadTexture("assets/graphics/testimage.png"));


    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        BeginDrawing();
        ClearBackground(WHITE);
        s2->Draw();
        s2->pos_x += 5;
        EndDrawing();
    } // Main game loop end


    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
