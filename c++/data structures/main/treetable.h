#ifndef __TREETABLE_H__
#define __TREETABLE_H__

#include "common.h"

/**
 * An ordered key-value map. TreeTable support logarithmic time insertion,
 * removal and lookup of values.
 */
typedef struct treetable_s TreeTable;

/**
 * Red-Black tree node.
 *
 * @note Modifying this structure may invalidate the table.
 */
typedef struct rbnode_s {
    /**
     * Key in the table. */
    void *key;

    /**
     * Value associated with the key */
    void *value;

    /**
     * The color of this node */
    char  color;

    /**
     * Parent of this node */
    struct rbnode_s *parent;

    /**
     * Left child node */
    struct rbnode_s *left;

    /**
     * Right child node */
    struct rbnode_s *right;
} RBNode;

/**
 * TreeTable table entry.
 */
typedef struct tree_table_entry_s {
    void *key;
    void *value;
} TreeTableEntry;

/**
 * TreeTable iterator object. Used to iterate over the entries of the table.
 * The iterator also supports operations for safely removing elements during
 * iteration.
 *
 * @code
 * TreeTableIter i;
 * treetable_iter_init(&i);
 *
 * while (treetable_iter_has_next(&i)) {
 *     TreeTableEntry *e = treetable_iter_next(&i);
 *     e->key;
 *     e->value;
 * }
 * @endcode
 *
 * @note This structure should only be modified through the iterator functions.
 */
typedef struct tree_table_iter_s {
    TreeTable *table;
    RBNode    *current;
    RBNode    *next;
} TreeTableIter;

/**
 * TreeTable configuration object. Used to initialize a new TreeTable with
 * specific values.
 *
 * @code
 * TreeTableConf c;
 * treetable_conf_init(&c);
 *
 * c.cmp = mycmpfunc;
 * c.mem_alloc = mymalloc;
 * ...
 *
 * TreeTable *t = treetable_new_conf(&c);
 * @endcode
 */
typedef struct treetable_conf_s {
    int    (*cmp)         (void *k1, void *k2);
    void  *(*mem_alloc)   (size_t size);
    void  *(*mem_calloc)  (size_t blocks, size_t size);
    void   (*mem_free)    (void *block);
} TreeTableConf;


void       treetable_conf_init        (TreeTableConf *conf);
TreeTable *treetable_new              (int (*cmp) (void *, void *));
TreeTable *treetable_new_conf         (TreeTableConf *conf);

void       treetable_destroy          (TreeTable *table);
bool       treetable_add              (TreeTable *table, void *key, void *val);

void      *treetable_remove           (TreeTable *table, void *key);
void       treetable_remove_all       (TreeTable *table);
void      *treetable_remove_first     (TreeTable *table);
void      *treetable_remove_last      (TreeTable *table);

void      *treetable_get              (TreeTable *table, void *key);
void      *treetable_get_first_value  (TreeTable *table);
void      *treetable_get_first_key    (TreeTable *table);
void      *treetable_get_last_value   (TreeTable *table);
void      *treetable_get_last_key     (TreeTable *table);
void      *treetable_get_greater_than (TreeTable *table, void *key);
void      *treetable_get_lesser_than  (TreeTable *table, void *key);

size_t     treetable_size             (TreeTable *table);
bool       treetable_contains_key     (TreeTable *table, void *key);
size_t     treetable_contains_value   (TreeTable *table, void *key);

void       treetable_foreach_key      (TreeTable *table, void (*op) (const void*));
void       treetable_foreach_value    (TreeTable *table, void (*op) (void*));

void       treetable_iter_init        (TreeTableIter *iter, TreeTable *table);
bool       treetable_iter_has_next    (TreeTableIter *iter);
void       treetable_iter_next        (TreeTableIter *iter, TreeTableEntry *entry);
void       treetable_iter_remove      (TreeTableIter *iter);

#ifdef DEBUG
#define RB_ERROR_CONSECUTIVE_RED 0
#define RB_ERROR_BLACK_HEIGHT    1
#define RB_ERROR_TREE_STRUCTURE  2
#define RB_ERROR_OK              4

int treetable_assert_rb_rules(TreeTable *table);
#endif

#endif
