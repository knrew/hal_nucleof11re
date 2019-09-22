#include <string>
#include "main.h"
#include "core.hpp"

#include "../stm32_wrapper/hal/include/led.hpp"
#include "../stm32_wrapper/hal/include/button.hpp"
#include "../stm32_wrapper/hal/include/debug.hpp"

void core() {
    auto led = hal::Led(LD2_GPIO_Port, LD2_Pin);
    auto button = hal::Button(B1_GPIO_Port, B1_Pin, true);
//    auto debug = hal::Debug(huart);

    char buf[20];
    setbuf(stdout, NULL);
    while (1) {
        led.Toggle();
        if (button.IsPushed()) { printf("poyo\r\n"); }

        printf("%f\r\n", 11.4514f);

        HAL_Delay(500);
    }
}
