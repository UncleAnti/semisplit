cmake_minimum_required (VERSION 3.13)

project(SemiSplit)

find_package(fmt)

add_compile_options("-Wall" "-Wextra" "-pedantic" "-Werror" "-Wfatal-errors" "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>" )

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SemiSplit)
target_sources(SemiSplit PRIVATE main.cpp)
target_link_libraries(SemiSplit fmt::fmt)

install(TARGETS SemiSplit EXPORT semisplot DESTINATION bin)
