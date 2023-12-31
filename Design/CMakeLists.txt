project(Design)

find_package(raylib 4.0 REQUIRED)


add_executable(Gomoku Gomoku/main.c
        Gomoku/chessboard.h
        Gomoku/texts.h
        Gomoku/WinCondition.h
        Gomoku/Includes.h
        Gomoku/chess_robot.h
        Gomoku/special_chess_types.h
        Gomoku/hashtable.h
)


target_link_libraries(Gomoku raylib)