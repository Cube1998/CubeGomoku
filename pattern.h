//
//  pattern.h
//  Gomoku
//
//  Created by 张大方 on 2018/7/9.
//  Copyright © 2018年 Cube. All rights reserved.
//

#ifndef pattern_h
#define pattern_h
class Evaluate_pattern {
public:
    bool* Sequence ;
    int score ;
    
    Evaluate_pattern(){
        Sequence = new bool[6];
        score = 0;
    };
    
    
    
    Evaluate_pattern(const Evaluate_pattern & copy){
        Sequence = new bool[6];
        for(int i = 0;i<6;i++)Sequence[i] = copy.Sequence[i];
        this->score = copy.score;
    }
    
};

#endif /* pattern_h */
