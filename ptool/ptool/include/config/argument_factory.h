//
//  project: ptool
//  filename: argument_factory.h
//

#ifndef PTOOL_ARGUMENTFACTORY_H
#define PTOOL_ARGUMENTFACTORY_H

#include <string>
#include <string_view>

#include "argument.h"

namespace ptool::config
{

class ArgumentFactory
{
private:
  ArgumentFactory() = delete;
  
public:
  static Argument<bool>* createBoolArgument(const std::string_view name,
                                           const std::string_view defaultValue,
                                           ArgumentI::ArgumentCharacteristics::OptionalOrMandatory optionalOrMandatory,
                                           ArgumentI::ArgumentCharacteristics::UniqueOrMultiple uniqueOrMultiple);
  
  static Argument<double>* createFloatArgument(const std::string_view name,
                                              const std::string_view defaultValue,
                                              ArgumentI::ArgumentCharacteristics::OptionalOrMandatory optionalOrMandatory,
                                              ArgumentI::ArgumentCharacteristics::UniqueOrMultiple uniqueOrMultiple);
  
  static Argument<long>* createIntegerArgument(const std::string_view name,
                                              const std::string_view defaultValue,
                                              ArgumentI::ArgumentCharacteristics::OptionalOrMandatory optionalOrMandatory,
                                              ArgumentI::ArgumentCharacteristics::UniqueOrMultiple uniqueOrMultiple);
  
  static Argument<std::string>* createStringArgument(const std::string_view name,
                                                    const std::string_view defaultValue,
                                                    ArgumentI::ArgumentCharacteristics::OptionalOrMandatory optionalOrMandatory,
                                                    ArgumentI::ArgumentCharacteristics::UniqueOrMultiple uniqueOrMultiple);
};

} // namespace config::ptool

#endif /* PTOOL_ARGUMENTFACTORY_H */

