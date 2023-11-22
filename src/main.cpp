#include <iostream>
#include <math.h>
#include <raylib.h>
#include <vector>

#include "euler.hpp"
#include "physix_object.hpp"

constexpr int WIDTH = 1280;
constexpr int HEIGHT = 720;

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "Raylib Template");

    std::vector<physix::PhysixObject> objs{};
    objs.push_back(physix::PhysixObject(400, 400));
    objs.push_back(physix::PhysixObject(700, 200));

    physix::EulerSolver solver(objs, 2800);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        solver.solve(GetFrameTime());
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (const auto &obj : solver.objects())
        {
            DrawCircle(obj.m_x, obj.m_y, 30, RED);
        }

        EndDrawing();
    }

    CloseWindow();
}
