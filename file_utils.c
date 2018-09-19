#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

//read function where the store the cont
int read_file(char* filename, char **buffer) {
    
    //Professor Ira provided the code to find the size
    struct stat st;
    stat(filename, &st);
    int sizeRead = st.st_size;
    
    //opening the file and reads it
    FILE *rInput = fopen(filename, "r");
    
    //checks if the file is empty or not
    if (rInput == NULL) {
        fprintf(stderr, "Error: file is empty");
        exit(1);
    }
    
    //number counter
    int num = 0;
    //holder for the character
    char let;
    
    //while loop that scans each letter and adds the the buffer until the end
    while (fscanf(rInput, "%c", &let) != EOF)
        *buffer[num++] = let;

    //closes the read file
    fclose(rInput);
    
    return sizeRead;
}

//write function where it writes the reverse text in the other file
int write_file(char* filename, char *buffer, int size) {
    
    //Professor Ira provided the code to fine the size
    struct stat st;
    stat(filename, &st);
    int sizeWrite = st.st_size;
    
    //opening the file and writes it
    FILE *wInput = fopen(filename, "w");
    
    //checks if you can write it in there
    if (wInput == NULL) {
        fprintf(stderr, "Error: Can't write in file");
        exit(1);
    }
    
    //loops through to write it into the file
    for (int i = 0; i < size; i++)
        fprintf(wInput, "%c", buffer[i]);
    
    fclose(wInput);
    return sizeWrite;
}
