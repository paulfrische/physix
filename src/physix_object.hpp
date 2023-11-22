#pragma once

namespace physix
{

struct PhysixObject
{
    PhysixObject(float x, float y) : m_x(x), m_y(y)
    {
    }

    // position
    float m_x = 0;
    float m_y = 0;

    // velocity
    float m_vx = 0;
    float m_vy = 0;

    // acceleration
    float m_ax = 0;
    float m_ay = 0;
};

} // namespace physix
