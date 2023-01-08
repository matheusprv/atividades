#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    long long int n1;
    long long int n2;

    while (scanf("%lld", &n1) != EOF){
        scanf("%lld", &n2);

        long long int diferenca = n2-n1;

        if(diferenca < 0)
            diferenca *= -1;

        printf("%lld\n", diferenca);

    }
    
    return 0;
}