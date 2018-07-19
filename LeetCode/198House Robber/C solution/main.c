#include <stdio.h>
#include <stdlib.h>

int rob(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; ++i)
    	if(*(nums + i) < 0)
    		exit(1);
    
    int sumFromFirstHouse = 0;
    for (int i = 0; i < numsSize; i+=2)
    	sumFromFirstHouse += *(nums + i);
    int sumFromSecondHouse = 0;
    for (int i = 1; i < numsSize; i+=2)
    	sumFromSecondHouse += *(nums + i);
    if(sumFromFirstHouse > sumFromSecondHouse)
    	return sumFromFirstHouse;
    else
    	return sumFromSecondHouse;
}

int main(int argc, char const *argv[])
{
	int numsSize;
	scanf("%d\n", &numsSize);
	int c;
	int * nums = malloc(numsSize * sizeof(int));
	for(int i = 0; i < numsSize; i++)
		scanf("%d", &nums[i]);
	printf("You can get: %d\n", rob(nums, numsSize));
	return 0;
}