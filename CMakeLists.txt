cmake_minimum_required(VERSION 3.20)

project(PixelSandbox)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/../SFML-2.6.2/lib/cmake/SFML")

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

add_executable(PixelSandbox
    src/main.cpp
    src/Game.cpp
    src/Player.cpp
    src/Tile.cpp
    src/World.cpp
    src/WorldGenerator.cpp
    src/Tree.cpp
    src/ItemEntity.cpp
    src/Inventory.cpp
    src/InventoryUI.cpp
)

target_link_libraries(PixelSandbox PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
)

add_custom_command(TARGET PixelSandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:PixelSandbox>/assets
)