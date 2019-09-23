#include "main.h"
#include "core.hpp"

#include "nucleof411re.hpp"

auto board = NucleoF411RE();
auto &debug = board.debug;

void Core() {
    while (true) {}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM3) {
        static auto s = HAL_GetTick();
        debug << HAL_GetTick() - s << endl;
        s = HAL_GetTick();
    }

    if (htim->Instance == TIM4) {
        board.led.Toggle();
    }
}