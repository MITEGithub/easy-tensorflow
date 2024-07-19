#include "tensor.h"
#include <cassert>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "easytf.h"
#include "node.h"

tensor_t::tensor_t(vector<size_t> shape) {
    // TODO(): NULL
    TODO();
};

tensor_t::tensor_t(vector<size_t> shape, float_t init_value) {
    // TODO: NULL
    TODO();
}

// TODO: now, init function of class tensor_t have other version to solve

[[nodiscard]] auto tensor_t::get_data() const -> const vector<float_t>& {
    return data;
}

[[nodiscard]] auto tensor_t::get_shape() const -> const vector<size_t>& {
    return shape;
}

auto tensor_t::set_data(const vector<float_t>& new_data) -> void {
    //here not use the move function
    TODO();
}

auto tensor_t::forward() -> void {
   // TODO(): you will think the useage of the forward() in class tensor_t 
   TODO();
}

auto tensor_t::backward(tensor_t&& grad, float_t lr) -> void {
    node_t::backward(std::move(grad), lr);
}

void to_string_recursive(const std::vector<size_t>& shape,
                         size_t dimIdx,
                         const std::vector<float>& data,
                         size_t& startIdx,
                         std::stringstream& ss) {
    if (dimIdx == shape.size() - 1) {
        ss << "[";
        for (size_t i = 0; i < shape[dimIdx]; i++) {
            ss << std::fixed << std::setprecision(2) << data[startIdx++];
            if (i < shape[dimIdx] - 1) {
                ss << ", ";
            }
        }
        ss << "]";
    } else {
        ss << "[";
        for (size_t i = 0; i < shape[dimIdx]; i++) {
            to_string_recursive(shape, dimIdx + 1, data, startIdx, ss);
            if (i < shape[dimIdx] - 1) {
                ss << "," << '\n';
            }
        }
        ss << "]";
    }
}

void shape_to_string(std::stringstream& ss, const std::vector<size_t>& shape) {
    ss << "shape: [";
    for (size_t i = 0; i < shape.size(); i++) {
        ss << shape[i] << (i == shape.size() - 1 ? "" : ", ");
    }
    ss << "]";
}

auto tensor_t::to_string() -> string {
    std::stringstream ss;
    ss << "tensor(" << '\n';
    size_t startIdx = 0;
    to_string_recursive(shape, 0, data, startIdx, ss);
    ss << ",\n";
    shape_to_string(ss, shape);
    ss << ")";
    return ss.str();
}
