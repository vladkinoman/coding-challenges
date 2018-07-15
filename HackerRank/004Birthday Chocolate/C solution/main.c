#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the solve function below.
int solve(int s_count, int* s, int d, int m) {
	// constraints
	if(s_count < 1 || s_count > 100)
		exit(1);
	for (int i = 0; i < s_count; ++i)
		if(*(s+i) < 1 || *(s+i) > 5)
			exit(1);
	if(d < 1 || d > 31)
		exit(1);
	if(m < 1 || m > 12)
		exit(1);

	int total_bar_count = 0;
	for (int i = 0; i < s_count; ++i)
	{
		int d_sum = 0;
		int m_counter = 0;
		for (int j = i; j < s_count; ++j)
		{
			d_sum += s[j];
			m_counter++;
			if(d_sum == d && m_counter == m)
			{
				total_bar_count++;
				break;
			}
			if(d_sum > d || m_counter > m)
				break;
		}
	}

	return total_bar_count;
}

int main()
{
    /*FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
*/
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** s_temp = split_string(readline());

    int* s = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* s_item_endptr;
        char* s_item_str = *(s_temp + i);
        int s_item = strtol(s_item_str, &s_item_endptr, 10);

        if (s_item_endptr == s_item_str || *s_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(s + i) = s_item;
    }

    int s_count = n;

    char** dm = split_string(readline());

    char* d_endptr;
    char* d_str = dm[0];
    int d = strtol(d_str, &d_endptr, 10);

    if (d_endptr == d_str || *d_endptr != '\0') { exit(EXIT_FAILURE); }

    char* m_endptr;
    char* m_str = dm[1];
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    int result = solve(s_count, s, d, m);

    fprintf(stdout/*fptr*/, "%d\n", result);

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

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
