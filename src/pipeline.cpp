#include "pipeline.h"


void sendCommandToSender(int32_t cmd) {
    char * pipePath = "/tmp/baymax-sender";
    mkfifo(pipePath, 0666);
    int fd = open(pipePath, O_WRONLY);
    char buff[35];
    snprintf(buff, 35, "%d", cmd);
    write(fd, buff, sizeof(buff));
}
