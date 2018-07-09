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
    for(int i = 0;i<grids_per*2+5;i++)cout<<"=";
    cout<<endl;
    for(int i = grids_per - 1;i>-1;i--){
        printf("%2d",i+1);
        cout<<"| ";
        for(int j = 0; j< grids_per;j++)
            cout<<state_of_board[i*grids_per+j]<<" ";
        cout<<"|"<<endl;
    }
    cout<<"  | ";
    for(int i = 0;i<grids_per;i++)cout<<(char)('A'+ i) <<" ";
    cout<<"|"<<endl;
    for(int i = 0;i<grids_per*2+5;i++)cout<<"=";
    cout<<endl;
}

flatted_Data* board::flat_by_grid(int column, int row){
    flatted_Data * result = new flatted_Data;
    result->sum = column + row ;
    result->Sum_Array = new int[result->sum];
    result->differ = column - row;
    result->Differ_Array = new int[result->differ];
    for(int k = 0;k<GRID;k++){
        result->Horitical[k] = state_of_board[column * grids_per + k];
        result->Vertical[k] = state_of_board[k * grids_per + row];
    }
    int sum_tmp = (result->sum - grids_per + 1 )<=0?0:(result->sum - grids_per + 1 );
    int differ_start = (result->differ <= 0)? result->differ:0;

    for(int _row = sum_tmp,_column = result->sum - _row;_row<grids_per;_row++,_column--)
        result->Sum_Array[_row - sum_tmp] = state_of_board[_column*grids_per + _row];
    for(int _row = differ_start,_column = _row + result->differ;_row<grids_per;_row++,_column++)
        result->Differ_Array[_row - differ_start] = state_of_board[_column*grids_per + _row];
    return result;
}
board& board:: operator=(const board & k){
    
    this->grids_num = k.grids_num;
    this->grids_per = k.grids_per;
    this->Next_Player = k.Next_Player;
    this->state_of_board = new int[k.grids_num];
    for(int i = 0;i<this->grids_num;i++ )
        this->state_of_board[i] = k.state_of_board[i];
    return *this;
    
}


