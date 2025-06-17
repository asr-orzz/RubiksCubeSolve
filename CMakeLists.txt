cmake_minimum_required(VERSION 3.28)
project(RUbiks)

set(CMAKE_CXX_STANDARD 17)

add_executable(RUbiks main.cpp
        Models/genericRubiksCube.cpp
        Models/genericRubiksCube.h
        Models/RubiksCube3darray.cpp
        Models/RubiksCube1darray.cpp
        Models/RubiksCubeBitboard.cpp
        Solver/DFSSOLVER.h
        Solver/BFSSOLVER.h
        Solver/IDDFSSolver.h
        Solver/IDAstarSOLVER.h
        PatternDatabases/NibbleArray.h
        PatternDatabases/NibbleArray.cpp
        PatternDatabases/PatternDatabase.h
        PatternDatabases/PatternDatabase.cpp
)
