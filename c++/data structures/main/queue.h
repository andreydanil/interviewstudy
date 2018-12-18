#define QUEUE_H_

#include "common.h"
#include "deque.h"

/**
 * A FIFO (first in first out) structure. Supports constant time insertion, removal
 * and lookup.
 */
typedef struct queue_s Queue;

/**
 * Queue configuration object.
 */
typedef DequeConf QueueConf;

/**
 * Queue iterator object. Used to iterate over the elements of a queue
 * in an ascending order.
 *
 * @code
 * QueueIter i;
 * queue_iter_init(&i);
 *
 * while (queue_iter_has_next(&i)) {
 *     MyType *e = queue_iter_next(&i);
 * }
 * @endcode
 */
typedef struct queue_iter_s {
    DequeIter i;
} QueueIter;

void   queue_conf_init    (QueueConf *conf);

Queue *queue_new          (void);
Queue *queue_new_conf     (QueueConf *conf);
void   queue_destroy      (Queue *queue);
void   queue_destroy_free (Queue *queue);

void  *queue_peek         (Queue *queue);
void  *queue_poll         (Queue *queue);
bool   queue_enqueue      (Queue *queue, void *element);

size_t queue_size         (Queue *queue);
void   queue_foreach      (Queue *queue, void (*op) (void*));

void   queue_iter_init    (QueueIter *iter, Queue *queue);
bool   queue_iter_has_next(QueueIter *iter);
void*  queue_iter_next    (QueueIter *iter);
void*  queue_iter_replace (QueueIter *iter, void *replacement);

#endif /* QUEUE_H_ */
