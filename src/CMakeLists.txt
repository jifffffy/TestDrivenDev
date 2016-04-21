project(TestDrivenDev)

include_directories(${PROJECT_SOURCE_DIR}/../include)
include_directories(${PROJECT_SOURCE_DIR}/../include/LedDriver/)

add_library(LedDriver ./LedDriver/LedDriver.c)