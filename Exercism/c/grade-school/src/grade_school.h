#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 20

typedef struct {
   uint8_t grade;
   char *name;
} student_t;

typedef struct {
   size_t count;
   student_t students[MAX_STUDENTS];
} roster_t;

int cmpfunc (const void * va, const void * vb);

bool add_student(char *name, uint8_t grade);

roster_t get_grade(uint8_t desired_grade);

roster_t get_roster();

void clear_roster();

#endif
