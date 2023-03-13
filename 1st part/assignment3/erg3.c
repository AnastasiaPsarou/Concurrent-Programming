//NIKOS LYMPEROPOULOS 2812
//ANASTASIA PSAROU 2860
//1h erg 3h ask
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct sorting_array{
    int *array;      // pinakas pou periexei ta stoixeia kathe sorting pinaka
    int total_elems; // plithos stoixeiwn pou periexei kathe sorting pinakas
}typedef sorting_array_T;

struct pinakas_s {//struct pou afora to kathe thread
    pthread_t thr;
    struct pinakas_s *kid1;
    struct pinakas_s *kid2;
    
    sorting_array_T less;
    sorting_array_T equal;
    sorting_array_T greater;
    
    int terminate;
    int given_array_size;
    int *ptr_array; // pointer pou koitaei ston dosmeno pinaka tou nimatos
}typedef pinakas_T;

int *input_array;//pinakas pou apothikeuontai oi arithmoi tou input3.txt
int input_array_size;

void print_input(){//ektiponei kathe fora ton input_array
    printf("##############################################\n\n");
    
    for(int j=0; j < input_array_size; j++){
        printf("input_array[%02d] = %d\n", j, input_array[j]);
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}

void sort_arrays(pinakas_T *element){//bazei kathe stoixeio tou pinaka tou element se enan apo tous 3 dynamikous pinakes
    int i, x, pivot;//os pivot epilegoume to mesaio stoixeio tou pinaka pros ta pano
    
    //dimiourgoume tous pinakes less, equal, greater kai arxikopoioume ta stoixeia tous
    element->less.array = malloc(element->given_array_size*sizeof(int));
    element->equal.array = malloc(element->given_array_size*sizeof(int));
    element->greater.array = malloc(element->given_array_size*sizeof(int));
    
    for(i=0; i < element->given_array_size; i++){
        element->less.array[i] = 0;
        element->equal.array[i] = 0;
        element->greater.array[i] = 0;
        
        element->less.total_elems = 0;
        element->equal.total_elems = 0;
        element->greater.total_elems = 0;
    }
    pivot = *(element->ptr_array + element->given_array_size/2);
    
    for(i=0; i < element->given_array_size; i++){
        x = *(element->ptr_array+i);
        if(x < pivot){//ston less pane ta noumera pou einai mikrotera tou pivot
            element->less.array[element->less.total_elems] = x;
            element->less.total_elems++;
        }
        else if( x == pivot){//ston equal pane ta noumera pou einai isa tou pivot
            element->equal.array[element->equal.total_elems] = x;
            element->equal.total_elems++;
        }
        else{//ston greater pane ta noumera pou einai megalitera tou pivot
            element->greater.array[element->greater.total_elems] = x;
            element->greater.total_elems++;
        }
    }
}

void order_arrays(pinakas_T *element){
    int i;
    int *arrays_ptr;
    arrays_ptr = element->ptr_array;
    
    for(i=0; i < element->less.total_elems; i++){//i epanalipsi ginetai toses fores osa ta stoixeia tou pinaka less
        *arrays_ptr = element->less.array[i];
        arrays_ptr++;
    }
    for(i=0; i < element->equal.total_elems; i++){//i epanalipsi ginetai toses fores osa ta stoixeia tou pinaka equal
        *arrays_ptr = element->equal.array[i];
        arrays_ptr++;
    }
    for(i=0; i < element->greater.total_elems; i++){//i epanalipsi ginetai toses fores osa ta stoixeia tou pinaka greater
        *arrays_ptr = element->greater.array[i];
        arrays_ptr++;
    }
    
    free(element->less.array);//afou kanw to order oi pinakes less, equal, greater den me endiaferoun kai tous kanw free
    free(element->equal.array);
    free(element->greater.array);
}
void *quicksort(void *element){   
    pinakas_T *current_thread = element;    
    
    if(current_thread->given_array_size > 2 ){
        
        sort_arrays(current_thread);
        
        current_thread->kid1 = malloc(sizeof(pinakas_T)); // dimiourgia paidiwn tou nimatos
        current_thread->kid2 = malloc(sizeof(pinakas_T));
        
        current_thread->kid1->terminate = 0; // arxikopoioume tis metavlites twn paidiwn
        current_thread->kid2->terminate = 0;
        
        current_thread->kid1->given_array_size = current_thread->less.total_elems;
        current_thread->kid2->given_array_size = current_thread->greater.total_elems;
        
        current_thread->kid1->ptr_array = current_thread->less.array;
        current_thread->kid2->ptr_array = current_thread->greater.array;
        
        pthread_create(&current_thread->kid1->thr, NULL, quicksort, current_thread->kid1);
        pthread_create(&current_thread->kid2->thr, NULL, quicksort, current_thread->kid2);
        while(1){//to thread perimenei na teleiwsoun ta paidia tou
            if((current_thread->kid1->terminate == 1) && (current_thread->kid2->terminate == 1)){
                
                order_arrays(current_thread);//afou teleiosoun ta paidia ginetai order twn pinakwn less, equal, great
                free(current_thread->kid1);  //h mnini twn paidiwn apeleutheronetai 
                free(current_thread->kid2);
                current_thread->terminate = 1;//to thread gonios termatizei
                return(NULL);
            }
            else{
                pthread_yield();
            }
        }
    }
    else{       
        if(current_thread->given_array_size == 2){
            sort_arrays(current_thread);
            order_arrays(current_thread);
        }
        current_thread->terminate = 1;
    }    
    return NULL;
}

int main(){
    pinakas_T *initial_thread;
    FILE* file = fopen ("input3.txt", "r");
    int i, k;
    input_array_size = -1;
    
    while (!feof (file)){ //diavazoume apo to input3.txt ta noumera pou tha sortaroume
        input_array_size++;
        fscanf (file, "%d", &i);
    }
    
    input_array = (int *)malloc(input_array_size * sizeof(int));
    
    file = fopen ("input3.txt", "r");
    fscanf (file, "%d", &i);
    while(!feof(file)){
        input_array[k] = i;
        k++;
        fscanf (file, "%d", &i);
    }
    print_input();
    
    initial_thread = malloc(sizeof(pinakas_T));
    initial_thread->terminate = 0;
    initial_thread->given_array_size = input_array_size;
    initial_thread->ptr_array = input_array;
    
    pthread_create(&initial_thread->thr, NULL, quicksort, initial_thread);

    while(!initial_thread->terminate){//energi anamoni tis main
        pthread_yield();
    }
    
    print_input();
    
    fclose(file);
    free(initial_thread);
    free(input_array);
    
    return(0);
}
