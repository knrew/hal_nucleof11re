#include "main.h"
#include "core.hpp"

#include "../stm32_wrapper/hal/include/led.hpp"
#include "../stm32_wrapper/hal/include/button.hpp"
#include "../stm32_wrapper/hal/include/debug.hpp"

void core() {
    auto led = hal::Led(LD2_GPIO_Port, LD2_Pin);
    auto button = hal::Button(B1_GPIO_Port, B1_Pin, true);
    auto debug = hal::Debug();

    while (1) {
        led.Toggle();
        if (button.IsPushed()) { debug << "poyo" << endl; }
        
        debug << 11.4514f << endl;

        HAL_Delay(500);
    }
}
