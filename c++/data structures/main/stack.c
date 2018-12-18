#include "array.h"
#include "stack.h"

struct stack_s {
    Array *v;

    void *(*mem_alloc)  (size_t size);
    void *(*mem_calloc) (size_t blocks, size_t size);
    void  (*mem_free)   (void *block);
};

/**
 * Initializes the fields of the StackConf struct to default values.
 *
 * @param[in, out] conf the configuration object that is being initialized
 */
void stack_conf_init(StackConf *conf)
{
    array_conf_init(conf);
}

/**
 * Returns a new empty stack, or NULL if the space allocation fails.
 *
 * @return a new empty stack, or NULL.
 */
Stack *stack_new()
{
    StackConf conf;
    stack_conf_init(&conf);
    return stack_new_conf(&conf);
}

/**
 * Returns a new empty stack based on the StackConf struct.
 *
 * The stack is allocated using the allocators specified in the StackConf
 * struct. The allocation may fail if the undlying allocator fails.
 *
 * @param[in] conf the stack configuration
 *
 * @return a new empty stack, or NULL if the allocation fails
 */
Stack *stack_new_conf(StackConf *conf)
{
    Stack *s      = conf->mem_calloc(1, sizeof(Stack));
    s->v          = array_new_conf(conf);

    s->mem_alloc  = conf->mem_alloc;
    s->mem_calloc = conf->mem_calloc;
    s->mem_free   = conf->mem_free;

    return s;
}

/**
 * Destroys the specified stack structure, while leaving the data it holds
 * intact.
 *
 * @param[in] stack the stack to be destroyed
 */
void stack_destroy(Stack *stack)
{
    array_destroy(stack->v);
    stack->mem_free(stack);
}

/**
 * Destroys the specified stack structure along with all the data it holds.
 *
 * @param[in] stack the stack to be destroyed
 */
void stack_destroy_free(Stack *stack)
{
    array_destroy_free(stack->v);
    free(stack);
}

/**
 * Pushes a new element onto the stack. This operation may fail if the space
 * for the new element cannot be allocated.
 *
 * @param[in] stack the stack on which the elment is being pushed onto
 * @param[in] element the element being pushed onto the stack
 *
 * @return true if the operation was successful, false if not
 */
bool stack_push(Stack *stack, void *element)
{
    return array_add(stack->v, element);
}

/**
 * Returns the top element of the stack without removing it.
 *
 * @param[in] stack the stack whose top element is being returned
 *
 * @return the top element of the stack
 */
void *stack_peek(Stack *stack)
{
    return array_get_last(stack->v);
}

/**
 * Returns and removes the top element of the stack.
 *
 * @param[in] stack the stack whose top element is being popped
 *
 * @return the top element of the stack
 */
void *stack_pop(Stack *stack)
{
    return array_remove_last(stack->v);
}

/**
 * Returns the number stack element.
 *
 * @param[in] stack the stack whose number of elements is being returned.
 *
 * @return the number of stack elements
 */
size_t stack_size(Stack *stack)
{
    return array_size(stack->v);
}

/**
 * A stack foreach loop function that invokes the specified function on
 * each element of the stack.
 *
 * @param[in] stack the stack on which this operation being performed
 * @param[in] op the operation function that is to be invoked on each
 *               element of the stack
 */
void stack_foreach(Stack *stack, void (*op) (void *))
{
    array_foreach(stack->v, op);
}
