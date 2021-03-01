/*
         MEGN540 Mechatronics Lab
    Copyright (C) Andrew Petruska, 2021.
       apetruska [at] mines [dot] edu
          www.mechanical.mines.edu
*/

/*
    Copyright (c) 2021 Andrew Petruska at Colorado School of Mines

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.

*/

#include "../c_lib/SerialIO.h"
#include "../c_lib/Timing.h"
#include "../c_lib/MEGN540_MessageHandeling.h"


/** Main program entry point. This routine configures the hardware required by the application, then
 *  enters a loop to run the application tasks in sequence.
 */
int main(void) {

    USB_SetupHardware();
    GlobalInterruptEnable();
    Message_Handling_Init();

    SetupTimer0();         // initialize timer zero functionality

    while (true){

        USB_Upkeep_Task();
        Message_Handling_Task();

        Time_t loopStart = GetTime();

        if( MSG_FLAG_Execute( &mf_restart ) ){
            //re initialzie your stuff...
            USB_SetupHardware();
            GlobalInterruptEnable();
            Message_Handling_Init();
        }

        if( MSG_FLAG_Execute( &mf_send_time ) ) {

            mf_send_time.last_trigger_time = GetTime();
            float sendTime = (mf_send_time.last_trigger_time.millisec / 1000.0);
            usb_send_msg("cf", '0', &sendTime, sizeof(sendTime));
            if(mf_send_time.duration < 0.0) {
           mf_send_time.active = false;
    }
        }

        if( MSG_FLAG_Execute( &mf_time_float_send ) ){

            mf_time_float_send.last_trigger_time.millisec = GetMilli();
            float floatTest = 0.000001;
            usb_send_msg("cf", '1', &floatTest, sizeof(floatTest));
            float floatTime = SecondsSince(&mf_time_float_send.last_trigger_time.millisec);
            usb_send_msg("cf", '1', &floatTime, sizeof(floatTime));

            if(mf_time_float_send.duration < 0.0) {
                mf_time_float_send.active = false;
            }

        }
        if( MSG_FLAG_Execute( &mf_loop_timer ) ){
            mf_loop_timer.last_trigger_time = GetTime();
            float loop_time = SecondsSince(&loopStart);
            usb_send_msg("cf", '2', &loop_time, sizeof(loop_time));
            if(mf_loop_timer.duration < 0.0) {
            mf_loop_timer.active = false;
}

        }

    }
        return 0;
    }