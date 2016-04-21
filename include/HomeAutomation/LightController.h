#ifndef TESTDRIVENDEV_LIGHTCONTROLLER_H
#define TESTDRIVENDEV_LIGHTCONTROLLER_H
enum { MAX_LIGHTS = 32 };

void LightController_Create(void);
void LightController_Destroy(void);
void LightController_TurnOn(int id);
void LightController_TurnOff(int id);
void LightContorller_Wakeup(void);
#endif //TESTDRIVENDEV_LIGHTCONTROLLER_H
