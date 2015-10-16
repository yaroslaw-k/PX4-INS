/****************************************************************************
 *
 *   Copyright (c) 2012-2015 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file px4_diff_app.c
 * Minimal application example for PX4 autopilot
 *
 * @author Example User <mail@example.com>
 */

#include <px4_config.h>
#include <unistd.h>
#include <stdio.h>
#include <poll.h>
#include <string.h>
#include <stm32.h>


#include <uORB/uORB.h>
#include <uORB/topics/sensor_combined.h>
#include <uORB/topics/vehicle_attitude.h>

__EXPORT int px4_diff_app_main(int argc, char *argv[]);
//__EXPORT  int ch_one(void);
//__EXPORT  int ch_two(void);


//#define GPIO_ENC_IN1      (GPIO_INPUT|GPIO_PULLUP|GPIO_PORTC|GPIO_PIN3)
//#define GPIO_ENC_IN2       (GPIO_INPUT|GPIO_PULLUP|GPIO_PORTC|GPIO_PIN4)
#define GPIO_ENC_IN1 (GPIO_INPUT | GPIO_PULLUP | GPIO_EXTI | GPIO_PORTC | GPIO_PIN2)
#define GPIO_ENC_IN2 (GPIO_INPUT | GPIO_PULLUP | GPIO_EXTI | GPIO_PORTC | GPIO_PIN3)

static int ch_one(void){
    printf("port 1 trigger\n");
    return 0;

}


static int ch_two(void){
    printf("port 2 trigger\n");
    return 0;

}

int px4_diff_app_main(int argc, char *argv[])
{
   // stm32_configgpio(GPIO_ENC_IN1);
   // stm32_configgpio(GPIO_ENC_IN2);

    stm32_gpiosetevent(GPIO_ENC_IN1, true, false, false, (xcpt_t)ch_one);
    stm32_gpiosetevent(GPIO_ENC_IN2, true, false, false, (xcpt_t)ch_two);



    printf("Test App\n");



	return 0;
}
