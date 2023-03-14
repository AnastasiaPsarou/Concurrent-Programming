#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "library.h"

struct thread{
    int given_num;              // to noumero pou tha tsekarei to thread an einai prime
    int work_signal;            // sima pou ginetai 1 afou i main anathesei mia douleia sto thread
    int percentage;             // sinolo arithmon pou exei epe3ergastei to thread 
    pthread_t thr;              // i metabliti pano stin opoia dimiourgeitai to thread
    int semid;                  // o simatoforos toy kathe thread
    struct sembuf op;
}typedef thread_T;

thread_T *pinakas_thread;

int terminate_signal = 0; //sima pou leei sta threads na termatisoun otan exei timi 1
int check = 0;
int num_of_threads;
int array_size;//to megethos tou pinaka pou exei apothikeumenous tous arithmous tou input
int total_threads;

int main_semid;
int terminate_semid;
struct sembuf main_op;

int mtx;    // 2 simatoroi pou xrisimopoiountai gia amivaio apokleismo meta3i nimatwn
int mtx2;

struct sembuf mtx_op;
struct sembuf mtx2_op;

int find_thread_index(){//synartisi pou vriskei tin thesi tou thread ston pinakas_thread
    int i;
    for(i = 0; i < num_of_threads; i++){
        if(pinakas_thread[i].thr == pthread_self()){
            break;
        }
    }
    return(i);
}
void check_plus(){ // Sinartisi pou mas epitrepei na proxwrisoume sto epomeno nima apo ekei pou eimaste. An eimaste sto teleftaio nima tote pame pali sto 0.
    if(check == num_of_threads-1){
        check = 0;
    }
    else{
        check++;
    }
}
int check_availability(){ //An thread[i] exei work_signal = 0 tote simainei oti den douleuei ara einai diathesimo kai epistrefetai 1. An to nima sto opoio kanonika prepei na dwsoume ton epomeno arithmo den einai diathesimo tote
                          // Koitame ena ena ola ta nimata meta apo afto mexri na vroume ena diathesimo nima. An den vroume kanena diathesimo nima, diladi an exoume epistrepsei sto nima apo to opoio 3ekinisame i sinartisi epistrefei 0.
    for(int i = 0; i < num_of_threads; i++){
        if(pinakas_thread[check].work_signal == 0){
            return(1);
        }
        check_plus();
    }
    return(0);
}
int isPrime(int num_to_check){ 
    int i, flag = 0;
    
    for (i = 2; i <= num_to_check / 2; ++i) {
        if (num_to_check % i == 0) { // condition for non-prime
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
    int thread_index, res;
    
    thread_index = find_thread_index();//epistrefei ton eauto tou nimatos
    while(1){
        if(!terminate_signal){
            mysem_down(pinakas_thread[thread_index].op, pinakas_thread[thread_index].semid);   // Edw perimenei to ekastote nima mexris wtou na tou anatethei arithmos. An den tou anatethei pote arithmos tote otan 3ipnisei 
        }                                                                                          // logw tis parakatw if termatizei amesws.
        if((terminate_signal == 1) && (pinakas_thread[thread_index].work_signal == 0)){ // An i main exei pei oti ola ta nimata prepei na tesmatisoun kai sto ekastote nima den exei anatethei arithmos tote prepei na termatisei
            
            mysem_down(mtx2_op, mtx2);
            total_threads--;
            if(total_threads == 0){ // Kathe nima prin termatisei meiwnei to plithos twn sinolikwn nimatwn etsi wste mono to teleftaio nima na 3ipnisei tin main kai na eimaste sigouroi oti den tha leitourgei nima enw i main termatizei.
                printf("%d WOKE UP MAIN\n", thread_index);
                mysem_up(terminate_semid);
            }
            mysem_up(mtx2);
            
            return(NULL); 
        }
        pinakas_thread[thread_index].percentage++;   // Plithos arithmwn pou exei epe3ergastei to ekastote nima
        res = isPrime(pinakas_thread[thread_index].given_num);
        if(res == 1){
            printf("\n -------------- THREAD %d : %d IS PRIME ------\n", thread_index, pinakas_thread[thread_index].given_num);
        }
        else{
            printf("\n -------------- THREAD %d : %d IS NOT PRIME --\n", thread_index, pinakas_thread[thread_index].given_num);
        }
        
        mysem_down(mtx_op, mtx);
        if(!semctl(main_semid, 0, GETVAL)){ // Elegxos etsi wste mono ena nima na 3ipnisei tin main otan xreiastei
            mysem_up(main_semid);
        }
        mysem_up(mtx);
        pinakas_thread[thread_index].work_signal = 0; // Allagi metavlitis work_signal pou deixnei stin main oti to nima einai pia diathesimo
    }
    return(NULL);
}

int main(int argc, char *argv[]){
    FILE* file = fopen ("input2.txt", "r");
    int num, i;
    int k = 0;
    int sum = 0;
    int array_counter = 0;
    
    int *array;
    array_size = -1;
    
    printf("num of threads:  ");
    scanf("%d", &num_of_threads);

    total_threads = num_of_threads;
    
    while (!feof (file)){  // metraei to plithos twn arithmwn mesa sto arxeio eisodou etsi wste na kanei malloc gia katallilo megethos ton pinaka array poy tha apothikeutoun
        array_size++;
        fscanf (file, "%d", &i);
    }
    
    array = (int *)malloc(array_size * sizeof(int));                            // pinakas dosmenwn arithmwn
    pinakas_thread = (thread_T*) malloc(num_of_threads * (sizeof(thread_T)));
    
    main_semid = mysem_create(main_op, 0);       // arxikopoisi simatoforwn
    terminate_semid = mysem_create(main_op, 0);
    
    mtx = mysem_create(mtx_op, 1);
    mtx2 = mysem_create(mtx2_op, 1);
    
    fclose(file);
    file = fopen ("input2.txt", "r");
    fscanf (file, "%d", &i);
    while(!feof(file)){ //diabazei tous int apo to arxeio kai tous apothikeuei ston array
        array[k] = i;
        k++;
        fscanf (file, "%d", &i);
    }
    
    for(i = 0; i < num_of_threads; i++){ // arxikopoisi pinaka nimatwn kai dimiourgia twn simatoforwn tous
        pinakas_thread[i].given_num = 0;
        pinakas_thread[i].work_signal=0;
        pinakas_thread[i].percentage=0;
        pinakas_thread[i].semid = mysem_create(pinakas_thread[i].op, 0);
    }
    
    for(i = 0; i < num_of_threads; i++){
        pthread_create(&pinakas_thread[i].thr, NULL, prime_function, NULL); //dimiourgia nimatwn
    }
    while(array_counter < array_size){//oso yparxoun akomi arithmoi na anatethoun sta nimata
        if(check_availability()){ // An iparxei diathesimo nima dwstou ton epomeno arithmo pou prepei na epe3ergastei kai 3ipna to
            num = array[array_counter];
            array_counter++;
            pinakas_thread[check].given_num = num;
            pinakas_thread[check].work_signal = 1;
            
            mysem_up(pinakas_thread[check].semid);
            check_plus();
        }
        else{
            mysem_down(main_op, main_semid); // An den iparxei diathesimo nima tote i main  mplokarei
        }
    }
    
    terminate_signal = 1; // sima poy leei sta threads na termatisoun
    for(i=0; i < num_of_threads; i++){
        mysem_up(pinakas_thread[i].semid); // I main kanei up olous tous simatoforous nimatwn etsi wste osa exoun mplokarei kai den exoun douleia na termatisoun amesws kai osa exoun douleia afou tin teleiwsoun na min mplokaroun ston 
    }                                      // simatoforo tous.
    
    mysem_down(main_op, terminate_semid); // I main perimenei mexri na termatisoun ola ta nimata
    
    for(int j = 0; j < num_of_threads; j++){
        printf("~~~~~~~~~~ THREAD %2d PROCESSED %3d / %d ~~~~~~~~~~~\n", j, pinakas_thread[j].percentage, array_size);
        sum = sum + pinakas_thread[j].percentage; // elegxos gia to an to plithos twn arithmwn pou epe3ergastikan einai iso me to plithos twn arithmwn pou dothikan apo to input
    }
    printf(" TOTAL SUM = %d / %d\n", sum, array_size);
    
    for(i=0; i < num_of_threads; i++){
        mysem_destroy(pinakas_thread[i].semid); // Katastrofi olwn twn simatoforwn twn nimatwn
    }
    mysem_destroy(mtx); // Katastrofi olwn twn simatoforwn
    mysem_destroy(mtx2); 
    mysem_destroy(main_semid);
    mysem_destroy(terminate_semid);
    
    fclose(file);
    free(array);
    free(pinakas_thread);

    return(0);  
}
