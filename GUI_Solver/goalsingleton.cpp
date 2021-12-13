#include "goalsingleton.h"
GoalSingleton* GoalSingleton::instance = 0;


GoalSingleton* GoalSingleton::getInstance()
{
    if(!instance)
    {
        instance = new GoalSingleton;
    }
    return instance;
}

bool GoalSingleton::G0_G1_isSatisfied(const CubeModel& cube)
 {
   CubeModel::COLOR UB = cube.getColor(CubeModel::FACE::UP, 0, 1);
   CubeModel::COLOR UL = cube.getColor(CubeModel::FACE::UP, 1, 0);
   CubeModel::COLOR UR = cube.getColor(CubeModel::FACE::UP, 1, 2);
   CubeModel::COLOR UF = cube.getColor(CubeModel::FACE::UP, 2, 1);

   CubeModel::COLOR LU = cube.getColor(CubeModel::FACE::LEFT, 0, 1);
   CubeModel::COLOR LB = cube.getColor(CubeModel::FACE::LEFT, 1, 0);
   CubeModel::COLOR LF = cube.getColor(CubeModel::FACE::LEFT, 1, 2);
   CubeModel::COLOR LD = cube.getColor(CubeModel::FACE::LEFT, 2, 1);

   CubeModel::COLOR FU = cube.getColor(CubeModel::FACE::FRONT, 0, 1);
   CubeModel::COLOR FL = cube.getColor(CubeModel::FACE::FRONT, 1, 0);
   CubeModel::COLOR FR = cube.getColor(CubeModel::FACE::FRONT, 1, 2);
   CubeModel::COLOR FD = cube.getColor(CubeModel::FACE::FRONT, 2, 1);

   CubeModel::COLOR RU = cube.getColor(CubeModel::FACE::RIGHT, 0, 1);
   CubeModel::COLOR RF = cube.getColor(CubeModel::FACE::RIGHT, 1, 0);
   CubeModel::COLOR RB = cube.getColor(CubeModel::FACE::RIGHT, 1, 2);
   CubeModel::COLOR RD = cube.getColor(CubeModel::FACE::RIGHT, 2, 1);

   CubeModel::COLOR BU = cube.getColor(CubeModel::FACE::BACK, 0, 1);
   CubeModel::COLOR BL = cube.getColor(CubeModel::FACE::BACK, 1, 0);
   CubeModel::COLOR BR = cube.getColor(CubeModel::FACE::BACK, 1, 2);
   CubeModel::COLOR BD = cube.getColor(CubeModel::FACE::BACK, 2, 1);

   CubeModel::COLOR DF = cube.getColor(CubeModel::FACE::DOWN, 0, 1);
   CubeModel::COLOR DL = cube.getColor(CubeModel::FACE::DOWN, 1, 0);
   CubeModel::COLOR DR = cube.getColor(CubeModel::FACE::DOWN, 1, 2);
   CubeModel::COLOR DB = cube.getColor(CubeModel::FACE::DOWN, 2, 1);

   // See the spreadsheet in this directory for possible "good" edges.  Each
   // should be movable to its solved position without using F, F', B, or B'. (GREEN AND BLUE)
   return
     (UF == CubeModel::COLOR::RED  || UF == CubeModel::COLOR::ORANGE || FU == CubeModel::COLOR::WHITE || FU == CubeModel::COLOR::YELLOW) &&
     (UB == CubeModel::COLOR::RED  || UB == CubeModel::COLOR::ORANGE || BU == CubeModel::COLOR::WHITE || BU == CubeModel::COLOR::YELLOW) &&
     (DF == CubeModel::COLOR::RED  || DF == CubeModel::COLOR::ORANGE || FD == CubeModel::COLOR::WHITE || FD == CubeModel::COLOR::YELLOW) &&
     (DB == CubeModel::COLOR::RED  || DB == CubeModel::COLOR::ORANGE || BD == CubeModel::COLOR::WHITE || BD == CubeModel::COLOR::YELLOW) &&
     (LU == CubeModel::COLOR::RED  || LU == CubeModel::COLOR::ORANGE || UL == CubeModel::COLOR::WHITE || UL == CubeModel::COLOR::YELLOW) &&
     (LD == CubeModel::COLOR::RED  || LD == CubeModel::COLOR::ORANGE || DL == CubeModel::COLOR::WHITE || DL == CubeModel::COLOR::YELLOW) &&
     (RU == CubeModel::COLOR::RED  || RU == CubeModel::COLOR::ORANGE || UR == CubeModel::COLOR::WHITE || UR == CubeModel::COLOR::YELLOW) &&
     (RD == CubeModel::COLOR::RED  || RD == CubeModel::COLOR::ORANGE || DR == CubeModel::COLOR::WHITE || DR == CubeModel::COLOR::YELLOW) &&
     (LF == CubeModel::COLOR::RED  || LF == CubeModel::COLOR::ORANGE || FL == CubeModel::COLOR::WHITE || FL == CubeModel::COLOR::YELLOW) &&
     (LB == CubeModel::COLOR::RED  || LB == CubeModel::COLOR::ORANGE || BL == CubeModel::COLOR::WHITE || BL == CubeModel::COLOR::YELLOW) &&
     (RF == CubeModel::COLOR::RED  || RF == CubeModel::COLOR::ORANGE || FR == CubeModel::COLOR::WHITE || FR == CubeModel::COLOR::YELLOW) &&
     (RB == CubeModel::COLOR::RED  || RB == CubeModel::COLOR::ORANGE || BR == CubeModel::COLOR::WHITE || BR == CubeModel::COLOR::YELLOW);
 }

bool GoalSingleton::G1_G2_isSatisfied(const CubeModel& cube)
{
    // Corners, left and right facets.
    CubeModel::COLOR LUB = cube.getColor(CubeModel::FACE::LEFT, 0, 0);
    CubeModel::COLOR LUF = cube.getColor(CubeModel::FACE::LEFT, 0, 2);
    CubeModel::COLOR LDB = cube.getColor(CubeModel::FACE::LEFT, 2, 0);
    CubeModel::COLOR LDF = cube.getColor(CubeModel::FACE::LEFT, 2, 2);

    CubeModel::COLOR RUB = cube.getColor(CubeModel::FACE::RIGHT, 0, 2);
    CubeModel::COLOR RUF = cube.getColor(CubeModel::FACE::RIGHT, 0, 0);
    CubeModel::COLOR RDB = cube.getColor(CubeModel::FACE::RIGHT, 2, 2);
    CubeModel::COLOR RDF = cube.getColor(CubeModel::FACE::RIGHT, 2, 0);

    // Edges in the M slice (between R and L).
    CubeModel::COLOR UF = cube.getColor(CubeModel::FACE::UP,    2, 1);
    CubeModel::COLOR FU = cube.getColor(CubeModel::FACE::FRONT, 0, 1);

    CubeModel::COLOR UB = cube.getColor(CubeModel::FACE::UP,    0, 1);
    CubeModel::COLOR BU = cube.getColor(CubeModel::FACE::BACK,  0, 1);

    CubeModel::COLOR DF = cube.getColor(CubeModel::FACE::DOWN,  0, 1);
    CubeModel::COLOR FD = cube.getColor(CubeModel::FACE::FRONT, 2, 1);

    CubeModel::COLOR DB = cube.getColor(CubeModel::FACE::DOWN,  2, 1);
    CubeModel::COLOR BD = cube.getColor(CubeModel::FACE::BACK,  2, 1);

    return
      // All left/right corner facets either yellow or white.
      (LUB == CubeModel::COLOR::YELLOW || LUB == CubeModel::COLOR::WHITE) &&
      (LUF == CubeModel::COLOR::YELLOW || LUF == CubeModel::COLOR::WHITE) &&
      (LDB == CubeModel::COLOR::YELLOW || LDB == CubeModel::COLOR::WHITE) &&
      (LDF == CubeModel::COLOR::YELLOW || LDF == CubeModel::COLOR::WHITE) &&
      (RUB == CubeModel::COLOR::YELLOW || RUB == CubeModel::COLOR::WHITE) &&
      (RUF == CubeModel::COLOR::YELLOW || RUF == CubeModel::COLOR::WHITE) &&
      (RDB == CubeModel::COLOR::YELLOW || RDB == CubeModel::COLOR::WHITE) &&
      (RDF == CubeModel::COLOR::YELLOW || RDF == CubeModel::COLOR::WHITE) &&

      // UF, UB, DF, DB in the M slice.  Note that the edges
      // are already oriented.
      (UF == CubeModel::COLOR::GREEN   || UF == CubeModel::COLOR::BLUE)  &&
      (FU == CubeModel::COLOR::RED || FU == CubeModel::COLOR::ORANGE)  &&

      (UB == CubeModel::COLOR::GREEN   || UB == CubeModel::COLOR::BLUE)  &&
      (BU == CubeModel::COLOR::RED || BU == CubeModel::COLOR::ORANGE)  &&

      (DF == CubeModel::COLOR::GREEN   || DF == CubeModel::COLOR::BLUE)  &&
      (FD == CubeModel::COLOR::RED || FD == CubeModel::COLOR::ORANGE)  &&

      (DB == CubeModel::COLOR::GREEN   || DB == CubeModel::COLOR::BLUE)  &&
      (BD == CubeModel::COLOR::RED || BD == CubeModel::COLOR::ORANGE);
}

bool GoalSingleton::G2_G3_isSatisfied(const CubeModel& cube)
{
   // Edges.  Note that the edge pieces in the M slice were taken care
   // of in the G1->G2 goal.
   CubeModel::COLOR UL = cube.getColor(CubeModel::FACE::UP,    1, 0);
   CubeModel::COLOR LU = cube.getColor(CubeModel::FACE::LEFT,  0, 1);

   CubeModel::COLOR UR = cube.getColor(CubeModel::FACE::UP,    1, 2);
   CubeModel::COLOR RU = cube.getColor(CubeModel::FACE::RIGHT, 0, 1);

   CubeModel::COLOR DL = cube.getColor(CubeModel::FACE::DOWN,  1, 0);
   CubeModel::COLOR LD = cube.getColor(CubeModel::FACE::LEFT,  2, 1);

   CubeModel::COLOR DR = cube.getColor(CubeModel::FACE::DOWN,  1, 2);
   CubeModel::COLOR RD = cube.getColor(CubeModel::FACE::RIGHT, 2, 1);

   CubeModel::COLOR LB = cube.getColor(CubeModel::FACE::LEFT,  1, 0);
   CubeModel::COLOR BL = cube.getColor(CubeModel::FACE::BACK,  1, 2);

   CubeModel::COLOR LF = cube.getColor(CubeModel::FACE::LEFT,  1, 2);
   CubeModel::COLOR FL = cube.getColor(CubeModel::FACE::FRONT, 1, 0);

   CubeModel::COLOR RB = cube.getColor(CubeModel::FACE::RIGHT, 1, 2);
   CubeModel::COLOR BR = cube.getColor(CubeModel::FACE::BACK,  1, 0);

   CubeModel::COLOR RF = cube.getColor(CubeModel::FACE::RIGHT, 1, 0);
   CubeModel::COLOR FR = cube.getColor(CubeModel::FACE::FRONT, 1, 2);


   // After this goal, the cube will be solvable with only 180-degree turns.
   return
     // All corners in a permutation that is achievable from the solved
     // state in only 180-degree turns.
     permutationExists(cube) &&

     // Edges in their slices.
     (UL == CubeModel::COLOR::RED   || UL == CubeModel::COLOR::ORANGE) && (LU == CubeModel::COLOR::YELLOW || LU == CubeModel::COLOR::WHITE)  &&
     (UR == CubeModel::COLOR::RED   || UR == CubeModel::COLOR::ORANGE) && (RU == CubeModel::COLOR::YELLOW || RU == CubeModel::COLOR::WHITE)  &&
     (DL == CubeModel::COLOR::RED   || DL == CubeModel::COLOR::ORANGE) && (LD == CubeModel::COLOR::YELLOW || LD == CubeModel::COLOR::WHITE)  &&
     (DR == CubeModel::COLOR::RED   || DR == CubeModel::COLOR::ORANGE) && (RD == CubeModel::COLOR::YELLOW || RD == CubeModel::COLOR::WHITE)  &&
     (BL == CubeModel::COLOR::WHITE || BL == CubeModel::COLOR::YELLOW) && (LB == CubeModel::COLOR::YELLOW || LB == CubeModel::COLOR::WHITE)  &&
     (FL == CubeModel::COLOR::WHITE || FL == CubeModel::COLOR::YELLOW) && (LF == CubeModel::COLOR::YELLOW || LF == CubeModel::COLOR::WHITE)  &&
     (BR == CubeModel::COLOR::WHITE || BR == CubeModel::COLOR::YELLOW) && (RB == CubeModel::COLOR::YELLOW || RB == CubeModel::COLOR::WHITE)  &&
     (FR == CubeModel::COLOR::WHITE || FR == CubeModel::COLOR::YELLOW) && (RF == CubeModel::COLOR::YELLOW || RF == CubeModel::COLOR::WHITE);
}

bool GoalSingleton::permutationIsSatisfied(CubeModel& cube)
{
  perm_t perm = this->permToArr(cube);

  if (this->perms.count(perm) == 0)
  {
    this->perms.insert(perm);

    // There are 96 total permutations.
    if (this->perms.size() == 96)
      return true;
  }

  return false;
}

/**
 * Convert a permutation of the corners to a string.
 * @param cube The cube.
 */
GoalSingleton::perm_t GoalSingleton::permToArr(const CubeModel& cube) const
{
  // Note that two facets of a corner dictate the orientation of a corner.
  // The third facet doesn't need to be stored, therefore.  For example,
  // there are two corner cubies with red and blue facets: RBW, and RBY.
  // With red up top and blue on the left, the RBW cubie occupies the top,
  // left, front position.  There's no possible way to get the RBY cubie to
  // occupy that same position such that red is on top and blue is on the
  // left.  Indexing top, left, front, the RBY corner cubie can be in three
  // permutations: RYB, YBR, BRY, but never RBY.
  perm_t perm =
  {{
    cube.getColor(CubeModel::FACE::UP,    0, 0),
    cube.getColor(CubeModel::FACE::LEFT,  0, 0),

    cube.getColor(CubeModel::FACE::UP,    2, 0),
    cube.getColor(CubeModel::FACE::LEFT,  0, 2),

    cube.getColor(CubeModel::FACE::UP,    0, 2),
    cube.getColor(CubeModel::FACE::RIGHT, 0, 2),

    cube.getColor(CubeModel::FACE::UP,    2, 2),
    cube.getColor(CubeModel::FACE::RIGHT, 0, 0),

    cube.getColor(CubeModel::FACE::DOWN,  2, 0),
    cube.getColor(CubeModel::FACE::LEFT,  2, 0),

    cube.getColor(CubeModel::FACE::DOWN,  0, 0),
    cube.getColor(CubeModel::FACE::LEFT,  2, 2),

    cube.getColor(CubeModel::FACE::DOWN,  2, 2),
    cube.getColor(CubeModel::FACE::RIGHT, 2, 2),

    cube.getColor(CubeModel::FACE::DOWN,  0, 2),
    cube.getColor(CubeModel::FACE::RIGHT, 2, 0),
  }};

  return perm;
}

/**
 * Check if the permutation of the cube's corners is one that can be achieved
 * by only 180-degree twists.
 * @cube The cube.
 */
bool GoalSingleton::permutationExists(const CubeModel& cube) const
{
  perm_t perm = this->permToArr(cube);
  return this->perms.count(perm) == 1;
}

/**
 * Quick compare for two permutation arrays.
 * @param lhs The left array.
 * @param rhs The right array.
 */
bool GoalSingleton::PermComp::operator()(const perm_t& lhs, const perm_t& rhs) const
{
  // 16 corner facets are stored (see note in the ctor).  Each facet is an
  // 8-bit char (a COLOR), so the array of corners can be treated as two
  // 64-bit ints.  This is quite a bit faster than the default
  // set comparator.
  int64_t lDiff = *(int64_t*)&lhs[0] - *(int64_t*)&rhs[0];

  if (lDiff < 0)
    return true;
  else if (lDiff == 0)
  {
    if (*(int64_t*)&lhs[8] < *(int64_t*)&rhs[8])
      return true;
  }

  return false;
}
