#include "movesimplify.h"

MoveSimplify::MoveSimplify()
{

}

vector<CubeModel::MOVE> MoveSimplify::simplify(vector<string> const &input)
{
    vector<CubeModel::MOVE> output;
    for (int i = 0; i < input.size(); i++) {
        output.push_back(convertToMove(input[i]));
    }

    return output;
}

CubeModel::MOVE MoveSimplify::convertToMove(string move)
{
     switch(move[0]) {
        case('F'):
         switch(move[1]) {
             case(' '):
              return CubeModel::MOVE::F;
             case('2'):
              return CubeModel::MOVE::F2;
             case('\''):
              return CubeModel::MOVE::FPRIME;
         }
         case('B'):
          switch(move[1]) {
              case(' '):
               return CubeModel::MOVE::B;
              case('2'):
               return CubeModel::MOVE::B2;
              case('\''):
               return CubeModel::MOVE::BPRIME;
          }
         case('U'):
          switch(move[1]) {
              case(' '):
               return CubeModel::MOVE::U;
              case('2'):
               return CubeModel::MOVE::U2;
              case('\''):
               return CubeModel::MOVE::UPRIME;
          }
         case('D'):
          switch(move[1]) {
              case(' '):
               return CubeModel::MOVE::D;
              case('2'):
               return CubeModel::MOVE::D2;
              case('\''):
               return CubeModel::MOVE::DPRIME;
          }
         case('L'):
          switch(move[1]) {
              case(' '):
               return CubeModel::MOVE::L;
              case('2'):
               return CubeModel::MOVE::L2;
              case('\''):
               return CubeModel::MOVE::LPRIME;
          }
         case('R'):
          switch(move[1]) {
              case(' '):
               return CubeModel::MOVE::R;
              case('2'):
               return CubeModel::MOVE::R2;
              case('\''):
               return CubeModel::MOVE::RPRIME;
          }
     }
     return CubeModel::MOVE::F;
}
