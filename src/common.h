//
// BCM2835 Rebol extension
// ====================================
// Use on your own risc!

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "rebol-extension.h"


//#define USE_TRACES
#ifdef  USE_TRACES
//#include <stdio.h>
#define debug_print(fmt, ...) do { printf(fmt, __VA_ARGS__); } while (0)
#define trace(str) puts(str)
#else
#define debug_print(fmt, ...)
#define trace(str) 
#endif
