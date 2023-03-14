#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "library.h"

int mysem_create(struct sembuf op, int initial_value){
    int semid= semget(IPC_PRIVATE, 1, S_IRWXU);
    
    semctl(semid, 0, SETVAL, initial_value);//arxikopoisi tou simatoforou tou read/write me 1
    
    op.sem_flg = SEM_UNDO;
    op.sem_num = 0; 
    
    return(semid);
}

void mysem_down(struct sembuf op, int semid){
    op.sem_op = -1; 
    semop(semid, &op, 1);
}

int mysem_up(int semid){
    if(semctl(semid, 0, GETVAL) == 1){
        return(0);
    }
    semctl(semid, 0, SETVAL, 1);
    return(1);
}

void mysem_destroy(int semid){
    semctl(semid, 0, IPC_RMID);
}
