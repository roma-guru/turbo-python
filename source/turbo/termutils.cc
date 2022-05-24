#include <stdio.h>
#include <string.h>
#include <termios.h>

void wait_key() {
    struct termios orig_termios, new_termios;
    tcgetattr(0, &orig_termios);
    memcpy(&new_termios, &orig_termios, sizeof(new_termios));
    cfmakeraw(&new_termios);
    tcsetattr(0, TCSANOW, &new_termios);

    printf("Please press any key to continue\n");
    getchar();
    tcsetattr(0, TCSANOW, &orig_termios);
}
