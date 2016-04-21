project (TestDrivenDev)

include_directories(${PROJECT_SOURCE_DIR}/../include)
include_directories(${PROJECT_SOURCE_DIR}/../include/HomeAutomation)
include_directories(${PROJECT_SOURCE_DIR}/../include/util)

add_library(RuntimeErrorStub RuntimeErrorStub.c)
add_library(FakeTimeService FakeTimeService.c)
add_library(LightControllerSpc LightControllerSpc.c)