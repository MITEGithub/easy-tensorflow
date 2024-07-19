#include <iostream>
#include "easytf.h"
#include "node.h"
#include "ops/matmul.h"
#include "ops/sigmoid.h"
#include "optimizer.h"

// this time you will get the basic function to code your model like tensorflow
// you will get the base class: node_t to know the different function of tensor and operator
//
// !! you must complete the following task: !!
// 1 . please complete the blanks in this project 
// 2 . create the new operator add, relu and conv2d, comparing our demo
// 3 . try to optimize the whole project to get the fast speed
//
// Tips: 1. our model only use to create the model that has one input and one output
//       2. you can think whether we can change the structure of tensor and operator to create more input or output
//       3. to relize conv2d(), you can use the GP thought    

auto main() -> int {
    tensor_t input({1, 4}, 1);
    tensor_t w1({4, 4}, 1);
    tensor_t w2({4, 1}, 1);

    auto a = apply<matmul>(&input, &w1);  // 1 x 4
    auto b = apply<sigmoid>(a);           // 1 x 4
    auto out = apply<matmul>(b, &w2);     // 1 x 1

    optimizer_t opt(&input, out);

    for (size_t i = 0; i < 100; i++) {
        opt.step({{1, 4}, 1}, {{1, 1}, 1});  // input is [1,1,1,1] and output is [1],
        // now you should change the weights to learning this stastion
        std::cout << "out is :" << "\n";
        std::cout << out->to_string() << "\n\n";

        std::cout << "w1 is :" << "\n";
        std::cout << w1.to_string() << "\n\n";

        std::cout << "w2 is :" << "\n";
        std::cout << w2.to_string() <<"\n\n";
    }

    return 0;
}
