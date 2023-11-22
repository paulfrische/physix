#include "euler.hpp"
#include "physix_object.hpp"
#include "spring.hpp"
#include <iostream>
#include <memory>
#include <vector>

namespace physix
{

void EulerSolver::solve(float dt)
{
    for (auto &obj : m_objs)
    {
        // update position
        obj->m_y += obj->m_vy * dt;
        obj->m_x += obj->m_vx * dt;

        // apply acceleration
        obj->m_vx += obj->m_ax;
        obj->m_vy += obj->m_ay;

        // apply drag
        obj->m_vx -= obj->m_vx * m_drag_factor * dt;
        obj->m_vy -= obj->m_vy * m_drag_factor * dt;

        // reset acceleration
        obj->m_ax = 0;
        obj->m_ay = 0;

        // apply gravity
        obj->m_ay += m_gravity * dt;
    }

    for (auto &spring : m_springs)
    {
        float fx = spring.forceX();
        float fy = spring.forceY();

        spring.m_a->m_ax -= fx * dt * 0.5;
        spring.m_a->m_ay -= fy * dt * 0.5;

        spring.m_b->m_ay += fy * dt * 0.5;
        spring.m_b->m_ax += fx * dt * 0.5;
    }
}

std::vector<std::shared_ptr<PhysixObject>> const &EulerSolver::objects()
{
    return m_objs;
}

std::vector<Spring> const &EulerSolver::springs()
{
    return m_springs;
}

} // namespace physix
