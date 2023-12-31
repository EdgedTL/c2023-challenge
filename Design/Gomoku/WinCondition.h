//
// Created by Admin on 13/11/2023.
//

#ifndef C2023_CHALLENGE_WINCONDITION_H
#define C2023_CHALLENGE_WINCONDITION_H

#endif //C2023_CHALLENGE_WINCONDITION_H
#include "Includes.h"

enum game determinine_win(int X, int Y, enum chess chess_color){
    Vector2 direction[4] = {{0, 1},{1, 0},{1,1},{-1, 1}};

    for (int i = 0; i < 4; i++){
        int link_on_dir = 1;
        int dir = 1;
        int reverse = 0;
        int steps = 1;
        while(reverse < 2){
            if
                    ((chessboard[(int)(X + dir*steps*(int)(direction[i].x))]
                     [(int)(Y + dir*steps*(int)(direction[i].y))] == chess_color)
                     && (X + dir*steps*(int)(direction[i].x) >= 0) &&  (X + dir*steps*(int)(direction[i].x) <= 14)
                     &&  (Y + dir*steps*(int)(direction[i].y) >= 0) &&  (Y + dir*steps*(int)(direction[i].y) <= 14))
            {
                steps++;link_on_dir++;
            }
            else{
                reverse++;
                steps = 1;
                dir*=-1;
            }
        }
        if(link_on_dir >= 5){
            return (enum game)chess_color;
        }
    }
     return GoingOn;

}


