# RubiksSolverRobot

This project is intended to be a Rubik's Cube Solving Robot. The code is broken up as follows:
1. GUI -> written in QT can be run as a standalone desktop GUI to solve a Rubik's Cube
1. Hardware -> this will receive input from the GUI to then manipulate the cube
      



## GUI
The GUI contains 3 major parts:
1. CubeView -> contains the logic for displaying the cube.
1. CubeModel -> contains logic for turning and manipulating the cube. Has functionality for turns, scramble, reset, etc. 
1. Solver -> the actual cube solver that outputs turns needed to solve the scrambled cube. 
      
      
      
      
## Hardware
  Coming soon...
      
      
      
    
      
## Recognition:  
- Most of the inspiration from CubeModel came from [Ben Botto's implementation of a Rubik's Cube Model and his article](https://medium.com/@benjamin.botto/implementing-an-optimal-rubiks-cube-solver-using-korf-s-algorithm-bf750b332cf9)
- The Solver is directly from [Stefan Pochmann's Thisthlewaite Solver](https://www.stefan-pochmann.info/spocc/other_stuff/tools/)
