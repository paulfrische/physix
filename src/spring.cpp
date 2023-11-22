#include "spring.hpp"
#include <cmath>
#include <iostream>

namespace physix
{
float Spring::forceX()
{
    float dx = m_a->m_x - m_b->m_x;
    float dy = m_a->m_y - m_b->m_y;
    float m = std::sqrt(dx * dx + dy * dy);
    float m2 = m - m_length;
	dx /= m;
	dx *= m2;

    return dx * m_stiffnes;
}

float Spring::forceY()
{
    float dx = m_a->m_x - m_b->m_x;
    float dy = m_a->m_y - m_b->m_y;
    float m = std::sqrt(dx * dx + dy * dy);
    float m2 = m - m_length;
	dy /= m;
	dy *= m2;

    return dy * m_stiffnes;
}

} // namespace physix
