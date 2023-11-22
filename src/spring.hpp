#pragma once

#include "physix_object.hpp"
#include <memory>

namespace physix
{

struct Spring
{
    Spring(std::shared_ptr<PhysixObject> a, std::shared_ptr<PhysixObject> b, float l, float s)
        : m_a(a), m_b(b), m_length(l), m_stiffnes(s)
    {
    }

    std::shared_ptr<PhysixObject> m_a;
    std::shared_ptr<PhysixObject> m_b;

    float m_length = 0;
    float m_stiffnes = 0;

    float forceX();
    float forceY();
};

} // namespace physix
