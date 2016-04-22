#ifndef TESTDRIVENDEV_LIGHTCONTROLLER_H
#define TESTDRIVENDEV_LIGHTCONTROLLER_H
enum { MAX_LIGHTS = 32 };

void LightController_Create(void);
void LightController_Destroy(void);
void LightController_On(int id);
void LightController_Off(int id);
void LightContorller_Wakeup(void);
#endif //TESTDRIVENDEV_LIGHTCONTROLLER_H
