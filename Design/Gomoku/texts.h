//
// Created by Admin on 13/11/2023.
//

#ifndef C2023_CHALLENGE_TEXTS_H
#define C2023_CHALLENGE_TEXTS_H

#endif //C2023_CHALLENGE_TEXTS_H
enum status {
    NORMAL = 0,
    PLACE_ON_PREVIOUS_CHESS = 101,
};
enum game{
    GoingOn = 0,
    BlackWin = 1,
    WhiteWin = -1

};


void Print_win(enum game game_status){
    switch (game_status) {
        case BlackWin:
            DrawText("Black Win", 142, 230, 100, DARKGREEN);
            return ;

        case WhiteWin:
            DrawText("White Win", 142, 230, 100, DARKGREEN);
            return ;

        case GoingOn:
            return ;
    }
}

void draw_winning_line(int X, int Y, enum chess chess_color){
    Vector2 start_chess;
    Vector2 end_chess;
    Vector2 direction[4] = {{0, 1},{1, 0},{1,1},{-1, 1}};


    for(int i = 0; i < 4; i++){
        int dir = 1;
        int steps = 1;
        int count_on_dir = 1;
        while((chessboard[(int)(X + dir*steps*(int)(direction[i].x))]
               [(int)(Y + dir*steps*(int)(direction[i].y))] == chess_color)
              && (X + dir*steps*(int)(direction[i].x) >= 0) &&  (X + dir*steps*(int)(direction[i].x) <= 14)
              &&  (Y + dir*steps*(int)(direction[i].y) >= 0) &&  (Y + dir*steps*(int)(direction[i].y) <= 14))
        {
            steps++;count_on_dir++;
        }
        start_chess.x = (float)(X + dir*(steps-1)*(int)(direction[i].x));
        start_chess.y = (float)(Y + dir*(steps-1)*(int)(direction[i].y));
        dir *= -1;
        steps = 1;
        while((chessboard[(int)(X + dir*steps*(int)(direction[i].x))]
               [(int)(Y + dir*steps*(int)(direction[i].y))] == chess_color)
              && (X + dir*steps*(int)(direction[i].x) >= 0) &&  (X + dir*steps*(int)(direction[i].x) <= 14)
              &&  (Y + dir*steps*(int)(direction[i].y) >= 0) &&  (Y + dir*steps*(int)(direction[i].y) <= 14))
        {
            steps++;count_on_dir++;
        }
        end_chess.x = (float)(X + dir*(steps-1)*(int)(direction[i].x));
        end_chess.y = (float)(Y + dir*(steps-1)*(int)(direction[i].y));

        if(count_on_dir >= 5){
            DrawLineEx(
                    //direction[i].x * 10
                    //direction[i].y
                    (Vector2){25 + (start_chess.x) * 50+ direction[i].x * 21,25 + (start_chess.y) * 50 + direction[i].y * 21},
                    (Vector2){25 + (end_chess.x) * 50 -  direction[i].x * 21,25 + (end_chess.y) * 50 - direction[i].y * 21},
                    5,GREEN );
            return;
        }

    }


}