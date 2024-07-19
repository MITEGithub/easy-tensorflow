#pragma once

#include <cmath>
#include <vector>
#include "tensor.h"

using std::vector;

class optimizer_t {
   public:
    tensor_t* root; // root is the point of output tensor
    tensor_t* input; // input is the input's

    float_t lr = 0.01;  // lr is the learning rate

    optimizer_t(tensor_t* input, tensor_t* output);

    optimizer_t(tensor_t* input, tensor_t* output, float_t lr);

    auto get_grads(tensor_t&& Y) -> tensor_t; // calculate the loss abs(y_hot - y) and init the grad(class: tensor_t)

    void step(tensor_t&& X, tensor_t&& Y); // is the key of the program, control the forward() and backward(),
                                           // to change the weight in your model, using the grad
};
