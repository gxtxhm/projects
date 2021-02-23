#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int cntZero = 0;
int cntOne = 0;
int a[100000];
int memo[41];
int memoZero[41];
int memoOne[41];


int fibonacci(int n) {
    if (n == 0) {
        cntZero++;
        return 0;
    }
    else if (n == 1) {
        cntOne++;
        return 1;
    }
    else {

        if (memo[n] != 0)
        {
            memoOne[n] = memoOne[n - 1] + memoOne[n - 2];
            memoZero[n] = memoZero[n - 1] + memoZero[n - 2];

            return memo[n];
        }
        else
        {

            memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
            memoOne[n] = memoOne[n - 1] + memoOne[n - 2];
            memoZero[n] = memoZero[n - 1] + memoZero[n - 2];
            return memo[n];

        }



    }
}

int main()
{
    int N;
    scanf("%d", &N);
    memoOne[0] = 0;
    memoZero[0] = 1;
    memoOne[1] = 1;
    memoZero[1] = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < N; i++)
    {
        cntOne = 0;
        cntZero = 0;
        fibonacci(a[i]);
        printf("%d %d\n", memoZero[a[i]], memoOne[a[i]]);
    }
    return 0;
}