#include <stdio.h>
#include <stdlib.h>

#define LEN 50

int shift_element(int *arr, int i) {
    for (int j = i; j >= 0; j--) {
        *(arr + j + 1) = *(arr + j);

    }
    return 0;
}

int insertion_sort(int *arr, int len) {
    for (int i = 1; i < len; ++i) {
        int t = *(arr + i);
        int count = 0;
        int j = i - 1;
        while (j >= 0 && *(arr + j) > t) {
            count++;
            j--;
        }
        shift_element((arr + i - count), count - 1);
        *(arr + i - count) = t;
    }
    return 0;
}

int printarr(int *a) {
    for (size_t i = 0; i < LEN; i++) {
        if (i == 0) {
            printf("%d", *(a));
        } else {
            printf(",%d", *(a + i));
        }

    }
    printf("\n");
    return 0;
}

int main() {
   
    int arr[LEN];
    printf("insert 50 numbers\n");
    for (int i = 0; i < LEN; i++) {
        scanf("%d", (arr + i));


    }
    printarr(arr);
    insertion_sort(arr,LEN);
    printarr(arr);
    return 0;
}
