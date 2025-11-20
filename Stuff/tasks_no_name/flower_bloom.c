#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


char *func(char *name,bool months[12], int size){
    char *result = malloc(sizeof(char) *  9 * 12 + sizeof(char) * size);    
    if(result == NULL){
        printf("ERROR: Memory Allocation Failed.\n");
        exit(1);
    }

    strcpy(result, name);
    for(int i = 0;i<12;i++){
        if(months[i]){
            switch(i){
                case 0: strcat(result, " January");break;
                case 1: strcat(result, " February");break;
                case 2: strcat(result, " March");break;
                case 3: strcat(result, " April");break;
                case 4: strcat(result, " May");break;
                case 5: strcat(result, " June");break;
                case 6: strcat(result, " July");break;
                case 7: strcat(result, " August");break;
                case 8: strcat(result, " Septmeber");break;
                case 9: strcat(result, " October");break;
                case 10: strcat(result, " November");break;
                case 11: strcat(result, " December");break;
            }
        }
    }

    return result;
    

}


int main(){
    char *name = "lale";
    int size = strlen(name);
    bool months[12] = {0,0,1,1,1,0,0,0,0,0,0,0};
    printf("result: %s\n", func(name, months, size));

}