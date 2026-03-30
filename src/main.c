#include "../lib/raylib/src/raylib.h"


int main(void) {
    InitWindow(800, 600, "Urbex Prototype");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 2.0f, 5.0f };
    camera.target = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(120);

    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_FIRST_PERSON);

        BeginDrawing();
        ClearBackground(DARKGRAY);

        BeginMode3D(camera);
        DrawCube((Vector3){0,1,0}, 2,2,2, GRAY);
        EndMode3D();

        DrawText("Urbex Prototype", 10, 10, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}