#include <stdlib.h>

#include "memory.h"
#include "value.h"

ValueArray ValueArray_init(void) {
    return (ValueArray){
        .length = 0,
        .capacity = 0,
        .values = NULL,
    };
}

void ValueArray_delete(ValueArray *array) {
    FREE_ARRAY(Value, array->values, array->capacity);
    array->values = NULL;
}

void ValueArray_write(ValueArray *array, Value value) {
    if (array->capacity <= array->length) {
        size_t old_capacity = array->capacity;
        array->capacity = GROW_CAPACITY(old_capacity);
        array->values = GROW_ARRAY(Value, array->values, old_capacity, array->capacity);
    }

    array->values[array->length] = value;
    array->length++;
}
