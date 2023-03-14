#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "library.h"

typedef struct car{
    pthread_t thr;
    char color;//mporei na exei color r(red), b(blue)
    int time_pass_bridge;
    int time_to_appear;
}car_t;

int cars_in = 0;//synolikos arithmos aftokinitwn pou mpainoun stin gefira
int cars_out = 0;//synolikos arithmos aftokinitwn pou bgainoun apo tin gefira
int cars_allowed_bridge;//megistos arithmos aftokinitwn pou epitrepontai taytoxrona stin gefira
int maximum_cars_row;//megistos synexomenos arithmos aftokinitwn apo tin kathe pleura
int blue_cars = 0;
int red_cars = 0;
int first = 1;

int mutex;
int mutex1;
int main_semid;//simatoforos oste na epistrepsoume stin main
int row_semid_blue;
int row_semid_red;

struct sembuf mutex_op;
struct sembuf mutex1_op;
struct sembuf main_semid_op;
struct sembuf semid_blue_op;
struct sembuf semid_red_op;

int color(car_t *car){//synartisi pou epistrefei ton simatoforou tou xromatos tou aftokinitou
    if(car->color == 'b'){
        return(row_semid_blue);
    }
    else{
        return(row_semid_red);
    }
} 

int oposite_color(car_t *car){//synartisi pou epistrefei ton simatoforou tou antithetou xromatos tou aftokinitou
    if(car->color == 'b'){
        return(row_semid_red);
    }
    else{
        return(row_semid_blue);
    }
}

void *bridge(void *arg){
    car_t *car;
    car = arg;
    
    sleep(car->time_to_appear);//anamoni mexri to kathe aftokinito na ftasei ligo prin tin arxi ths gefyras
    
    mysem_down(mutex1_op, mutex1);//KRISIMO TMIMA
    if(first == 1){//to 1o nima pou tha mpei tha kathorisei to xroma twn aftokinitwn pou tha 3ekinisei
        first = 0;
        if(car->color == 'b'){
            mysem_down(semid_red_op, row_semid_red);
        }
        else{
            mysem_down(semid_blue_op, row_semid_blue);
        }
    }
    mysem_up(mutex1);
    
    //analoga me to xroma to nima perimenei ston ekastote simatoforo
    if(car->color == 'r'){//edo perimenoun ta kokkina aytokinhta
        mysem_down(semid_red_op, row_semid_red);
    }
    else{//edo perimenoun ta mple aytokinhta
        mysem_down(semid_blue_op, row_semid_blue);
    }
    //EISODOS STIN GEFYRA
    cars_in++;//o arithmos twn aftokinitwn ay3anetai kathe fora pou mpainei ena aftokinitwn stin gefira
    printf("\n\nmy color is !%c! : time_pass_bridge %d and time_to_appear %d\n\n", car->color, car->time_pass_bridge, car->time_to_appear);
    printf("There are %d cars in the bridge\n", (cars_in - cars_out));
    printf("Sinexomena aftokinita : %d\n\n", cars_in);
    if((cars_in < maximum_cars_row) && ((cars_in - cars_out) < cars_allowed_bridge)){
        if(((car->color == 'b') && ((blue_cars - 1) > 0)) || ((car->color == 'r') && ((red_cars - 1) > 0))){//an ena aftokinito einai to teleutaio tou xromatos tou den tha 3ypnisei allo
            mysem_up(color(car));//an i gefira exei xwro kai den exei 3eperastei o max arithmos sinexomenon aftokinitwn 3ipnaei kai allo aftokinito tou idiou xromatos
        }
    }
    sleep(car->time_pass_bridge);//xronos pou to kathe aytokinhto dianuei tin gefira
    
    mysem_down(mutex_op, mutex);//KRISIMO TMIMA
    //E3ODOS APO TIN GEFYRA
    if(car->color == 'b'){//ypologismos twn aftokinitwn tou kathe xromatos pou emeinan
        blue_cars--;
    }
    else{
        red_cars--;
    }
    if((red_cars + blue_cars) == 0){//an den yparxoun alla aftokinita epestrepse stin main
        mysem_up(main_semid);
    }
    else if(((blue_cars == 0) && (car->color == 'b')) || ((red_cars == 0) && (car->color == 'r'))){//an eisai to teleutaio aftokinito tou xromatos sou 3ipna to allo xroma
        cars_in = 0;
        cars_out = 0;
        mysem_up(oposite_color(car));
    }
    else{ 
        cars_out++;
        if(((cars_in < maximum_cars_row) && ((cars_in - cars_out + 1) == cars_allowed_bridge)) || ((cars_out == maximum_cars_row) && ((cars_in - cars_out) == 0))){//mpes an h gefira itan gemati prin bgo kai den exoume yperbei ton synexomeno arithmo aftokinitwm apo tin pleyra mas h an eimai to teleytaio aftokinito apo ta max synexomena aytokinhta kathe pleura
                if(cars_out == maximum_cars_row){//an anikw stin 2h periptosi
                    cars_in = 0;//arxikopoiountai ta cars_in kai cars_out
                    cars_out = 0;
                    if(((car->color == 'b') && (red_cars == 0)) || ((car->color == 'r') && (blue_cars == 0))){//an den yparxoun aftokinita allou xromatos pou na perimenoun 3ipna to diko mou xroma
                        mysem_up(color(car));
                    }
                    else{//alliws 3ipna to allo xroma
                        mysem_up(oposite_color(car));
                    }
                }
                else{//an h gefira itan gemati prin bgo kai den exoume yperbei ton synexomeno arithmo aftokinitwm apo tin pleyra mas
                    mysem_up(color(car));
                }
        }
    }
    mysem_up(mutex);
    
    free(car);//apeleutherosi tis mnimis kathe aftokinitou
    
    return(0);
}

int main (int argc, char *argv[]){
    FILE *fp;
    fp = fopen("input3c.txt", "r");
    int i, time_pass_bridge, time_to_appear;
    int num_of_cars = 0;
    char color;//metavlites gia na broume to num_of_cars
    car_t *car;
    
    maximum_cars_row = atoi(argv[1]);//1o orisma einai to n(megistos arithmos synexomenwn aftokinitwn apo kathe pleura)
    cars_allowed_bridge = atoi(argv[2]);//2o orisma megistos arithmwn aftokinitwn poy xwrane stin gefira
    
    while(!feof(fp)){
        num_of_cars++;
        fscanf(fp, "%c %d %d ", &color, &time_pass_bridge, &time_to_appear);
    }
    fp = fopen("input3c.txt", "r");
    
    mutex = mysem_create(mutex_op, 1);//dimiourgia/arxikopoisi simatoforwn
    mutex1 = mysem_create(mutex1_op, 1);
    main_semid= mysem_create(main_semid_op, 0);
    row_semid_blue = mysem_create(semid_blue_op, 1);
    row_semid_red = mysem_create(semid_red_op, 1);
    
    for(i = 0; i < num_of_cars; i++){//dimiourgia kai arxikopoisi kathe aftokinitou
        car = (car_t*) malloc(sizeof(car_t));
        fscanf(fp, "%c %d %d ", &car->color, &car->time_pass_bridge, &car->time_to_appear);
        if(car->color == 'b'){
            blue_cars++;
        }
        else{
            red_cars++;
        }
        pthread_create(&car->thr, NULL, bridge, car);
    }
    mysem_down(main_semid_op, main_semid);//anamoni mexri na perasoun ola ta aftokinita panw apo tin gefira
    printf("MAIN IS UP\n");
    
    fclose(fp);
    
    mysem_destroy(mutex);//katastrofi simatoforwn
    mysem_destroy(mutex1);
    mysem_destroy(row_semid_blue);
    mysem_destroy(row_semid_red);
    mysem_destroy(main_semid);
    
    return(0);
}
