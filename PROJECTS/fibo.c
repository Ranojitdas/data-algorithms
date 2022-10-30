#include <stdio.h>
#include <stdlib.h>

int *fibonacci(int num);

int main(){

    int num, *f;
    printf("Número:");
    scanf("%d", &num);

    f = fibonacci(num);

    for (int i = 0; i < num; i++){
        printf("%d -> ", f[i]);
    }

    free(f);
    return 0;
}

int *fibonacci(int num){

    int a = 1, b = 1, c, *fibo;

    fibo = malloc(sizeof(int) * num);

    for (int i = 0; i < num; i++){
        fibo[i] = a;
        c = a + b;
        a = b;
        b = c;
    }

    return fibo;

}