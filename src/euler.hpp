#pragma once

#include "physix_object.hpp"
#include "solver.hpp"
#include "spring.hpp"
#include <memory>
#include <vector>

namespace physix
{

class EulerSolver : public Solver
{
  public:
    EulerSolver(std::vector<std::shared_ptr<PhysixObject>> os, std::vector<Spring> s, float g, float d)
        : m_objs(os), m_springs(s), m_gravity(g), m_drag_factor(d){};

    void solve(float dt) override;
    std::vector<std::shared_ptr<PhysixObject>> const &objects() override;
    std::vector<Spring> const &springs() override;

  private:
    std::vector<std::shared_ptr<PhysixObject>> m_objs;
    std::vector<Spring> m_springs;
    float m_gravity = 0.0;
    float m_drag_factor = 1.0;
};

} // namespace physix
