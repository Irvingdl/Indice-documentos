#include <chrono>

auto start = std::chrono::high_resolution_clock::now();
// Lógica de procesamiento
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed = end - start;
std::cout << "Tiempo de procesamiento: " << elapsed.count() << " segundos.\n";
