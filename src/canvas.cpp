#include "canvas.hpp"

#include <raylib.h>

#include <stdexcept>

const int width = 1280;
const int height = 720;
const char* const title = "skch";
const int targetFPS = 240;
const float circleRadius = 2.50F;
const float eraseMultiplier = 15.0F;

void createCanvas() {
  SetWindowState(FLAG_WINDOW_RESIZABLE);
  InitWindow(width, height, title);
  if (!IsWindowReady()) {
    throw std::runtime_error("Could not initialise window");
  }

  SetTargetFPS(targetFPS);

  RenderTexture2D texture = LoadRenderTexture(width, height);

  BeginTextureMode(texture);
  ClearBackground(BLACK);
  EndTextureMode();

  while (!WindowShouldClose()) {
    BeginTextureMode(texture);

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
      draw();
    } else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
      erase();
    }
    EndTextureMode();
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexture(texture.texture, 0, 0, WHITE);

    EndDrawing();

    if (IsKeyPressed(KEY_ESCAPE)) {
      CloseWindow();
    }
  }

  UnloadRenderTexture(texture);
  CloseWindow();
}

void draw() { DrawCircle(GetMouseX(), GetMouseY(), circleRadius, WHITE); }

void erase() {
  DrawCircle(GetMouseX(), GetMouseY(), circleRadius * eraseMultiplier, BLACK);
}