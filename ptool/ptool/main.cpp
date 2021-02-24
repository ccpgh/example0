//
//  project: ptool
//  filename: main.cpp
//

// TODO
// 1. on/off config logging - invert default
// 2. rename all classes - add prefix 'pt'
// 3. change namespace from ptool to pt
// 4. filenames change - to _
// 5. work out naming for base, impl, classes and templates

#include <iostream>

#include "include/config/argument_configuration.h"
#include "include/config/argument_factory.h"
#include "include/utility/logger.h"

namespace ptool
{

void displayHelp()
{
  std::cout
  << "+--------------------------------------------------+\n"
  << "|       SECURE PASSWORD GENERATION UTILITY         |\n"
  << "|       Name:   ptool                              |\n"
  << "|       Author: cc                                 |\n"
  << "+--------------------------------------------------+\n"
  << "| Flag    Purpose                    Default       |\n"
  << "+--------------------------------------------------+\n"
  << "| -h      Display this help screen   <OFF>         |\n"
  << "+--------------------------------------------------+"
  << std::endl;
}

bool configureArguments()
{
  using ptool::config::ArgumentI;

  
  //Argument(const std::string_view name, const std::string_view defaultValue, bool mandatory, bool multiple);
  //Argument argument1("-h", "n", Argument::ArgumentCharacteristics::OptionalMandatory::OM_OPTIONAL, Argument::ArgumentCharacteristics::UniqueMultiple::UM_UNIQUE);
  
  return true;
}

}

int main(int argc, const char ** argv)
{
  LOGGER_DEBUG("start");
  
  if (!ptool::config::ArgumentConfiguration::load(argc, argv))
  {
    ptool::displayHelp();
    
    LOGGER_ERROR("configuration load failed");
    return 1;
  }
  else
  {
    if (ptool::config::ArgumentConfiguration::configuration()->isArgumentSet("h") &&
        ptool::config::ArgumentConfiguration::configuration()->wasArgumentSetUsingDefaultValue("h") &&
        ptool::config::ArgumentConfiguration::configuration()->isBool("h"))
    {
      //auto results = ptool::config::Configuration::configuration()->getBool("h")->isTrue();
      
      ptool::displayHelp();
    }
    
    return 0;
  }
  
  LOGGER_INFO("end");
  return 0;
}
