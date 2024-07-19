#pragma once

#include <cstddef>
#include "operator.h"

class matmul : public operator_t {
   public:
    matmul(const vector<node_t*>& inputs);

    auto apply() -> tensor_t override;

    auto gradient(tensor_t&& grad) -> vector<tensor_t> override;

    auto get_shape() -> vector<size_t> override;
};
