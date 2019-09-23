#pragma once

#include "../stm32_wrapper/hal/include/led.hpp"
#include "../stm32_wrapper/hal/include/button.hpp"
#include "../stm32_wrapper/hal/include/debug.hpp"

#include "main.h"

struct NucleoF411RE {
public:
//    hal::Led led;
    hal::Button button;
    hal::Debug debug;

    void SetLedBrightness(const float percent) {
        if (pwm_led_timer_handler_ == nullptr) { return; }
        if (percent < 0.f) {
            __HAL_TIM_SET_COMPARE(pwm_led_timer_handler_, TIM_CHANNEL_1, 0);
        } else if (percent > 1.f) {
            __HAL_TIM_SET_COMPARE(pwm_led_timer_handler_, TIM_CHANNEL_1, 999);
        } else {
            __HAL_TIM_SET_COMPARE(pwm_led_timer_handler_, TIM_CHANNEL_1, static_cast<uint32_t>(percent * 999.f));
        }
    }

    void BindPWMLedTimerHandler(TIM_HandleTypeDef *const pwm_led_timer_handler) {
        pwm_led_timer_handler_ = pwm_led_timer_handler;
    }

    explicit NucleoF411RE(TIM_HandleTypeDef *const pwm_led_timer_handler = nullptr) noexcept:
//            led(LD2_GPIO_Port, LD2_Pin),
            button(B1_GPIO_Port, B1_Pin, true),
            debug(),
            pwm_led_timer_handler_(pwm_led_timer_handler) {}

private:
    TIM_HandleTypeDef *pwm_led_timer_handler_;
};