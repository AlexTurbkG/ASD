#include <stdio.h>

int func(int rights, char access, char type){
    switch(access){
        case 'u': rights >>= 6;break;
        case 'g': rights >>= 3;break;
        case 'o': break;
        default: printf("Not a valid access form.\n");
    }

    switch(type){
        case 'r': 
            if(rights & (1 << 2)){
                printf("Yes\n");
            }
            else printf("No\n");
            break;
        case 'w':
            if(rights & (1 << 1)){
                printf("Yes\n");
            }
            else printf("No\n");
            break;
        case 'x':
            if(rights & 1){
                printf("Yes\n");
            }
            else printf("No\n");
            break;
        default: printf("Not a valid type.\n");
    }
}


int main(){
    func(755, 'u', 'w');
}