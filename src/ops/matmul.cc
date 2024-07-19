#include <cassert>
#include <cstddef>
#include "easytf.h"
#include "tensor.h"

matmul::matmul(const vector<node_t*>& inputs) : operator_t(inputs) {}

auto transpose(const tensor_t& t) -> tensor_t {
    // TODO(): Matrix transpose
    TODO();
}

auto _matmul_(const tensor_t* a, const tensor_t* b) -> tensor_t {
    auto a_shape = a->get_shape();
    auto b_shape = b->get_shape();

    assert(a_shape.size() == 2);
    assert(b_shape.size() == 2);
    assert(a_shape[1] == b_shape[0]);

    auto c_shape = vector<size_t>{a_shape[0], b_shape[1]};
    auto c = tensor_t(c_shape);

    auto a_data = a->get_data();
    auto b_data = b->get_data();
    auto& c_data = c.data;

    // TODO(): Matrix Matmul
    TODO();

    return c;
}

auto matmul::apply() -> tensor_t {
    assert(inputs.size() == 2);
    auto a = dynamic_cast<const tensor_t*>(inputs[0]);
    auto b = dynamic_cast<const tensor_t*>(inputs[1]);
    return _matmul_(a, b);
}

auto matmul::gradient(tensor_t&& grad) -> vector<tensor_t> {
    //TODO(): use function you get to complete
    TODO();
}

auto matmul::get_shape() -> vector<size_t> {
    //TODO(): NULL 
    TODO();
}
