#include "FakeTimeService.h"

static long int theMinute;
static int theDay;

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