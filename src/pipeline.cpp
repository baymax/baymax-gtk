#include "pipeline.h"
#include "cmdparser.h"

char * uiPipePath = "/tmp/baymax-ui";
char * senderPipePath = "/tmp/baymax-sender";

void sendSender(unsigned char cmd, unsigned char data) {   
    mkfifo(senderPipePath, 0666);
    int fd = open(senderPipePath, O_WRONLY);
    char buff[35];
    snprintf(buff, 35, "%c%c", cmd, data);
    write(fd, buff, sizeof(buff));
}

gpointer readUi(gpointer user_data) {
    int fd;
    char buf[35] = "0";
    fd = open(uiPipePath, O_RDONLY);
    unsigned char cmd;
    unsigned char data;
    while(1) {
        read(fd, buf, 35);
        if (buf[0] != '0') {
            cmd = buf[0];
            data = buf[1];
            parseCmd(cmd, data);
            printf("Received: %c\n", buf[0]);
            snprintf(buf, 35, "%s", "0");            
        } 
    }
    return (NULL);
}