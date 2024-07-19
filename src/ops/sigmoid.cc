#include <cassert>
#include <cmath>
#include <cstddef>
#include "easytf.h"
#include "tensor.h"

sigmoid::sigmoid(const vector<node_t*>& inputs) : operator_t(inputs) {}

auto sigmoid::apply() -> tensor_t {
    // TODO(): compare the apply() in the matmul.cc, give your solution here
      
    TODO();
}

auto sigmoid::gradient(tensor_t&& grad) -> vector<tensor_t> {
    // TODO(): give your solution here

    TODO();
}

auto sigmoid::get_shape() -> vector<size_t> {
    // TODO(): NULL
    TODO();
}
