#pragma once

#include "physix_object.hpp"
#include "spring.hpp"
#include <vector>

namespace physix
{

class Solver
{
  public:
    virtual void solve(float dt) = 0;
    virtual std::vector<PhysixObject> objects() = 0;
};

} // namespace physix
