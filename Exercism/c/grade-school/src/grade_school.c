#include "grade_school.h"

static roster_t roster = { 0 };

int cmpfunc (const void * va, const void * vb) {
   student_t * a = (student_t*)va;
   student_t * b = (student_t*)vb;
   int exp = a->grade - b->grade;
   if (exp) return exp;
   return strcmp(a->name, b->name);
}

bool add_student(char *name, uint8_t grade) {
    roster.students[roster.count].grade  = grade;
    roster.students[roster.count++].name = name;

    qsort(roster.students, roster.count, sizeof(student_t), cmpfunc);
    
    return true;
}

roster_t get_grade(uint8_t desired_grade) {
    roster_t roster_of_grade = { 0 };

    for (size_t i = 0; i < roster.count; i++) {
        if (roster.students[i].grade == desired_grade) {
            for (size_t j = i; j < roster.count && roster.students[j].grade 
                == desired_grade; j++) {
                
                roster_of_grade.students[roster_of_grade.count].grade 
                    = roster.students[j].grade;

                roster_of_grade.students[roster_of_grade.count++].name 
                    = roster.students[j].name;
            }
            break;
        }
    }

    return roster_of_grade;
}

roster_t get_roster() {
    return roster;
}

void clear_roster() {
    roster_t empty_roster = {0};
    roster = empty_roster;
}