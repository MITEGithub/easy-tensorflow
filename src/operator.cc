#include "operator.h"
#include <cmath>
#include "easytf.h"
#include "node.h"
#include "tensor.h"

operator_t::operator_t(const vector<node_t*>& inputs) {
   // TODO(): It seems that the inputs not be initlized
   TODO();
}

auto operator_t::forward() -> void {
    // TODO(): class operator_t solve the node_t is different from the tensor_t
    // think the key difference, you will get the tensorflow the core of calculated photo
    TODO();  
}

auto operator_t::backward(tensor_t&& grad, float_t lr) -> void {  // tensor_t&& grad is the right value reference
    // TODO(): base on the basic class, you will get more ideas
    TODO();
};
