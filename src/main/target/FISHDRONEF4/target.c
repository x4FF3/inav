/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>

#include <platform.h>
#include "drivers/io.h"
#include "drivers/pwm_mapping.h"
#include "drivers/timer.h"

const timerHardware_t timerHardware[] = {
    { TIM5,  IO_TAG(PA0),  TIM_Channel_1, 0, IOCFG_AF_PP , GPIO_AF_TIM5,    TIM_USE_PPM | TIM_USE_PWM }, // S1_IN(PPM)
    { TIM5,  IO_TAG(PA1),  TIM_Channel_2, 0, IOCFG_AF_PP , GPIO_AF_TIM5,    TIM_USE_PWM }, // S2_IN
    { TIM3,  IO_TAG(PB0),  TIM_Channel_3, 0, IOCFG_AF_PP , GPIO_AF_TIM3,    TIM_USE_PWM }, // S3_IN
    { TIM2,  IO_TAG(PB10), TIM_Channel_3, 0, IOCFG_AF_PP , GPIO_AF_TIM2,    TIM_USE_PWM }, // S4_IN
    { TIM2,  IO_TAG(PB11), TIM_Channel_4, 0, IOCFG_AF_PP , GPIO_AF_TIM2,    TIM_USE_PWM }, // S5_IN
    { TIM1,  IO_TAG(PA8),  TIM_Channel_1, 0, IOCFG_AF_PP , GPIO_AF_TIM1,    TIM_USE_PWM }, // S6_IN

    { TIM12, IO_TAG(PB14), TIM_Channel_1, 1, IOCFG_AF_PP, GPIO_AF_TIM12,    TIM_USE_MC_MOTOR |                    TIM_USE_FW_MOTOR },// S1_OUT
    { TIM12, IO_TAG(PB15), TIM_Channel_2, 1, IOCFG_AF_PP, GPIO_AF_TIM12,    TIM_USE_MC_MOTOR |                    TIM_USE_FW_MOTOR },// S2_OUT
    { TIM8,  IO_TAG(PC6),  TIM_Channel_1, 1, IOCFG_AF_PP, GPIO_AF_TIM8,     TIM_USE_MC_MOTOR |                    TIM_USE_FW_SERVO }, // S3_OUT
    { TIM8,  IO_TAG(PC7),  TIM_Channel_2, 1, IOCFG_AF_PP, GPIO_AF_TIM8,     TIM_USE_MC_MOTOR |                    TIM_USE_FW_SERVO }, // S4_OUT
    { TIM8,  IO_TAG(PC8),  TIM_Channel_3, 1, IOCFG_AF_PP, GPIO_AF_TIM8,     TIM_USE_MC_MOTOR |                    TIM_USE_FW_SERVO }, // S5_OUT
    { TIM8,  IO_TAG(PC9),  TIM_Channel_4, 1, IOCFG_AF_PP, GPIO_AF_TIM8,     TIM_USE_MC_MOTOR |                    TIM_USE_FW_SERVO }, // S6_OUT

    { TIM3,  IO_TAG(PB1),  TIM_Channel_4, 1, IOCFG_AF_PP , GPIO_AF_TIM3,    TIM_USE_LED }, // LED_STRIP
};

const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);
