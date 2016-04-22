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
} ScheduledLightEvent;

static ScheduledLightEvent scheduledLightEvent;

static void scheduleEvent(int id, Day day, int minuteOfDay , int event)
{
    scheduledLightEvent.id = id;
    scheduledLightEvent.event = event;
    scheduledLightEvent.minuteOfDay = minuteOfDay;
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

    if(lightEvent->minuteOfDay != time->minuteOfDay)
        return;

    operateLight(lightEvent);
}

void LightScheduler_Create(void)
{
    scheduledLightEvent.id = UNUSED;
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