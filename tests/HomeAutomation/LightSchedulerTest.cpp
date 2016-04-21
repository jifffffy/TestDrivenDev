#include "CppUTest/TestHarness.h"

extern "C"
{
    #include "LightControllerSpy.h"
    #include "FakeTimeService.h"
}

TEST_GROUP(LightScheduler)
{
    int id;

    void setup() {
        LightController_Create();
        LightScheduler_Create();
    }

    void teardown() {
        LightScheduler_Destroy();
        LightController_Destroy();
    }


};

TEST(LightScheduler, NoScheduleNothingHappens)
{
    FakeTimeService_SetDay(MONDAY);
    FakeTimeService_SetMinute(100);

    LightScheduler_Wakeup();

    LONGS_EQUAL(LIGHT_ID_UNKNOW, LightControllerSpy_GetLastId());
    LONGS_EQUAL(LIGHT_STATE_UNKNOW, LightControllerSpy_GetLastState());
}