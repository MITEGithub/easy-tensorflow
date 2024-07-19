#include "easytf.h"
#include "optimizer.h"
#include "tensor.h"

optimizer_t::optimizer_t(tensor_t* input, tensor_t* output) {
    TODO();
}

optimizer_t::optimizer_t(tensor_t* input, tensor_t* output, float_t lr) {
    TODO();
}
auto optimizer_t::get_grads(tensor_t&& Y) -> tensor_t {
    auto& Y_hat = root->data;

    //TODO(): init grad(tensor_t)
    TODO();

    //TODO(): get the per grad from the abs(y_hat - y) 
    TODO();
}

void optimizer_t::step(tensor_t&& X, tensor_t&& Y) {
    //TODO(): NULL
    TODO();
}
