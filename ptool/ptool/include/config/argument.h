//
//  project: ptool
//  filename: argument.h
//

#ifndef PTOOL_ARGUMENT_H
#define PTOOL_ARGUMENT_H

#include <memory>
#include <string>
#include <string_view>
#include <vector>
#include <variant>

#include "argumentI.h"

namespace ptool::config
{

template <class T>
class Argument final : public ArgumentI
{
  // disable any T other than (long, double, bool or std::string)
  using value_type = typename std::enable_if<
  std::is_same<double, T>::value || std::is_same<long, T>::value || std::is_same<bool, T>::value || std::is_same<std::string, T>::value ,
  T
  >::type;

private:
  friend class ArgumentFactory;
  
  Argument(const std::string_view name,
           const std::string_view defaultValue,
           ArgumentCharacteristics::OptionalOrMandatory optionalOrMandatory,
           ArgumentCharacteristics::UniqueOrMultiple uniqueOrMultiple) :
  ArgumentI(name, defaultValue, optionalOrMandatory, uniqueOrMultiple)
  {}
  
public:
  
  bool operator==(const Argument<T>& argument) const
  {
    return static_cast<const ArgumentI*>(this)->operator==(argument);
  }
  
  Argument<T>& operator=(const Argument<T>& argument)
  {
    ArgumentI::operator=(argument);
    return (*this);
  }
  
  Argument<T>(const Argument<T>& argument) : ArgumentI(argument)
  {
  }
  
  virtual bool setValue(const std::variant<bool, long, double, std::string>& value) override;
  
  virtual ~Argument<T>() override
  {}
};


} // namespace config::ptool

#endif /* PTOOL_ARGUMENT_H */
