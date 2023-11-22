#include "euler.hpp"
#include "physix_object.hpp"
#include "spring.hpp"
#include <vector>

namespace physix
{

void EulerSolver::solve(float dt)
{
    for (auto &obj : m_objs)
    {
        // update position
        obj.m_y += obj.m_vy * dt;
        obj.m_x += obj.m_vx * dt;

        // apply acceleration
        obj.m_vx += obj.m_ax;
        obj.m_vy += obj.m_ay;

        // reset acceleration
        obj.m_ax = 0;
        obj.m_ay = 0;

        // apply gravity
        obj.m_ay += m_gravity * dt;
    }
}

std::vector<PhysixObject> EulerSolver::objects()
{
    return m_objs;
}

} // namespace physix
