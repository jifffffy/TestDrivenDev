#include "CppUTest/TestHarness.h"

extern "C"
{
#include "FakeTimeService.h"
}

TEST_GROUP(TimeService)
{
    void setup()
    {
        TimeService_Create();
    }

    void teardown()
    {
        TimeService_Destroy();
    }
};

TEST(TimeService, Create)
{
    //LONGS_EQUAL(-1, TimeService_GetMinute());
    //LONGS_EQUAL(-1, TimeService_GetDay());
}

TEST(TimeService, Set)
{
    FakeTimeService_SetMinute(42);
    //LONGS_EQUAL(42, TimeService_GetMinute());
    FakeTimeService_SetDay(3);
    //LONGS_EQUAL(3, TimeService_GetDay());
}
