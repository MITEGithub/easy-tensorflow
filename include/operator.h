#pragma once

#include <cstddef>
#include "node.h"
#include "tensor.h"

class operator_t : public node_t {
   public:
    operator_t() = default;

    operator_t(const vector<node_t*>& inputs);

   private:
    auto forward() -> void override; // what the difference between this forward() and the one in tensor

    auto backward(tensor_t&& grad, float_t lr) -> void override; // the same 

    virtual auto apply() -> tensor_t = 0; // give the virtual function for the per concrete operator, such as the matmul, sigmoid
    virtual auto get_shape() -> vector<size_t> = 0; // think why operator need get_shape() function (Tips: get the shape of it stores tensor's)
    virtual auto gradient(tensor_t&& grad) -> vector<tensor_t> = 0; // override the grad through the operator
    // so these functions are based on the concrete operator, we use the virtual functino to solve the reuse problem
};
