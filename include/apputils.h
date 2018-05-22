#ifndef APPUTILS_H
#define APPUTILS_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>

#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <ctype.h>

#include "wmbusext.h"

//App defines
#define MAXMETER 16

#define AES_KEYLENGTH           128
#define AES_KEYLENGHT_BYTES     ( AES_KEYLENGTH / 16 )

//colorcoding
#define PRINTF_BRIGHT  1
#define PRINTF_BLACK   0
#define PRINTF_RED     1
#define PRINTF_GREEN   2
#define PRINTF_YELLOW  3
#define PRINTF_BLUE    4
#define PRINTF_MAGENTA 5
#define PRINTF_CYAN    6
#define PRINTF_WHITE   7


void Colour(int8_t c, bool cr);

static struct termios orig_term_attr;
// Save current stdin setting for later restore
void saveStdin();

// Restore stdin on exit
void restoreStdin(void);

// setup the stdin stream to read a character without blocking
void setupStdin(void);

// By default, stdout is line buffered, stderr is none buffered and file is completely buffered.
// Make stdout unbuffered which allows to output partial lines
void setupStdout(void);
void intHandler(int signal);

// setup the stdin stream to read a character without blocking
void setupConsole(void);

// Returns EOF (-1) if no character is available
signed char getkey(void);

// Return true when something different from only '\n' has been enterred
bool getLine(char* inputBuf, int inputBufSize);
static int iTime;
static int iMinute;

int IsNewSecond(int iS);
int IsNewMinute(void);
void ErrorAndExit(const char *info);
unsigned int CalcUIntBCD(  unsigned int ident);
//void UpdateMetersonStick(unsigned long handle, uint16_t stick, 
//    int iMax, pecwMBUSMeter ecpiwwMeter, uint16_t infoflag);

#endif //APPUTILS_H