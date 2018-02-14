cmake_minimum_required(VERSION 3.8)
project(ex2)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES chess.cpp Board.cpp Board.h Piece.cpp Piece.h Queen.cpp Queen.h Rook.cpp Rook.h Knight.cpp Knight.h Bishop.cpp Bishop.h Pawn.cpp Pawn.h King.cpp King.h)
add_executable(ex2 ${SOURCE_FILES})