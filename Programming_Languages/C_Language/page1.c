#include <stdio.h>


void start(){
    char name[];
    printf("Enter your name: \n");
    scanf("%s", name);
    printf("Hello, %s!\n", name);
    for(int i = 0; i < 5; i++) {
        printf("This is line %d\n", i + 1);
    }
}
int main() {
    printf("Hello, World in C!\n");
    return 0;
}
