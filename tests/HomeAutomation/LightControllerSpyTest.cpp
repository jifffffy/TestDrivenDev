#include "CppUTest/TestHarness.h"

extern "C"
{
#include "LightControllerSpy.h"
}

TEST_GROUP(LightController)
{
    void setup()
    {
        LightController_Create();
    }

    void teardown()
    {
        LightController_Destroy();
    }
};

TEST(LightController, Create)
{
    LONGS_EQUAL(LIGHT_ID_UNKNOW, LightControllerSpy_GetLastId());
    LONGS_EQUAL(LIGHT_STATE_UNKNOW, LightControllerSpy_GetLastState());
}

TEST(LightController, RememberTheLastLightIdControlled)
{
    LightController_On(10);
    LONGS_EQUAL(10, LightControllerSpy_GetLastId());
    LONGS_EQUAL(LIGHT_ON, LightControllerSpy_GetLastState());
}

