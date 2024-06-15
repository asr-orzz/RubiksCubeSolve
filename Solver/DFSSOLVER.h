//
// Created by anees on 15-06-2024.
//
#include "bits/stdc++.h"
#include "..\Models\genericRubiksCube.h"
#ifndef RUBIKS_DFSSOLVER_H
#define RUBIKS_DFSSOLVER_H

template<typename T,typename H>

class DFSSOLVER{
private:
    vector<genericRubiksCube::MOVE> moves;
    int maxDepth;

    bool dfs(int depth){
        if(rubiksCube.solved()) return true;
        if(depth>maxDepth) return false;
        for(int i=0;i<18;i++){
            rubiksCube.move(genericRubiksCube::MOVE(i));
            moves.push_back(genericRubiksCube::MOVE(i));
            if(dfs(depth+1)) return true;
            rubiksCube.invert(genericRubiksCube::MOVE(i));
            moves.pop_back();
        }
    }

public:
    T rubiksCube;

    DFSSOLVER(T _rubiksCube,int _maxDepth){
        rubiksCube=_rubiksCube;
        maxDepth=_maxDepth;
    }
    vector<genericRubiksCube::MOVE> solve(){
        moves.clear();
        if(dfs(1)) return moves;
        else return {};
    }
};

#endif //RUBIKS_DFSSOLVER_H
