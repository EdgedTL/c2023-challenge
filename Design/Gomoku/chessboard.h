//
// Created by Admin on 6/11/2023.
//

#ifndef C2023_CHALLENGE_CHESSBOARD_H
#define C2023_CHALLENGE_CHESSBOARD_H

#endif //C2023_CHALLENGE_CHESSBOARD_H
#include "Includes.h"
enum chess{
    black = 1, white = -1, empty = 0
};
enum chess chessboard[15][15] = {empty};
void zero_matrix(){
    for (int i = 0;i<255;i++){
     chessboard[i%15][i/15] = empty;
    }
}
typedef struct node{
    int x;
    int y;
    enum chess chess;
}node_t;
void push_node(node_t *timeline, int steps, int x, int y, enum chess chess){
    timeline[steps-1].x = x;
    timeline[steps-1].y = y;
    timeline[steps-1].chess = chess;
}
