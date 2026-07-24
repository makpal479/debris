cmake_minimum_required(VERSION 3.20)

project(PixelSandbox)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/../SFML-2.6.2/lib/cmake/SFML")

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

add_executable(PixelSandbox
    src/main.cpp
)

target_link_libraries(PixelSandbox PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
)

add_custom_command(TARGET PixelSandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}/../SFML-2.6.2/bin/sfml-graphics-d-2.dll>$<$<NOT:$<CONFIG:Debug>>:${CMAKE_SOURCE_DIR}/../SFML-2.6.2/bin/sfml-graphics-2.dll>"
        "$<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}/../SFML-2.6.2/bin/sfml-window-d-2.dll>$<$<NOT:$<CONFIG:Debug>>:${CMAKE_SOURCE_DIR}/../SFML-2.6.2/bin/sfml-window-2.dll>"
        "$<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}/../SFML-2.6.2/bin/sfml-system-d-2.dll>$<$<NOT:$<CONFIG:Debug>>:${CMAKE_SOURCE_DIR}/../SFML-2.6.2/bin/sfml-system-2.dll>"
        $<TARGET_FILE_DIR:PixelSandbox>
)