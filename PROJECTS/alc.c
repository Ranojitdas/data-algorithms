#include <stdio.h>

int len(char *str);



int main(int argc, char *argv[]){
    char *str_max, *str_min, str[41] = "";

    if (len(argv[1]) >= len(argv[2])){
        str_max = argv[1];
        str_min = argv[2];
    }else{
        str_max = argv[2];
        str_min = argv[1];
    }

    int i = 0, j = 0;
    while(i < len(str_min)){
        str[j] = argv[1][i];
        str[1 + j] = argv[2][i++];
        j += 2;
    }

    while(i < len(str_max)){
        str[j++] = str_max[i++];
    }

    printf("%s", str);

    return 0;
}


int len(char *str){
    int lenght = 0;
    for (; *str++;){
        lenght++;

    }
    return lenght;
}