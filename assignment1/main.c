//Nikos Lymperopoulos 2812
//Anastasia Psarou 2860
//1h erg 1h ask
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include "erg1.h"

char *pinakas;//pinakas-buffer
char *head;
char *tail;
int size;//megethos pinaka-buffer
FILE *fpto;
FILE *fp;  
int main_sleep;

int main(int argc, char* argv[]){
    pthread_t t1,t2;
    main_sleep = 1;
    
    size = 64;
    fpto = fopen("output.txt", "w+");
    
    fp = fopen("input.txt", "r");
    pipe_init();//dimiourgei to pipe

    pthread_create(&t1, NULL, write_data, NULL);//gia to write
    pthread_create(&t2, NULL, read_data, NULL);//gia to read
    
    while(main_sleep == 1){//energi anamoni main
        pthread_yield();
    }
    
    free(pinakas);
    fclose(fp);
    fclose(fpto);
    
    return(0);
}
