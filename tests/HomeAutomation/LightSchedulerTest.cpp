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

void setTimeTo(int day, int minuteOfDay)
{
    FakeTimeService_SetDay(day);
    FakeTimeService_SetMinute(minuteOfDay);
}

void checkLightState(int id, int level)
{
    LONGS_EQUAL(id, LightControllerSpy_GetLastId());
    LONGS_EQUAL(level, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, CreateDoesNotChangeTheLights)
{
    LONGS_EQUAL(LIGHT_ID_UNKNOW, LightControllerSpy_GetLastId());
    LONGS_EQUAL(LIGHT_STATE_UNKNOW, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, NoChangeToLightsDuringInitialization)
{
    LONGS_EQUAL(LIGHT_ID_UNKNOW, LightControllerSpy_GetLastId());
    LONGS_EQUAL(LIGHT_STATE_UNKNOW, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, NoScheduleNothingHappens)
{
    FakeTimeService_SetDay(MONDAY);
    FakeTimeService_SetMinute(100);

    LightScheduler_WakeUp();
    LONGS_EQUAL(LIGHT_ID_UNKNOW, LightControllerSpy_GetLastId());
    LONGS_EQUAL(LIGHT_STATE_UNKNOW, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, SecheduleOnEverydayNotTimeYet)
{
    LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
    FakeTimeService_SetDay(MONDAY);
    FakeTimeService_SetMinute(1199);

    LightScheduler_WakeUp();

    LONGS_EQUAL(LIGHT_ID_UNKNOW, LightControllerSpy_GetLastId());
    LONGS_EQUAL(LIGHT_STATE_UNKNOW, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, ScheduleOnEverydayItsTime)
{
    LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
    FakeTimeService_SetMinute(1200);
    FakeTimeService_SetDay(MONDAY);
    LightScheduler_WakeUp();
    LONGS_EQUAL(3, LightControllerSpy_GetLastId());
    LONGS_EQUAL(LIGHT_ON, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, ScheduleTurnOffEverydayItsTime)
{
    LightScheduler_ScheduleTurnOff(3, EVERYDAY, 1200);
    setTimeTo(MONDAY, 1200);

    LightScheduler_WakeUp();

    checkLightState(3, LIGHT_OFF);

}

