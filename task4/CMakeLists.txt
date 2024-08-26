cmake_minimum_required(VERSION 3.16)
set (PROJECT_NAME task4)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DSFML_STATIC)
include_directories("SFML/include")
include_directories("inc")
include_directories("src")
link_directories("SFML/lib")

add_executable(main.cpp src/Game.cpp src/Circle.cpp src/Rectangle.cpp src/Triangle.cpp src/Line.cpp)
target_link_libraries("${PROJECT_NAME}" sfml-graphics-s-d
        sfml-window-s-d
        sfml-system-s-d
        opengl32
        freetype
        winmm
        gdi32
        sfml-audio-s-d
        openal32
        flac
        vorbisenc
        vorbisfile
        vorbis
        ogg)