#include "canvas.hpp"

#include <raylib.h>

#include <array>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <stdexcept>

const int width = 2560;
const int height = 1440;
const char* const title = "skch";
const int targetFPS = 240;
const float circleRadius = 2.50F;
const float eraseMultiplier = 15.0F;
const float lineThickness = 4.0F;

const int timeArraySize = 30;

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

  Vector2 mousePrevPos = {(float)GetMouseX(), (float)(height - GetMouseY())};

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_SPACE)) {
      clear(texture);
    }

    BeginTextureMode(texture);

    Vector2 mousePos = {float(GetMouseX()), (float)(height - GetMouseY())};

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      DrawCircle((int)mousePos.x, (int)mousePos.y, circleRadius, WHITE);
      mousePos = mousePrevPos;
    } else if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
      DrawLineEx(mousePrevPos, mousePos, lineThickness, WHITE);
      mousePrevPos = mousePos;
    } else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
      DrawCircle((int)mousePos.x, (int)mousePos.y,
                 circleRadius * eraseMultiplier, BLACK);
    } else {
      mousePrevPos = mousePos;
    }

    EndTextureMode();

    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexture(texture.texture, 0, 0, WHITE);

    EndDrawing();

    if (IsKeyPressed(KEY_ESCAPE)) {
      time_t currentTime = std::time(nullptr);
      tm* timePtr = std::localtime(&currentTime);
      tm time = *timePtr;
      std::array<char, timeArraySize> arr{};
      strftime(arr.data(), arr.size(), "%Y-%m-%d_%H-%M-%S", &time);
      Image image = LoadImageFromTexture(texture.texture);
      const char* env_p = std::getenv("XDG_DATA_HOME");
      if (env_p == nullptr) {
        env_p = std::getenv("HOME");
      }
      std::string basePath = std::string(env_p) + "/skch/images/";
      std::filesystem::create_directories(basePath);

      std::string fileName = std::string(arr.data()) + ".png";
      std::string fullFilePath = basePath + fileName;

      ExportImage(image, fullFilePath.c_str());
      UnloadImage(image);
      break;
    }
  }

  UnloadRenderTexture(texture);
  CloseWindow();
}

void clear(RenderTexture2D& texture) {
  BeginTextureMode(texture);
  ClearBackground(BLACK);
  EndTextureMode();
}
