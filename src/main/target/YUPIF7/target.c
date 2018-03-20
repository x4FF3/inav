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
#include "drivers/timer.h"
#include "drivers/pwm_mapping.h"
#include "drivers/bus.h"

const timerHardware_t timerHardware[USABLE_TIMER_CHANNEL_COUNT] = {
    { TIM8,  IO_TAG(PC8),  TIM_CHANNEL_3, 0, IOCFG_AF_PP, GPIO_AF3_TIM8, TIM_USE_PPM }, 									// PPM IN
    { TIM2,  IO_TAG(PA0),  TIM_CHANNEL_1, 1, IOCFG_AF_PP_PD, GPIO_AF1_TIM2, TIM_USE_MC_MOTOR | TIM_USE_FW_MOTOR }, 					// S1_OUT
    { TIM5,  IO_TAG(PA1),  TIM_CHANNEL_2, 1, IOCFG_AF_PP_PD, GPIO_AF2_TIM5, TIM_USE_MC_MOTOR | TIM_USE_FW_MOTOR }, 					// S2_OUT
    { TIM2,  IO_TAG(PA2),  TIM_CHANNEL_3, 1, IOCFG_AF_PP_PD, GPIO_AF1_TIM2, TIM_USE_MC_MOTOR | TIM_USE_FW_SERVO }, 					// S3_OUT
    { TIM2,  IO_TAG(PA3),  TIM_CHANNEL_4, 1, IOCFG_AF_PP_PD, GPIO_AF1_TIM2, TIM_USE_MC_MOTOR | TIM_USE_FW_SERVO }, 					// S4_OUT
    { TIM3,  IO_TAG(PB0),  TIM_CHANNEL_3, 1, IOCFG_AF_PP_PD, GPIO_AF2_TIM3, TIM_USE_MC_MOTOR | TIM_USE_MC_SERVO | TIM_USE_FW_SERVO }, 			// S5_OUT
    { TIM3,  IO_TAG(PB1),  TIM_CHANNEL_4, 1, IOCFG_AF_PP_PD, GPIO_AF2_TIM3, TIM_USE_MC_MOTOR | TIM_USE_MC_SERVO | TIM_USE_FW_SERVO | TIM_USE_LED }, 	// S6_OUT
    { TIM2,  IO_TAG(PB7),  TIM_CHANNEL_2, 1, IOCFG_AF_PP_PD, GPIO_AF2_TIM4, TIM_USE_ANY }, 								// ANY
    { TIM2,  IO_TAG(PB14), TIM_CHANNEL_1, 1, IOCFG_AF_PP_PD, GPIO_AF1_TIM2, TIM_USE_BEEPER }, 								// BEEPER PWM
};
