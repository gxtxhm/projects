#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

 int arr[1000001];

 int fibonacci(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else {
        if (arr[n] != 0)
        {
           return arr[n];
        }
        else
        {
            arr[n]= (fibonacci(n - 1) + fibonacci(n - 2))%15746;
            return arr[n];
        }
    }
}


int main()
{
    int N;
    scanf("%d", &N);
    arr[1] = 1;
    arr[2] = 2;
    fibonacci(N);
    printf("%d", arr[N]);
    
    return 0;
}
