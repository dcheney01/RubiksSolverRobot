#include "CubeModel.h"

/**
* Initialize the cube with orange on the top and green up front.
*/
CubeModel::CubeModel()
{
    // Edges.
    for (unsigned i = 0; i < 12; ++i)
    {
      this->edges[i].index       = i;
      this->edges[i].orientation = 0;
    }

    // Corners.
    for (unsigned i = 0; i < 8; ++i)
    {
      this->corners[i].index       = i;
      this->corners[i].orientation = 0;
    }

    // Centers.
    this->centers[0] = COLOR::ORANGE;
    this->centers[1] = COLOR::YELLOW;
    this->centers[2] = COLOR::GREEN;
    this->centers[3] = COLOR::WHITE;
    this->centers[4] = COLOR::BLUE;
    this->centers[5] = COLOR::RED;
}

CubeModel& CubeModel::move(MOVE ind)
{
  switch (ind)
  {
    case MOVE::L:
      return this->l();
    case MOVE::LPRIME:
      return this->lPrime();
    case MOVE::R:
      return this->r();
    case MOVE::RPRIME:
      return this->rPrime();
    case MOVE::U:
      return this->u();
    case MOVE::UPRIME:
      return this->uPrime();
    case MOVE::D:
      return this->d();
    case MOVE::DPRIME:
      return this->dPrime();
    case MOVE::F:
      return this->f();
    case MOVE::FPRIME:
      return this->fPrime();
    case MOVE::B:
      return this->b();
    case MOVE::BPRIME:
      return this->bPrime();
    default:
      throw CubeException("Invalid face turn index. (MOVE)");
  };
}

/**
 * Invert a move.
 * @param ind The move index.  The inverse will be applied.
 */
CubeModel& CubeModel::invert(MOVE ind)
{
  switch (ind)
  {
    case MOVE::L:
      return this->lPrime();
    case MOVE::LPRIME:
      return this->l();
    case MOVE::R:
      return this->rPrime();
    case MOVE::RPRIME:
      return this->r();
    case MOVE::U:
      return this->uPrime();
    case MOVE::UPRIME:
      return this->u();
    case MOVE::D:
      return this->dPrime();
    case MOVE::DPRIME:
      return this->d();
    case MOVE::F:
      return this->fPrime();
    case MOVE::FPRIME:
      return this->f();
    case MOVE::B:
      return this->bPrime();
    case MOVE::BPRIME:
      return this->b();
    default:
      throw CubeException("Invalid face turn index. (INVERT)");
  }
}

/**
 * Describe a move using an index.
 */
std::string CubeModel::getMove(MOVE ind) const
{
  switch (ind)
  {
    case MOVE::L:
      return "L";
    case MOVE::LPRIME:
      return "L'";
    case MOVE::R:
      return "R";
    case MOVE::RPRIME:
      return "R2";
    case MOVE::U:
      return "U";
    case MOVE::UPRIME:
      return "U'";
    case MOVE::D:
      return "D";
    case MOVE::DPRIME:
      return "D'";
    case MOVE::F:
      return "F";
    case MOVE::FPRIME:
      return "F'";
    case MOVE::B:
      return "B";
    case MOVE::BPRIME:
      return "B'";
    default:
      throw CubeException("Invalid face turn index. (GET MOVE)");
  };
}


/**
* Get the cubie index of an edge cubie.
*/
uint8_t CubeModel::getEdgeIndex(EDGE ind) const
{
return this->edges[(unsigned)ind].index;
}

/**
* Get the orientation of an edge cubie.
*/
uint8_t CubeModel::getEdgeOrientation(EDGE ind) const
{
return this->edges[(unsigned)ind].orientation;
}

/**
* Get the cubie index of a corner cubie.
*/
uint8_t CubeModel::getCornerIndex(CORNER ind) const
{
return this->corners[(unsigned)ind].index;
}

/**
* Get the orientation of a corner cubie.
*/
uint8_t CubeModel::getCornerOrientation(CORNER ind) const
{
return this->corners[(unsigned)ind].orientation;
}

/**
* Check if the cube is in a solved state.
*/
bool CubeModel::isSolved() const
{
    for (unsigned i = 0; i < this->corners.size(); ++i)
    {
      if (this->corners[i].index != i || this->corners[i].orientation != 0)
        return false;
    }

    for (unsigned i = 0; i < this->edges.size(); ++i)
    {
      if (this->edges[i].index != i || this->edges[i].orientation != 0)
        return false;
    }

    return true;
}

/**
   * Get the edge colors at an index.
   */
std::array<CubeModel::COLOR, 2> CubeModel::getEdgeColors(
    CubeModel::EDGE ind) const
  {
    std::array<COLOR, 2> colors;

    Cubie edge = this->edges.at((unsigned)ind);

    switch ((EDGE)edge.index)
    {
      case EDGE::UB:
        colors[0] = COLOR::ORANGE;
        colors[1] = COLOR::BLUE;
        break;

      case EDGE::UR:
        colors[0] = COLOR::ORANGE;
        colors[1] = COLOR::WHITE;
        break;

      case EDGE::UF:
        colors[0] = COLOR::ORANGE;
        colors[1] = COLOR::GREEN;
        break;

      case EDGE::UL:
        colors[0] = COLOR::ORANGE;
        colors[1] = COLOR::YELLOW;
        break;

      case EDGE::FR:
        colors[0] = COLOR::GREEN;
        colors[1] = COLOR::WHITE;
        break;

      case EDGE::FL:
        colors[0] = COLOR::GREEN;
        colors[1] = COLOR::YELLOW;
        break;

      case EDGE::BL:
        colors[0] = COLOR::BLUE;
        colors[1] = COLOR::YELLOW;
        break;

      case EDGE::BR:
        colors[0] = COLOR::BLUE;
        colors[1] = COLOR::WHITE;
        break;

      case EDGE::DF:
        colors[0] = COLOR::RED;
        colors[1] = COLOR::GREEN;
        break;

      case EDGE::DL:
        colors[0] = COLOR::RED;
        colors[1] = COLOR::YELLOW;
        break;

      case EDGE::DB:
        colors[0] = COLOR::RED;
        colors[1] = COLOR::BLUE;
        break;

      case EDGE::DR:
        colors[0] = COLOR::RED;
        colors[1] = COLOR::WHITE;
        break;
    }

    if (edge.orientation == 1)
      std::swap(colors[0], colors[1]);

    return colors;
  }

  /**
   * Get the corner colors at an index.  Three colors are returns: U or D, L or
   * R, F or B (YXZ).
   */
  std::array<CubeModel::COLOR, 3> CubeModel::getCornerColors(
    CubeModel::CORNER ind) const
  {
    std::array<COLOR, 3> colors;

    Cubie corner = this->corners.at((unsigned)ind);

    unsigned i0, i1, i2;

    // Red or orange on top.
    if (corner.orientation == 0)
    {
      i0 = 0;
      i1 = 1;
      i2 = 2;

      // A quarter turn of U or D swaps the two other colors.
      if ((corner.index + (unsigned)ind) % 2 == 1)
        std::swap(i1, i2);
    }
    else if (corner.orientation == 1)
    {
      i0 = 1;
      i1 = 2;
      i2 = 0;

      if ((corner.index + (unsigned)ind) % 2 == 1)
        std::swap(i0, i1);
    }
    else // if (corner.orientation == 2)
    {
      i0 = 2;
      i1 = 0;
      i2 = 1;

      if ((corner.index + (unsigned)ind) % 2 == 1)
        std::swap(i0, i2);
    }

    switch ((CORNER)corner.index)
    {
      case CORNER::ULB:
        colors[i0] = COLOR::ORANGE;
        colors[i1] = COLOR::YELLOW;
        colors[i2] = COLOR::BLUE;
        break;

      case CORNER::URB:
        colors[i0] = COLOR::ORANGE;
        colors[i1] = COLOR::WHITE;
        colors[i2] = COLOR::BLUE;
        break;

      case CORNER::URF:
        colors[i0] = COLOR::ORANGE;
        colors[i1] = COLOR::WHITE;
        colors[i2] = COLOR::GREEN;
        break;

      case CORNER::ULF:
        colors[i0] = COLOR::ORANGE;
        colors[i1] = COLOR::YELLOW;
        colors[i2] = COLOR::GREEN;
        break;

      case CORNER::DLF:
        colors[i0] = COLOR::RED;
        colors[i1] = COLOR::YELLOW;
        colors[i2] = COLOR::GREEN;
        break;

      case CORNER::DLB:
        colors[i0] = COLOR::RED;
        colors[i1] = COLOR::YELLOW;
        colors[i2] = COLOR::BLUE;
        break;

      case CORNER::DRB:
        colors[i0] = COLOR::RED;
        colors[i1] = COLOR::WHITE;
        colors[i2] = COLOR::BLUE;
        break;

      case CORNER::DRF:
        colors[i0] = COLOR::RED;
        colors[i1] = COLOR::WHITE;
        colors[i2] = COLOR::GREEN;
        break;
    }

    return colors;
  }


/**
   * Get the facet color using a face, row, and column.
   */
CubeModel::COLOR CubeModel::getColor(
    FACE f, unsigned row, unsigned col) const
  {
    if (row == 1 && col == 1)
      return (COLOR)this->centers[(unsigned)f];

    // The colors are arranged Y, X, Z (see getCornerColors).
    if (f == FACE::UP)
    {
      if (row == 0)
      {
        if (col == 0)
          return this->getCornerColors(CORNER::ULB)[0];
        else if (col == 1)
          return this->getEdgeColors(EDGE::UB)[0];
        else
          return this->getCornerColors(CORNER::URB)[0];
      }
      else if (row == 1)
      {
        if (col == 0)
          return this->getEdgeColors(EDGE::UL)[0];
        else
          return this->getEdgeColors(EDGE::UR)[0];
      }
      else
      {
        if (col == 0)
          return this->getCornerColors(CORNER::ULF)[0];
        else if (col == 1)
          return this->getEdgeColors(EDGE::UF)[0];
        else
          return this->getCornerColors(CORNER::URF)[0];
      }
    }
    else if (f == FACE::LEFT)
    {
      if (row == 0)
      {
        if (col == 0)
          return this->getCornerColors(CORNER::ULB)[1];
        else if (col == 1)
          return this->getEdgeColors(EDGE::UL)[1];
        else
          return this->getCornerColors(CORNER::ULF)[1];
      }
      else if (row == 1)
      {
        if (col == 0)
          return this->getEdgeColors(EDGE::BL)[1];
        else
          return this->getEdgeColors(EDGE::FL)[1];
      }
      else
      {
        if (col == 0)
          return this->getCornerColors(CORNER::DLB)[1];
        else if (col == 1)
          return this->getEdgeColors(EDGE::DL)[1];
        else
          return this->getCornerColors(CORNER::DLF)[1];
      }
    }
    else if (f == FACE::FRONT)
    {
      if (row == 0)
      {
        if (col == 0)
          return this->getCornerColors(CORNER::ULF)[2];
        else if (col == 1)
          return this->getEdgeColors(EDGE::UF)[1];
        else
          return this->getCornerColors(CORNER::URF)[2];
      }
      else if (row == 1)
      {
        if (col == 0)
          return this->getEdgeColors(EDGE::FL)[0];
        else
          return this->getEdgeColors(EDGE::FR)[0];
      }
      else
      {
        if (col == 0)
          return this->getCornerColors(CORNER::DLF)[2];
        else if (col == 1)
          return this->getEdgeColors(EDGE::DF)[1];
        else
          return this->getCornerColors(CORNER::DRF)[2];
      }
    }
    else if (f == FACE::RIGHT)
    {
      if (row == 0)
      {
        if (col == 0)
          return this->getCornerColors(CORNER::URF)[1];
        else if (col == 1)
          return this->getEdgeColors(EDGE::UR)[1];
        else
          return this->getCornerColors(CORNER::URB)[1];
      }
      else if (row == 1)
      {
        if (col == 0)
          return this->getEdgeColors(EDGE::FR)[1];
        else
          return this->getEdgeColors(EDGE::BR)[1];
      }
      else
      {
        if (col == 0)
          return this->getCornerColors(CORNER::DRF)[1];
        else if (col == 1)
          return this->getEdgeColors(EDGE::DR)[1];
        else
          return this->getCornerColors(CORNER::DRB)[1];
      }
    }
    else if (f == FACE::BACK)
    {
      if (row == 0)
      {
        if (col == 0)
          return this->getCornerColors(CORNER::URB)[2];
        else if (col == 1)
          return this->getEdgeColors(EDGE::UB)[1];
        else
          return this->getCornerColors(CORNER::ULB)[2];
      }
      else if (row == 1)
      {
        if (col == 0)
          return this->getEdgeColors(EDGE::BR)[0];
        else
          return this->getEdgeColors(EDGE::BL)[0];
      }
      else
      {
        if (col == 0)
          return this->getCornerColors(CORNER::DRB)[2];
        else if (col == 1)
          return this->getEdgeColors(EDGE::DB)[1];
        else
          return this->getCornerColors(CORNER::DLB)[2];
      }
    }
    else // if (f == FACE::DOWN)
    {
      if (row == 0)
      {
        if (col == 0)
          return this->getCornerColors(CORNER::DLF)[0];
        else if (col == 1)
          return this->getEdgeColors(EDGE::DF)[0];
        else
          return this->getCornerColors(CORNER::DRF)[0];
      }
      else if (row == 1)
      {
        if (col == 0)
          return this->getEdgeColors(EDGE::DL)[0];
        else
          return this->getEdgeColors(EDGE::DR)[0];
      }
      else
      {
        if (col == 0)
          return this->getCornerColors(CORNER::DLB)[0];
        else if (col == 1)
          return this->getEdgeColors(EDGE::DB)[0];
        else
          return this->getCornerColors(CORNER::DRB)[0];
      }
    }
}


/*
* Helper to update the orientation of corners on 90-degree CW twist.
* @param ind The corner index to update.
* @param amount The amount to update the orientation by: 1, or 2.
*/
inline void CubeModel::updateCornerOrientation(CORNER ind)
{
    Cubie& corner = this->corners[(unsigned)ind];

    // For 90-degree twists that change the orientation of corners, half of the
    // corners change orientation by 1 (0->1, 1->2, 2->0) and the other half
    // change by 2 (0->2, 1->0, 2->1 [mod 3]).
    // Orientation 0: Red or orange on top or bottom.
    // Orientation 1: Red or orange is twisted clockwise from its nearest up or
    // down face.
    // Orientation 2: Red or orange is twisted counterclockwise from its
    // nearest up or down face.

    if (corner.orientation == 0)
      corner.orientation = 2;
    else if (corner.orientation >= 2)
      corner.orientation = 0;
}

/*
* Helper to update the orientation of corners on 90-degree CW twist for an L or R turn.
* @param ind The corner index to update.
* @param amount The amount to update the orientation by: 1, or 2.
*/
inline void CubeModel::updateLRCornerOrientation(
CORNER ind, uint8_t amount)
{
    Cubie& corner = this->corners[(unsigned)ind];

    // For 90-degree twists that change the orientation of corners, half of the
    // corners change orientation by 1 (0->1, 1->2, 2->0) and the other half
    // change by 2 (0->2, 1->0, 2->1 [mod 3]).
    // Orientation 0: Red or orange on top or bottom.
    // Orientation 1: Red or orange is twisted clockwise from its nearest up or
    // down face.
    // Orientation 2: Red or orange is twisted counterclockwise from its
    // nearest up or down face.
    corner.orientation += amount;

    // % 3, but a bit faster.
    if (corner.orientation == 3)
      corner.orientation = 0;
    else if (corner.orientation > 3)
      corner.orientation = 0;
}

/**
* Helper to update the orientation of edges on an F or B turn.  Moving F or
* B toggles the orientation of each edge.
*/
inline void CubeModel::updateEdgeOrientationZ(EDGE ind)
{
    this->edges[(unsigned)ind].orientation ^= 1;
}

CubeModel& CubeModel::f()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::ULF];
    this->corners[(unsigned)CORNER::ULF] = this->corners[(unsigned)CORNER::DLF];
    this->corners[(unsigned)CORNER::DLF] = this->corners[(unsigned)CORNER::DRF];
    this->corners[(unsigned)CORNER::DRF] = this->corners[(unsigned)CORNER::URF];
    this->corners[(unsigned)CORNER::URF] = hold;

    hold                                 = this->edges[(unsigned)EDGE::UF];
    this->edges[(unsigned)EDGE::UF]      = this->edges[(unsigned)EDGE::FL];
    this->edges[(unsigned)EDGE::FL]      = this->edges[(unsigned)EDGE::DF];
    this->edges[(unsigned)EDGE::DF]      = this->edges[(unsigned)EDGE::FR];
    this->edges[(unsigned)EDGE::FR]      = hold;

    this->updateCornerOrientation(CORNER::ULF);
    this->updateCornerOrientation(CORNER::URF);
    this->updateCornerOrientation(CORNER::DRF);
    this->updateCornerOrientation(CORNER::DLF);

    this->updateEdgeOrientationZ(EDGE::UF);
    this->updateEdgeOrientationZ(EDGE::FL);
    this->updateEdgeOrientationZ(EDGE::DF);
    this->updateEdgeOrientationZ(EDGE::FR);

    return *this;
}

CubeModel& CubeModel::fPrime()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::ULF];
    this->corners[(unsigned)CORNER::ULF] = this->corners[(unsigned)CORNER::URF];
    this->corners[(unsigned)CORNER::URF] = this->corners[(unsigned)CORNER::DRF];
    this->corners[(unsigned)CORNER::DRF] = this->corners[(unsigned)CORNER::DLF];
    this->corners[(unsigned)CORNER::DLF] = hold;

    hold                                 = this->edges[(unsigned)EDGE::UF];
    this->edges[(unsigned)EDGE::UF]      = this->edges[(unsigned)EDGE::FR];
    this->edges[(unsigned)EDGE::FR]      = this->edges[(unsigned)EDGE::DF];
    this->edges[(unsigned)EDGE::DF]      = this->edges[(unsigned)EDGE::FL];
    this->edges[(unsigned)EDGE::FL]      = hold;

    this->updateCornerOrientation(CORNER::ULF);
    this->updateCornerOrientation(CORNER::URF);
    this->updateCornerOrientation(CORNER::DRF);
    this->updateCornerOrientation(CORNER::DLF);

    this->updateEdgeOrientationZ(EDGE::UF);
    this->updateEdgeOrientationZ(EDGE::FL);
    this->updateEdgeOrientationZ(EDGE::DF);
    this->updateEdgeOrientationZ(EDGE::FR);

    return *this;
}


CubeModel& CubeModel::b()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::ULB];
    this->corners[(unsigned)CORNER::ULB] = this->corners[(unsigned)CORNER::URB];
    this->corners[(unsigned)CORNER::URB] = this->corners[(unsigned)CORNER::DRB];
    this->corners[(unsigned)CORNER::DRB] = this->corners[(unsigned)CORNER::DLB];
    this->corners[(unsigned)CORNER::DLB] = hold;

    hold                                 = this->edges[(unsigned)EDGE::UB];
    this->edges[(unsigned)EDGE::UB]      = this->edges[(unsigned)EDGE::BR];
    this->edges[(unsigned)EDGE::BR]      = this->edges[(unsigned)EDGE::DB];
    this->edges[(unsigned)EDGE::DB]      = this->edges[(unsigned)EDGE::BL];
    this->edges[(unsigned)EDGE::BL]      = hold;

    this->updateCornerOrientation(CORNER::ULB);
    this->updateCornerOrientation(CORNER::URB);
    this->updateCornerOrientation(CORNER::DRB);
    this->updateCornerOrientation(CORNER::DLB);

    this->updateEdgeOrientationZ(EDGE::UB);
    this->updateEdgeOrientationZ(EDGE::BL);
    this->updateEdgeOrientationZ(EDGE::DB);
    this->updateEdgeOrientationZ(EDGE::BR);

    return *this;
}

CubeModel& CubeModel::bPrime()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::ULB];
    this->corners[(unsigned)CORNER::ULB] = this->corners[(unsigned)CORNER::DLB];
    this->corners[(unsigned)CORNER::DLB] = this->corners[(unsigned)CORNER::DRB];
    this->corners[(unsigned)CORNER::DRB] = this->corners[(unsigned)CORNER::URB];
    this->corners[(unsigned)CORNER::URB] = hold;

    hold                                 = this->edges[(unsigned)EDGE::UB];
    this->edges[(unsigned)EDGE::UB]      = this->edges[(unsigned)EDGE::BL];
    this->edges[(unsigned)EDGE::BL]      = this->edges[(unsigned)EDGE::DB];
    this->edges[(unsigned)EDGE::DB]      = this->edges[(unsigned)EDGE::BR];
    this->edges[(unsigned)EDGE::BR]      = hold;

    this->updateCornerOrientation(CORNER::ULB);
    this->updateCornerOrientation(CORNER::URB);
    this->updateCornerOrientation(CORNER::DRB);
    this->updateCornerOrientation(CORNER::DLB);

    this->updateEdgeOrientationZ(EDGE::UB);
    this->updateEdgeOrientationZ(EDGE::BL);
    this->updateEdgeOrientationZ(EDGE::DB);
    this->updateEdgeOrientationZ(EDGE::BR);

    return *this;
}

CubeModel& CubeModel::l()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::DLB];
    this->corners[(unsigned)CORNER::DLB] = this->corners[(unsigned)CORNER::DLF];
    this->corners[(unsigned)CORNER::DLF] = this->corners[(unsigned)CORNER::ULF];
    this->corners[(unsigned)CORNER::ULF] = this->corners[(unsigned)CORNER::ULB];
    this->corners[(unsigned)CORNER::ULB] = hold;

    hold                                 = this->edges[(unsigned)EDGE::BL];
    this->edges[(unsigned)EDGE::BL]      = this->edges[(unsigned)EDGE::DL];
    this->edges[(unsigned)EDGE::DL]      = this->edges[(unsigned)EDGE::FL];
    this->edges[(unsigned)EDGE::FL]      = this->edges[(unsigned)EDGE::UL];
    this->edges[(unsigned)EDGE::UL]      = hold;

    this->updateLRCornerOrientation(CORNER::DLB, 1);
    this->updateLRCornerOrientation(CORNER::DLF, 2);
    this->updateLRCornerOrientation(CORNER::ULF, 1);
    this->updateLRCornerOrientation(CORNER::ULB, 2);

    return *this;
}

CubeModel& CubeModel::lPrime()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::DLB];
    this->corners[(unsigned)CORNER::DLB] = this->corners[(unsigned)CORNER::ULB];
    this->corners[(unsigned)CORNER::ULB] = this->corners[(unsigned)CORNER::ULF];
    this->corners[(unsigned)CORNER::ULF] = this->corners[(unsigned)CORNER::DLF];
    this->corners[(unsigned)CORNER::DLF] = hold;

    hold                                 = this->edges[(unsigned)EDGE::BL];
    this->edges[(unsigned)EDGE::BL]      = this->edges[(unsigned)EDGE::UL];
    this->edges[(unsigned)EDGE::UL]      = this->edges[(unsigned)EDGE::FL];
    this->edges[(unsigned)EDGE::FL]      = this->edges[(unsigned)EDGE::DL];
    this->edges[(unsigned)EDGE::DL]      = hold;

    this->updateLRCornerOrientation(CORNER::DLB, 1);
    this->updateLRCornerOrientation(CORNER::DLF, 2);
    this->updateLRCornerOrientation(CORNER::ULF, 1);
    this->updateLRCornerOrientation(CORNER::ULB, 2);

    return *this;
}

CubeModel& CubeModel::r()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::DRB];
    this->corners[(unsigned)CORNER::DRB] = this->corners[(unsigned)CORNER::URB];
    this->corners[(unsigned)CORNER::URB] = this->corners[(unsigned)CORNER::URF];
    this->corners[(unsigned)CORNER::URF] = this->corners[(unsigned)CORNER::DRF];
    this->corners[(unsigned)CORNER::DRF] = hold;

    hold                                 = this->edges[(unsigned)EDGE::BR];
    this->edges[(unsigned)EDGE::BR]      = this->edges[(unsigned)EDGE::UR];
    this->edges[(unsigned)EDGE::UR]      = this->edges[(unsigned)EDGE::FR];
    this->edges[(unsigned)EDGE::FR]      = this->edges[(unsigned)EDGE::DR];
    this->edges[(unsigned)EDGE::DR]      = hold;

    this->updateLRCornerOrientation(CORNER::DRB, 1);
    this->updateLRCornerOrientation(CORNER::DRF, 2);
    this->updateLRCornerOrientation(CORNER::URF, 1);
    this->updateLRCornerOrientation(CORNER::URB, 2);

    return *this;
}

CubeModel& CubeModel::rPrime()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::DRB];
    this->corners[(unsigned)CORNER::DRB] = this->corners[(unsigned)CORNER::DRF];
    this->corners[(unsigned)CORNER::DRF] = this->corners[(unsigned)CORNER::URF];
    this->corners[(unsigned)CORNER::URF] = this->corners[(unsigned)CORNER::URB];
    this->corners[(unsigned)CORNER::URB] = hold;

    hold                                 = this->edges[(unsigned)EDGE::BR];
    this->edges[(unsigned)EDGE::BR]      = this->edges[(unsigned)EDGE::DR];
    this->edges[(unsigned)EDGE::DR]      = this->edges[(unsigned)EDGE::FR];
    this->edges[(unsigned)EDGE::FR]      = this->edges[(unsigned)EDGE::UR];
    this->edges[(unsigned)EDGE::UR]      = hold;

    this->updateLRCornerOrientation(CORNER::DRB, 1);
    this->updateLRCornerOrientation(CORNER::DRF, 0);
    this->updateLRCornerOrientation(CORNER::URF, 1);
    this->updateLRCornerOrientation(CORNER::URB, 0);

    return *this;
}


CubeModel& CubeModel::u()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::ULF];
    this->corners[(unsigned)CORNER::ULF] = this->corners[(unsigned)CORNER::URF];
    this->corners[(unsigned)CORNER::URF] = this->corners[(unsigned)CORNER::URB];
    this->corners[(unsigned)CORNER::URB] = this->corners[(unsigned)CORNER::ULB];
    this->corners[(unsigned)CORNER::ULB] = hold;

    hold                                 = this->edges[(unsigned)EDGE::UL];
    this->edges[(unsigned)EDGE::UL]      = this->edges[(unsigned)EDGE::UF];
    this->edges[(unsigned)EDGE::UF]      = this->edges[(unsigned)EDGE::UR];
    this->edges[(unsigned)EDGE::UR]      = this->edges[(unsigned)EDGE::UB];
    this->edges[(unsigned)EDGE::UB]      = hold;

    return *this;
}

CubeModel& CubeModel::uPrime()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::ULB];
    this->corners[(unsigned)CORNER::ULB] = this->corners[(unsigned)CORNER::URB];
    this->corners[(unsigned)CORNER::URB] = this->corners[(unsigned)CORNER::URF];
    this->corners[(unsigned)CORNER::URF] = this->corners[(unsigned)CORNER::ULF];
    this->corners[(unsigned)CORNER::ULF] = hold;

    hold                                 = this->edges[(unsigned)EDGE::UB];
    this->edges[(unsigned)EDGE::UB]      = this->edges[(unsigned)EDGE::UR];
    this->edges[(unsigned)EDGE::UR]      = this->edges[(unsigned)EDGE::UF];
    this->edges[(unsigned)EDGE::UF]      = this->edges[(unsigned)EDGE::UL];
    this->edges[(unsigned)EDGE::UL]      = hold;

    return *this;
}


CubeModel& CubeModel::d()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::DLB];
    this->corners[(unsigned)CORNER::DLB] = this->corners[(unsigned)CORNER::DRB];
    this->corners[(unsigned)CORNER::DRB] = this->corners[(unsigned)CORNER::DRF];
    this->corners[(unsigned)CORNER::DRF] = this->corners[(unsigned)CORNER::DLF];
    this->corners[(unsigned)CORNER::DLF] = hold;

    hold                                 = this->edges[(unsigned)EDGE::DB];
    this->edges[(unsigned)EDGE::DB]      = this->edges[(unsigned)EDGE::DR];
    this->edges[(unsigned)EDGE::DR]      = this->edges[(unsigned)EDGE::DF];
    this->edges[(unsigned)EDGE::DF]      = this->edges[(unsigned)EDGE::DL];
    this->edges[(unsigned)EDGE::DL]      = hold;

    return *this;
}


CubeModel& CubeModel::dPrime()
{
    Cubie hold                           = this->corners[(unsigned)CORNER::DLF];
    this->corners[(unsigned)CORNER::DLF] = this->corners[(unsigned)CORNER::DRF];
    this->corners[(unsigned)CORNER::DRF] = this->corners[(unsigned)CORNER::DRB];
    this->corners[(unsigned)CORNER::DRB] = this->corners[(unsigned)CORNER::DLB];
    this->corners[(unsigned)CORNER::DLB] = hold;

    hold                                 = this->edges[(unsigned)EDGE::DL];
    this->edges[(unsigned)EDGE::DL]      = this->edges[(unsigned)EDGE::DF];
    this->edges[(unsigned)EDGE::DF]      = this->edges[(unsigned)EDGE::DR];
    this->edges[(unsigned)EDGE::DR]      = this->edges[(unsigned)EDGE::DB];
    this->edges[(unsigned)EDGE::DB]      = hold;

    return *this;
}

std::string CubeModel::toString() const {
     char colors[] = {'O', 'Y', 'G', 'W', 'B', 'R'};
     std::string currCube = "";

     for (unsigned row = 0; row < 3; ++ row)
     {
       for (unsigned col = 0; col < 3; ++ col)
         currCube += colors[(unsigned)getColor(FACE::UP, row, col)];
     }

     for (unsigned row = 0; row < 3; ++ row)
     {
       for (unsigned col = 0; col < 3; ++ col)
         currCube += colors[(unsigned)getColor(FACE::LEFT,  row, col)];
     }

     for (unsigned row = 0; row < 3; ++ row)
     {
         for (unsigned col = 0; col < 3; ++ col)
        currCube += colors[(unsigned)getColor(FACE::FRONT, row, col)];
     }

     for (unsigned row = 0; row < 3; ++ row)
     {
        for (unsigned col = 0; col < 3; ++ col)
        currCube += colors[(unsigned)getColor(FACE::RIGHT, row, col)];
     }

    for (unsigned row = 0; row < 3; ++ row)
    {
        for (unsigned col = 0; col < 3; ++ col)
        currCube += colors[(unsigned)getColor(FACE::BACK,  row, col)];
    }

    for (unsigned row = 0; row < 3; ++ row)
    {
      for (unsigned col = 0; col < 3; ++ col)
        currCube += colors[(unsigned)getColor(FACE::DOWN, row, col)];
    }
  return currCube;
}