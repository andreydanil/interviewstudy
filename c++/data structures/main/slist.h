#ifndef SLIST_H_
#define SLIST_H_

#include "common.h"

/**
 * A singly linked list. List is a sequential structure that supports constant time
 * insertion, deletion  and lookup at the beginning of the list, while the worst
 * case for these operations is linear time.
 */
typedef struct slist_s SList;

/**
 * SList node.
 *
 * @note Modifying the links may invalidate the list structure.
 */
typedef struct snode_s {
    void           *data;
    struct snode_s *next;
} SNode;

/**
 * SList iterator object. Used to iterate over the elements of the list
 * in an ascending order. The iterator also supports operations for safely
 * adding and removing elements during iteration.
 *
 * @code
 * SListIter i;
 * slist_iter_init(&i);
 *
 * while (slist_iter_has_next(&i)) {
 *     MyType *e = slist_iter_next(&i);
 * }
 * @endcode
 */
typedef struct slist_iter_s {
    size_t  index;
    SList  *list;
    SNode   *next;
    SNode   *current;
    SNode   *prev;
} SListIter;

/**
 * SList configuration object. Used to initalize a new SList with specific
 * values.
 *
 * @code
 * SListConf c;
 * slist_conf_init(&c);
 *
 * c.mem_alloc  = mymalloc;
 * c.mem_free   = myfree;
 * c.mem_calloc = mycalloc;
 *
 * SList *l = slist_new_conf(&c);
 * @endcode
 */
typedef struct slist_conf_s {
    void  *(*mem_alloc)  (size_t size);
    void  *(*mem_calloc) (size_t blocks, size_t size);
    void   (*mem_free)   (void *block);
} SListConf;

void       slist_conf_init       (SListConf *conf);

SList*     slist_new             (void);
SList*     slist_new_conf        (SListConf *conf);
bool       slist_destroy         (SList *list);
bool       slist_destroy_free    (SList *list);

bool       slist_splice          (SList *list1, SList *list2);
bool       slist_splice_at       (SList *list1, SList *list2, size_t index);

bool       slist_add             (SList *list, void *element);
bool       slist_add_at          (SList *list, void *element, size_t index);
bool       slist_add_all         (SList *list1, SList *list2);
bool       slist_add_all_at      (SList *list1, SList *list2, size_t index);
bool       slist_add_first       (SList *list, void *element);
bool       slist_add_last        (SList *list, void *element);

void*      slist_remove          (SList *list, void *element);
void*      slist_remove_first    (SList *list);
void*      slist_remove_last     (SList *list);
void*      slist_remove_at       (SList *list, size_t index);

bool       slist_remove_all      (SList *list);
bool       slist_remove_all_free (SList *list);

void*      slist_get             (SList *list, size_t index);
void*      slist_get_first       (SList *list);
void*      slist_get_last        (SList *list);

SList*     slist_sublist         (SList *list, size_t from, size_t to);
SList*     slist_copy_shallow    (SList *list);
SList*     slist_copy_deep       (SList *list, void *(*cp) (void*));

void*      slist_replace_at      (SList *list, void *element, size_t index);

size_t     slist_contains        (SList *list, void *element);
size_t     slist_index_of        (SList *list, void *element);
void**     slist_to_array        (SList *list);

void       slist_reverse         (SList *list);
bool       slist_sort            (SList *list, int (*cmp) (void const*, void const*));
size_t     slist_size            (SList *list);

void       slist_foreach         (SList *list, void (*op) (void *));

void       slist_iter_init       (SListIter *iter, SList *list);
void*      slist_iter_remove     (SListIter *iter);
bool       slist_iter_add        (SListIter *iter, void *element);
void*      slist_iter_replace    (SListIter *iter, void *element);
void*      slist_iter_next       (SListIter *iter);
size_t     slist_iter_index      (SListIter *iter);
bool       slist_iter_has_next   (SListIter *iter);

#endif /* SLIST_H_ */
