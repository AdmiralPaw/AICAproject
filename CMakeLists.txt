cmake_minimum_required(VERSION 3.24)
project (AICAproject)

set(CMAKE_CXX_STANDARD 20)

add_executable(AICAproject
        main.cpp
        Base/Settings.cpp
        Base/Settings.h
        Base/Interfaces/Algorithm.cpp
        Base/Interfaces/Algorithm.h
        Data/Interfaces/Table.cpp
        Data/Interfaces/Table.h
        Data/CompressData.cpp
        Data/CompressData.h
        Data/Implementations/TableImpl_0.cpp
        Data/Implementations/TableImpl_0.h
        Utils/Utils.cpp
        Utils/Utils.h
        Base/Implementations/AlgorithmImpl_0.cpp
        Base/Implementations/AlgorithmImpl_0.h
        )
