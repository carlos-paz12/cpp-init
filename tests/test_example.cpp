#include "cpp-init/example.h"

#include <cassert>  // assert
#include <cstdlib>  // EXIT_SUCCESS
#include <iostream> // std::cout

int main(int argc, char* argv[]) {
  Example e("abc");
  assert(e.to_string() == "abc");
  return EXIT_SUCCESS;
}
