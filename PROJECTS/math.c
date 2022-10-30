#include <stdio.h>

int palindrome(int arr);
int reverse(int arr);

int palindrome(int arr){
    if (arr == reverse(arr)){
        return 1;
    }
    else{
        return 0;
    }
}

int reverse(int arr){
    int dig;
    static int sum = 0;
    
    if(arr != 0){
            dig = arr % 10;
            sum = sum * 10 + dig;
            reverse(arr/10);
    }
        else
            return sum;
    return sum;
}

int main()
{
    int arr;
    
    printf("Insira elementos inteiros para o array: \n");
    scanf("%d", &arr);
    
    if (palindrome(arr) == 1){
        printf("True");
    }
    else{
        printf("False");
    }
}
