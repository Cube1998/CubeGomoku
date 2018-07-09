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

static const int GRID = 15;

using namespace std;

struct flatted_Data{
    int* Horitical = new int[GRID];
    int* Vertical = new int[GRID];
    int* Sum_Array = NULL;   // Array which presents(column + row)
    int* Differ_Array = NULL; // Array which presents(column - row)
    
    int sum;  //column + row
    int differ; //column - row
};

class board {
private:
    int *state_of_board; // board data
    
    int grids_num ;  //Number of grids in board;
    int grids_per; //Number of grids in each column/row;
    
    int Next_Player; // Current next player;
    
    //Flat by grid(i，j) to evaluate this node;
    flatted_Data* flat_by_grid(int column , int row );
    
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
    
    int Evaluate(int _row,int _column);
    // evaluate grid;
    //评估函数 TODO: 完成评估方案及评估标准
    
    int minimax(board *node,int depth);
    // 返回该节点的评估结果。
    
    board& operator=(const board &);
    
    
};




#endif /* Board_hpp */
