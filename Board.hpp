//
//  Board.hpp
//  Gomoku
//
//  Created by 张大方 on 2018/7/8.
//  Copyright © 2018年 Cube. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <string>
#include <iostream>

static const int PLAYER = 1;

static const int COMPUTER = 2;

static const int NOBODY = 0;

static const int NONE_PIECE = 0;

using namespace std;

class board {
private:
    int *state_of_board;
    
    int grids_num ;  //Number of grids in board;
    int grids_per; //Number of grids in each column/row;
    
    int Next_Player; // Current next player;
    
public:
    board(int board_size = 15,int NEXT_PLAYER = COMPUTER){
        //init board's size
        grids_per = board_size;
        grids_num = grids_per * grids_per;
        state_of_board = new int[grids_num];
        for(int i = 0; i< grids_num ; i++)
        {state_of_board[i] = NONE_PIECE;}
        
        Next_Player = NEXT_PLAYER; //
        
        }//  Constructor;
    
    //set a piece
    void setPiece(int column , int row);
    
    void printBoard();
    
    void Evaluate();
    //评估函数 TODO: 完成评估方案及评估标准
    
    int minimax(board *node,int depth);
    // 返回该节点的评估结果。
    
    
};

class board_Methods{
    
};


#endif /* Board_hpp */
