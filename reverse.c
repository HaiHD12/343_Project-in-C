#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

/*********************************************************
 *This program inputs a text and reverse the contect
 *then writes it into another input
 *
 * @author Hai Duong
 * @semster Fall 2018
 *********************************************************/


int main(int argc, char** argv) {
   
    //checks to make sure there are three arugments
    if (argc != 3) {
        fprintf(stderr,"Input Invalid, need 3 arguments");
        exit(1);
    }
    
    //pointer to hold file
    char *buffer;
    
    //calls read_file and returns the size of it
    int read = read_file(argv[1], &buffer);
    
    //malloc to hold characters
    char *storeRev = (char*)malloc(read * sizeof(char));
    
    //for loop to reverse the letters
    for(int i = 0; i < read; i++)
        storeRev[read - 1 - i] = buffer[i];
    
    //writes the content into file 2 and returns the size
    int write = write_file(argv[2], storeRev, read);
    
    //checks if the files are not equal
    if (read != write) {
        fprintf(stderr, "Error: Both files don't match");
        exit(1);
    }
    
    //free space from mallac
    free(storeRev);
    free(buffer);
    
    return 0;
}

