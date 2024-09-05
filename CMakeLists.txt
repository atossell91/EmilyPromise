CMAKE_MINIMUM_REQUIRED(VERSION 3.11.2)

project(EmilyPromise)

set (SRC ${CMAKE_SOURCE_DIR}/src)
set (INCLUDE ${CMAKE_SOURCE_DIR}/include)

include_directories(
    ${INCLUDE}
)

add_executable(EmilyPromise
    ${SRC}/main.cpp
    #ADD_CPP - DO NOT MODIFY THIS LINE
)

#target_link_libraries(EmilyPromise
#    ${DEPS}/name/build/libVica.so
#)
