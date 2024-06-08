//
// Created by anees on 08-06-2024.
//
#include "genericRubiksCube.h"

class RubiksCube1darray : public genericRubiksCube{

private:
    static inline int getIndex(int ind,int row,int col){
        return ((9*ind) + (3*row) + (col));
    }
    void rotateFace(int ind){
        char temp[9]={};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                temp[getIndex(0,i,j)]= cube[getIndex(ind,i,j)];
            }
        }
        for(int i=0;i<3;i++) cube[getIndex(ind,0,i)]=temp[getIndex(0,2-i,0)];
        for(int i=0;i<3;i++) cube[getIndex(ind,1,i)]=temp[getIndex(0,2-i,1)];
        for(int i=0;i<3;i++) cube[getIndex(ind,2,i)]=temp[getIndex(0,2-i,2)];
    }
public:
    char cube[54];

    RubiksCube1darray(){
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    cube[getIndex(i,j,k)]= getColorLetter(COLOR(i));
                }
            }
        }
    }
    COLOR getColor(FACE F,unsigned row,unsigned col) const override{
        char color = cube[getIndex((int)F,(int)row, (int)col)];
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
                    if(getColorLetter(COLOR(i))!=this->cube[getIndex(i,j,k)]){
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

        for (int i = 0; i < 3; i++) temp[i] = cube[getIndex(1,0,i)];
        for(int i = 0; i < 3; i++) cube[getIndex(1,0,i)] = cube[getIndex(2,0,i)];
        for (int i = 0; i < 3; i++)cube[getIndex(2,0,i)] = cube[getIndex(3,0,i)];
        for (int i = 0; i < 3; i++)cube[getIndex(3,0,i)] = cube[getIndex(4,0,i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4,0,i)] = temp[i];

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
        for(int i=0;i<3;i++) temp[i]=cube[getIndex(2,i,0)];
        for(int i=0;i<3;i++) cube[getIndex(2,i,0)]=cube[getIndex(1,i,0)];
        for(int i=0;i<3;i++) cube[getIndex(1,i,0)]=cube[getIndex(4,2-i,2)];
        for(int i=0;i<3;i++) cube[getIndex(4,2-i,2)]=cube[getIndex(5,i,0)];
        for(int i=0;i<3;i++) cube[getIndex(5,i,0)]=temp[i];

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
        for(int i=0;i<3;i++) temp[i]=cube[getIndex(0,2,i)];
        for(int i=0;i<3;i++) cube[getIndex(0,2,i)]=cube[getIndex(1,2-i,2)];
        for(int i=0;i<3;i++) cube[getIndex(1,2-i,2)]=cube[getIndex(5,0,2-i)];
        for(int i=0;i<3;i++) cube[getIndex(5,0,2-i)]=cube[getIndex(3,i,0)];
        for(int i=0;i<3;i++) cube[getIndex(3,i,0)]=temp[i];

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
    genericRubiksCube &r() override{
        this->rotateFace(3);

        char temp[3]={};
        for (int i = 0; i < 3; i++) temp[i] = cube[getIndex(0,2 - i,2)];
        for (int i = 0; i < 3; i++) cube[getIndex(0,2 - i,2)] = cube[getIndex(2,2 - i,2)];
        for (int i = 0; i < 3; i++) cube[getIndex(2,2 - i,2)] = cube[getIndex(5,2 - i,2)];
        for (int i = 0; i < 3; i++) cube[getIndex(5,2 - i,2)] = cube[getIndex(4,i,0)];
        for (int i = 0; i < 3; i++) cube[getIndex(4,i,0)] = temp[i];

        return *this;
    }
    genericRubiksCube &rPrime() override{
        this->r();
        this->r();
        this->r();

        return *this;
    }
    genericRubiksCube &r2() override{
        this->r();
        this->r();

        return *this;
    }
    genericRubiksCube &b() override{
        this->rotateFace(4);

        char temp[3]={};
        for(int i=0;i<3;i++) temp[i]=cube[getIndex(0,0,i)];
        for(int i=0;i<3;i++) cube[getIndex(0,0,i)]=cube[getIndex(3,i,2)];
        for(int i=0;i<3;i++) cube[getIndex(3,i,2)]=cube[getIndex(5,2-i,2)];
        for(int i=0;i<3;i++) cube[getIndex(5,2-i,2)]=cube[getIndex(1,2-i,0)];
        for(int i=0;i<3;i++) cube[getIndex(1,2-i,0)]=temp[i];

        return *this;
    }
    genericRubiksCube &bPrime() override{
        this->b();
        this->b();
        this->b();

        return *this;
    }
    genericRubiksCube &b2() override{
        this->b();
        this->b();

        return *this;
    }
    genericRubiksCube &d() override{
        this->rotateFace(5);

        char temp[3]={};
        for(int i=0;i<3;i++) temp[i]=cube[getIndex(2,2,i)];
        for(int i=0;i<3;i++) cube[getIndex(2,2,i)]=cube[getIndex(1,2,i)];
        for(int i=0;i<3;i++) cube[getIndex(1,2,i)]=cube[getIndex(4,2,i)];
        for(int i=0;i<3;i++) cube[getIndex(4,2,i)]=cube[getIndex(3,2,i)];
        for(int i=0;i<3;i++) cube[getIndex(3,2,i)]=temp[i];

        return  *this;
    }
    genericRubiksCube &dPrime() override{
        this->d();
        this->d();
        this->d();

        return *this;
    }
    genericRubiksCube &d2() override{
        this->d();
        this->d();

        return *this;
    }
};