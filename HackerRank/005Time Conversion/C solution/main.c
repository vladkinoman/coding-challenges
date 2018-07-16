#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* itoa_zero(int num, char* s)
{
	if(num < 10)
	{
		s[0] = '0';
		s[1] = '0' + num;	
	}
	else
	{
		s[0] = '0'+ (num / 10);
		s[1] = '0'+ (num % 10);
	}
	s[2] = '\0';
	return s;
}
/*
 * Complete the timeConversion function below.
 */

/*
 * Please either make the string static or allocate on the heap. For example,
 * static char str[] = "hello world";
 * return str;
 *
 * OR
 *
 * char* str = "hello world";
 * return str;
 *
 */
char* timeConversion(char* s) {
	char * input_str = malloc(10*sizeof(char));
	strcpy(input_str, s);
	char * hh = strtok(s, ":");
	char * other_part = strtok(NULL, "AP");
	char * half = strpbrk(input_str, "AP");
	char * str = malloc(10);
	if     (strcmp(hh, "12") == 0 && strcmp(half, "AM") == 0)
		str = "00:00:00";
	else if(strcmp(hh, "12") == 0 && strcmp(half, "PM") == 0
		|| strcmp(hh, "12") != 0 && strcmp(half, "AM") == 0) 
		str = input_str;
	else if(strcmp(hh, "12") != 0 && strcmp(half, "PM") == 0)
	{
		int ihh = atoi(hh);
		ihh += 12;
		char * shh = malloc(10 * sizeof(char));
		shh = itoa_zero(ihh, shh);
		str = strcat(str, strcat(shh, strcat(":", other_part)));
	}
	return str;
	//printf("%s\n%s\n%s\n%s\n", hh, mm, ss, half);
	//printf("%s\n", input_str);

	/*if(strcmp(hh, "12") == 0 
		&& strcmp(mm, "00") == 0
		&& strcmp(ss, "00") == 0)
	*/
}



int main()
{
    //FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

    fprintf(stdout/*fptr*/, "%s\n", result);

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
