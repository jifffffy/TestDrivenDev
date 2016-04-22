#include <util/TimeService.h>
#include "LightScheduler.h"
#include "LightController.h"

enum
{
    TURN_ON, TURN_OFF, DIM, RANDOM_ON, RANDOM_OFF
};

enum
{
    MAX_EVENTS = 128, UNUSED = -1
};

typedef struct
{
    int id;
    int minuteOfDay;
    int event;
    Day day;
} ScheduledLightEvent;

static ScheduledLightEvent scheduledLightEvent;


static void scheduleEvent(int id, Day day, int minuteOfDay , int event)
{
    scheduledLightEvent.id = id;
    scheduledLightEvent.event = event;
    scheduledLightEvent.minuteOfDay = minuteOfDay;
    scheduledLightEvent.day = day;
}

static int DoesLightRespondToday(Time * time, int reactionDay)
{
    int today = time->dayOfWeek;

    if(reactionDay == EVERYDAY)
        return TRUE;

    if(reactionDay == today)
        return TRUE;

    if(reactionDay ==WEEKEND && (SATURDAY == today || SUNDAY == today))
        return TRUE;

    if(reactionDay ==WEEKEND && today >= MONDAY && today <+FRIDAY)
        return TRUE;

    return FALSE;

}

static void operateLight(ScheduledLightEvent * lightEvent)
{
    if(lightEvent->event == TURN_ON)
        LightController_On(lightEvent->id);

    if(lightEvent->event == TURN_OFF)
        LightController_Off(lightEvent->id);
}

static void processEventDueNow(Time * time, ScheduledLightEvent * lightEvent)
{
    if(lightEvent->id == UNUSED)
        return;

    if(!DoesLightRespondToday(time, lightEvent->day))
        return;

    if(lightEvent->minuteOfDay != time->minuteOfDay)
        return;

    operateLight(lightEvent);
}

void LightScheduler_Create(void)
{
    scheduledLightEvent.id = UNUSED;

    TimeService_SetPeriodicAlarmInSeconds(60, LightScheduler_WakeUp);
};
void LightScheduler_Destroy(void)
{

};
void LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay)
{
    scheduleEvent(id, day, minuteOfDay, TURN_ON);
};
void LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay)
{
    scheduleEvent(id, day, minuteOfDay, TURN_OFF);

};
void LightScheduler_Randomize(int id, Day day, int minuteOfDay)
{

};
void LightScheduler_ScheduleRemove(int id, Day day, int minuteOfDay)
{

};
void LightScheduler_WakeUp(void)
{
    Time time;
    TimeService_GetTime(&time);

    processEventDueNow(&time, &scheduledLightEvent);

};