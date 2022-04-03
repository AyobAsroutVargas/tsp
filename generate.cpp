#include "generador.h"

int main() {
  Generator* generator = new Generator();
  for (int i = 2; i < 100; i++) {
    std::string filename = "grafos/instancia_" + std::to_string(i);
    generator->GenerateInstance(filename, i);
  }
  return 0;
}