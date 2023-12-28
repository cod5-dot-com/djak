#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <signal.h>

#ifdef __SUBC__
#define var int
#else
#define var long
#endif
#define STR(s) ((var)(s + 2))
#define NEW(c) var __this; \
	__this = std__alloc(c##___DsizeD); \
	((var*)__this)[-1] = c##___DcidD

var main__main(void);
var std__free(var mem);

