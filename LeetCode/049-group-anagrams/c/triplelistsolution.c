#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct list_item
{
	struct list_item * next;
	struct alist_item * ahead;
	int count_anagrams;
};

struct alist_item
{
	char * anagram;
	struct alist_item * next;
};

struct list_item * list_init(struct list_item * head)
{
	head = NULL;
	return head;
}

struct list_item * list_add(struct list_item * head, struct alist_item * aitem)
{
	struct list_item * tmp = malloc(sizeof(struct list_item));
	tmp->ahead = aitem;
	tmp->next = head;
	tmp->count_anagrams = 0;
	head = tmp;
	return head;
}

void list_print(struct list_item * head)
{
	while(head != NULL)
	{
		printf("count of anagrams in list: %d\n[", head->count_anagrams);
		while(head->ahead != NULL)
		{
			printf(" %s ", head->ahead->anagram);
			head->ahead = head->ahead->next;
		}
		printf("]\n");
		head = head->next;
	}
}

struct alist_item * alist_init(struct alist_item * ahead)
{
	ahead = NULL;
	return ahead;
}

struct list_item * alist_add(struct list_item * head, char * str)
{
	struct alist_item * tmp = malloc(sizeof(struct alist_item));
	tmp->anagram = str;
	tmp->next = head->ahead;
	head->ahead = tmp;
	head->count_anagrams++;
	return head;
}

struct clist_item
{
    char c;
    int is_appeared;
    struct clist_item * next;
};

struct clist_item * clist_init(struct clist_item * chead)
{
	chead = NULL;
	return chead;
}

struct clist_item * clist_add(struct clist_item * chead, char c)
{
    struct clist_item * tmp = malloc(sizeof(struct clist_item));
	tmp->c = c;
	tmp->is_appeared = 0;
	tmp->next= chead;
	chead = tmp;
	return chead;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
	struct list_item * head;
	head = list_init(head);
	
	*returnSize = 0;
	for (int i = 0; i < strsSize; ++i)
	{
		if(strs[i] == NULL) continue;
		struct alist_item * ahead;
		ahead = alist_init(ahead);
		head = list_add(head, ahead);
		head = alist_add(head, strs[i]);
		*returnSize = *returnSize + 1;
		for (int j = i + 1; j < strsSize; ++j)
		{
			if(strs[j] == NULL) continue;
			int ilen = strlen(strs[i]);
			int jlen = strlen(strs[j]);
			if(ilen != jlen) continue;
			int k;
            if(strcmp((strs[i]), (strs[j])) == 0) printf("%s == %s\n",strs[i],strs[j]);
            struct clist_item * chead;
            struct clist_item * cfirst;
            struct clist_item * cprev;
            chead = clist_init(chead);
            
            for(int p = 0; p < jlen; p++)
                chead = clist_add(chead, strs[j][p]);
            cfirst = chead;
			for (k = 0; k < ilen; ++k)
            {
                int is_found = 0;
                for(cprev = NULL; chead != NULL; chead = chead->next)
                {
                    if(chead->c == *(*(strs + i ) + k))
                    {
                        if(cprev) cprev->next = chead->next;
                        if(cfirst == chead) cfirst = chead->next;
                        free(chead);
                        chead = cprev;
                        is_found = 1;
                        break;
                    }
                    cprev = chead;
                }
                chead = cfirst;
                if(!is_found) break;
            }

            // free the list with characters from strs[j]
            
            while(chead != NULL)
            {
                cprev = chead;
                chead=chead->next;
                free(cprev);
            }

			if(k != ilen) continue;
			head = alist_add(head, strs[j]);
			strs[j] = NULL;
		}
		strs[i] = NULL;
	}
	
	char *** strres = (char ***) malloc(*returnSize * sizeof(char **));
	// we don't have to malloc columnSizes because we need to return values to the caller function
    // so we use this model: colSizes -> *colSizes (malloc this) -> array of sizes
    *columnSizes = (int *) malloc(*returnSize * sizeof(int));
	struct list_item * prev;
    struct alist_item * aprev;
	for(int i = 0; head != NULL;i++)
	{
		strres[i] = (char **) malloc(head->count_anagrams * sizeof(char *));
		*(*(columnSizes) + i) = head->count_anagrams;
		for(int j = 0; head->ahead != NULL; j++)
		{
			strres[i][j] = head->ahead->anagram;
			aprev = head->ahead;
			head->ahead = head->ahead->next;
			free(aprev);
		}
		prev = head;
		head = head->next;
        free(prev);
	}
	return strres;
}

int main(int argc, char *argv[])
{
	int strsSize = argc - 1; 
	char** strs = malloc(strsSize);
	for (int i = 0; i < strsSize; ++i)
	{
		strs[i] = malloc(strlen(argv[i + 1]));
		strs[i] = argv[i + 1];
	}
	int* columnSizes = malloc(sizeof(int));
	int* returnSize  = malloc(sizeof(int));
	char *** strresult = groupAnagrams(strs, strsSize, &columnSizes, returnSize);
	for (int i = 0; i < *returnSize; ++i)
	{
		printf("count of anagrams in list: %d\n[", columnSizes[i]);
		for (int j = 0; j < columnSizes[i]; ++j)
		{
			printf(" %s ", strresult[i][j]);
		}
		printf("]\n");
	}
	return 0;
}