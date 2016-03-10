#include "pipeline.h"


void sendSender(unsigned char cmd, unsigned char data) {
    char * pipePath = "/tmp/baymax-sender";
    mkfifo(pipePath, 0666);
    int fd = open(pipePath, O_WRONLY);
    char buff[3];
    snprintf(buff, 35, "%c%c", cmd, data);
    write(fd, buff, sizeof(buff));
}
