#include <iostream>
#include "bits/stdc++.h"
#include "C:\Users\anees\CLionProjects\RUbiks\Solver\BFSSOLVER.h"
#include "C:\Users\anees\CLionProjects\RUbiks\Models\RubiksCube3darray.cpp"

int main() {
    RubiksCube3darray cube;
    cube.print();

    vector<genericRubiksCube::MOVE> shuffle_moves = cube.randomShuffleColor(3);
    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    cube.print();

    BFSSolver<RubiksCube3darray, Hash3d> BFSSolver(cube);
    vector<genericRubiksCube::MOVE> solve_moves = BFSSolver.Solve();

    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    BFSSolver.rubiksCube.print();


//    checking of DFSSolver
//    RubiksCube3darray cube;
//    cube.print();
//
//    vector<genericRubiksCube::MOVE> shuffle_moves = cube.randomShuffleColor(3);
//    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    cube.print();
//
//    DFSSolver<RubiksCube3darray, Hash3d> dfsSolver(cube, 6);
//    vector<genericRubiksCube::MOVE> solve_moves = dfsSolver.solve();
//
//    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    dfsSolver.rubiksCube.print();


    return 0;
}
