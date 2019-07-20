#include <stdio.h>

int rob(int* nums, int numsSize) {
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