#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <string> // std::string

using str = std::string; //!< Alias to std::string.

class Example
{
public:
  /// @brief Default constructor.
  Example(str string = str());

  /// @brief Destructor.
  ~Example();

  /// @brief Return string represeantation.
  [[nodiscard]] str to_string() const;

private:
  str m_string; //!< My string member.
};

#endif //!< EXAMPLE_H