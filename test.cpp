//
// Created by Jeff Hinton on 2/7/21.
//

#include "test.h"


#include  "modulo.h"
#include  "ringBufS.h"
int ringBufS_get (ringBufS *_this){
    int c;    if (_this->count>0)
    {      c           = _this->buf[_this->tail];
    _this->tail = modulo_inc (_this->tail, RBUF_SIZE);
    --_this->count;
    }    else    {      c = -1;    }    return (c);}
