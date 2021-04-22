#include "circular_buffer.h"

circular_buffer_t * new_circular_buffer(size_t capacity) {
    circular_buffer_t * buffer = malloc(sizeof(circular_buffer_t));
    buffer->values = malloc(sizeof(buffer_value_t) * capacity);
    memset(buffer->values, 0, sizeof(buffer_value_t) * capacity);
    return buffer;
}

int16_t read(circular_buffer_t* buffer, buffer_value_t* read_value) {
    if (buffer->capacity == 0) return EXIT_FAILURE;
    return 0;
}

int16_t write(circular_buffer_t* buffer, buffer_value_t new_value) {
    return 0;
}

int16_t overwrite(circular_buffer_t* buffer, buffer_value_t new_value) {
    return 0;
}

void clear_buffer(circular_buffer_t* buffer) {

}

void delete_buffer(circular_buffer_t* buffer) {
    free(buffer->values);
    free(buffer);
}