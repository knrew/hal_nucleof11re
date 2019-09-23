#include "main.h"
#include "core.hpp"

#include "nucleof411re.hpp"

class Machine {
public:
    Machine() noexcept : board(), debug(board.debug) {}

    void run() {
        while (true) {
            debug << "poyo" << endl;
            HAL_Delay(500);
        }
    }

    void OnTimer3Interrupt() {
        static auto s = HAL_GetTick();
        debug << HAL_GetTick() - s << endl;
        s = HAL_GetTick();
    }

    void OnTimer4Interrupt() {
        board.led.Toggle();
    }

    NucleoF411RE board;
    hal::Debug &debug;
} machine;

void Core() {
    machine.run();
    while (true);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM3) {
        machine.OnTimer3Interrupt();
    }

    if (htim->Instance == TIM4) {
        machine.OnTimer4Interrupt();
    }
}