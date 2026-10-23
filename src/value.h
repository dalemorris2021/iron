#ifndef IRON_VALUE_H
#define IRON_VALUE_H

#include <stdlib.h>

typedef double Value;

typedef struct {
    size_t length;
    size_t capacity;
    Value *values;
} ValueArray;

ValueArray ValueArray_new(void);
void ValueArray_delete(ValueArray *array);
void ValueArray_write(ValueArray *array, Value value);

#endif // IRON_VALUE_H
