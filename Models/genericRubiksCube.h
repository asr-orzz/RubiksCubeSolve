//
// Created by anees on 06-06-2024.
//

#ifndef RUBIKS_GENERICRUBIKSCUBE_H
#define RUBIKS_GENERICRUBIKSCUBE_H
#include "bits/stdc++.h"
using namespace std;

class genericRubiksCube{
public:
    enum class FACE{
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };
    enum class COLOR{
        RED,
        WHITE,
        BLUE,
        ORANGE,
        YELLOW,
        GREEN
    };
    enum class MOVE{
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };
    //returns Color for an piece specific row and column
    //for row from top to bottom and column is left to right indexed-0
    virtual COLOR getColor(FACE F,unsigned row,unsigned col) const=0;

    static char getColorLetter(COLOR color);

    virtual bool isSolved() const=0;

    static string getMove(MOVE ind);

    void print() const;

    genericRubiksCube &move(MOVE ind);

    genericRubiksCube &invert(MOVE ind);

    vector<MOVE> randomShuffleColor(unsigned int times);

    virtual genericRubiksCube &f() = 0;

    virtual genericRubiksCube &fPrime() = 0;

    virtual genericRubiksCube &f2() = 0;

    virtual genericRubiksCube &u() = 0;

    virtual genericRubiksCube &uPrime() = 0;

    virtual genericRubiksCube &u2() = 0;

    virtual genericRubiksCube &l() = 0;

    virtual genericRubiksCube &lPrime() = 0;

    virtual genericRubiksCube &l2() = 0;

    virtual genericRubiksCube &r() = 0;

    virtual genericRubiksCube &d() = 0;

    virtual genericRubiksCube &dPrime() = 0;

    virtual genericRubiksCube &d2() = 0;

    virtual genericRubiksCube &rPrime() = 0;

    virtual genericRubiksCube &r2() = 0;

    virtual genericRubiksCube &b() = 0;

    virtual genericRubiksCube &bPrime() = 0;

    virtual genericRubiksCube &b2() = 0;

};




#endif //RUBIKS_GENERICRUBIKSCUBE_H
