#include "node.h"
#include "tensor.h"

//  here we use the GP (Generic Programming) to improve program flexibility
template <class op_type>
auto apply(node_t* src1, node_t* src2) -> tensor_t* {
    auto op = new op_type({src1, src2});
    auto output = new tensor_t(op->get_shape());
    output->inputs.push_back(op);
    return output;
}

template <class op_type>
auto apply(node_t* src) -> tensor_t* {
    auto op = new op_type({src});
    auto output = new tensor_t(op->get_shape());
    output->inputs.push_back(op);
    return output;
}
