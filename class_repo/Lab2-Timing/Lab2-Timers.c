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
    //SetupTimer0();

   // SetupTimer0();         // initialize timer zero functionality
    //GlobalInterruptEnable(); // Enable Global Interrupts for USB and Timer etc.


    while (true){
        Time_t loopStart = GetTime();
        //USB_Echo_Task();
        USB_Upkeep_Task();
        Message_Handling_Task();




        if( MSG_FLAG_Execute( &mf_restart ) ){
            //re initialzie your stuff...
            USB_SetupHardware();
            GlobalInterruptEnable();
            Message_Handling_Init();
            //SetupTimer0();
        }
        if( MSG_FLAG_Execute( &mf_send_time ) ){
            float time = mf_send_time.last_trigger_time.millisec + (mf_send_time.last_trigger_time.microsec/1000);
           // usb_send_msg("ccf",mf_send_time->cmd, time, sizeof(time));
        }

        if( MSG_FLAG_Execute( &mf_time_float_send ) ){
            Time_t start_float_time = GetTime();
            float f = 2.223;
            //float f_time = SecondsSince(start_float_time);
           // usb_send_msg("ccf",mf_time_float_send->cmd,f_time,sizeof(f_time));
        }
        if( MSG_FLAG_Execute( &mf_time_float_send ) ){
            //  float loop_time = SecondsSince(loopStart);
            //  usb_send_msg("ccf", mf_loop_timer->cmd );
        }

    }
    // baseline above.


        //USB_Upkeep_Task();
        //Message_Handling_Task();
        // baby steps of main.
        // have the robot send the time once.
        // 1. have the robot send the time each second.
        // 2. toggle ledevery few ms with the interrupt ( might show as dim)
        // 3. time how long a loop takes.
        //Time_t test = GetTime();

        //usb_send_data(&test,48);
/*
        if (MSG_FLAG_Execute(&mf_restart))// TODO add desired timer
        {
            //re initialzie your stuff...
           // SetupTimer0();
            USB_SetupHardware();
            GlobalInterruptEnable();
            Message_Handling_Init();
        }*/


        return 0;
    }