#pragma once

#include <cstddef>
#include "operator.h"
#include "tensor.h"

class sigmoid : public operator_t {
   public:
    sigmoid(const vector<node_t*>& inputs);

    auto apply() -> tensor_t override;

    auto gradient(tensor_t&&) -> vector<tensor_t> override;

    auto get_shape() -> vector<size_t> override;
};
