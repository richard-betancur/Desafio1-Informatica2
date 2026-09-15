cmake_minimum_required(VERSION 3.16)

project(Desafio1-Informatica2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Desafio1-Informatica2
    main.cpp
    bits.cpp
    bits.h
    tablero.cpp
    tablero.h
    combinaciones.cpp
    combinaciones.h
    juego.h
    juego.cpp
)

include(GNUInstallDirs)
install(TARGETS Desafio1-Informatica2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)