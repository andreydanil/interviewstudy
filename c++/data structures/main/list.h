#ifndef LIST_H_
#define LIST_H_

#include "common.h"

/**
 * A doubly linked list. List is a sequential structure that supports insertion, deletion
 * and lookup from both ends in constant time, while the worst case is O(n/2) at the middle
 * of the list.
 */
typedef struct list_s List;

/**
 * List node.
 *
 * @note Modifying the links may invalidate the list structure.
 */
typedef struct node_s {
    void          *data;
    struct node_s *next;
    struct node_s *prev;
} Node;

/**
 * List iterator object. Used to iterate over the elements of the list
 * in an ascending or descending order. The iterator also supports
 * operations for safely adding and removing elements during iteration.
 *
 * @code
 * ListIter i;
 * list_iter_init(&i);
 *
 * while (list_iter_has_next(&i)) {
 *     MyType *e = list_iter_next(&i);
 * }
 * @endcode
 */
typedef struct list_iter_s {
    /**
     * The current position of the iterator.*/
    size_t  index;

    /**
     * The list associated with this iterator */
    List   *list;

    /**
     * Last returned node */
    Node   *last;

    /**
     * Next node in the sequence. */
    Node   *next;
} ListIter;

/**
 * List configuration object. Used to initalize a new List with specific
 * values.
 *
 * @code
 * ListConf c;
 * list_conf_init(&c);
 *
 * c.mem_alloc  = mymalloc;
 * c.mem_free   = myfree;
 * c.mem_calloc = mycalloc;
 *
 * List *l = list_new_conf(&c);
 * @endcode
 */
typedef struct list_conf_s {
    void  *(*mem_alloc)  (size_t size);
    void  *(*mem_calloc) (size_t blocks, size_t size);
    void   (*mem_free)   (void *block);
} ListConf;

void       list_conf_init       (ListConf *conf);

List*      list_new             (void);
List*      list_new_conf        (ListConf *conf);
bool       list_destroy         (List *list);
bool       list_destroy_free    (List *list);

bool       list_splice          (List *list1, List *list2);
bool       list_splice_at       (List *list, List *list2, size_t index);

bool       list_add             (List *list, void *element);
bool       list_add_at          (List *list, void *element, size_t index);
bool       list_add_all         (List *list1, List *list2);
bool       list_add_all_at      (List *list, List *list2, size_t index);
bool       list_add_first       (List *list, void *element);
bool       list_add_last        (List *list, void *element);

void*      list_remove          (List *list, void *element);
void*      list_remove_first    (List *list);
void*      list_remove_last     (List *list);
void*      list_remove_at       (List *list, size_t index);

bool       list_remove_all      (List *list);
bool       list_remove_all_free (List *list);

void*      list_get             (List *list, size_t index);
void*      list_get_first       (List *list);
void*      list_get_last        (List *list);

List*      list_sublist         (List *list, size_t from, size_t to);
List*      list_copy_shallow    (List *list);
List*      list_copy_deep       (List *list, void *(*cp) (void*));

void*      list_replace_at      (List *list, void *element, size_t index);

size_t     list_contains        (List *list, void *element);
size_t     list_index_of        (List *list, void *element);
void**     list_to_array        (List *list);

void       list_reverse         (List *list);
bool       list_sort            (List *list, int (*cmp) (void const*, void const*));
void       list_sort_in_place   (List *list, int (*cmp) (void const*, void const*));
size_t     list_size            (List *list);

void       list_foreach         (List *list, void (*op) (void *));

void       list_iter_init       (ListIter *iter, List *list);
void*      list_iter_remove     (ListIter *iter);
bool       list_iter_add        (ListIter *iter,  void *element);
void*      list_iter_replace    (ListIter *iter, void *element);
bool       list_iter_has_next   (ListIter *iter);
size_t     list_iter_index      (ListIter *iter);
void*      list_iter_next       (ListIter *iter);

void       list_diter_init      (ListIter *iter, List *list);
void*      list_diter_remove    (ListIter *iter);
bool       list_diter_add       (ListIter *iter, void *element);
void*      list_diter_replace   (ListIter *iter, void *element);
bool       list_diter_has_next  (ListIter *iter);
size_t     list_diter_index     (ListIter *iter);
void*      list_diter_next      (ListIter *iter);

#endif /* LIST_H_ */
