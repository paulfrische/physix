#include <iostream>
#include <math.h>
#include <raylib.h>

constexpr int WIDTH = 1280;
constexpr int HEIGHT = 720;

int main(void) {
  InitWindow(WIDTH, HEIGHT, "Raylib Template");

  auto accumulator = 0.0f;
  while (!WindowShouldClose()) {
    accumulator += GetFrameTime();
    auto hue = std::sin(accumulator) * 100;

    BeginDrawing();
    ClearBackground(ColorFromHSV(hue, 1.0, 1.0));
    EndDrawing();
  }

  CloseWindow();
}
