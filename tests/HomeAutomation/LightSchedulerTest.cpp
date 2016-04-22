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
    setTimeTo(MONDAY, 1200);
    LightScheduler_WakeUp();
    checkLightState(3, LIGHT_ON);
}

TEST(LightScheduler, ScheduleTurnOffEverydayItsTime)
{
    LightScheduler_ScheduleTurnOff(3, EVERYDAY, 1200);
    setTimeTo(MONDAY, 1200);

    LightScheduler_WakeUp();

    checkLightState(3, LIGHT_OFF);

}

TEST(LightScheduler, ScheduleTuesdayButItsMonday)
{
    LightScheduler_ScheduleTurnOn(3, TUESDAY, 1200);
    setTimeTo(MONDAY, 1200);
    LightScheduler_WakeUp();
    checkLightState(LIGHT_ID_UNKNOW, LIGHT_STATE_UNKNOW);
}

TEST(LightScheduler, ScheduleTuesdayAndItsTuesday)
{
    LightScheduler_ScheduleTurnOn(3, TUESDAY, 1200);
    setTimeTo(TUESDAY, 1200);
    LightScheduler_WakeUp();
    checkLightState(3, LIGHT_ON);
}

TEST(LightScheduler, ScheduleWeekEndItsFriday)
{
    LightScheduler_ScheduleTurnOn(3, WEEKEND, 1200);
    setTimeTo(FRIDAY, 1200);
    LightScheduler_WakeUp();

    checkLightState(LIGHT_ID_UNKNOW, LIGHT_STATE_UNKNOW);
}

TEST(LightScheduler, ScheduleWeekEndItsSaturday)
{
    LightScheduler_ScheduleTurnOn(3, WEEKEND, 1200);
    setTimeTo(SATURDAY, 1200);
    LightScheduler_WakeUp();
    checkLightState(3, LIGHT_ON);
}

TEST_GROUP(LightSchedulerInitAndCleanup)
{

};
TEST(LightSchedulerInitAndCleanup, CreateStartsOneMinuteAlarm)
{
    LightScheduler_Create();
    POINTERS_EQUAL((void *)LightScheduler_WakeUp, (void *)FakeTimeService_GetAlarmCallback());
    LONGS_EQUAL(60, FakeTimeService_GetAlarmPeriod());
    LightScheduler_Destroy();
}

TEST(LightSchedulerInitAndCleanup, DestoryCancelOneMinuteAlarm)
{
    LightScheduler_Create();
    LightScheduler_Destroy();
    POINTERS_EQUAL(NULL, (void *)FakeTimeService_GetAlarmCallback());
}

