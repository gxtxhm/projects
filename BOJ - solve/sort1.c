#include<stdio.h>

int main() {

    int i, j, n, imsi;
    int arr[1000];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                imsi = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = imsi;
            }
        }

    for (i = 0; i < n; i++)
        printf("%d\n", arr[i]);

    return 0;
}