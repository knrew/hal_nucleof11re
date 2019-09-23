#include "main.h"

#include "nucleof411re.hpp"

#include "core.hpp"

class Machine {
public:
    Machine() noexcept : board(), debug(board.debug) {}

    void Run() {
        while (true) {
//            debug << "poyo" << endl;
//            HAL_Delay(500);
        }
    }

    void OnTimer3Interrupt() {
        static auto s = HAL_GetTick();
        if (HAL_GetTick() - s < 1000) { return; }
        debug << "poyo | " << HAL_GetTick() - s << endl;
        s = HAL_GetTick();
    }

    void OnTimer4Interrupt() {
        static constexpr float step = 0.005;
        static float brightness = 0.f;
        static bool is_rising = true;
        if (is_rising) {
            if ((brightness += step) > 1.f) {
                brightness = 1.f;
                is_rising = !is_rising;
            }
        } else {
            if ((brightness -= step) < 0.f) {
                brightness = 0.f;
                is_rising = !is_rising;
            }
        }

        board.SetLedBrightness(brightness);
//        board.led.Toggle();
    }

    NucleoF411RE board;
    hal::Debug &debug;
} machine;

void Initialize(TIM_HandleTypeDef *const pwm_led_timer_handler) {
    machine.board.BindPWMLedTimerHandler(pwm_led_timer_handler);
}

void Core() {
    machine.Run();
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