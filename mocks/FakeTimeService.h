#ifndef TESTDRIVENDEV_FAKETIMESERVICE_H
#define TESTDRIVENDEV_FAKETIMESERVICE_H
#include "TimeService.h"

void FakeTimeService_SetMinute(int);
void FakeTimeService_SetDay(int);

WakeupCallback FakeTimeService_GetAlarmCallback(void);
int FakeTimeService_GetAlarmPeriod();
enum {MINUTE_UNKNOWN = -1, DAY_UNKNOWN = -1 };
#endif //TESTDRIVENDEV_FAKETIMESERVICE_H
