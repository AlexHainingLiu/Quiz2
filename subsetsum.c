
#include <stdbool.h>
#include <stdio.h>

int sumsTo(int array[], int length, int subset, int sum){
    if(sum == 0 && subset == 0){
        return true;
    }
    if (sum != 0 && subset == 0){
        return false;
    }
    if (length == 0){
        return false;
    }
    int res1 = 0;
    if (sum >= array[0]){
        res1 = sumsTo(array + 1, length - 1, subset - 1, sum - array[0]);
    }
    int res2 = sumsTo(array + 1, length - 1, subset, sum);
    return res1 + res2 > 0;
}

int main (void){
    int elements[5] = {1, 2, 3 ,4 ,5};

    if(sumsTo(elements, 5, 2, 5)){
        printf("Success\n");
    }
    if(!sumsTo(elements, 5, 2, 1)){
    printf("Success\n");
    }
    return 0;
}