#pragma once

#include "physix_object.hpp"
#include "solver.hpp"
#include "spring.hpp"
#include <vector>

namespace physix
{

class EulerSolver : public Solver
{
  public:
    EulerSolver(std::vector<PhysixObject> os, float g) : m_objs(os), m_gravity(g){};

    void solve(float dt) override;
    std::vector<PhysixObject> objects() override;

  private:
    std::vector<PhysixObject> m_objs;
    float m_gravity = 0.0;
};

} // namespace physix
