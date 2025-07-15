#include <raylib.h>

#include <stdexcept>

const int width = 1280;
const int height = 720;
const char* const title = "skch";
const int targetFPS = 60;

void createCanvas() {
  SetWindowState(FLAG_WINDOW_RESIZABLE);
  InitWindow(width, height, title);
  if (!IsWindowReady()) {
    throw std::runtime_error("Could not initialise window");
  }

  SetTargetFPS(targetFPS);

  while (!WindowShouldClose()) {
    ClearBackground(BLACK);

    if (IsKeyPressed(KEY_ESCAPE)) {
      CloseWindow();
    }
  }
}
