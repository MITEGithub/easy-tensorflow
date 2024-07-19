#pragma once

#include <cmath>
#include <cstddef>
#include <vector>

using std::vector;

class tensor_t;

class node_t {
   public:
    node_t() = default;

    node_t(vector<size_t> shape);

    virtual auto forward() -> void;
    virtual auto backward(tensor_t&& grad, float_t lr) -> void = 0;

    vector<node_t*> inputs; // the point of the node_t, we can use it to find our object.

    vector<size_t> shape; // the basic shape, such as the tensor shape inherit it 
    vector<float_t> data; // the concrete data in the node

    bool visited = false; // the flag is used to the node whether visited
};
