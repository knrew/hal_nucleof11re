#include "main.h"
#include "core.hpp"

#include "../stm32_wrapper/hal/include/led.hpp"
#include "../stm32_wrapper/hal/include/button.hpp"
#include "../stm32_wrapper/hal/include/debug.hpp"

auto led = hal::Led(LD2_GPIO_Port, LD2_Pin);
auto button = hal::Button(B1_GPIO_Port, B1_Pin, true);
auto debug = hal::Debug();

void Core() {
    while (true) {}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM3) {
        static auto s = HAL_GetTick();
        printf("%ld\r\n", HAL_GetTick() - s);
        s = HAL_GetTick();
    }

    if (htim->Instance == TIM4) {
        led.Toggle();
    }

}