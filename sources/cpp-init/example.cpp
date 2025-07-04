#include "cpp-init/example.h"

#include <utility> // std::move

Example::Example(str string) : m_string(std::move(string)) { }

Example::~Example() = default;

str Example::to_string() const { return m_string; }
