#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "assign2funcs.h"
#define MAXSIZE 9
#define MINSIZE 1

// method to read the user input
void readInput(void)
{
        char input[100];
        char *token;
        int arrSize;
        bool checkExit;
        checkExit=true;

        LOOP:
            if((fgets(input, 100, stdin)) == NULL){
                    // check for any bad input in the loop and exits accordingly
                    if(checkExit == true){
                        exit(0);
                    }
                    else{
                        exit(1);
                    }
            }

            for(int i=0; i<strlen(input); i++)
            {
                if ((isalpha(input[i]) != 0))
                    {
                        checkExit = false;
                        fprintf(stderr,"BAD INPUT\n");
                        goto LOOP;
                    }
            }

            input[strlen(input)-1] = '\0';

            if(testValidCharacters(input) == 0){
                    checkExit = false;
                    fprintf(stderr,"BAD INPUT\n");
                    goto LOOP;
            }

            token = strtok(input, " ");
            sscanf(token, "%d", &arrSize);


            if(arrSize == 0){
                    if(checkExit == true){
                        exit(0);
                    }
                    else{
                        exit(1);
                    }
            }

            if(arrSize > MAXSIZE || arrSize < MINSIZE){
                checkExit = false;
                fprintf(stderr,"BAD INPUT\n");
                goto LOOP;
            }

            double *newArr = (double *) malloc(256 *sizeof(double));

            int newcount;
            newcount=0;

            while (token != NULL){
                token = strtok(NULL, " ");
                if(token == NULL){
                    break;
                }
                double tempVar = atof(token);
                newArr[newcount] = tempVar;
                newcount++;
            }

            if(newcount < arrSize){
                for(int i = newcount; i < arrSize+1; i++){
                    if(newcount >= arrSize){
                        break;
                    }
                    char newinput[100];
                    char *newtoken;

                    if((fgets(newinput, 100, stdin)) == NULL){
                        exit(1);
                    }
                    for(int i=0; i<strlen(newinput); i++){
                        if (isalpha(newinput[i]) != 0){
                            checkExit = false;
                            fprintf(stderr,"BAD INPUT\n");
                            goto LOOP;
                        }
                    }

                    newtoken = strtok(newinput, " ");
                    while (newtoken != NULL && newcount < arrSize+1)
                    {
                        double tempVar = atof(newtoken);
                        newArr[newcount] = tempVar;
                        newcount++;
                        newtoken = strtok(NULL, " ");
                    }
                }
            }

            arrayVector(newArr, arrSize);
            normalizeArray(newArr, arrSize);
            arrSize = 0;
            goto LOOP;
}

void arrayVector(double *newArr, int arrSize){
    printf("VECTOR: [ ");
    for(int i = 0; i < arrSize-1; i++)
        printf("%.3lf, ", newArr[i]);
    printf("%.3lf ", newArr[arrSize-1]);
    printf("]");

}

void normalizeArray(double *newArr, int arrSize) {
    double sum = 0;
    double N;
    for(int i = 0; i < arrSize; i++){
        double result;
        result = pow(newArr[i],2);
        sum = sum + result;
    }
    N = sqrt(sum);
    printf(" NORMALIZED: [ ");
    for(int i = 0; i < arrSize-1; i++)
        printf("%.3lf, ", newArr[i]/N);
    printf("%.3lf ", newArr[arrSize-1]/N);
    printf("]\n");
}

int testValidCharacters(char input[100]){

    for(int i=0; i<strlen(input); i++)
    {
         if ( !(isdigit(input[i])) &&  (input[i] != ' ') &&  (input[i] != '.') &&  (input[i] != '+') &&  (input[i] != '-'))
			{
			    return 0;
            }
    }
    return 1;
}
