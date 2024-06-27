//
// Created by anees on 27-06-2024.
//
#include "bits/stdc++.h"
#include "..\Models\genericRubiksCube.h"
#include"DFSSolver.h"
#ifndef RUBIKS_IDDFSSOLVER_H
#define RUBIKS_IDDFSSOLVER_H

template<typename T,typename H>

class IDDFSSolver{
private:
    int max_depth;
    vector<genericRubiksCube::MOVE> moves;

public:

    T rubiksCube;

    IDDFSSolver(T _rubiksCube,int _max_depth=7){
        rubiksCube=_rubiksCube;
        max_depth= _max_depth;
    }

    vector<genericRubiksCube::MOVE> Solve(){
        for(int i=1;i<=max_depth;i++){
            DFSSolver<T,H> dfsSolver(rubiksCube,i);
            moves=dfsSolver.solve();
            if(dfsSolver.rubiksCube.isSolved()){
                rubiksCube=dfsSolver.rubiksCube;
                break;
            }
        }
        return moves;
    }

};


#endif //RUBIKS_IDDFSSOLVER_H
