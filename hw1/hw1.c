/* 
 * Yasemin Arslan
 * 1901042263
 * CSE102 - hw1
 * 
 * Description: Finds duplicate integers in a file, and replaces 
 *   them with spaces.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fptr;
    int number, testnumber;
    long int loc;
    int digit=0;

    // Try to open the file and return if cannot open
    if((fptr = fopen("file.txt", "r+")) == NULL)
    {
        printf("Could not open the file...");
        return -1;
    } else {
        // First loop on testing integers
        while(!feof(fptr)){
            int x = fscanf(fptr, "%d", &number);
        // If there is no integers to read, exit. 
            if (x == -1) {return -1;}
            loc = ftell(fptr);
                // Test the selected integers with the following integer
                while(!feof(fptr)){
                    int y = fscanf(fptr, "%d", &testnumber);
                    // If there is no integers to read, break. 
                    if (y == -1) {break;}
                    // Finding the number of digits
                    if (number == testnumber){
                        if(testnumber<0){
                            digit=1;
                            testnumber = testnumber * -1;
                        }
                        
                        while(testnumber>10){
                            testnumber= testnumber/10;
                        //This is for decimal part.
                            digit++;
                        }
                        //This is for the whole number part.
                        digit++;
                        // Finds duplicate integers in a file, and replaces them 
                        // with spaces.
                        fseek(fptr, ftell(fptr)-digit, 0);
                        for(int i=0; i<digit; i++){
                            fprintf(fptr, " ");
                        }
                        digit = 0;
                    }
                }
                fseek(fptr, loc, 0);
            }
        fclose(fptr);
        }    

    return 0;
}