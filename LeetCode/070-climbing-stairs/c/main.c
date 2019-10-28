#include <stdio.h>
#include <stdlib.h>

int climb_Stairs(int i, int n) {
    if (i > n) return 0;
    if (i == n) return 1;

    return climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
}

int climbStairs(int n) {
    return climb_Stairs(0, n);
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	printf("%d", climbStairs(n));
	return 0;
}