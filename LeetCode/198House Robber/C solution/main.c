#include <stdio.h>
#include <stdlib.h>

struct list_item
{
    struct list_item * prev;
    struct list_item * next;
    int value;
    int is_security_activated;
};

struct list_item * list_init(struct list_item * head)
{
    head = NULL;
    return head;
}

struct list_item * list_add(struct list_item * head, int value)
{
    struct list_item * tmp = malloc(sizeof(struct list_item));
    tmp->value = value;
    tmp->is_security_activated = 0;
    tmp->prev = NULL;
    tmp->next = head;
    if(head) head->prev = tmp;
    head = tmp;
    return head;
}

struct list_item * list_find_max(struct list_item * head)
{
    int max = 0;
    struct list_item * elem_with_max = NULL;
    struct list_item * first = head;
    while(head != NULL)
    {
        if(head->value > 0 && head->value > max 
            && !head->is_security_activated){
            max = head->value;
            elem_with_max = head;
        }
        head = head->next;
    }
    return elem_with_max;
}

int rob(int* nums, int numsSize) {
    int sum = 0;
    struct list_item * head;
    head = list_init(head);

    for (int i = 0; i < numsSize; ++i)
        head = list_add(head, nums[i]);

    struct list_item * house_to_rob;
    while((house_to_rob = list_find_max(head)) != NULL)
    {
        sum += house_to_rob->value;
        house_to_rob->value = 0;
        if(house_to_rob->prev)
            house_to_rob->prev->is_security_activated = 1;
        if(house_to_rob->next)
            house_to_rob->next->is_security_activated = 1;
    }

    return sum;
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