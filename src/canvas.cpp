#include <raylib.h>
#include <stdexcept>

const int width = 1280;
const int height = 720;
const char* const title = "skch";

void createCanvas() {
    InitWindow(width, height, title);
    if (!IsWindowReady()) {
        throw std::runtime_error("Could not initialise window");
    }
    CloseWindow();
}
