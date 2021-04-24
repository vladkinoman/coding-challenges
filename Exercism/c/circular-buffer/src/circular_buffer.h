#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <errno.h>
#include <stdint.h>
#include <stdlib.h>

typedef int16_t buffer_value_t;

typedef struct { 
    buffer_value_t * values;
    int capacity;
    int size;
    int first;
    int last;
} circular_buffer_t; // based on Queue

circular_buffer_t * new_circular_buffer(size_t capacity);
int16_t read(circular_buffer_t* buffer, buffer_value_t* read_value);
int16_t write(circular_buffer_t* buffer, buffer_value_t new_value);
int16_t overwrite(circular_buffer_t* buffer, buffer_value_t new_value);
void clear_buffer(circular_buffer_t* buffer);
void delete_buffer(circular_buffer_t* buffer);

#endif