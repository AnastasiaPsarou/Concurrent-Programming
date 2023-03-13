#include <stdio.h>
#include <stdlib.h>

//sygkrinei 2 arxeia
//epistrefei 0 an einai idia ta arxeia allios -1
int compareFile(FILE * fPtr1, FILE * fPtr2, int * line, int * col)
{
    char ch1, ch2;

    *line = 1;
    *col  = 0;

    do{
        
        ch1 = fgetc(fPtr1);
        ch2 = fgetc(fPtr2);
        
        //allazoume grammi
        if (ch1 == '\n')
        {
            *line += 1;
            *col = 0;
        }

        if (ch1 != ch2)
            return -1;

        *col  += 1;

    } while (ch1 != EOF && ch2 != EOF);


    //an ta arxeia eftasan sto telos tous
    if (ch1 == EOF && ch2 == EOF)
        return 0;
    else
        return -1;
}

int main(){
    FILE * fPtr1; 
    FILE * fPtr2;
    int diff;
    int line, col;
    
    fPtr1 = fopen("input.txt", "r");
    fPtr2 = fopen("output.txt", "r");

    if (fPtr1 == NULL || fPtr2 == NULL){
        exit(EXIT_FAILURE);
    }
    
    diff = compareFile(fPtr1, fPtr2, &line, &col);

    if (diff == 0)
    {
        printf("Both files are equal.\n");
    }
    else 
    {
        printf("Files are not equal.\n");
        printf("Line: %d, col: %d\n", line, col);
    }

    fclose(fPtr1);
    fclose(fPtr2);

    return 0;
}
