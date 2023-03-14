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

typedef struct pinakas{
    pthread_t thr;  // To thread mesw tou opoiou iparxei kathe epivatis
    int wait_time;  // Xronos anamonis kathe epivati
}pinakas_T;

int train_sem;
struct sembuf train_op;

int line_sem;
struct sembuf line_op;

int ride_sem;
struct sembuf ride_op;

int main_sem;
struct sembuf main_op;

int train_passengers = 0;  // Plithos epivatwn pou vriskontai kapoia sigkekrimeni xroniki stigmi sto trenaki
int past_passengers = 0;   // Plithos epivatwn pou exoun mpei sto trenaki
int total_passengers = -1; // Sinolikoi epivates pou theloun na mpoun sto trenaki
int max_passengers;        // Max epivates pou xwrane sto trenaki

void *train_function(void *arg){ // I sinartisi gia to trenaki
    
    while(1){       
        printf("\n ~~~~~~~~~~~~~~~~~~~~~~~ TRAIN IS IN STATION ~~~~~~~~~~~~~~~~~~~~~~~ \n");
        if(past_passengers == total_passengers){ // Sinthiki pou elegxei an ola ta atoma pou vriskontan stin oura exoun kanei tin volta me to trenaki. An nai tote to trenaki 3ipnaei tin main kai termatizei
            printf("FIN WITH %d / %d\n", past_passengers, total_passengers);
            mysem_up(main_sem);
            return(NULL);
        }
        
        printf("WAITING FOR PASSENGERS\n\n");
        mysem_up(line_sem); // 3ipnaei ton prwto stin oura
         
        mysem_down(train_op, train_sem); // Koimatai mexri na mpei kai o teleftaios epivatis sto trenaki kai na ton 3ipnisei
      
        printf("RIDE STARTS\n");
        printf("~~~~\n");
        sleep(0);
        printf("~~~~\n");
        printf("RIDE FIN\n\n");

        mysem_up(ride_sem); // Afou teleiwsei i volta tote 3ipna ton prwto epivati etsi wste na apovivastei 
        
        mysem_down(train_op, train_sem); // perimene na vgoun oloi oi epivates         
        printf(" ####################### EVERYONE IS OUT RESTART RIDE #############\n\n\n");

    }
    return(NULL);
}

void *line_function(void *arg){ // sinartisi epivatwn
    int *wait_time; 
    wait_time = arg;
    
    sleep(*wait_time); // perimene gia osi wra xreiazetai vasei tou input
   
    mysem_down(line_op, line_sem); // mpes stin oura gia to trenaki kai perimene mexri na erthei i seira sou
    
    train_passengers++;
    past_passengers++;
    printf("NUM = %2d - - PASSENGER #", *wait_time);

    if((past_passengers == total_passengers) || (train_passengers == max_passengers)){ // An eisai o teleftaios epivatis gia to trenaki epeidi gemise i epeidh den iparxoun alla atoma stin oura 3ipna to trenaki
        printf("%2d - LAST TO GET IN\n\n", train_passengers);
        mysem_up(train_sem);
    }
    else{
        printf("%2d IN\n", train_passengers); // 3ipna ton epomeno epivati an xwraei allos
        mysem_up(line_sem);
    }

    mysem_down(ride_op ,ride_sem); // edw perimenoun oloi oi epivates otan einai mesa sto trenaki
    
    train_passengers--;
    printf("NUM = %2d - -  PASSENGERS LEFT IN TRAIN = ", *wait_time);
    
    if(train_passengers > 0){ // An den eisai o teleftaios epivatis sto trenaki gia na apovivastei tote 3ipna ton epomeno epivati
        printf("%2d\n", train_passengers);
        mysem_up(ride_sem);
    }
    else{
        printf("%2d - LAST TO GET OUT\n\n", train_passengers);
        mysem_up(train_sem); // An eisai o teleftaios epivatis mesa sto trenaki tote afou apovivasteis 3ipna to trenaki
    }

    return(NULL);
}

int main(int argc, char *argv[]){
    pinakas_T *pinakas;
    pthread_t train;
    FILE* file = fopen ("input4.txt", "r");
    int i;
    
    max_passengers = atoi(argv[1]); // O megistos arithmos epivatwn pou xwraei to trenaki vasei argument.
    
    printf("ARGV[0] = %d\n", max_passengers);
    
    while (!feof (file)){  // metraei to plithos twn arithmwn mesa sto arxeio eisodou etsi wste na kanei malloc gia katallilo megethos ton pinaka epivatwn
        total_passengers++;
        fscanf (file, "%d", &i);
    }
    printf("total passengers is %d\n", total_passengers);
    fclose(file);
    file = fopen ("input4.txt", "r");
    
    pinakas = (pinakas_T *) malloc(total_passengers * (sizeof(pinakas_T)));
   
    line_sem = mysem_create(line_op, 0); // Arxikopoisi olwn twn simatoforwn se 0
    ride_sem = mysem_create(ride_op, 0);
    train_sem = mysem_create(train_op, 0);
    main_sem = mysem_create(main_op, 0);
    
    for(i=0; i < total_passengers; i++){
        fscanf (file, "%d", &pinakas[i].wait_time);  // Apothikeusei olwn twn xronwn anamonis apo to arxeio input ston pinaka epivatwn
    }
    
    pthread_create(&train, NULL, train_function, NULL); // Dimiourgia tou nimatos gia to trenaki
    
    for(i = 0; i < total_passengers; i++){
        pthread_create(&pinakas[i].thr, NULL, line_function, &pinakas[i].wait_time);//dimiourgia epivatwn kai perasma ws argument stin sinartisi tous ton xrono anamonis tou ekastote epivati
    }
    
    mysem_down(main_op ,main_sem); // I main mplokarei mexri na mpoun oloi oi epivates sto trenaki kai na min perimenei kaneis allos.
    
    mysem_destroy(line_sem); // Katastrofi olwn twn simatoforwn
    mysem_destroy(ride_sem);
    mysem_destroy(train_sem);
    mysem_destroy(main_sem);
    fclose(file);
    
    free(pinakas);
    
    return(0);  
}
