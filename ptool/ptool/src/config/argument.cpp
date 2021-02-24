//
//  project: ptool
//  filename: argument.cpp
//

#include "../../include/config/argument.h"

namespace ptool::config
{

template<>
bool Argument<bool>::setValue(const std::variant<bool, long, double, std::string>& value)
{
  // NYI implement
  return false;
}

template<>
bool Argument<long>::setValue(const std::variant<bool, long, double, std::string>& value)
{
  // NYI implement
  return false;
}

template<>
bool Argument<double>::setValue(const std::variant<bool, long, double, std::string>& value)
{
  // NYI implement
  return false;
}

template<>
bool Argument<std::string>::setValue(const std::variant<bool, long, double, std::string>& value)
{
  // NYI implement
  return false;
}


} // namespace config::ptool
