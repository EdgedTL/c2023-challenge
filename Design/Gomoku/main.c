#include "Includes.h"

#define Humans_turn if(Gesture == GESTURE_TAP){X = (int)(touchPosition.x / 50);Y = (int)(touchPosition.y / 50);if(chessboard[X][Y] == 0){chessboard[X][Y] = (enum chess)turn;push_node(chess_timeline, steps, X, Y, (enum chess)turn);turn*=-1;steps++;}else{error = PLACE_ON_PREVIOUS_CHESS;}}
#define Robots_turn robot_location = robot(chessboard, (enum chess)turn);X = (int)robot_location.x;Y = (int)robot_location.y;chessboard[X][Y] = (enum chess)turn;push_node(chess_timeline, steps, X, Y, (enum chess)turn);turn*=-1;steps++;


enum turn_t {
    black_turn = 1, white_turn = -1
};
enum robot_human {
    ROBOT = 1, HUMAN = -1, null = 0
};

int pos(int input) {
    int temp;
    temp = 25 + (input) * 50;
    return temp;
}

void DrawCross(int X, int Y, int radius, int width, Color color) {
    Vector2 Startpos1 = {X - radius, Y - radius};
    Vector2 Endpos1 = {X + radius, Y + radius};
    Vector2 Startpos2 = {X + radius, Y - radius};
    Vector2 Endpos2 = {X - radius, Y + radius};

    DrawLineEx(Startpos1, Endpos1, width, color);
    DrawLineEx(Startpos2, Endpos2, width, color);
}


int relation;

void main() {

    const int screenWidth = 752, screenHeight = 752;
    bool Exit,CHOSE_HUMAN,CHOSE_ROBOT;
    int X, Y,steps,Gesture;
    enum game Current_Status = GoingOn;
    enum turn_t turn = black_turn;//black first
    enum robot_human RobotHumanTurn;
    Vector2 cursor_position,robot_location;
    InitWindow(screenWidth, screenHeight, "Gomoku");
    Vector2 touchPosition;
    enum status error;
    static Rectangle
    touchArea = {1, 1, screenWidth - 2, screenHeight - 2},
    Robot_first = {51, 320, 300, 75},
    Human_first = {401, 320, 300, 75},
    Continue_Button = {225, 400, 300, 75},
    End_Button = {225, 500, 300, 75};
    SetTargetFPS(60);
    //Define variables


    Start:
    /**************************
    *   Initialise variables  *
    **************************/
    zero_matrix();
    error = NORMAL;
    touchPosition = (Vector2){0, 0};
    node_t *chess_timeline = (node_t*) malloc(sizeof(node_t) * 255);
    chess_timeline[0].x = 100;
    chess_timeline[0].y = 100;
    chess_timeline[0].chess = empty;
    Gesture = GESTURE_NONE;
    steps = 1;
    Current_Status = GoingOn;
    turn = black_turn;//black first
    CHOSE_ROBOT = false;CHOSE_HUMAN = false;Exit = false;
    RobotHumanTurn = null;




    //Main loop
    while (!Exit) {
        /*************************************
        *   Numeral calculations and logics  *
        *************************************/
        error = NORMAL;
        Gesture = GetGestureDetected();
        touchPosition = GetTouchPosition(0);
        if (RobotHumanTurn == null) {
            if (Gesture == GESTURE_TAP) {
                if (CheckCollisionPointRec(touchPosition, Robot_first)) {
                    RobotHumanTurn = ROBOT;
                    relation = 1;
                    CHOSE_ROBOT = true;
                } else if (CheckCollisionPointRec(touchPosition, Human_first)) {
                    RobotHumanTurn = HUMAN;
                    relation = -1;
                    CHOSE_HUMAN = true;
                }
                goto Draw_directly;
            } else goto Draw_directly;

        }//choose sides
        if(Current_Status){
            if (Gesture == GESTURE_TAP) {
                if (CheckCollisionPointRec(touchPosition, Continue_Button)) {
                    Exit = false;
                    free(chess_timeline);
                    goto Start;
                } else if (CheckCollisionPointRec(touchPosition, End_Button)) {
                    Exit = true;
                }
            }goto Draw_directly;
        } //Ending logic




        if ((enum robot_human) turn * relation == ROBOT) {
            robot_location = robot(chessboard, (enum chess)turn, (Vector2){chess_timeline[steps-2].x, chess_timeline[steps-2].y});
            X = (int)robot_location.x;
            Y = (int)robot_location.y;
            chessboard[X][Y] = (enum chess)turn;
            push_node(chess_timeline, steps, X, Y, (enum chess)turn);turn*=-1;steps++;
        } else if ((enum robot_human) turn * relation == HUMAN) {
            Humans_turn;
        }
        //Human's turn or robot's turn

        Current_Status = determinine_win(X, Y, (enum chess) (turn * -1));


        /**************************************
        *  Printing chessboards and statuses  *
         *************************************/

        Draw_directly:
        BeginDrawing();
        DrawRectangleRec(touchArea, WHITE);
        for (int i = 0; i < 15; i++) {
            DrawLine(25 + i * 50, 25, 25 + i * 50, 725, BLACK);
        }
        for (int i = 0; i < 15; i++) {
            DrawLine(25, 25 + i * 50, 725, 25 + i * 50, BLACK);
        }
        ClearBackground(WHITE);
        for (int i = 0; i < steps - 1; ++i) {
            cursor_position.x = pos(chess_timeline[i].x);
            cursor_position.y = pos(chess_timeline[i].y);
            switch (chessboard[chess_timeline[i].x][chess_timeline[i].y]) {
                case black:
                    DrawCircleV(cursor_position, 21, BLACK);
                    break;
                case white:
                    DrawCircleV(cursor_position, 21, BLACK);
                    DrawCircleV(cursor_position, 20, WHITE);
                    break;
                case empty:
                    break;
            }
        }

        if (RobotHumanTurn == null) {
            DrawText("Choose your side", 110, 230, 60, DARKGRAY);
            DrawRectangleRec(Robot_first, GRAY);
            DrawText("Robot First", 53, 340, 50, BLACK);
            DrawRectangleRec(Human_first, GRAY);
            DrawText("Human First", 401, 340, 50, BLACK);
        }
        if (CHOSE_ROBOT) {
            DrawRectangleRec(Robot_first, WHITE);
            DrawText("robot turn", 53, 340, 50, WHITE);
            CHOSE_ROBOT = false;
        }
        if (CHOSE_HUMAN) {
            DrawRectangleRec(Human_first, WHITE);
            DrawText("Human First", 401, 340, 50, WHITE);
            CHOSE_HUMAN = false;
        }

        switch (error) {
            case NORMAL:
                break;
            case PLACE_ON_PREVIOUS_CHESS:
                DrawCross(pos(X), pos(Y), 15, 6, RED);
                break;
        }


        draw_winning_line(X,Y,(enum chess)(turn*-1));
        Print_win(Current_Status);

        if(abs(Current_Status)){
            DrawRectangleRec(Continue_Button, GRAY);
            DrawText("Continue", 267, 415, 50, BLACK);
            DrawRectangleRec(End_Button, GRAY);
            DrawText("End", 330, 515, 50, BLACK);
        }



        EndDrawing();
    }
    //system("pause");

}
