#ifndef GOALSINGLETON_H
#define GOALSINGLETON_H

#include "CubeModel.h"

#include <string>
#include <set>
#include <array>
#include <cstdint>

class GoalSingleton
{
private:
    GoalSingleton() {}
    static GoalSingleton* instance;

    typedef std::array<CubeModel::COLOR, 16> perm_t;

    // Fast comparator for a permutation.
    struct PermComp
    {
      bool operator()(const perm_t& lhs, const perm_t& rhs) const;
    };

    std::set<perm_t, PermComp> perms;
    perm_t permToArr(const CubeModel& cube) const;
    bool permutationExists(const CubeModel& cube) const;
    bool permutationIsSatisfied(CubeModel& cube);

public:
    static GoalSingleton *getInstance();

    bool G0_G1_isSatisfied(const CubeModel& cube);
    bool G1_G2_isSatisfied(const CubeModel& cube);
    bool G2_G3_isSatisfied(const CubeModel& cube);
};

#endif // GOALSINGLETON_H
