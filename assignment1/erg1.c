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

char *pinakas;
char *head;
char *tail;
int size;
int writeDone = 0;
int write_counter = 0;//metraei posous xaraktires exei o pinakas
int read_sleep = 1; // 1 otan koimatai i read
int main_sleep = 1;
FILE *fpto;
FILE *fp;  

void print_array(){
    
    for(int i=0; i < size; i++){
        printf("pinakas[%d] = %c\n", i, pinakas[i]);
    }
    printf("\n\n");
}

void pipe_init(){ //dimiourgia buffer
    pinakas = (char*) malloc((size) * sizeof(char));
    head = pinakas;
    tail = pinakas;
    
    for(int i = 0; i < size; i++){
        memset(&pinakas[0], 0, sizeof(char)); // afti i sinartisi 'adeiazei' ton pinaka
    }
    return;
}

int pipe_read(char *c){
    char read;
    
    if(write_counter == 0){
        return(0);
    }
    else{//diabazei
        read = *c;
        *c = '\0';
        
        fputc(read, fpto); //ayto pou diabazei h read grafetai sto output
        write_counter--;
        return(1);
    }
}

void *read_data(){//h synartisi tis read
    int return_pipe_read;
    print_array();
    
    while(read_sleep){//energi anamoni
                pthread_yield();
    }
    while(1){
        
        while(1){
            return_pipe_read = pipe_read(tail);//diabasma

            if(return_pipe_read == 1){//an epistrafei 1 simainei oti to diavasma egine kanonika
                if(tail ==  &pinakas[size-1]){
                    tail = &pinakas[0];
                }
                else{
                    tail++;
                }
            }
            else{ // an ginei klisi tis read_data enw to buffer einai adeio
                break;
            }
        }
        if(writeDone == 1){// 3ipna tin main kai termatise
            print_array();
            main_sleep = 0; 
            break;
        }
        else{
            read_sleep = 1;// 3ipna tin thread1
            while(read_sleep == 1){
                pthread_yield();
            }
        }
    }
     return(NULL);
}

void pipe_writeDone(){
    writeDone = 1;
    read_sleep = 0; // 3ipna tin thread2 (read)
}

void pipe_write(char c){//grafei enan char
    *head = c;
    
    return;
}

void *write_data(){//h synartisi tis write
    char scan_char;
    
    while(1){
        if(*head == '\0'){
            scan_char = fgetc(fp);//diavazei kathe fora ena char apo to input.txt
            
            if(feof(fp)){//sinthiki gia write_done/diabazei oti exei meinei ston pinaka, telos arxeiou eisodou
                pipe_writeDone();
                return(NULL);
            }
            else{
                pipe_write(scan_char); // grafei ston buffer ton xaraktira pou pire apo to arxeio eisodou
                write_counter++;
                
                if(head ==  &pinakas[size-1]){ // afti i sinthiki dimiourgei ton kikliko buffer
                    head = &pinakas[0];
                }
                else{
                    head++;
                }
            }
        }
        else{//edo mpainei otan gemisei to buffer
            if(write_counter == size){
                read_sleep = 0;
                while(read_sleep == 0){//koimatai i write kai douleuei i read
                    pthread_yield();
                }
            }
        }
    }
    return(NULL);
}
