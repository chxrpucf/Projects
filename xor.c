/*
xor.c


*/

#include <stdio.h>
#include <stdlib.h>

#define KEY 'X';


void printchar (char c, char *text) {
    printf("%s, '%c' (0x%x)\n", text, c, c);
    return;
}

//main
int main() {
    char cleartext, key, ciphertext, newcleartext;

    //open file in read mode
    FILE *file = fopen("input.txt", "r");
    
    //check if file is opened
    if(file == NULL) {
        printf("Error: Could not open file.\n");
        return 1; //exit if file is not opened
    }

    //read file until no more characters remaining
    while ((cleartext = fgetc(file)) != EOF) {
        printchar(cleartext, "cleartext");

    key = KEY;  
    printchar(key, "key");  

    //XOR
    ciphertext = cleartext ^ key;
    printchar(ciphertext, "ciphertext");

    newcleartext = ciphertext ^ key;
    printchar(newcleartext, "newcleartext");

    printf("\n"); 

    }

    fclose(file); //close file
    return 0; //exit
}