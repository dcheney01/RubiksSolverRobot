#ifndef MOVESIMPLIFY_H
#define MOVESIMPLIFY_H

#include <vector>
using std::vector;
#include <string>
using std::string;

#include "CubeModel.h"

class MoveSimplify
{
private:
    CubeModel::MOVE convertToMove(string move);
public:
    MoveSimplify();
    vector<CubeModel::MOVE> simplify(vector<string> const &input);
};

#endif // MOVESIMPLIFY_H
