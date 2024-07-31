cmake_minimum_required(VERSION 3.20)
project(Questions)

# SRC is the name of variable
#set(SRC question_5.cpp)

# search resource
#aux_source_directory(${PROJECT_SOURCE_DIR} SRC)

# search resource
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
# set 
#set(EXECUTABLE_OUTPUT_PATH /home/jswqzx/Linux_Study/Lession4)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(app ${SRC})