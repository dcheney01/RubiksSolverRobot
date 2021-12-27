#include "Solver.h"

Solver::Solver() \
{
    phase = 0;
}

void Solver::solve(vector<string> const &input)
{
    solveMoves.clear();
    //--- Define the goal.
      string goal[] = { "UF", "UR", "UB", "UL", "DF", "DR", "DB", "DL", "FR", "FL", "BR", "BL",
                "UFR", "URB", "UBL", "ULF", "DRF", "DFL", "DLB", "DBR" };
      //--- Prepare current (start) and goal state.
      vi currentState( 40 ), goalState( 40 );
      for( int i=0; i<20; i++ ){

        //--- Goal state.
        goalState[i] = i;

        //--- Current (start) state.
        string cubie = input[i];
        while( (currentState[i] = find( goal, goal+20, cubie ) - goal) == 20){
          cubie = cubie.substr( 1 ) + cubie[0];
          currentState[i+20]++;
        }
      }

      //--- Dance the funky Thistlethwaite...
      while( ++phase < 5 ){

        //--- Compute ids for current and goal state, skip phase if equal.
        vi currentId = id( currentState ), goalId = id( goalState );
        if( currentId == goalId )
          continue;

        //--- Initialize the BFS queue.
        queue<vi> q;
        q.push( currentState );
        q.push( goalState );

        //--- Initialize the BFS tables.
        map<vi,vi> predecessor;
        map<vi,int> direction, lastMove;
        direction[ currentId ] = 1;
        direction[ goalId ] = 2;

        //--- Dance the funky bidirectional BFS...
        while( 1 ){

          //--- Get state from queue, compute its ID and get its direction.
          vi oldState = q.front();
          q.pop();
          vi oldId = id( oldState );
          int& oldDir = direction[oldId];

          //--- Apply all applicable moves to it and handle the new state.
          for( int move=0; move<18; move++ ){
        if( applicableMoves[phase] & (1 << move) ){

          //--- Apply the move.
          vi newState = applyMove( move, oldState );
          vi newId = id( newState );
          int& newDir = direction[newId];

          //--- Have we seen this state (id) from the other direction already?
          //--- I.e. have we found a connection?
          if( newDir  &&  newDir != oldDir ){

            //--- Make oldId represent the forwards and newId the backwards search state.
            if( oldDir > 1 ){
              swap( newId, oldId );
              move = inverse( move );
            }

            //--- Reconstruct the connecting algorithm.
            vi algorithm( 1, move );
            while( oldId != currentId ){
              algorithm.insert( algorithm.begin(), lastMove[ oldId ] );
              oldId = predecessor[ oldId ];
            }
            while( newId != goalId ){
              algorithm.push_back( inverse( lastMove[ newId ] ));
              newId = predecessor[ newId ];
            }

            //--- Print and apply the algorithm.
            for( int i=0; i<(int)algorithm.size(); i++ ){
              string s(1, "UDFBLR"[algorithm[i]/3]);
              s += " 2'"[algorithm[i]%3];
              solveMoves.push_back(s);
              //solveMoves.push_back(std::to_string("UDFBLR"[algorithm[i]/3] + " 2'"[algorithm[i]%3]));
              currentState = applyMove( algorithm[i], currentState );
            }

            //--- Jump to the next phase.
            goto nextPhasePlease;
          }

          //--- If we've never seen this state (id) before, visit it.
          if( ! newDir ){
            q.push( newState );
            newDir = oldDir;
            lastMove[ newId ] = move;
            predecessor[ newId ] = oldId;
          }
        }
          }
        }
      nextPhasePlease:
        ;
      }
}

Solver::vi Solver::applyMove ( int move, Solver::vi state ) {
  int turns = move % 3 + 1;
  int face = move / 3;
  while( turns-- ){
    vi oldState = state;
    for( int i=0; i<8; i++ ){
      int isCorner = i > 3;
      int target = affectedCubies[face][i] + isCorner*12;
      int killer = affectedCubies[face][(i&3)==3 ? i-3 : i+1] + isCorner*12;;
      int orientationDelta = (i<4) ? (face>1 && face<4) : (face<2) ? 0 : 2 - (i&1);
      state[target] = oldState[killer];
      //state[target+20] = (oldState[killer+20] + orientationDelta) % (2 + isCorner);
      state[target+20] = oldState[killer+20] + orientationDelta;
      if( !turns )
    state[target+20] %= 2 + isCorner;
    }
  }
  return state;
}

int Solver::inverse ( int move ) {
  return move + 2 - 2 * (move % 3);
}

Solver::vi Solver::id ( vi state ) {

  //--- Phase 1: Edge orientations.
  if( phase < 2 )
    return vi( state.begin() + 20, state.begin() + 32 );

  //-- Phase 2: Corner orientations, E slice edges.
  if( phase < 3 ){
    vi result( state.begin() + 31, state.begin() + 40 );
    for( int e=0; e<12; e++ )
      result[0] |= (state[e] / 8) << e;
    return result;
  }

  //--- Phase 3: Edge slices M and S, corner tetrads, overall parity.
  if( phase < 4 ){
    vi result( 3 );
    for( int e=0; e<12; e++ )
      result[0] |= ((state[e] > 7) ? 2 : (state[e] & 1)) << (2*e);
    for( int c=0; c<8; c++ )
      result[1] |= ((state[c+12]-12) & 5) << (3*c);
    for( int i=12; i<20; i++ )
      for( int j=i+1; j<20; j++ )
    result[2] ^= state[i] > state[j];
    return result;
  }

  //--- Phase 4: The rest.
  return state;
}
