//
// Created by anees on 09-06-2024.
//
#include "genericRubiksCube.h"
typedef uint64_t bitBoard;

class RubiksCubeBitBoard: public genericRubiksCube{
private:
    void setBit(int position,FACE F){
        int face=(int)F;
        cube[face]|=(1ULL<<position);
    }
    void clearBit(int position,FACE F){
        int face=(int)F;
        cube[face]&=~(1ULL<<position);
    }
    bool bitCheck(FACE F,int position){
        int face=(int)F;
        return cube[face]&(1ULL<<position);
    }
    void rotateFace(FACE F){
        int face=(int)F;
        cube[face]=(cube[face]<<16)|(cube[face]>>48);
    }
public:
    bitBoard cube[6]={};

    RubiksCubeBitBoard(){
        for(int i=0;i<6;i++){
            for(int j=0;j<8;j++){
                int position = 8*j+i;
                setBit(position,(FACE)i);
            }
        }
    }
    COLOR getColor(FACE F,unsigned row,unsigned col) const override{
        int face=(int)F;
        if(row==1 and col==1) return (COLOR)face;
        int num=cube[face];

        

    }

};