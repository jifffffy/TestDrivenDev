#ifndef TESTDRIVENDEV_LIGHTCONTROLLERSPY_H
#define TESTDRIVENDEV_LIGHTCONTROLLERSPY_H

#include "LightController.h"

enum {LIGHT_ID_UNKNOW = -1, LIGHT_STATE_UNKNOW = -1 , LIGHT_OFF = 0, LIGHT_ON = 1};

int LightControllerSpy_GetLastId(void);
int LightControllerSpy_GetLastState(void);
#endif //TESTDRIVENDEV_LIGHTCONTROLLERSPY_H
