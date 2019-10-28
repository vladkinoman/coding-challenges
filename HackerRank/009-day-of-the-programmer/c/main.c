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

#define PROGRAMMER_DAY 256

static char daytab[2][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int get_day_and_month(int is_leap, int is_1918, int * month, int * day)
{
	for (int i = 0, sum = 0; i < 12; ++i)
	{
		if((sum + daytab[is_leap][i]) > PROGRAMMER_DAY)
		{
			*day = PROGRAMMER_DAY - sum;
			*month = i + 1;
			break;
		}
		if(is_1918 && i == 1) sum += daytab[is_leap][i] - 13;
		else sum += daytab[is_leap][i];
	}
}

// Complete the solve function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//
char* solve(int year) {

	if(year < 1700 || year > 2700)
		exit(EXIT_FAILURE);
	
	int month;
	int day;

	if(year < 1918 && (year % 4 == 0))
		get_day_and_month(1, 0, &month, &day);
	else if(year > 1918 && (year % 400 == 0 || year % 4 == 0 && year % 100 != 0))
		get_day_and_month(1, 0, &month, &day);		
	else if(year == 1918) // isn't a leap year
		get_day_and_month(0, 1, &month, &day);
	else
		get_day_and_month(0, 0, &month, &day);

	char * date = malloc(10);
	if(day < 10 && month < 10)
		sprintf(date, "0%d.0%d.%d", day, month, year);
	else if(day < 10 && month >= 10)
		sprintf(date, "0%d.%d.%d", day, month, year);
	else if(day >= 10 && month < 10)
		sprintf(date, "%d.0%d.%d", day, month, year);
	else if(day >= 10 && month >= 10)
		sprintf(date, "%d.%d.%d", day, month, year);
	return date;
}

int main()
{
    //FILE* fptr = fopen(/*getenv("OUTPUT_PATH")*/, "w");

    char* year_endptr;
    char* year_str = readline();
    int year = strtol(year_str, &year_endptr, 10);

    if (year_endptr == year_str || *year_endptr != '\0') { exit(EXIT_FAILURE); }

    char* result = solve(year);

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
