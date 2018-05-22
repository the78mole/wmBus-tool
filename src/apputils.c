#include "apputils.h"

void Colour(int8_t c, bool cr) {
    printf("%c[%dm",0x1B,(c>0) ? (30+c) : c);
    if(cr)
        printf("\n");
}

static struct termios orig_term_attr;
// Save current stdin setting for later restore
void saveStdin() {
    /* Make sure stdin is a terminal. */
    if (!isatty (STDIN_FILENO)) {
      fprintf (stderr, "Not a terminal.\n");
      exit (EXIT_FAILURE);
    }

    /* set the terminal to raw mode */
    tcgetattr(fileno(stdin), &orig_term_attr);
}

// Restore stdin on exit
void restoreStdin(void) {
    /* restore the original terminal attributes */
    tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);
}

// setup the stdin stream to read a character without blocking
void setupStdin(void) {
    struct termios new_term_attr;

    tcgetattr(fileno(stdin), &new_term_attr);
    new_term_attr.c_lflag &= ~(ECHO|ICANON);
    new_term_attr.c_cc[VTIME] = 0;
    new_term_attr.c_cc[VMIN]  = 0;
    tcsetattr(fileno(stdin), TCSANOW, &new_term_attr);
}

// By default, stdout is line buffered, stderr is none buffered and file is completely buffered.
// Make stdout unbuffered which allows to output partial lines
void setupStdout(void) {
    setbuf(stdout, NULL); // stdout is restored on program exit automatically
}

void intHandler(int signal) {
    exit(1); // calls exit handler which is set by atexit()
}

// setup the stdin stream to read a character without blocking
void setupConsole(void) {
    saveStdin();
    setupStdin();
    setupStdout();
    atexit(restoreStdin); // setup callback to restore console on exit

    // Register a signal handel which catch CTRL-C which stops the program and restore the console

    if(signal(SIGINT, intHandler) == SIG_ERR) {
        printf("SIGINT handler could not be established. Aborting!");
        exit(1);
    }
    // struct sigaction act;
    // act.sa_handler = intHandler;
    // sigaction(SIGINT, &act, NULL);
}

// Returns EOF (-1) if no character is available
signed char getkey(void) {
    char character = -1;
    if (read (STDIN_FILENO, &character, 1) <= 0)
        character = -1;
    return character;
}

// Return true when something different from only '\n' has been enterred
bool getLine(char* inputBuf, int inputBufSize) {
    restoreStdin();
    (void)fgets(inputBuf, inputBufSize, stdin);
    setupStdin();
    return inputBuf[0] != '\n';
}

static int iTime;
static int iMinute;

int IsNewSecond(int iS) {
    int CurTime;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    CurTime = tm.tm_hour*60*60+tm.tm_min*60+tm.tm_sec;
    if (iS > 0)
        CurTime = CurTime/iS;

    if (CurTime != iTime) {
        iTime = CurTime;
        return 1;
    }
    return 0;
}

int IsNewMinute(void) {
    int CurTime;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    CurTime = tm.tm_hour*60+tm.tm_min;

    if (CurTime != iMinute) {
        iMinute = CurTime;
        return 1;
    }
    return 0;
}

void ErrorAndExit(const char *info) {
    Colour(PRINTF_RED, false);
    printf("%s", info);
    Colour(0, true);
    exit(0);
}

/*
unsigned int CalcUIntBCD(  unsigned int ident) {
    int32_t identNumBCD=0;
    #define MAXIDENTLEN 12
    uint8_t  identchar[MAXIDENTLEN];
    memset(identchar,0,MAXIDENTLEN*sizeof(uint8_t));
    sprintf((char *)identchar, "%08d", ident);
    uint32_t uiMul = 1;
    uint8_t  uiX   = 0;
    uint8_t  uiLen = strlen((char const*)identchar);

    for(uiX=0; uiX < uiLen;uiX++) {
        identNumBCD += (identchar[uiLen-1-uiX] - '0')*uiMul;
        uiMul = uiMul*16;
    }
    return identNumBCD;
}
*/