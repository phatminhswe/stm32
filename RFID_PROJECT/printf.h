#ifndef __PRINTF__
#define __PRINTF__

#include "stdarg.h"
#include "stdint.h"
typedef enum{
    HEX = 1,
    DEC
}Ascci;
	void print(uint8_t * string,Ascci ascci);
	void println(uint8_t * string,Ascci ascci);
#endif