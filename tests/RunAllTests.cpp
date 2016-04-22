#include "CppUTest/CommandLineTestRunner.h"

IMPORT_TEST_GROUP(LedDriver);
IMPORT_TEST_GROUP(TimeService);
IMPORT_TEST_GROUP(LightController);
IMPORT_TEST_GROUP(LightScheduler);
IMPORT_TEST_GROUP(LightSchedulerInitAndCleanup);

int main(int argc, char** argv)
{
    return RUN_ALL_TESTS(argc, argv);
}