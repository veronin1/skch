#include "canvas.hpp"

#include <raylib.h>

#include <stdexcept>

const int width = 2560;
const int height = 1440;
const char* const title = "skch";
const int targetFPS = 240;
const float circleRadius = 2.50F;
const float eraseMultiplier = 15.0F;
const float lineThickness = 4.0F;

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

  int mousePrevX = GetMouseX();
  int mousePrevY = height - GetMouseY();

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_SPACE)) {
      clear(texture);
    }

    BeginTextureMode(texture);

    const int mouseX = GetMouseX();
    const int mouseY = height - GetMouseY();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      draw();
      mousePrevX = mouseX;
      mousePrevY = mouseY;
    } else if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
      Vector2 startPos = {(float)mousePrevX, (float)mousePrevY};
      Vector2 endPos = {(float)mouseX, (float)mouseY};
      DrawLineEx(startPos, endPos, lineThickness, WHITE);
      mousePrevX = mouseX;
      mousePrevY = mouseY;
    } else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
      erase();
    } else {
      mousePrevX = mouseX;
      mousePrevY = mouseY;
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

void draw() {
  const int mouseX = GetMouseX();
  const int mouseY = height - GetMouseY();
  DrawCircle(mouseX, mouseY, circleRadius, WHITE);
}

void erase() {
  const int mouseX = GetMouseX();
  const int mouseY = height - GetMouseY();
  DrawCircle(mouseX, mouseY, circleRadius * eraseMultiplier, BLACK);
}

void clear(RenderTexture2D& texture) {
  BeginTextureMode(texture);
  ClearBackground(BLACK);
  EndTextureMode();
}
