#include "cpp-init/example.h"
#include <cstdlib>  // EXIT_SUCCESS
#include <iostream> // std::cout

int main(int argc, char* argv[]) {
  Example m_example("hello world");
  std::cout << m_example.to_string() << '\n';
  return EXIT_SUCCESS;
}