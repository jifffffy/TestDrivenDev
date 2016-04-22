#include "FakeTimeService.h"

static long int theMinute;
static int theDay;

static WakeupCallback callback;
static int period;

void FakeTimeService_SetMinute(int minute)
{
    theMinute = minute;
};

void FakeTimeService_SetDay(int day)
{
    theDay = day;
};

void TimeService_Create(void)
{
    theMinute = MINUTE_UNKNOWN;
    theDay = DAY_UNKNOWN;
};
void TimeService_Destroy(void)
{

};



void TimeService_GetTime(Time * time)
{
    time ->minuteOfDay = theMinute;
    time ->dayOfWeek = theDay;
};

int TimeService_GetMinute(void)
{
    return theMinute;
};
int TimeService_GetDay(void)
{
    return theDay;
};


void TimeService_SetPeriodicAlarmInSeconds(int seconds, WakeupCallback cb)
{
    callback = cb;
    period = seconds;

};
void TimeService_CancelPeriodicAlarmInSeconds(int seconds, WakeupCallback cb)
{
    if(cb == callback && period == seconds)
    {
        callback = NULL;
        period = 0;
    }
};

WakeupCallback FakeTimeService_GetAlarmCallback(void)
{
    return callback;
};

int FakeTimeService_GetAlarmPeriod()
{
    return period;
};