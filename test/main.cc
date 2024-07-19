#include "../include/easytf.h"

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
        std::cout << "out is :";
        std::cout << out->to_string() << "\n\n";

        std::cout << "w1 is :";
        std::cout << w1.to_string() << "\n\n";

        std::cout << "w2 is :";
        std::cout << w2.to_string() <<"\n\n";
    }

    return 0;
}