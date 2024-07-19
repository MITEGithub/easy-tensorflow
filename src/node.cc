#include <cstddef>
#include "easytf.h"

node_t::node_t(vector<size_t> shape) : shape(std::move(shape)) {
    TODO();
}

auto node_t::forward() -> void {
    TODO();
}

auto node_t::backward(tensor_t&& grad, float_t lr) -> void {
    for (size_t i = 0; i < grad.data.size(); i++) {
        data[i] -= lr * grad.data[i];
    }
    for (auto& input : inputs) {
        input->backward(std::move(grad), lr);
    }
    visited = false;
}
