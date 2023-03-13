//Anastasia Psarou 2860
//Nikos Lymperopoulos 2812
//1h erg 2h askisi
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>


struct thread{
    int given_num;              //to noumero pou tha tsekarei to thread an einai prime
    int work_signal;            //sima pou ginetai 1 afou i main anathesei mia douleia sto thread
    int percentage;             //sinolo arithmon pou exei epejergastei to thread 
    pthread_t thr;              //i metabliti pano stin opoia dimiourgeitai to thread
}typedef thread_T;

thread_T *pinakas_thread;

int terminate_signal = 0; //sima pou leei sta threads na termatisoun otan exei timi 1

int num_of_threads;
int array_size;//to megethos tou pinaka pou exei apothikeumenous tous arithmous tou input

int find_thread_index(){//synartisi pou vriskei tin thesi tou thread ston pinakas_thread
    int i;
    for(i = 0; i < num_of_threads; i++){
        if(pinakas_thread[i].thr == pthread_self()){
            break;
        }
    }
    return(i);
}
int check_availability(){//an thread[i] exei work_signal = 0 tote simainei oti den douleuei ara einai diathesimo kai epistrefetai h thesi tou
    for(int i = 0; i < num_of_threads; i++){
        if(pinakas_thread[i].work_signal == 0){
            return(i);
        }
    }
    return(-1);
}
int check_all_available(){
    for(int i = 0; i < num_of_threads; i++){
        if(pinakas_thread[i].work_signal == 1){
            return(0);
        }
    }
    return(1);
}
int isPrime(int num_to_check){ 
    int i, flag = 0;
    
    for (i = 2; i <= num_to_check / 2; ++i) {
        // condition for non-prime
        if (num_to_check % i == 0) {
            flag = 1;
            break;
        }
    }
    
    if (num_to_check != 1) {
        if (flag == 0){
            return(1);
        }
        else{
            return(0);
        }
    }
    return(0); 
}

void *prime_function(){
    int i, thread_index, res;
    
    thread_index = find_thread_index();//epistrefei ton eauto tou nimatos
    
    while(1){
        while(!pinakas_thread[thread_index].work_signal){  // EDW PERIMENEI TO EKASTOTE THREAD AFOU DEN EXEI DOYLEIA
            if(terminate_signal == 1){                              // An exw pio polla threads apo oti noumera tote ta threads pou
                return(NULL);                                       // den tha paroun douleia pote apla menoun gia panta se afti tin while
            }                                                       // mexri to telos pou tous leei i main na pethanoun. px 7 nums, 10 threads
            pthread_yield();
        }
        pinakas_thread[thread_index].percentage++;
        res = isPrime(pinakas_thread[thread_index].given_num);
        if(res == 1){
            printf("\n -------------- THREAD %d : %d IS PRIME ------\n", thread_index, pinakas_thread[thread_index].given_num);
        }
        else{
            printf("\n -------------- THREAD %d : %d IS NOT PRIME --\n", thread_index, pinakas_thread[thread_index].given_num);
        }
        pinakas_thread[thread_index].work_signal = 0;//leei stin main oti teleiose ti douleia
    }
    return(NULL);
}

int main(int argc, char *argv[]){
    FILE* file = fopen ("input2.txt", "r");
    int num, check, i;
    int k = 0;
    int sum = 0;
    int array_counter = 0;
    
    int *array;
    array_size = -1;
    
    printf("num of threads:  ");
    scanf("%d", &num_of_threads);
    
    
    while (!feof (file)){  // metraei to plithos twn arithmwn mesa sto arxeio eisodou etsi wste na kanei malloc gia katallilo megethos ton pinaka array poy tha apothikeutoun
        array_size++;
        fscanf (file, "%d", &i);
    }
    
    array = (int *)malloc(array_size * sizeof(int));
    pinakas_thread = (thread_T*) malloc(num_of_threads * (sizeof(thread_T)));
    
    fclose(file);
    file = fopen ("input2.txt", "r");
    fscanf (file, "%d", &i);
    while(!feof(file)){ //diabazei tous int apo to arxeio kai tous apothikeuei ston array
        array[k] = i;
        k++;
        fscanf (file, "%d", &i);
    }
    
    for(i = 0; i < num_of_threads; i++){
        pinakas_thread[i].given_num = 0;
        pinakas_thread[i].work_signal=0;
        pinakas_thread[i].percentage=0;
    }
    
    printf("ARRAY SIZE = %d\n", array_size);
    
    for(i = 0; i < num_of_threads; i++){
        pthread_create(&pinakas_thread[i].thr, NULL, prime_function, NULL);//dimiourgia nimatwn
    }
    
    while(array_counter < array_size){//oso yparxoun akomi arithmoi na anatethoun sta nimata
        check = check_availability();
        
        if(check >= 0){
            num = array[array_counter];
            array_counter++;
            
            pinakas_thread[check].given_num = num;
            pinakas_thread[check].work_signal = 1;
        }
        else{
            pthread_yield();
        }
    }
    
    terminate_signal = 1; // sima poy leei sta threads na termatisoun

    while(!check_all_available()){
        pthread_yield();
    }
    
    for(int j = 0; j < num_of_threads; j++){
        printf("~~~~~~~~~~ THREAD %2d PROCESSED %3d / %d ~~~~~~~~~~~\n", j, pinakas_thread[j].percentage, array_size);
        sum = sum + pinakas_thread[j].percentage; // elegxos gia to an to plithos twn arithmwn pou epe3ergastikan einai iso me to plithos twn arithmwn
    }
    printf(" TOTAL SUM = %d / %d\n", sum, array_size);
    
    fclose(file);
    free(array);
    free(pinakas_thread);
    
    return(0);  
}
