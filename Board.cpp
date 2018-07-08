//
//  Board.cpp
//  Gomoku
//
//  Created by 张大方 on 2018/7/8.
//  Copyright © 2018年 Cube. All rights reserved.
//

#include "Board.hpp"

void board::setPiece(int column, int row){
    state_of_board[column*grids_per + row] = Next_Player;
    Next_Player = Next_Player == COMPUTER ? PLAYER : COMPUTER;
    printBoard();
}

void board::printBoard(){
    for(int i = 0;i<grids_per*2+3;i++)cout<<"=";
    cout<<endl;
    for(int i = 0;i<grids_per;i++){
        cout<<"| ";
        for(int j = 0; j< grids_per;j++)
            cout<<state_of_board[i*grids_per+j]<<" ";
        cout<<"|"<<endl;
    }
    for(int i = 0;i<grids_per*2+3;i++)cout<<"=";
    cout<<endl;
}
