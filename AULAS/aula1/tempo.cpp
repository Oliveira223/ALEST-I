#include <chrono>
#include <iostream> 

using namespace std; 

int main() {
  // Marca o tempo inicial
  auto start = chrono::high_resolution_clock::now();

  // Código a ser cronometrado
  for (int i = 0; i < 1000000; ++i) {
    // Loop vazio para simular alguma operação
  }

  // Marca o tempo final
  auto end = chrono::high_resolution_clock::now();

  // Calcula a diferença de tempo
  auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

  // Exibe o tempo decorrido em microssegundos
  cout << "Tempo de execução: " << duration.count() << " microssegundos" << std::endl;

  return 0;
}