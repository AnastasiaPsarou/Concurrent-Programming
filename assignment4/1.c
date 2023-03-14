#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include "library.h"

struct sembuf op; 
struct sembuf semid_op; 
struct sembuf semid_main_op;
int number = 0;
int semid;
int semid_main;

void *foo1(){
    number = 5;
    printf("number is %d\n", number);
    number = 10;
    printf("number is %d\n", number);
    
    mysem_up(semid);
    return(0);
}

void *foo2(){
    mysem_down(semid_op, semid);
    
    number = 15;
    printf("number is %d\n", number);
    number = 20;
    printf("number is %d\n", number);
    
    mysem_up(semid_main);
    return(0);
}

int main(int argc, char *argv[]){
    pthread_t thr1, thr2;
    
    semid = mysem_create(semid_op, 0);
    semid_main = mysem_create(semid_main_op, 0);
    
    printf("number is %d\n", number);
    
    pthread_create(&thr1, NULL, foo1, NULL);
    pthread_create(&thr2, NULL, foo2, NULL);
    mysem_down(semid_main_op, semid_main);
    
    printf("Main ends\n");
    mysem_destroy(semid);
    mysem_destroy(semid_main);
    
    return(0);
}
