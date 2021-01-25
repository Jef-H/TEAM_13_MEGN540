#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include "stdint.h"

#define RB_LENGTH_F 8  // must be a power of 2. This is an easy place to adjust
#define RB_LENGTH_C 16  // must be a power of 2. This is an easy place to adjust


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
   poorly defined if inedex is outside of active length.
   Use of the push_back or push_front methods are prefered.
*/
void  rb_set_F( struct Ring_Buffer_F* p_buf, uint8_t index, float value);
void  rb_set_C( struct Ring_Buffer_C* p_buf, uint8_t index, char value);

#endif