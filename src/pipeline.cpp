#include "pipeline.h"
#include "cmdparser.h"

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
    char buff[10];
    snprintf(buff, 10, "%c%c", cmd, data);
    write(senderPipeFd, buff, sizeof(buff));
}

void* reader(void* data) {
    unsigned char cmd;
    unsigned char value;
	char buf[100];
	int bytesRead;
	while(1) {
		bytesRead = read(gtkPipeFd, buf, 100);
		if (bytesRead > 0) {
            //asda
		    cmd = buf[0];
            value = buf[1];
            printf("Reviced %d komento %d arvolla\n", cmd, value);
            fflush(stdout);
            parseCmd(cmd, value);
		}
	}	
}

gpointer readUi(gpointer user_data) {
    unsigned char cmd;
    unsigned char data;
    char buf[100];
    int bytesRead;
    printf("Reader thread started\n");
	while(1) {
        if (gtkPipeFd > -1) {
		    bytesRead = read(gtkPipeFd, buf, 100);
            //printf("Readed %d\n", bytesRead);
		    if (bytesRead > 0) {
			    printf("Reviced");
                cmd = buf[0];
                data = buf[1];
                parseCmd(cmd, data);
		    }
        } else {
            printf("Putki on kuollut");
        }
	}
    
    /*while(1) {
        //read(senderPipeFd, buf, 10);
        bytesRead = scanf("%s", buf);
        if (bytesRead > 0) {
            //printf("reviced %d", buf);
            
            cmd = buf[0];
            data = buf[1];
            printf("komento %d arvolla %d", cmd, data);
            fflush(stdout);
            parseCmd(cmd, data);
        }
    }*/
    return (NULL);
}