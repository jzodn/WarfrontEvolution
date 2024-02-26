cmake_minimum_required(VERSION 3.16)
project(WarfrontEvolution)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 17)

# Set the source directory
set(SOURCE_DIR src)

# Set the include directory
set(INCLUDE_DIR include)

# Set the SFML include directory
set(SFML_INCLUDE_DIR C:/dev/SFML-2.6.1/include)

# Set the library directory
set(LIB_DIR C:/dev/SFML-2.6.1/lib)

# Set the binary directory
set(BIN_DIR C:/dev/SFML-2.6.1/bin)

# Add source files to the project
add_executable(WarfrontEvolution ${SOURCE_DIR}/main.cpp)

# Link SFML libraries
target_link_directories(WarfrontEvolution PUBLIC ${LIB_DIR})
target_link_libraries(WarfrontEvolution PUBLIC
    sfml-graphics-d.lib
    sfml-window-d.lib
    sfml-system-d.lib
    sfml-audio-d.lib
)

# Include directories
include_directories(${INCLUDE_DIR} ${SFML_INCLUDE_DIR})

# Copy DLLs to the build directory
add_custom_command(TARGET WarfrontEvolution POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${BIN_DIR}
        $<TARGET_FILE_DIR:WarfrontEvolution>
)

# Set compile_commands.json
set(DCMAKE_EXPORT_COMPILE_COMMANDS ON)

