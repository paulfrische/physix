#pragma once

#include "physix_object.hpp"
#include "spring.hpp"
#include <memory>
#include <vector>

namespace physix
{

class Solver
{
  public:
    virtual void solve(float dt) = 0;
    virtual std::vector<std::shared_ptr<PhysixObject>> const &objects() = 0;
    virtual std::vector<Spring> const &springs() = 0;
};

} // namespace physix
