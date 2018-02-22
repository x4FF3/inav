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
#include "drivers/bus.h"

const timerHardware_t timerHardware[USABLE_TIMER_CHANNEL_COUNT] = {
#if defined(OMNIBUSF4PRO) || defined(OMNIBUSF4V3)
    { TIM10, IO_TAG(PB8),  TIM_Channel_1, 0, IOCFG_AF_PP_PD, GPIO_AF_TIM10, TIM_USE_PPM }, // PPM
    { TIM4,  IO_TAG(PB9),  TIM_Channel_4, 0, IOCFG_AF_PP_PD, GPIO_AF_TIM4,  TIM_USE_ANY }, // S2_IN
#else
    { TIM12, IO_TAG(PB14), TIM_Channel_1, 0, IOCFG_AF_PP_PD, GPIO_AF_TIM12, TIM_USE_PPM }, // PPM / S.BUS input, above MOTOR1
    { TIM12, IO_TAG(PB15), TIM_Channel_2, 0, IOCFG_AF_PP_PD, GPIO_AF_TIM12, TIM_USE_ANY }, // Connected: small CH2 pad, not used as PWM, definition inherited from REVO target - GPIO_PartialRemap_TIM3
#endif
    { TIM8,  IO_TAG(PC6),  TIM_Channel_1, 0, IOCFG_AF_PP_PD, GPIO_AF_TIM8, TIM_USE_ANY }, // Connected: UART6 TX, not used as PWM, definition inherited from REVO target
    { TIM8,  IO_TAG(PC7),  TIM_Channel_2, 0, IOCFG_AF_PP_PD, GPIO_AF_TIM8, TIM_USE_ANY }, // Connected: UART6 RX, not used as PWM, definition inherited from REVO target
    { TIM8,  IO_TAG(PC8),  TIM_Channel_3, 0, IOCFG_AF_PP_PD, GPIO_AF_TIM8, TIM_USE_ANY }, // Connected: small CH5 pad, not used as PWM, definition inherited from REVO target
    { TIM8,  IO_TAG(PC9),  TIM_Channel_4, 0, IOCFG_AF_PP_PD, GPIO_AF_TIM8, TIM_USE_ANY }, // Connected: small CH6 pad, not used as PWM, definition inherited from REVO target
    { TIM3,  IO_TAG(PB0),  TIM_Channel_3, 1, IOCFG_AF_PP_PD, GPIO_AF_TIM3, TIM_USE_MC_MOTOR                    | TIM_USE_FW_MOTOR }, // MOTOR_1
    { TIM3,  IO_TAG(PB1),  TIM_Channel_4, 1, IOCFG_AF_PP_PD, GPIO_AF_TIM3, TIM_USE_MC_MOTOR                    | TIM_USE_FW_MOTOR }, // MOTOR_2
    { TIM9,  IO_TAG(PA3),  TIM_Channel_2, 1, IOCFG_AF_PP_PD, GPIO_AF_TIM9, TIM_USE_MC_MOTOR                    | TIM_USE_FW_SERVO }, // MOTOR_3
    { TIM2,  IO_TAG(PA2),  TIM_Channel_3, 1, IOCFG_AF_PP_PD, GPIO_AF_TIM2, TIM_USE_MC_MOTOR                    | TIM_USE_FW_SERVO }, // MOTOR_4
#if (defined(OMNIBUSF4PRO) || defined(OMNIBUSF4V3)) && !defined(OMNIBUSF4PRO_LEDSTRIPM5)
    { TIM5,  IO_TAG(PA1),  TIM_Channel_2, 1, IOCFG_AF_PP_PD, GPIO_AF_TIM5, TIM_USE_MC_MOTOR | TIM_USE_MC_SERVO | TIM_USE_FW_SERVO }, // MOTOR_5
    { TIM4,  IO_TAG(PB6),  TIM_Channel_1, 1, IOCFG_AF_PP_PD, GPIO_AF_TIM4, TIM_USE_LED                                            }, // LED strip for F4 V2 / F4-Pro-0X and later
#else
    { TIM5,  IO_TAG(PA1),  TIM_Channel_2, 1, IOCFG_AF_PP_PD, GPIO_AF_TIM5, TIM_USE_MC_MOTOR | TIM_USE_MC_SERVO | TIM_USE_FW_SERVO }, // MOTOR_5
#endif
    { TIM1,  IO_TAG(PA8),  TIM_Channel_1, 1, IOCFG_AF_PP_PD, GPIO_AF_TIM1, TIM_USE_MC_MOTOR | TIM_USE_MC_SERVO | TIM_USE_FW_SERVO }, // MOTOR_6
};
