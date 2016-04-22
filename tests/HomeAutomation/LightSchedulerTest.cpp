#include "CppUTest/TestHarness.h"

extern "C"
{
#include "LightScheduler.h"
#include "LightControllerSpy.h"
#include "FakeTimeService.h"
}

TEST_GROUP(LightScheduler)
{
    int id;

    void setup()
    {
        LightController_Create();
        LightScheduler_Create();
    }

    //START: DestroyCancelsOneMinuteAlarm
    void teardown()
    {
        LightScheduler_Destroy();
//       POINTERS_EQUAL(NULL, (void *)FakeTimeSource_GetAlarmCallback());
    }
};

TEST(LightScheduler, CreateDoesNotChangeTheLights)
{
    LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
    LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}