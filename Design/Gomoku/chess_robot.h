//
// Created by Admin on 20/11/2023.
//

#ifndef C2023_CHALLENGE_CHESS_ROBOT_H
#define C2023_CHALLENGE_CHESS_ROBOT_H

#include "Includes.h"


#define ATTACK_INDEX 0.7
#define DEFEND_INDEX 1.3
#define MAX_DEPTH 2
#define ROOT_SEARCH_RANGE 3
#define BRANCH_SEARCH_RANGE 2
#define LEAF_SEARCH_RANGE 2

#define c(n) to_int(input.c[n], Friend_color)

struct chess_type{
    char name[15];
    int value;
};
struct chess_chain{
    int count;
    enum chess c[11];
};

struct Global {
    Vector2 put_chess;

};



Vector2 Get_best_location(enum chess Chessboard[15][15], enum chess Friend_color, int depth, Vector2 Last_location);
int alpha_beta_search(enum chess Chessboard[15][15], enum chess Friend_color, int depth, int alpha, int beta,Vector2 put_chess);


int max(int A, int B) {
    if (A > B)return A;
    else return B;
}

int min(int A, int B) {
    if (A < B)return A;
    else return B;
}


bool in_boundary(int i) {
    if (i >= 0 && i <= 14) return true;
    else return false;

}


struct chess_type hashTable[97]={
        {"empty", 0},
        {"21", 0},
        {"010", 1},
        {"211", 150},
        {"010", 1},
        {"1012", 250},
        {"0110", 650},
        {"2111", 500},
        {"010", 1},
        {"1001", 200},
        {"101", 400},
        {"10112", 800},
        {"0110",  650},
        {"11012", 800},
        {"01110", 1500},
        {"11112", 2500},
        {"010",1},
        {"10001", 100},
        {"1001", 200},
        {"100112", 600},
        {"101", 550},
        {"10101", 550},
        {"1011",3100},
        {"101112", 3000},
        {"0110", 650},
        {"110012", 600},
        {"1101", 2100},
        {"11011", 3000},
        {"01110", 1500},
        {"211101", 3000},
        {"011110", 3000000},
        {"11111", 10000000},
        {"21", 0},
        {"21", 0},
        {"10001", 100},
        {"100011", 175},
        {"1001", 200},
        {"100101", 300},
        {"210011", 600},
        {"100111", 725},
        {"1012", 250},
        {"101001", 300},
        {"10101",550},
        {"101011", 937},
        {"11012", 800},
        {"101101", 1000},
        {"111012", 3000},
        {"101111", 3625},
        {"211", 150},
        {"100011", 175},
        {"100112", 600},
        {"110011", 750},
        {"10112", 800},
        {"101011", 937},
        {"110112", 2600},
        {"110111", 3650},
        {"1112", 500},
        {"100111", 725},
        {"101112", 3000},
        {"110111", 3650},
        {"11112", 2500},
        {"101111", 3625},
        {"11111", 10000000},
        {"111111", 10000000},
        {"empty", 0},
        {"010", 1},
        {"010",1},
        {"211", 150},
        {"010", 1},
        {"1012", 250},
        {"0110", 650},
        {"2111", 500},
        {"010", 1},
        {"1001", 200},
        {"101", 550},
        {"10112", 800},
        {"0110", 650},
        {"11012", 800},
        {"01110", 1500},
        {"11112", 2500},
        {"21", 0},
        {"10001", 100},
        {"1001", 200},
        {"100112",  600},
        {"1012", 250},
        {"10101", 550},
        {"11012", 800},
        {"111012", 3000},
        {"211",  150},
        {"210011", 600},
        {"10112", 800},
        {"110112", 2600},
        {"1112", 500},
        {"211101", 1500},
        {"11112", 2500},
        {"11111", 10000000},
        {"empty", 0}
};


struct Global global = {(Vector2){7,7}};
static Vector2 direction[4] = {{0,  1},
                               {1,  0},
                               {1,  1},
                               {-1, 1}};


Vector2 robot(enum chess Chessboard[15][15], enum chess my_color, Vector2 last_location) {

    if(last_location.x == 100 || last_location.y == 100){
        return (Vector2){7,7};
    }

     alpha_beta_search(Chessboard, my_color, MAX_DEPTH, -INFINITY,INFINITY-1, last_location);
    return global.put_chess;

}



struct chess_chain get_chain(enum chess Chessboard[15][15], enum chess Friend_color,Vector2 put_chess, Vector2 direction) {
    struct chess_chain chain;
    int p=0,q=0;


    for(int i = 1;i <= 5;i++){
        int X = (int)put_chess.x + i*(int)direction.x;
        int Y = (int)put_chess.y + i*(int)direction.y;
        if(!(in_boundary(X) || in_boundary(Y))||
             Chessboard[X][Y] == Friend_color*-1){break;}
        p=i;
    }
    for(int i = 1;i <= 5;i++){
        int X = (int)put_chess.x - i*(int)direction.x;
        int Y = (int)put_chess.y - i*(int)direction.y;
        if(!(in_boundary(X) && in_boundary(Y))||
           Chessboard[X][Y] == Friend_color*-1){break;}
                q=i;
    }
    chain.c[0] = Friend_color*-1;
    int index = 1;
    chain.count = p+q+1;
    for(int i = 1-q;i<p;i++){
        int X = max((int)put_chess.x + i*(int)direction.x, 0);
        int Y = max((int)put_chess.y + i*(int)direction.y, 0);
        chain.c[index] = Chessboard[X][Y];
        index++;
    }
    chain.c[chain.count+1] = Friend_color*-1;

    return chain;

}

struct chess_chain put_temp(struct chess_chain input, int index){
    struct chess_chain temp;
    for(int i = 0;i<6;i++){
        temp.c[i]=input.c[i+index];
    }
    return temp;
}

int to_int(enum chess input, enum chess Friend_color){
    if(input == Friend_color) return 1;
    else if(input == Friend_color*-1) return 2;
    else return 0;
}

int get_key(struct chess_chain input, enum chess Friend_color){
   if(input.c[5] == Friend_color*-1) return (c(5)*32+c(4)*16+c(3)*8+c(2)*4+c(1)*2+c(0)*1);
    return (c(0)*32+c(1)*16+c(2)*8+c(3)*4+c(4)*2+c(5)*1);
}


int evaluate(enum chess *Chessboard[15][15], enum chess Friend_Color, Vector2 put_chess) {
    int count = 0;
    for(int X = max(put_chess.x - LEAF_SEARCH_RANGE, 0); X <= put_chess.x + LEAF_SEARCH_RANGE && in_boundary(X); X++){
        for(int Y = max(put_chess.y-LEAF_SEARCH_RANGE,0); Y <= put_chess.y + LEAF_SEARCH_RANGE && in_boundary(Y); Y++){

            for(int i = 0;i<4;i++){
                struct chess_chain friend_chain = get_chain(Chessboard, Friend_Color, (Vector2){X,Y}, direction[i]);
                if(friend_chain.count < 6){
                    count += 0;
                    continue;
                }
                for(int j = 0;j<=friend_chain.count-5;j++){
                    struct chess_chain temp = put_temp(friend_chain, j);
                    int key = get_key(temp, Friend_Color);
                    count += hashTable[key].value;
                }




                struct chess_chain enemy_chain = get_chain(Chessboard, Friend_Color*-1, (Vector2){X,Y}, direction[i]);
                if(enemy_chain.count < 6){
                    count -= 0;
                    continue;
                }
                for(int k = 0;k<=enemy_chain.count-5;k++){
                    struct chess_chain temp = put_temp(enemy_chain, k);
                    int key = get_key(temp ,Friend_Color*-1);
                    count -= hashTable[key].value;
                }
            }
        }
    }


//W????0???W
//count = 10
//i = 1~3

    return count;
}

int alpha_beta_search(enum chess Chessboard[15][15], enum chess Friend_color, int depth, int alpha, int beta,Vector2 put_chess) {

    if (depth == 0) {
        return evaluate(Chessboard, Friend_color, put_chess);
    }
    bool root = (depth == MAX_DEPTH);
    for (int X = max(put_chess.x - BRANCH_SEARCH_RANGE, 0); X <= put_chess.y + BRANCH_SEARCH_RANGE && in_boundary(X); X++) {
        for (int Y = max(put_chess.y - BRANCH_SEARCH_RANGE, 0); Y <= put_chess.y + BRANCH_SEARCH_RANGE && in_boundary(Y); Y++) {
            if (Chessboard[X][Y] == empty) {
                Chessboard[X][Y] = Friend_color;
                int value = alpha_beta_search(Chessboard, Friend_color, depth - 1, alpha, beta, (Vector2) {X, Y});

                Chessboard[X][Y] = empty;

                if (!(depth % 2)) {
                    if (value >= alpha) {
                        alpha = value;
                        if (root) {
                            printf("%d, %d, %d\n", X,Y, value);
                            global.put_chess.x = X;
                            global.put_chess.y = Y;
                        }
                    }
                } else {
                    if (value <= beta) {
                        beta = value;
                    }
                    if (alpha >= beta) {
                        break;
                    }
                }
            }

        }
    }
    return (!(depth % 2)) ? alpha : beta;
}

Vector2 Get_best_location(enum chess Chessboard[15][15], enum chess Friend_color, int depth, Vector2 Last_location){


    for(int X = max(Last_location.x - ROOT_SEARCH_RANGE, 0);X<=Last_location.x+ROOT_SEARCH_RANGE && in_boundary(X);X++){
        for(int Y = max(Last_location.y - ROOT_SEARCH_RANGE, 0);Y<=Last_location.y+ROOT_SEARCH_RANGE && in_boundary(Y);Y++){
            if(Chessboard[X][Y] == empty){
                alpha_beta_search(Chessboard, Friend_color,depth,1-(INFINITY), INFINITY-1, Last_location);
                return global.put_chess;
            }
        }
    }


}



#endif //C2023_CHALLENGE_CHESS_ROBOT_H
