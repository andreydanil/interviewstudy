#ifndef HASHSET_H_
#define HASHSET_H_

#include "common.h"
#include "hashtable.h"

/**
 * An unordered set. The lookup, deletion, and insertion are performed in
 * amortized constant time and in the worst case in amortized linear time.
 */
typedef struct hashset_s HashSet;

/**
 * HashSet configuration object.
 */
typedef HashTableConf HashSetConf;

/**
 * HashSet iterator object. Used to iterate over the elements of the set.
 * The iterator also supports operations for safely removing elements
 * during iteration.
 *
 * @code
 * HashSetIter i;
 * hashset_iter_init(&i);
 *
 * while (hashset_iter_has_next(&i)) {
 *     MyType *e = hashset_iter_next(&i);
 * }
 * @endcode
 */
typedef struct hashset_iter_s {
    HashTableIter iter;
} HashSetIter;

void        hashset_conf_init     (HashSetConf *conf);

HashSet    *hashset_new           (void);
HashSet    *hashset_new_conf      (HashSetConf *properties);
void        hashset_destroy       (HashSet *set);

bool        hashset_add           (HashSet *set, void *element);
void       *hashset_remove        (HashSet *set, void *element);
void        hashset_remove_all    (HashSet *set);

bool        hashset_contains      (HashSet *set, void *element);
size_t      hashset_size          (HashSet *set);
size_t      hashset_capacity      (HashSet *set);

void        hashset_foreach       (HashSet *set, void (*op) (const void*));

void        hashset_iter_init     (HashSetIter *iter, HashSet *set);
bool        hashset_iter_has_next (HashSetIter *iter);
const void *hashset_iter_next     (HashSetIter *iter);
void       *hashset_iter_remove   (HashSetIter *iter);

#endif /* HASHSET_H_ */
