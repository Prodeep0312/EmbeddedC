#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>


#define RED 0
#define GREEN 1
#define AMBER 2

typedef struct {
    long mtype;
    int state;
    int counter;
    int button_pressed;
} TrafficSignalData;

int msqid;

void send_message(int signal_color) {
    TrafficSignalData message;
    message.mtype = 1;
    message.state = signal_color;
    message.button_pressed = 1; 

    msgsnd(msqid, &message, sizeof(TrafficSignalData) - sizeof(long), 0);
}

int main() {
    key_t mq_key=0x5544aabb;

  
    if ((msqid = msgget(mq_key,IPC_CREAT|0777) )< 0) {
        perror("msgget");
        exit(1);
    }

    while (1) {
        printf("Traffic Signal Controller Menu:\n");
        printf("1. Press 'G' for Green\n");
        printf("2. Press 'R' for Red\n");
        printf("3. Press 'A' for Amber\n");
        printf("4. Quit\n");

        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case 'G':
                send_message(GREEN);
                break;
            case 'R':
                send_message(RED);
                break;
            case 'A':
                send_message(AMBER);
                break;
            case '4':
                
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    

    return 0;
}

