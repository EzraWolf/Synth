
cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)

project(j_cassette)
pico_sdk_init()

# Import 20 years of aging
# include_directories(src)

# Create and import the library targets
# file(GLOB SOURCES src/main.c)

# Broken but still could work?
# file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")

# These **may** cause annoying "undefined reference to main" errors...
file(GLOB SOURCES src/*.c)
file(GLOB SOURCES src/display/*.c)
file(GLOB SOURCES src/display/screens*.c)
file(GLOB SOURCES src/interface/*.c)

add_executable(j_cassette ${SOURCES})
# add_executable(j_cassette
#     src/display/screens/effects.c
#     src/display/screens/filter.c
#     src/display/screens/home.c
#     src/display/screens/osc.c
#     src/display/font.c
#     src/display/gfx.c
#     src/interface/PCA9555.c
#     src/interface/PCM5102.c
#     src/interface/ST7789V2.c
#     src/interface/W25Q16.c
#     src/keys.c
#     src/main.c
#     src/oscillator.c
# )

pico_generate_pio_header(j_cassette ${CMAKE_CURRENT_LIST_DIR}/src/pio/PCM5102.pio  OUTPUT_DIR include/pio)
pico_generate_pio_header(j_cassette ${CMAKE_CURRENT_LIST_DIR}/src/pio/ST7789V2.pio OUTPUT_DIR include/pio)
# pico_generate_pio_header(j_cassette pio/PCM5102.pio)
# pico_generate_pio_header(j_cassette pio/ST7789V2.pio)

target_sources(j_cassette PRIVATE src/main.c)

target_include_directories(j_cassette PUBLIC include)
target_link_libraries(j_cassette PRIVATE
    pico_stdlib
    hardware_pio 
    hardware_i2c
)

# Create the the UF2 and HEX files
pico_add_extra_outputs(j_cassette)
