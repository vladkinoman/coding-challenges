#include "circular_buffer.h"

circular_buffer_t * new_circular_buffer(size_t capacity) {
    circular_buffer_t * buffer = malloc(sizeof(circular_buffer_t));
    buffer->values = malloc(sizeof(buffer_value_t) * capacity);
    buffer->capacity = capacity;
    buffer->size  = 0;
    buffer->first = 0;
    buffer->last  = 0;
    
    return buffer;
}

int16_t read(circular_buffer_t* buffer, buffer_value_t* read_value) {
    if (buffer->size == 0) {
        errno = ENODATA;
        return EXIT_FAILURE;
    }

    *read_value = buffer->values[buffer->first];
    buffer->values[buffer->first++] = 0;
    if (buffer->first == buffer->capacity) buffer->first = 0; // wrap-around
    buffer->size--;

    return EXIT_SUCCESS;
}

int16_t write(circular_buffer_t* buffer, buffer_value_t new_value) {
    if (buffer->size == buffer->capacity) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    buffer->values[buffer->last++] = new_value;
    if (buffer->last == buffer->capacity) buffer->last = 0; // wrap-around
    buffer->size++;

    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t* buffer, buffer_value_t new_value) {
    if (buffer->size < buffer->capacity) return write(buffer, new_value);

    buffer_value_t read_value = 0;
    int16_t status = read(buffer, &read_value);
    if (status == EXIT_FAILURE) return status;
    status = write(buffer, new_value);

    return status;
}

void clear_buffer(circular_buffer_t* buffer) {
    if (buffer->size == 0) return;
    
    buffer->size  = 0;
    buffer->first = 0;
    buffer->last  = 0;
}

void delete_buffer(circular_buffer_t* buffer) {
    free(buffer->values);
    free(buffer);
}