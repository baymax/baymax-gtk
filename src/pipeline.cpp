#include "pipeline.h"
#include "cmdparser.h"

#include <stdlib.h>

char * senderPipePath = "/tmp/baymax-sender";
const char *gtkPipePathInput = "/tmp/baymax-gtk";


int senderPipeFd;
int gtkPipeFd;

void openSenderPipe() {
    senderPipeFd = open(senderPipePath, O_WRONLY);
}

void closeSenderPipe() {
    close(senderPipeFd);
}

void openGtkPipe() {
    gtkPipeFd = open(gtkPipePathInput, O_RDONLY);
}

void closeGtkPipe() {
    close(gtkPipeFd);
}

void sendToSender(unsigned char cmd, unsigned char data) {
    char buff[16];
    snprintf(buff, 16, "%c%c", cmd, data);
    write(senderPipeFd, buff, sizeof(buff));
}

void* reader(void* data) {
	char buf[16];
	int bytesRead;
	while(1) {
		bytesRead = read(gtkPipeFd, buf, 16);
		if (bytesRead > 0) {
            parseCmd(buf);
		}
	}	
}