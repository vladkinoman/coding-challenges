#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct list_of_anagram_lists
{
	struct list_of_anagram_lists * next;
	struct anagram_list * alist;
	int anagrams_count_in_cur_list;
};

struct anagram_list{
	char * info;
	struct anagram_list * next;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
    char ** newStrs = malloc(strsSize);

    for (int i = 0; i < strsSize; ++i)
    {
    	*(newStrs + i) = malloc(strlen(*(strs + i)));
    	*(newStrs + i) = *(strs + i);
    	//strcpy(*(newStrs + i), *(strs + i));
    }
    struct list_of_anagram_lists * main_list;
    struct list_of_anagram_lists * mlist_add_ptr = main_list;
    int count_of_lists = 0;
    for (int i = 0; i < strsSize - 1; ++i)
    {
    	if(*(newStrs + i) == NULL) continue;
    	main_list = malloc(sizeof(struct list_of_anagram_lists));
    	main_list->alist = malloc(sizeof(struct anagram_list));
    	strcpy(main_list->alist->info, *(newStrs + i));
    	main_list->anagrams_count_in_cur_list++;
    	count_of_lists++;
    	for (int j = i + 1; j < strsSize; ++j)
    	{
    		int ilen = strlen(*(newStrs + i));
    		int jlen = strlen(*(newStrs + j)); 
    		if(*(newStrs + j) == NULL || ilen != jlen) continue;
    		int k;
    		for (k = 0; k < ilen; ++k)
    			if(strchr(*(newStrs + j), *(*(newStrs + i) + k)) == NULL)
    				break;
    		if(k != ilen) continue;
    		main_list->alist->next = malloc(sizeof(struct anagram_list));
    		main_list->alist = main_list->alist->next;
    		strcpy(main_list->alist->info, *(newStrs + j));
    		*(newStrs + j) = NULL;
    		main_list->anagrams_count_in_cur_list++;
    	}
    	main_list = main_list->next;
    }
    main_list = mlist_add_ptr;

    char *** strres = malloc(count_of_lists);
    returnSize = malloc(sizeof(int));
    *returnSize = count_of_lists;
    columnSizes = malloc(sizeof(int) * count_of_lists);
    for (int i = 0; i < count_of_lists; ++i)
    {
    	*(strres + i) = malloc(main_list->anagrams_count_in_cur_list);
    	*(columnSizes + i) = malloc(sizeof(int));
    	**(columnSizes + i) = main_list->anagrams_count_in_cur_list;
    	for (int j = 0; j < main_list->anagrams_count_in_cur_list; ++j)
    	{
    		strcpy(*(*(strres + i) + j), main_list->alist->info);
    		struct anagram_list * prev_anode = main_list->alist;
    		main_list->alist = main_list->alist->next;
    		free(prev_anode);
     	}
     	struct list_of_anagram_lists * prev_mnode = main_list;
     	main_list = main_list->next;
     	free(prev_mnode);
    }
    return strres;
}

int main(int argc, char *argv[])
{
	int * size;
	int ** innersizes;
	char *** res = groupAnagrams(argv, argc, innersizes, size);
	for (int i = 0; i < *size; ++i)
	{
		for (int j = 0; j < **(innersizes + i); ++j)
			printf("%s ", *(*(res + i) + j));
		printf("\n");
	}

	return 0;
}