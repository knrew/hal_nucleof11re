#pragma once

#include "../stm32_wrapper/hal/include/led.hpp"
#include "../stm32_wrapper/hal/include/button.hpp"
#include "../stm32_wrapper/hal/include/debug.hpp"

#include "main.h"

struct NucleoF411RE {
public:
    hal::Led led;
    hal::Button button;
    hal::Debug debug;

    NucleoF411RE() noexcept:
            led(LD2_GPIO_Port, LD2_Pin),
            button(B1_GPIO_Port, B1_Pin, true),
            debug() {}
};