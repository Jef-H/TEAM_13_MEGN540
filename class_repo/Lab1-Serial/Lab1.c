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
#include "../c_lib/MEGN540_MessageHandeling.h"

void usb_read_next_byte()
/*Takes the next USB byte and reads it into a ring buffer for latter processing. If there is none waiting,
 * it returns without blocking.void usb_write_next_byte()Takes the next byte from an output ring buffer and writes it
 * to the usb port. If there is none waiting, it returns without blocking. */


 void usb_send_char(char)//takes a character and appends it to the output ring buffer
 void usb_send_data(void*, uint8_t) //Takes a pointer to a buffer (everything can be void *) and the length of the
 // buffer (hint use sizeof to help) and puts into the output ring buffer
 void usb_send_str(char*) //Puts a null-terminated c-string into the output ring buffer to send.
 uint8_t usb_msg_length() //Returns the number of bytes in the receive buffer
 uint8_t usb_msg_get() //Removes and Returns the next byte in the receive buffer
 uint8_t usb_msg_peek() //Returns the next byte in the receive buffer but does not remove it.






/** Main program entry point. This routine configures the hardware required by the application, then
 *  enters a loop to run the application tasks in sequence.
 */





int main(void)
{
    USB_SetupHardware();
    GlobalInterruptEnable();
    Message_Handling_Init(); // initialize message handling

    while( !mf_restart.active )
    {
        USB_Upkeep_Task();

        USB_Echo_Task();// you'll want to remove this once you get your serial sorted
        Message_Handling_Task();

        // Below here you'll process state-machine flags.

    }
}
