#include <iostream>
#include <math.h>
#include <memory>
#include <raylib.h>
#include <vector>

#include "euler.hpp"
#include "physix_object.hpp"
#include "spring.hpp"

constexpr int WIDTH = 1280;
constexpr int HEIGHT = 720;

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "Raylib Template");

    std::vector<std::shared_ptr<physix::PhysixObject>> objs{};
    objs.push_back(std::make_shared<physix::PhysixObject>(400, 400));
    objs.push_back(std::make_shared<physix::PhysixObject>(700, 200));

    std::vector<physix::Spring> springs{};
    springs.push_back(physix::Spring(objs.at(0), objs.at(1), 200, 10));

    /* physix::EulerSolver solver(objs, springs, 2800); */
    physix::EulerSolver solver(objs, springs, 0, 0.8);

    SetTargetFPS(60000);

    while (!WindowShouldClose())
    {
        solver.solve(GetFrameTime());
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (const auto &spring : solver.springs())
        {
            DrawLine(spring.m_a->m_x, spring.m_a->m_y, spring.m_b->m_x, spring.m_b->m_y, GRAY);
        }

        for (const auto &obj : solver.objects())
        {
            DrawCircle(obj->m_x, obj->m_y, 30, RED);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
