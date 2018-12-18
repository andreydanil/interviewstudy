#ifndef __TREESET_H_
#define __TREESET_H_

#include "common.h"
#include "treetable.h"

/**
 * An ordered set. The lookup, deletion, and insertion are performed in
 * logarithmic time.
 */
typedef struct treeset_s TreeSet;

/**
 * TreeSet configuration object.
 */
typedef TreeTableConf TreeSetConf;

/**
 * TreeSet iterator object. Used to iterate over the elements of the set.
 * The iterator also supports operations for safely removing elements
 * during iteration.
 *
 * @code
 * TreeSetIter i;
 * treeset_iter_init(&i);
 *
 * int * const* e;
 *
 * while (treeset_iter_has_next(&i)) {
 *     treeset_iter_next(&i, &e);
 *     do_something(e);
 * }
 * @endcode
 */
typedef struct treeset_iter_s {
    TreeTableIter i;
} TreeSetIter;

void      treeset_conf_init        (TreeSetConf *conf);
TreeSet  *treeset_new              (int (*cmp) (void*, void*));
TreeSet  *treeset_new_conf         (TreeSetConf *conf);
void      treeset_destroy          (TreeSet *set);

bool      treeset_add              (TreeSet *set, void *element);
void     *treeset_remove           (TreeSet *set, void *element);
void      treeset_remove_all       (TreeSet *set);

void     *treeset_get_first        (TreeSet *set);
void     *treeset_get_last         (TreeSet *set);
void     *treeset_get_greater_than (TreeSet *set, void *element);
void     *treeset_get_lesser_than  (TreeSet *set, void *element);

bool      treeset_contains         (TreeSet *set, void *element);
size_t    treeset_size             (TreeSet *set);

void      treeset_foreach          (TreeSet *set, void (*op) (const void*));

void      treeset_iter_init        (TreeSetIter *iter, TreeSet *set);
bool      treeset_iter_has_next    (TreeSetIter *iter);
void      treeset_iter_next        (TreeSetIter *iter, void **element);
void      treeset_iter_remove      (TreeSetIter *iter);

#endif
