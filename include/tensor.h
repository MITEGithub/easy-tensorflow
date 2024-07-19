#pragma once

#include <cstddef>
#include <string>
#include "node.h"

using std::float_t;
using std::string;
using std::vector;

class tensor_t : public node_t {
    // Tips: the tensor we realized is two dimensionality 
    public:
        tensor_t(vector<size_t> shape);

        tensor_t(vector<size_t> shape, float_t init_value);

        tensor_t(vector<size_t> shape, const vector<float_t>& data); 

        [[nodiscard]] auto get_data() const -> const vector<float_t>&; // get the data(vector<size_t>) in the tensor

        [[nodiscard]] auto get_shape() const -> const vector<size_t>&; // get the shape(vector<float_t>) in the tensor

        auto set_data(const vector<float_t>& new_data) -> void; // set the data in tensor directly (this is used to copy data to other)

        auto forward() -> void override; // think it over! what should the forward() do in class tensor [Tips: calculate the result per process]

        auto backward(tensor_t&& grad, float_t lr) -> void override; // the same [Tips: get the new grad per process]

        auto to_string() -> string; // used to cout
};
