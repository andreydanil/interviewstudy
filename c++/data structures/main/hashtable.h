#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include "array.h"

#define KEY_LENGTH_VARIABLE  -1
#define KEY_LENGTH_DOUBLE    sizeof(double)
#define KEY_LENGTH_FLOAT     sizeof(float)
#define KEY_LENGTH_INT       sizeof(int)
#define KEY_LENGTH_CHAR      sizeof(char)
#define KEY_LENGTH_SHORT     sizeof(short)
#define KEY_LENGHT_LONG      sizeof(long)
#define KEY_LENGTH_POINTER   sizeof(void*)

/**
 * An unordered key-value map. HashTable supports best case amortized
 * constant time insertion, removal, and lookup of values. The worst
 * case complexity for these operations is amortized linear time.
 * The performance of the table depends greatly on the quality of the
 * hash function being used.
 */
typedef struct hashtable_s HashTable;

/**
 * A HashTable table entry.
 *
 * @note modifying this structure may invalidate the table.
 */
typedef struct table_entry_s {
    /**
     * A key in the table */
    void     *key;

    /**
     * Value associated with the key */
    void     *value;

    /**
     * Hash of the key */
    size_t    hash;

    /**
     * Pointer the next entry in the list. */
    struct table_entry_s *next;
} TableEntry;

/**
 * HashTable iterator object. Used to iterate over the entries of the table
 * in an undefined order. The iterator also supports operations for safely
 * removing elements during iteration.
 *
 * @code
 * HashTableIter i;
 * hashtable_iter_init(&i);
 *
 * while (hashtable_iter_has_next(&i)) {
 *     TableEntry *e = hashtable_iter_next(&i);
 *     e->key;
 *     e->value;
 * }
 * @endcode
 *
 * @note This structure should only be modified through the iterator functions.
 */
typedef struct hashtable_iter {
    HashTable  *table;
    size_t      bucket_index;
    TableEntry *prev_entry;
    TableEntry *next_entry;
} HashTableIter;

/**
 * HashTable configuration object. Used to initialize a new HashTable with
 * specific values.
 *
 * @code
 * HashTableConf c;
 * hashtable_conf_init(&c);
 *
 * c.key_length  = sizeof(MyType);
 * c.key_compare = my_cmp_function;
 * c.hash        = GENERAL_HASH;
 * c.hash_seed   = 12345;
 *
 * HashTable *t = hashtable_new_conf(&c);
 * @endcode
 */
typedef struct hashtable_conf_s {
    /**
     * The load factor determines how the underlying
     * table array grows. For example if the load factor
     * is 0.5 and the arrays capacity is 100, the resize will
     * be triggered once the 50th entry is added. */
    float    load_factor;

    /**
     * The initial capacity of the table array. */
    size_t   initial_capacity;

    /**
     * Length of the key or -1 if the key length is
     * variable */
    int      key_length;

    /**
     * The hash seed passed to the hash function for
     * extra 'randomness'.*/
    uint32_t hash_seed;

    /**
     * Hash function used for hashing table keys */
    size_t (*hash)        (const void *key, int l, uint32_t seed);

    /**
     * The key comparator function */
    bool   (*key_compare) (void *key1, void *key2);

    /**
     * Memory allocators used to allocate the HashTable structure
     * and for all internal memory allocations. */
    void  *(*mem_alloc)   (size_t size);
    void  *(*mem_calloc)  (size_t blocks, size_t size);
    void   (*mem_free)    (void *block);
} HashTableConf;


void        hashtable_conf_init       (HashTableConf *conf);
HashTable  *hashtable_new             (void);
HashTable  *hashtable_new_conf        (HashTableConf *conf);

void        hashtable_destroy         (HashTable *table);
bool        hashtable_add             (HashTable *table, void *key, void *val);
void       *hashtable_get             (HashTable *table, void *key);
void       *hashtable_remove          (HashTable *table, void *key);
void        hashtable_remove_all      (HashTable *table);
bool        hashtable_contains_key    (HashTable *table, void *key);

size_t      hashtable_size            (HashTable *table);
size_t      hashtable_capacity        (HashTable *table);

Array      *hashtable_get_keys        (HashTable *table);
Array      *hashtable_get_values      (HashTable *table);

bool        hashtable_string_key_cmp  (void *key1, void *key2);
bool        hashtable_float_key_cmp   (void *key1, void *key2);
bool        hashtable_char_key_cmp    (void *key1, void *key2);
bool        hashtable_short_key_cmp   (void *key1, void *key2);
bool        hashtable_double_key_cmp  (void *key1, void *key2);
bool        hashtable_int_key_cmp     (void *key1, void *key2);
bool        hashtable_long_key_cmp    (void *key1, void *key2);
bool        hashtable_pointer_key_cmp (void *key1, void *key2);

size_t      hashtable_hash_string     (const void *key, int len, uint32_t seed);
size_t      hashtable_hash            (const void *key, int len, uint32_t seed);
size_t      hashtable_hash_ptr        (const void *key, int len, uint32_t seed);

void        hashtable_foreach_key     (HashTable *table, void (*op) (const void *));
void        hashtable_foreach_value   (HashTable *table, void (*op) (void *));

void        hashtable_iter_init       (HashTableIter *iter, HashTable *table);
bool        hashtable_iter_has_next   (HashTableIter *iter);
TableEntry *hashtable_iter_next       (HashTableIter *iter);
void        hashtable_iter_remove     (HashTableIter *iter);

#define CMP_STRING   hashtable_string_key_cmp
#define CMP_FLOAT    hashtable_float_key_cmp
#define CMP_CHAR     hashtable_char_key_cmp
#define CMP_SHORT    hasthable_short_key_cmp
#define CMP_LONG     hashtable_long_key_cmp
#define CMP_DOUBLE   hashtable_double_key_cmp
#define CMP_INT      hashtable_int_key_cmp
#define CMP_POINTER  hashtable_pointer_key_cmp

#define GENERAL_HASH hashtable_hash
#define STRING_HASH  hashtable_hash_string
#define POINTER_HASH hashtable_hash_ptr


#endif /* __HASHTABLE_H__ */
