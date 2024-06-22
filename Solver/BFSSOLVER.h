//
// Created by anees on 22-06-2024.
//
#include "bits/stdc++.h"
#include "..\Models\genericRubiksCube.h"
#ifndef RUBIKS_BFSSOLVER_H
#define RUBIKS_BFSSOLVER_H
template<typename T, typename H>

class BFSSolver{
private:
    vector<genericRubiksCube::MOVE> moves;
    unordered_map<T,bool,H> visited;
    unordered_map<T,genericRubiksCube::MOVE,H> move_done;

    T bfs(){
        queue<T> q;
        q.push(rubiksCube);
        visited[rubiksCube]=1;

        while(!q.empty()){
            T currentNode=q.front();
            q.pop();
            if(currentNode.isSolved()) return currentNode;
            for(int i=0;i<18;i++){
                auto moveit=genericRubiksCube::MOVE(i);
                currentNode.move(moveit);
                if(!visited[currentNode]){
                    visited[currentNode]=1;
                    move_done[currentNode]=moveit;
                    q.push(currentNode);
                }
                currentNode.invert(moveit);
            }
        }
    }

public:
    T rubiksCube;

    BFSSolver(T _rubiksCube){
        rubiksCube=_rubiksCube;
    }

    vector<genericRubiksCube::MOVE> Solve(){
        T solved_cube=bfs();
        T curr_cube = solved_cube;
        while(!(curr_cube==rubiksCube)){
            genericRubiksCube::MOVE curr_move=move_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.invert(curr_move);
        }
        rubiksCube=solved_cube;
        reverse(moves.begin(),moves.end());
        return moves;
    }
};



#endif //RUBIKS_BFSSOLVER_H
