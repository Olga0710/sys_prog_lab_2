#include <iostream>
#include <vector>
#include <chrono>

const int N = 1024;

void multiply(const std::vector<float>& a, const std::vector<float>& b, std::vector<float>& c) {
    for (int i, int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float sum = 0.0f;
            for (int k = 0; k < N; k++) {
                sum += a[i * N + k] * b[k * N + j];
            }
            c[i * N + j] = sum;
        }
    }
}

int main() {
    std::vector<float> a(N * N);
    std::vector<float> b(N * N);
    std::vector<float> c(N * N, 0.0f);

    for(int i = 0; i < N * N; i++) {
        a[i] = 1.0f;
        b[i] = 2.0f;
    }

    auto start = std::chrono::high_resolution_clock::now();
    multiply(a, b, c);
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Result [0][0] = " << c[0] << "\n";
    std::cout << "Execution time: " << elapsed.count() << " seconds\n";

    return 0;
}
