//
//  project: ptool
//  filename: configuration.cpp
//

#include "../../include/config/argument_configuration.h"
#include "../../include/utility/logger.h"

namespace ptool::config
{

std::unique_ptr<ArgumentConfiguration> ArgumentConfiguration::_configuration = std::unique_ptr<ArgumentConfiguration>(new ArgumentConfiguration);

ArgumentConfiguration::ArgumentConfiguration() : _arguments()
{
  LOGGER_INFO("called Configuration::Configuration()");
}

bool ArgumentConfiguration::load(int argc, const char** argv)
{
  LOGGER_DEVELOPMENT("called");

  return false;
}

bool ArgumentConfiguration::isArgumentSet(std::string_view key) const
{
  LOGGER_DEVELOPMENT("called");

  return false;
}

bool ArgumentConfiguration::wasArgumentSetUsingDefaultValue(std::string_view key) const
{
  LOGGER_DEVELOPMENT("called");

  return false;
}

bool ArgumentConfiguration::isBool(std::string_view key) const
{
  LOGGER_DEVELOPMENT("called");

  return false;
}

} // namespace config::ptool
