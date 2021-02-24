//
//  project: ptool
//  filename: argument_configuration.h
//

#ifndef PTOOL_ARGUMENTCONFIGURATION_H
#define PTOOL_ARGUMENTCONFIGURATION_H

#include <memory>
#include <string>
#include <string_view>
#include <vector>

#include "argument.h"

namespace ptool::config
{

class ArgumentConfiguration
{

private:
  ArgumentConfiguration();

  bool operator==(const ArgumentConfiguration&) = delete;
  ArgumentConfiguration& operator=(const ArgumentConfiguration&) = delete;
  ArgumentConfiguration(const ArgumentConfiguration&) = delete;
 
  static std::unique_ptr<ArgumentConfiguration> _configuration;

  std::vector<std::pair<std::string, std::string>> _arguments;
    
public:
  virtual ~ArgumentConfiguration()
  {}

  static const ArgumentConfiguration* const configuration()
  {
    return _configuration.get();
  }

  static bool load(int argc, const char** argv);
  
  // name
  bool isArgumentSet(std::string_view name) const;
  bool wasArgumentSetUsingDefaultValue(std::string_view name) const;
    
  // value

};

} // namespace config::ptool

#endif /* PTOOL_ARGUMENTCONFIGURATION_H */
