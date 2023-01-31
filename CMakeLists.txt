
cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)

project(j_cassette)

pico_sdk_init()

# Import 20 years of aging 
include_directories(src)

# Create and import the library targets

file(GLOB SOURCES "src/*.c")
add_executable(j_cassette ${SOURCES})

target_include_directories(j_cassette PUBLIC include)
target_link_libraries(j_cassette PRIVATE
    pico_stdlib
    hardware_pio 
    hardware_i2c
)

pico_generate_pio_header(j_cassette ${CMAKE_CURRENT_LIST_DIR}/src/pio/i2s.pio)
pico_generate_pio_header(j_cassette ${CMAKE_CURRENT_LIST_DIR}/src/pio/st7789v2.pio)

# Create the map, bin, hex files, etc
# pico_add_extra_outputs(j_cassette)
