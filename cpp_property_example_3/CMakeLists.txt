cmake_minimum_required(VERSION 3.14.0)

project(helloworld LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS Core)
find_package(Qt6 COMPONENTS Gui)

add_executable(cpp_property_example_3 main.cpp)

target_link_libraries(cpp_property_example_3 PUBLIC Qt::Core Qt::Gui)
