#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the gradingStudents function below.
 */

/*
 * Please store the size of the integer array to be returned in result_count pointer. For example,
 * int a[3] = {1, 2, 3};
 *
 * *result_count = 3;
 *
 * return a;
 *
 */
int* gradingStudents(int grades_count, int* grades, int* result_count) {
    if(grades_count < 1 || grades_count > 60)
        exit(1);
    for(int i = 0; i < grades_count; i++)
        if(*(grades + i) < 0 || *(grades + i) > 100)
            exit(1);
    
    int * a = malloc(grades_count*sizeof(int));
    *result_count = grades_count;

    for(int i = 0; i < grades_count; i++)
    {
        if (grades[i] < 38) 
        {
            a[i] = grades[i];
            continue;
        }
        int nmultiple;
        for (nmultiple = grades[i]; ; ++nmultiple)
            if((nmultiple % 5) == 0)
                break;
        if((nmultiple - grades[i]) < 3)
            a[i] = nmultiple;
        else
            a[i] = grades[i];
        
    }            
    return a;
}

int main()
{
    //FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    int grades[n];

    for (int grades_itr = 0; grades_itr < n; grades_itr++) {
        char* grades_item_endptr;
        char* grades_item_str = readline();
        int grades_item = strtol(grades_item_str, &grades_item_endptr, 10);

        if (grades_item_endptr == grades_item_str || *grades_item_endptr != '\0') { exit(EXIT_FAILURE); }

        grades[grades_itr] = grades_item;
    }

    int result_count;
    int grades_count = n;
    int* result = gradingStudents(grades_count, grades, &result_count);

    for (int result_itr = 0; result_itr < result_count; result_itr++) {
        fprintf(stdout/*fptr*/, "%d", result[result_itr]);

        if (result_itr != result_count - 1) {
            fprintf(stdout/*fptr*/, "\n");
        }
    }

    fprintf(stdout/*fptr*/, "\n");

    //fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
