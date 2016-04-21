#ifndef TESTDRIVENDEV_FAKETIMESERVICE_H
#define TESTDRIVENDEV_FAKETIMESERVICE_H
#include "TimeService.h"

void FakeTimeService_SetMinute(int);
void FakeTimeService_SetDay(int);

void TimeService_Create(void);
void TimeService_Destroy(void);

enum {MINUTE_UNKNOWN = -1, DAY_UNKNOWN = -1 };
#endif //TESTDRIVENDEV_FAKETIMESERVICE_H
