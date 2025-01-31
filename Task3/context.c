#include "context.h"
#include "assert.h"
#include "stdlib.h"
#include "string.h"

__generator __main_gen;
__generator* __now_gen = &__main_gen;

// Task 2

void __err_stk_push(__ctx* ctx){
    assert(ctx != 0);

    // TODO
}

__ctx* __err_stk_pop(){
    assert(__now_gen->__err_stk_head != 0);

    // TODO
}

void __err_cleanup(const int* error){

    // TODO
}

int __check_err_stk(){
    return __now_gen->__err_stk_head == 0;
}

// Task 3

int send(__generator* gen, int value) {
    if (gen == 0) throw(ERR_GENNIL);
    gen->data = value;

    // TODO

    return gen->data;
}

int yield(int value) {
    if (__now_gen->caller == 0) throw(ERR_GENNIL);
    __now_gen->data = value;

    // TODO

    return __now_gen->data;
}

__generator* generator(void (*f)(int), int arg) {
    // TODO: construct a new generator
}

void generator_free(__generator** gen) {
    if (*gen == NULL) throw(ERR_GENNIL);
    free((*gen)->stack);
    while ((*gen)->__err_stk_head != 0) {
        __err_stk_node* tmp = (*gen)->__err_stk_head;
        (*gen)->__err_stk_head = (*gen)->__err_stk_head->prev;
        free(tmp->ctx);
        free(tmp);
    }
    free(*gen);
    *gen = NULL;
}