project(TestDrivenDev)

include_directories(${PROJECT_SOURCE_DIR}/../include)
include_directories(${PROJECT_SOURCE_DIR}/../include/LedDriver/)
include_directories(${PROJECT_SOURCE_DIR}/../include/HomeAutomation/)
include_directories(${PROJECT_SOURCE_DIR}/../include/util/)

add_library(LedDriver ./LedDriver/LedDriver.c)
add_library(LightScheduler ./HomeAutomation/LightScheduler.c)