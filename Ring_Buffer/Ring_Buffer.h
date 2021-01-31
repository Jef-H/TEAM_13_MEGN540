/* Ring_Buffer_MEGN540.h
 *
 * This set of functions enables a ringbuffer for both float and char data types.
 * A ring buffer allows constant data addition and removal in a fixed size array.
 * The ring buffer will overwrite existing elements of the array if more data is
 * added than there is adequate space. This works well for a First in First Out
 * or Last in First Out type queue.
 *
 * Functions implemented are as follows (where X is either F or C to denote float or char):
 *
 * Ring_Buffer_X    <-- The internal data structure for the ringbuffer object
 * rb_print_data_X  <-- Prints debugging information to the terminal assist with code generation and capabilities
 * rb_initialize_X  <-- Initializes the ring buffer for use.
 * rb_length_X      <-- Returns the number of active elements in the ringbuffer
 * rb_push_back_X   <-- Appends an element to the end of the buffer
 * rb_push_front_X  <-- Appends an element to the start of the buffer
 * rb_pop_back_X    <-- Remojoshves and returns the last element
 * rb_pop_front_X   <-- Removes and returns the first element
 * rb_get_X         <-- Returns an desired element from within the buffer
 * rb_set_X         <-- Sets a desired element within the buffer
 *
 * Code Skeleton provided by Dr Petruska for MEGN 540, Mechatronics
 * Code Details Provided by:  [ YOUR NAME ]
 * Code Last Modified:  1/15/2021
 * */

#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include "stdint.h" // for uint8_t type

#define RB_LENGTH_F 8  // must be a power of 2 (max of 256). This is an easy place to adjust max expected length
#define RB_LENGTH_C 16  // must be a power of 2 (max of 256). This is an easy place to adjust max expected length

// data structure for a float ring buffer 
struct Ring_Buffer_F
{
    float buffer[RB_LENGTH_F];
    uint8_t start_index;
    uint8_t end_index;
};

// data structure for a char ring buffer
struct Ring_Buffer_C
{
    char buffer[RB_LENGTH_C];
    uint8_t start_index;
    uint8_t end_index;
};

// Debugging Assistant Functions (these are already written for you)
void rb_print_data_F(struct Ring_Buffer_F *p_buf);
void rb_print_data_C(struct Ring_Buffer_C *p_buf);


/****** Functions   **********/

/* Initialization */
void rb_initialize_F( struct Ring_Buffer_F* p_buf );
void rb_initialize_C( struct Ring_Buffer_C* p_buf );

/* Return active Length of Buffer */
uint8_t rb_length_F( const struct Ring_Buffer_F* p_buf);
uint8_t rb_length_C( const struct Ring_Buffer_C* p_buf);

/* Append element to end and lengthen */
void rb_push_back_F( struct Ring_Buffer_F* p_buf, float value);
void rb_push_back_C( struct Ring_Buffer_C* p_buf, char value);

/* Append element to front and lengthen */
void rb_push_front_F( struct Ring_Buffer_F* p_buf, float value);
void rb_push_front_C( struct Ring_Buffer_C* p_buf, char value);

/* Remove element from end and shorten */
float rb_pop_back_F( struct Ring_Buffer_F* p_buf);
char  rb_pop_back_C( struct Ring_Buffer_C* p_buf);

/* Remove element from start and shorten */
float rb_pop_front_F( struct Ring_Buffer_F* p_buf);
char  rb_pop_front_C( struct Ring_Buffer_C* p_buf);

/* access element */
float rb_get_F( const struct Ring_Buffer_F* p_buf, uint8_t index);
char  rb_get_C( const struct Ring_Buffer_C* p_buf, uint8_t index);

/* set element - This behavior is 
   poorly defined if index is outside of active length.
   Use of the push_back or push_front methods are preferred.
*/
void  rb_set_F( struct Ring_Buffer_F* p_buf, uint8_t index, float value);
void  rb_set_C( struct Ring_Buffer_C* p_buf, uint8_t index, char value);


#endif