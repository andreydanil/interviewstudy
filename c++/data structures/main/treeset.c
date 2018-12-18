#include "treeset.h"

struct treeset_s {
    TreeTable *t;
    int       *dummy;

    void *(*mem_alloc)  (size_t size);
    void *(*mem_calloc) (size_t blocks, size_t size);
    void  (*mem_free)   (void *block);
};

/**
 * Initializes the fields of the HashSetConf struct to default values.
 *
 * @param[in, out] conf the configuration struct that is being initialized
 */
void treeset_conf_init(TreeSetConf *conf)
{
    treetable_conf_init(conf);
}

/**
 * Returns a new empty TreeSet configured based on the specified configuration
 * object.
 *
 * @param[in] cmp  the comparator function used to order elements
 *
 * @return a new empty TreeSet
 */
TreeSet *treeset_new(int (*cmp) (void*, void*))
{
    TreeSetConf conf;
    treeset_conf_init(&conf);
    conf.cmp = cmp;
    return treeset_new_conf(&conf);
}

/**
 * Returns a new empty TreeSet based on the specified TreeSetConf object.
 *
 * The TreeSet is allocated using the allocators specified in the TreeSetConf
 * object. The allocation may fail if the underlying allocator fails.
 *
 * @param[in] conf The HashSet configuration object. All fields must be initialized.
 *
 * @return a new empty TreeSet
 */
TreeSet *treeset_new_conf(TreeSetConf *conf)
{
    TreeSet *set = conf->mem_calloc(1, sizeof(TreeSet));

    set->t          = treetable_new_conf(conf);
    set->dummy      = (int*) 1;
    set->mem_alloc  = conf->mem_alloc;
    set->mem_calloc = conf->mem_calloc;
    set->mem_free   = conf->mem_free;

    return set;
}

/**
 * Destroys the specified TreeSet.
 *
 * @param[in] set the TreeSet to be destroyed
 */
void treeset_destroy(TreeSet *set)
{
    treetable_destroy(set->t);
    set->mem_free(set);
}

/**
 * Adds a new element to the set.
 *
 * @param[in] set the set to which the element is being added
 * @param[in] element the element being added
 *
 * @return true if the element was successfully added to the set
 */
bool treeset_add(TreeSet *set, void *element)
{
    return treetable_add(set->t, element, set->dummy);
}

/**
 * Removes and returns the specified element from the set if such an element
 * exists. This function returns NULL if the element was not a part of the
 * set.
 *
 * @param[in] set the set from which the element is being removed
 * @param[in] element the element being removed
 *
 * @return the removed element, or NULL if the element was not found
 */
void *treeset_remove(TreeSet *set, void *element)
{
    return treetable_remove(set->t, element);
}

/**
 * Removes all elemetns from the specified set.
 *
 * @param set the set from which all elements are being removed
 */
void treeset_remove_all(TreeSet *set)
{
    treetable_remove_all(set->t);
}

/**
 * Returns the first element of the set.
 *
 * @param[in] set the set from which the first element is being returned
 *
 * @return the first (lowest) element in the set
 */
void *treeset_get_first(TreeSet *set)
{
    return treetable_get_first_key(set->t);
}

/**
 * Returns the last (higest) element of the set.
 *
 * @param[in] set the set from which the last element is being returned
 *
 * @return the last element in the set
 */
void *treeset_get_last(TreeSet *set)
{
    return treetable_get_last_key(set->t);
}

/**
 * Returns the immediate successor of the specified element.
 *
 * @param[in] set the set on which this operation is performed
 * @param[in] element the element whose successor is being returned
 *
 * @return successor of the element, or NULL if there is no successor element
 */
void *treeset_get_greater_than(TreeSet *set, void *element)
{
    return treetable_get_greater_than(set->t, element);
}

/**
 * Returns the immediate predecessor of the specified element.
 *
 * @param[in] set the set on which this operation is performed
 * @param[in] element the element whose predecessor is being returned
 *
 * @return predecessor of the element, or NULL if there is no predecessor element
 */
void *treeset_get_lesser_than(TreeSet *set, void *element)
{
    return treetable_get_lesser_than(set->t, element);
}

/**
 * Checks whether an element is a part of the specified set.
 *
 * @param[in] set the set being searched for the specified element
 * @param[in] element the element being seached for
 *
 * @return true if the specified element is an element of the set
 */
bool treeset_contains(TreeSet *set, void *element)
{
    return treetable_contains_key(set->t, element);
}

/**
 * Returns the size of the specified set.
 *
 * @param[in] set the set whose size is being returned
 *
 * @return the size of the set
 */
size_t treeset_size(TreeSet *set)
{
    return treetable_size(set->t);
}

/**
 * A 'foreach loop' function that invokes the specified function on every element
 * of the set. The operation function should not modify the elements. Any
 * modification of the elements will invalidate the set.
 *
 * @param[in] set the set on which this operation is being performed
 * @param[in] op the operation fuctnion that is invoked on each element of the
 *               set
 */
void treeset_foreach(TreeSet *set, void (*op) (const void*))
{
    treetable_foreach_key(set->t, op);
}

/**
 * Initializes the set iterator.
 *
 * @param[in] iter the iterator that is being initialized
 * @param[in] set the set on which this iterator will operate
 */
void treeset_iter_init(TreeSetIter *iter, TreeSet *set)
{
    treetable_iter_init(&(iter->i), set->t);
}

/**
 * Checks whether or not there are more set elements to iterate over.
 *
 * @param[in] iter iterator on which this operation is being performed
 *
 * @return true if the iterator has not reached the end of the set
 */
bool treeset_iter_has_next(TreeSetIter *iter)
{
    return treetable_iter_has_next(&(iter->i));
}

/**
 * Returns the next element in the sequence and advances the iterator.
 *
 * @param[in] iter the iterator that is being advanced
 * @param[out] element the next element returned by this function
 */
void treeset_iter_next(TreeSetIter *iter, void **element)
{
    TreeTableEntry entry;
    treetable_iter_next(&(iter->i), &entry);
    *element = entry.key;
}

/**
 * Removes the last element returned by <code>treeset_iter_next()</code>.
 *
 * @param[in] iter the iterator from which the element is being removed
 */
void treeset_iter_remove(TreeSetIter *iter)
{
    treetable_iter_remove(&(iter->i));
}
