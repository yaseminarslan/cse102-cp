/* 
 * Yasemin Arslan
 * 1901042263
 * CSE102 - hw2
 * 
 * Description: Read input.txt
                Count the repetitions of the integers
                Write the repetitions to output.txt in ascending order.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

void bubblesort_two(int a1[],int a2[], int size);

int main(void){
    FILE *fptr;
    int number;
    int hit = 0;
    int numbers[100] = {0};
    int counts[100] = {0};
    int idx = 0;
    
    // Try to open the file and exit if can't open
    if((fptr = fopen("input.txt", "r")) == NULL)
    {
        printf("Could not open the file...");
        return -1;
    } else {
        while(!feof(fptr)){
            int status = fscanf(fptr, "%d", &number);
            if (status == -1){
                break;
            }
            // check if the number is already in the array
            // idx is the max location pointer
            // check until idx. 

            hit = 0;
            for (int i=0; i<idx; i++){
                if(number == numbers[i]){
                    counts[i]++;
                    hit =1;
                    break;
                }
            }
            // if number is not in the array append to the end and increment idx
            if(hit == 0){
                numbers[idx] = number;
                counts[idx] = 1;
                idx++;
            }
        }
    }
    fclose(fptr);
    // sort based on counts array
    bubblesort_two(counts, numbers, idx);

    // Try to open the file and exit if can't open
    if((fptr = fopen("output.txt", "w")) == NULL)
    {
        printf("Could not open the file...");
        return -1;
    } 
    else {
        for(int i=0; i<idx; i++){
            fprintf(fptr, "%d:%d\n", numbers[i], counts[i]);
        }
    }
    fclose(fptr);

    return 0;
}

// sort based on d array
void bubblesort_two(int a1[],int a2[], int size){
    int hold;
    for(int i=0; i<size-2; i++){
        for(int j=0; j<size-1; j++){
            if(a1[j]>a1[j+1]){
                hold= a1[j];
                a1[j]=a1[j+1];
                a1[j+1]= hold;
                hold= a2[j];
                a2[j]=a2[j+1];
                a2[j+1]= hold;
            } 
            // if the numbers are equal sort a array
            else if (a1[j] == a1[j+1]){
                if(a2[j]>a2[j+1]){
                    hold = a2[j];
                    a2[j] = a2[j+1];
                    a2[j+1] = hold;
                }
            }

        }
    }
}