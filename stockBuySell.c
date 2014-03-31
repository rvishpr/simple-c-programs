#include <stdio.h>

int main(void)
{
//    int arr[] = {2, 5, 1, 7, 2, 9, 3, 0, 8};
    int arr[] = {10, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15, 0};
    int len = sizeof(arr) / sizeof(int);
    int i = 0;
    int maxSum, maxIndex, buyIndex, lowIndex, sum;
    maxSum = maxIndex = buyIndex = lowIndex = sum = 0;

    printf("arr = %d ", arr[0]);
    for (i = 1; i < len; i++) {
        printf("%d ", arr[i]);

        sum += arr[i] - arr[i-1];
        /*
         * Keep track of the maximum sum (of the diffs until now)
         * The highest sum is where we should sell, since it has increased
         * as much as it can and it will drop after that
         */
        if (maxSum < sum) {
            maxSum = sum;
            maxIndex = i;
            /*
             * keep track of the lowest buy value before the maxSum
             */
            lowIndex = buyIndex;
        }

        if (arr[i] < arr[buyIndex]) {
            buyIndex = i;
        }
    }

    printf("\nbuy at %d, sell at %d\n", arr[lowIndex], arr[maxIndex]);
    printf("buy at index %d, sell at index %d\n", lowIndex, maxIndex);
}
