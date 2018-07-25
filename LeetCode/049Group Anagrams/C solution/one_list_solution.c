#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// Runtime: 1080 ms
char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {

    *returnSize = 0;
    char *** strres = (char ***) malloc(strsSize * sizeof(char **));
    *columnSizes = (int *) malloc(strsSize * sizeof(int));
    // p points to current array of anagrams
    // q points to current anagram in current array[p]
    for (int i = 0, p = 0, q = 0, count_anagrams_in_cur_list = 0; i < strsSize; 
                      ++i, q = 0, count_anagrams_in_cur_list = 0)
    {
        if(*(strs + i) == NULL) continue;
        
        *(strres + p) = (char **) malloc(strsSize * sizeof(char *));
        *(*(strres + p) + q) = *(strs + i); // add first anagram in list
        count_anagrams_in_cur_list++;
        q = q + 1;
        *returnSize = *returnSize + 1;
        for (int j = i + 1; j < strsSize; ++j)
        {
            if(*(strs + j) == NULL) continue;
            int ilen = strlen(*(strs + i));
            int jlen = strlen(*(strs + j));
            if(ilen != jlen) continue;
            
            
            int is_passed = 0;
            for(int p = 0, c_counter_i = 0, c_counter_j = 0; p < ilen;
                    p++  , c_counter_i = 0, c_counter_j = 0)
            {
                for(int q = 0; q < ilen; q++)
                    if(strs[i][p] == strs[i][q])
                        c_counter_i++;
                
                for(int q = 0; q < jlen; q++)
                    if(strs[i][p] == strs[j][q])
                        c_counter_j++;
                
                if(c_counter_i != c_counter_j) 
                { 
                    is_passed = 1; 
                    break;
                }
            }
            if(is_passed) continue;
            
            
            *(*(strres + p) + q) = *(strs + j); // add other anagrams to list
            q = q + 1;
            count_anagrams_in_cur_list++;
            *(strs + j) = NULL;
        }
        
        *(*(columnSizes) + p) = count_anagrams_in_cur_list;
        *(strs + i) = NULL;
        p = p + 1;
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
	int returnSize;
	char *** strresult = groupAnagrams(strs, strsSize, &columnSizes, &returnSize);
	for (int i = 0; i < returnSize; ++i)
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