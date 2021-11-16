#ifndef CUBEMODEL_H
#define CUBEMODEL_H

#include "cubeexception.h"
#include <cstdint>
#include <string>
#include <array>
#include <algorithm>
#include <cstdint>

/**
 * A RubiksCubeModel that is optimized for fast moves and pattern database
 * indexing.  It stores each cubie as an index and orientation, with edges
 * and corners in separate arrays.
 *
 * Note that the cube is oriented with orange on top and green up front
 *
 * Edge indexes.
 *
 * 0  1  2  3  4  5  6  7  8  9  10 11
 * UB UR UF UL FR FL BL BR DF DL DB DR
 * FIXME
 *
 *
 * Corner indexes.
 *
 * 0   1   2   3   4   5   6   7
 * ULB URB URF ULF DLF DLB DRB DRF
 * FIXME
 */


class CubeModel
{
  public:
    struct Cubie
    {
      uint8_t index;                    // 0 - 11 for edges, 0 - 7 for corners.
      uint8_t orientation;              // 0 - 1 for edges, 0 - 2 for corners.
    };
    enum class FACE   : uint8_t {FRONT, BACK, LEFT, RIGHT, UP, DOWN};
    enum class COLOR  : uint8_t {GREEN, BLUE, YELLOW, WHITE, ORANGE, RED};
    enum class EDGE   : uint8_t {UB, UR, UF, UL, FR, FL, BR, BL, DB, DR, DF, DL};
    enum class CORNER : uint8_t {ULB, URB, ULF, URF, DLB, DRB, DLF, DRF};
    enum class MOVE   : uint8_t
    {
      L, LPRIME, L2,
      R, RPRIME, R2,
      U, UPRIME, U2,
      D, DPRIME, D2,
      F, FPRIME, F2,
      B, BPRIME, B2,
    };

  private:
      std::array<Cubie, 12> edges;
      std::array<Cubie, 8>  corners;
      std::array<COLOR, 6>  centers;

      inline void updateCornerOrientation(CubeModel::CORNER ind, uint8_t amount);
      inline void updateEdgeOrientationZ(EDGE ind);

  public:
    CubeModel();
    CubeModel(const CubeModel& cube);
    COLOR getColor(FACE face, unsigned row, unsigned col) const;
    bool isSolved() const;
    std::string getMove(MOVE ind) const;

    std::array<COLOR, 2> getEdgeColors(EDGE ind) const;
    std::array<COLOR, 3> getCornerColors(CORNER ind) const;

    // Indexing methods.
    uint8_t getEdgeIndex(EDGE ind) const;
    uint8_t getEdgeOrientation(EDGE ind) const;
    uint8_t getCornerIndex(CORNER ind) const;
    uint8_t getCornerOrientation(CORNER ind) const;

    CubeModel& move(MOVE ind);
    CubeModel& invert(MOVE ind);

    // Face moves
    CubeModel& f();
    CubeModel& fPrime();
    CubeModel& f2();

    CubeModel& b();
    CubeModel& bPrime();
    CubeModel& b2();

    CubeModel& l();
    CubeModel& lPrime();
    CubeModel& l2();

    CubeModel& r();
    CubeModel& rPrime();
    CubeModel& r2();

    CubeModel& u();
    CubeModel& uPrime();
    CubeModel& u2();

    CubeModel& d();
    CubeModel& dPrime();
    CubeModel& d2();
};

#endif
