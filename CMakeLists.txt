cmake_minimum_required(VERSION 3.15)
project(GoFish)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GoFish
        card.h
        card_demo.cpp
        deck.h
        player.h)
