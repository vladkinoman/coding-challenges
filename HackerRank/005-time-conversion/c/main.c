#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

char * format_datenumber_with_adding_zero(char * strformat, int number)
{
	if(number < 10)
		strcat(strformat, "0%d");
	else
		strcat(strformat,"%d");
	return strformat;
}

char * format_militarydate(char * str, int hh, int mm, int ss)
{
	char * strformat = malloc(12);
	*strformat = '\0';
	strformat = format_datenumber_with_adding_zero(strformat, hh);
	strcat(strformat, ":");
	strformat = format_datenumber_with_adding_zero(strformat, mm);
	strcat(strformat, ":");
	strformat = format_datenumber_with_adding_zero(strformat, ss);
	sprintf(str, strformat, hh, mm, ss);
	return str;
}

char* timeConversion(char* s) {
	int hh;
	int mm;
	int ss;
	char half[3];
	sscanf(s, "%d %*c %d %*c %d %s", &hh, &mm, &ss, half);
	if(hh < 1 || hh > 12)
		exit(EXIT_FAILURE);
	if(mm < 0 || mm > 59)
		exit(EXIT_FAILURE);
	if(ss < 0 || ss > 59)
		exit(EXIT_FAILURE);

	char * str = malloc(10);
	*str = '\0';

	if     (hh == 12 && strcmp(half, "AM") == 0)
		str = format_militarydate(str, hh * 0, mm, ss);
	else if(hh != 12 && strcmp(half, "AM") == 0
		|| hh == 12 && strcmp(half, "PM") == 0)
		str = format_militarydate(str, hh, mm, ss);
	else if(hh != 12 && strcmp(half, "PM") == 0)
		str = format_militarydate(str, hh + 12, mm, ss);
	
	return str;
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
