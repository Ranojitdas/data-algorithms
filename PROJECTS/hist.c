#include <stdio.h>

int main(){
    int n, 
    soma = 0,
    dig;
 
    printf("Digite até 9 números inteiros não negativos: ");
    scanf("%d", &n);
   
     while (n > 0){
        dig = (n % 10);
        soma += dig;
        n = n/10;
    }

    printf("%d\n", soma);

    return 0;
}