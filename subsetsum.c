
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int SubsetSum(int array[], int length, int subset, int sum){
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
        res1 = SubsetSum(array + 1, length - 1, subset - 1, sum - array[0]);
    }
    int res2 = SubsetSum(array + 1, length - 1, subset, sum);
    return res1 + res2 > 0;
}

int main (void){
    int elements[5] = {1, 2, 3 ,4 ,5};

    if(!SubsetSum(elements, 5, 5, 2)){ // 2 is not able to be found with 5 elements
        printf("Success\n");
    }
    if(SubsetSum(elements, 5, 1, 2)){ // 2 is able to be found with 1 element
        printf("Success\n");
    }
    if(SubsetSum(elements, 5, 2, 4)){ // 4 is able to be found with 2 elements
        printf("Success\n");
    }
    if(!SubsetSum(elements, 5, 2, 0)){ // 0 is not able to be found with 2 elements
        printf("Success\n");
    }
}

