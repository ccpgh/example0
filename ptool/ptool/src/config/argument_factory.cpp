//
//  project: ptool
//  filename: argumentfactory.cpp
//

#include "../../include/config/argument.h"
#include "../../include/utility/memory.h"
#include "../../include/config/argument_factory.h"

namespace ptool::config
{

Argument<bool>* ArgumentFactory::createBoolArgument(const std::string_view name,
                                                    const std::string_view defaultValue,
                                                    ArgumentI::ArgumentCharacteristics::OptionalOrMandatory optionalOrMandatory,
                                                    ArgumentI::ArgumentCharacteristics::UniqueOrMultiple uniqueOrMultiple)
{
  std::shared_ptr<Argument<bool>> argument(new Argument<bool>(name, defaultValue, optionalOrMandatory, uniqueOrMultiple));
  
  // NYI - check input and setup Argument
  
  return ptool::utility::memory::release(argument);
}

Argument<double>* ArgumentFactory::createFloatArgument(const std::string_view name,
                                                       const std::string_view defaultValue,
                                                       ArgumentI::ArgumentCharacteristics::OptionalOrMandatory optionalOrMandatory,
                                                       ArgumentI::ArgumentCharacteristics::UniqueOrMultiple uniqueOrMultiple)
{
  std::shared_ptr<Argument<double>> argument(new Argument<double>(name, defaultValue, optionalOrMandatory, uniqueOrMultiple));
  
  // NYI - check input and setup Argument
  
  return ptool::utility::memory::release(argument);
}


Argument<long>* ArgumentFactory::createIntegerArgument(const std::string_view name,
                                                       const std::string_view defaultValue,
                                                       ArgumentI::ArgumentCharacteristics::OptionalOrMandatory optionalOrMandatory,
                                                       ArgumentI::ArgumentCharacteristics::UniqueOrMultiple uniqueOrMultiple)
{
  std::shared_ptr<Argument<long>> argument(new Argument<long>(name, defaultValue, optionalOrMandatory, uniqueOrMultiple));
  
  // NYI - check input and setup Argument
  
  return ptool::utility::memory::release(argument);
}


Argument<std::string>* ArgumentFactory::createStringArgument(const std::string_view name,
                                                             const std::string_view defaultValue,
                                                             ArgumentI::ArgumentCharacteristics::OptionalOrMandatory optionalOrMandatory,
                                                             ArgumentI::ArgumentCharacteristics::UniqueOrMultiple uniqueOrMultiple)
{
  std::shared_ptr<Argument<std::string>> argument(new Argument<std::string>(name, defaultValue, optionalOrMandatory, uniqueOrMultiple));
  
  // NYI - check input and setup Argument
  
  return ptool::utility::memory::release(argument);
}



} // namespace config::ptool


