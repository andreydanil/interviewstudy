#ifndef STACK_H_
#define STACK_H_

#include "common.h"
#include "array.h"

/**
 * A LIFO (last in first out) structure. Supports constant time time insertion, removal
 * and lookup.
 */
typedef struct stack_s Stack;

/**
 * Stack configuration object.
 */
typedef ArrayConf StackConf;

void    stack_conf_init   (StackConf *conf);

Stack  *stack_new         (void);
Stack  *stack_new_conf    (StackConf *conf);
void    stack_destroy     (Stack *stack);
void    stack_destroy_free(Stack *stack);

bool    stack_push        (Stack *stack, void *element);
void   *stack_peek        (Stack *stack);
void   *stack_pop         (Stack *stack);

size_t  stack_size        (Stack *stack);

void    stack_foreach     (Stack *stack, void (*op) (void *));

#endif /* STACK_H_ */
