#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define KEY 1234
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

void display_details(TrafficSignalData *signal_data) {
    const char *colors[] = {"Red", "Green", "Amber"};
    printf("Current Signal Light: %s\tCount down Time: %d \n", colors[signal_data->state], signal_data->counter);
}

void display_countdown(int seconds) {
    printf("Changing signal in %d seconds...\n", seconds);
    for (int i = seconds; i >=0; --i) {
        printf("%d seconds\n", i);
        sleep(1);
    }
    printf("Signal changed\n");
}

void change_to_amber(TrafficSignalData *signal_data) {
    signal_data->state = AMBER;
    signal_data->counter = 20; 
    signal_data->button_pressed = 0;
    display_countdown(10);
}

void change_to_red(TrafficSignalData *signal_data) {
    signal_data->state = RED;
    signal_data->counter = 60; 
    signal_data->button_pressed = 0;
    display_countdown(10);
}


void change_to_green(TrafficSignalData *signal_data) {
    signal_data->state = GREEN;
    signal_data->counter = 40; 
    signal_data->button_pressed = 0;
    display_countdown(10);
}


int main() {
    key_t mq_key=0x5544aabb;

 
    if ((msqid = msgget(mq_key,IPC_CREAT|0777)) < 0) {
        perror("msgget");
        exit(1);
    }

    TrafficSignalData signal_data;
    signal_data.state = RED;
    signal_data.counter = 60;
    signal_data.button_pressed = 0;

    while (1) {
        

        if (msgrcv(msqid, &signal_data, sizeof(TrafficSignalData), 1, IPC_NOWAIT) > 0) {
           
            if (signal_data.button_pressed && signal_data.state==2) {
                change_to_amber(&signal_data);
            }
            else if(signal_data.button_pressed && signal_data.state==0)
            {
            	change_to_red(&signal_data);
            }
            
            else if(signal_data.button_pressed && signal_data.state==1)
            {
            	change_to_green(&signal_data);
            }
        }
        display_details(&signal_data);

        sleep(1);

        if (signal_data.state == RED || signal_data.state == GREEN || signal_data.state == AMBER) {
            signal_data.counter--;

            if (signal_data.counter < 0) {
                if (signal_data.state == RED) {
                    signal_data.state = GREEN;
                    signal_data.counter = 40;
                } else if (signal_data.state == GREEN) {
                    signal_data.state = RED;
                    signal_data.counter = 60;
                } else if (signal_data.state == AMBER) {
                    signal_data.state = RED; 
                    signal_data.counter = 60;
                }
            }
        }
    }

    

    return 0;
}

