#ifndef CUBEMODEL_H
#define CUBEMODEL_H

#include <iostream>
#include <iomanip>

#include "CubeException.h"
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
 * OB OW OG OY GW GY BY BW RG RY RB RW
 *
 *
 * Corner indexes.
 *
 * 0   1   2   3   4   5   6   7
 * ULB URB ULF URF DLB DRB DLF DRF
 * OYB OWB OYG OWG RYB RWB RYG RWG
 */


class CubeModel
{
  private:
    struct Cubie
    {
      uint8_t index;                    // 0 - 11 for edges, 0 - 7 for corners.
      uint8_t orientation;              // 0 - 1 for edges, 0 - 2 for corners.
    };
    enum class FACE   : uint8_t {UP, LEFT, FRONT, RIGHT, BACK, DOWN};
    enum class COLOR  : uint8_t {ORANGE, YELLOW, GREEN, WHITE, BLUE, RED};
    enum class EDGE   : uint8_t {UB, UR, UF, UL, FR, FL, BL, BR, DF, DL, DB, DR};
    enum class CORNER : uint8_t {ULB, URB, URF, ULF, DLF, DLB, DRB, DRF};
    enum class MOVE   : uint8_t //removed X2 turns for now
    {
      L, LPRIME,
      R, RPRIME,
      U, UPRIME,
      D, DPRIME,
      F, FPRIME,
      B, BPRIME,
    };

    std::array<Cubie, 12> edges;
    std::array<Cubie, 8>  corners;
    std::array<COLOR, 6>  centers;

    inline void updateCornerOrientation(CubeModel::CORNER ind);
    inline void updateLRCornerOrientation(CORNER ind, uint8_t amount);
    inline void updateEdgeOrientationZ(EDGE ind);

    char getColor(COLOR color) const;
    std::array<int, 3> getCornerPosition(int index, int orientation) const;
    std::array<int, 2> getEdgePosition(int index, int orientation) const;

    std::array<COLOR, 2> getEdgeColors(EDGE ind) const;
    std::array<COLOR, 3> getCornerColors(CORNER ind) const;
    COLOR getColor(FACE face, unsigned row, unsigned col) const;

  public:
    CubeModel();
    std::string toString() const;
    bool isSolved() const;
    std::string getMove(MOVE ind) const;

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

    CubeModel& b();
    CubeModel& bPrime();

    CubeModel& l();
    CubeModel& lPrime();

    CubeModel& r();
    CubeModel& rPrime();

    CubeModel& u();
    CubeModel& uPrime();

    CubeModel& d();
    CubeModel& dPrime();
};

#endif
