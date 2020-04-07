
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int SubsetSum(int array[], int length, int sum, int subset){
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

    if(SubsetSum(elements, 5, 2, 5)){
        printf("Success\n");
    }
    if(!SubsetSum(elements, 5, 2, 1)){
        printf("Success\n");
    }
    return 0;

    int universal[10000];
    for(int i = 0;i<100;i++){
        universal[i] = i+1;
        assert(!SubsetSum(universal,100,0,2));
        assert(!SubsetSum(universal,100,0,1));
        assert(SubsetSum(universal,100,5,2));
        assert(SubsetSum(universal,100,99,2));
        assert(SubsetSum(universal,100,80,2));
        assert(!SubsetSum(universal,100,2,2));
        assert(!SubsetSum(universal,0,2,5));
        assert(!SubsetSum(universal,100,1,2));
        //Random Tests
        for(int i = 0;i<10000;i++)
            universal[i] = rand();
            int sum = 0;
            int curSum = 0;
        //2 element tests
        for(int i = 1;i<10000;i++)
        {
            for(int j = 0;j<10000;j++) {
                curSum = universal[rand() % 10000] + sum;
                assert(SubsetSum(universal, 10000, curSum, i));
            }
            sum+=curSum;
        }
    }
}