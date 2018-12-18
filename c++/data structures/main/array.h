#ifndef ARRAY_H_
#define ARRAY_H_

#include "common.h"

/**
 * A dynamic array that expands automatically as elements are added. The array supports
 * amortized constant time insertion and removal of elements at the end of the array, as
 * well as constant time access.
 */
typedef struct array_s Array;

/**
 * Array configuration object. Used to initalize a new Array with specific
 * values.
 *
 * @code
 * ArrayConf c;
 * array_conf_init(&c);
 *
 * c.capcity = 32;
 *
 * Array *a = array_new_conf(&c);
 * @endcode
 */
typedef struct array_conf_s {
    /**
     * The initial capacity of the array */
    size_t capacity;

    /**
     * The rate at which the buffer expands (capacity * exp_factor). */
    float  exp_factor;

    /**
     * Memory allocators used to allocate the Array structure and the
     * underlying data buffers. */
    void *(*mem_alloc)  (size_t size);
    void *(*mem_calloc) (size_t blocks, size_t size);
    void  (*mem_free)   (void *block);
} ArrayConf;

/**
 * Array iterator object. Used to iterate over the elements of the array
 * in an ascending order. The iterator also supports operations for safely
 * adding and removing elements during iteration.
 *
 * @code
 * ArrayIter i;
 * array_iter_init(&i);
 *
 * while (array_iter_has_next(&i)) {
 *     MyType *e = array_iter_next(&i);
 * }
 * @endcode
 */
typedef struct array_iter_s {
    /**
     * The array associated with this iterator */
    Array  *ar;

    /**
     * The current position of the iterator.*/
    size_t  index;
} ArrayIter;

Array*       array_new             (void);
Array*       array_new_conf        (ArrayConf *conf);
void         array_conf_init       (ArrayConf *conf);

void         array_destroy         (Array *ar);
void         array_destroy_free    (Array *ar);

bool         array_add             (Array *ar, void *element);
bool         array_add_at          (Array *ar, void *element, size_t index);
void*        array_replace_at      (Array *ar, void *element, size_t index);

void*        array_remove          (Array *ar, void *element);
void*        array_remove_at       (Array *ar, size_t index);
void*        array_remove_last     (Array *ar);
void         array_remove_all      (Array *ar);
void         array_remove_all_free (Array *ar);

void*        array_get             (Array *ar, size_t index);
void*        array_get_last        (Array *ar);

Array*       array_subarray        (Array *ar, size_t from, size_t to);
Array*       array_copy_shallow    (Array *ar);
Array*       array_copy_deep       (Array *ar, void *(*cp) (void*));

void         array_reverse         (Array *ar);
bool         array_trim_capacity   (Array *ar);

size_t       array_contains        (Array *ar, void *element);
size_t       array_size            (Array *ar);
size_t       array_capacity        (Array *ar);

size_t       array_index_of        (Array *ar, void *element);
void         array_sort            (Array *ar, int (*cmp) (const void*, const void*));

void         array_foreach         (Array *ar, void (*op) (void *));

void         array_iter_init       (ArrayIter *iter, Array *vec);
bool         array_iter_has_next   (ArrayIter *iter);
void*        array_iter_next       (ArrayIter *iter);
void*        array_iter_remove     (ArrayIter *iter);
bool         array_iter_add        (ArrayIter *iter, void *element);
void*        array_iter_replace    (ArrayIter *iter, void *element);
size_t       array_iter_index      (ArrayIter *iter);

const void* const* array_get_buffer(Array *ar);

#endif /* ARRAY_H_ */
