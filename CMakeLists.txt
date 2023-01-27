
cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

project(j_cassette)

include_directories(src)

# Create and import the library targets


file(GLOB SOURCES "src/*.c")
add_executable(j_cassette ${SOURCES})

target_include_directories(j_cassette PUBLIC include)

pico_generate_pio_header(j_cassette ${CMAKE_CURRENT_LIST_DIR}/src/pio/i2s.pio)
pico_generate_pio_header(j_cassette ${CMAKE_CURRENT_LIST_DIR}/src/pio/st7789v2.pio)

# Use the pico_stdlib
target_link_libraries(j_cassette pico_stdlib)

# Create the map, bin, hex files, etc
pico_add_extra_outputs(j_cassette)
