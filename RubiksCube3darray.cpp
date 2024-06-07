//
// Created by anees on 07-06-2024.
//
#include "genericRubiksCube.h"

class RubiksCube3darray: public genericRubiksCube{
private:
    void rotateFace(int ind){
        char temp[3][3]={};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                temp[i][j]= cube[ind][i][j];
            }
        }
        for(int i=0;i<3;i++) cube[ind][0][i]=temp[2-i][0];
        for(int i=0;i<3;i++) cube[ind][1][i]=temp[2-i][1];
        for(int i=0;i<3;i++) cube[ind][2][i]=temp[2-i][2];
    }

public:
    char cube[6][3][3]{};

    RubiksCube3darray(){
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    cube[i][j][k]= getColorLetter(COLOR(i));
                }
            }
        }
    }
    COLOR getColor(FACE F,unsigned row,unsigned col) const override{
        char color=cube[int(F)][row][col];
        if(color=='B') return COLOR::BLUE;
        else if(color=='R') return COLOR::RED;
        else if(color=='Y') return COLOR::YELLOW;
        else if(color=='W') return COLOR::WHITE;
        else if(color=='G') return COLOR::GREEN;
        else return COLOR::ORANGE;
    }

    bool isSolved(){
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(getColorLetter(COLOR(i))!=this->cube[i][j][k]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    genericRubiksCube &u() override{

        this->rotateFace(0);

        char temp[3]={};

        for (int i = 0; i < 3; i++) temp[i] = cube[1][0][i];
        for(int i = 0; i < 3; i++) cube[1][0][i] = cube[2][0][i];
        for (int i = 0; i < 3; i++)cube[2][0][i] = cube[3][0][i];
        for (int i = 0; i < 3; i++)cube[3][0][i] = cube[4][0][i];
        for (int i = 0; i < 3; i++) cube[4][0][i] = temp[i];

        return *this;
    }
    genericRubiksCube &uPrime() override{
        this->u();
        this->u();
        this->u();

        return *this;
    }
    genericRubiksCube &u2() override{
        this->u();
        this->u();

        return *this;
    }

    genericRubiksCube &l() override{
        this->rotateFace(1);

        char temp[3]={};
        for(int i=0;i<3;i++) temp[i]=cube[2][i][0];
        for(int i=0;i<3;i++) cube[2][i][0]=cube[1][i][0];
        for(int i=0;i<3;i++) cube[1][i][0]=cube[4][i][0];
        for(int i=0;i<3;i++) cube[4][i][0]=cube[5][i][0];
        for(int i=0;i<3;i++) cube[5][i][0]=temp[i];

        return *this;
    }
    genericRubiksCube &lPrime() override{
        this->l();
        this->l();
        this->l();

        return *this;
    }
    genericRubiksCube &l2() override{
        this->l();
        this->l();

        return *this;
    }

    genericRubiksCube &f() override{
        this->rotateFace(2);

        char temp[3]={};
        for(int i=0;i<3;i++) temp[i]=cube[0][2][i];
        for(int i=0;i<3;i++) cube[0][2][i]=cube[1][2][i];
        for(int i=0;i<3;i++) cube[1][2][i]=cube[5][2][i];
        for(int i=0;i<3;i++) cube[5][2][i]=cube[3][2][i];
        for(int i=0;i<3;i++) cube[3][2][i]=temp[i];

        return *this;
    }
    genericRubiksCube &fPrime() override{
        this->f();
        this->f();
        this->f();

        return *this;
    }
    genericRubiksCube &f2() override{
        this->f();
        this->f();

        return *this;
    }
};