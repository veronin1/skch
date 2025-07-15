#include "canvas.hpp"

#include <raylib.h>

#include <stdexcept>

const int width = 1280;
const int height = 720;
const char* const title = "skch";
const int targetFPS = 60;
const float circleRadius = 5;

void createCanvas() {
  SetWindowState(FLAG_WINDOW_RESIZABLE);
  InitWindow(width, height, title);
  if (!IsWindowReady()) {
    throw std::runtime_error("Could not initialise window");
  }

  SetTargetFPS(targetFPS);
  ClearBackground(BLACK);

  while (!WindowShouldClose()) {
    BeginDrawing();
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      draw();
    }

    EndDrawing();
    if (IsKeyPressed(KEY_ESCAPE)) {
      CloseWindow();
    }
  }
}

void draw() { DrawCircle(GetMouseX(), GetMouseY(), circleRadius, WHITE); }
