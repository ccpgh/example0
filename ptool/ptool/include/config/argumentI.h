//
//  project: ptool
//  filename: argumentI.h
//

#ifndef PTOOL_ARGUMENTI_H
#define PTOOL_ARGUMENTI_H

#include <memory>
#include <string>
#include <string_view>
#include <vector>
#include <variant>
#include <tuple>

namespace ptool::config
{

class ArgumentI
{
public:
  class ArgumentCharacteristics
  {
  private:
    ArgumentCharacteristics(const ArgumentI& argument) = delete;

  public:
    enum class OptionalOrMandatory : int16_t
    {
      OM_OPTIONAL = 0,
      OM_MANDATORY
    };

    enum class UniqueOrMultiple : int16_t
    {
      UM_UNIQUE = 0,
      UM_MULTIPLE
    };
    
    enum class AssignedOrDefault : int16_t
    {
      DA_ASSIGNED = 0,
      DA_DEFAULT,
      DA_NONE
    };
    
    enum class ValidOrInvalid : int16_t
    {
      VI_VALID = 0,
      VI_INVALID,
      VI_NONE
    };
  };

private:
  static long _argumentNo;
  long _argumentValueNo;
  
  std::string _name;
  std::string _defaultValue;
  
  ArgumentCharacteristics::OptionalOrMandatory _optionalOrMandatory;
  ArgumentCharacteristics::UniqueOrMultiple    _uniqueOrMultiple;
  ArgumentCharacteristics::AssignedOrDefault   _assignedOrDefault;
  ArgumentCharacteristics::ValidOrInvalid      _validOrInvalid;
    
  std::vector<std::tuple<int, std::string, std::variant<bool, long, double, std::string>>> _values;
  std::vector<std::string> _diagnosticMessages;

protected:
  ArgumentI(const std::string_view name,
           const std::string_view defaultValue,
           ArgumentCharacteristics::OptionalOrMandatory optionalOrMandatory,
           ArgumentCharacteristics::UniqueOrMultiple uniqueOrMultiple);

public:
  bool operator==(const ArgumentI& argument) const;
  
  ArgumentI& operator=(const ArgumentI& argument);

  ArgumentI(const ArgumentI& argument);
  
  virtual bool setValue(const std::variant<bool, long, double, std::string>& value) = 0;
  
  virtual ~ArgumentI()
  {}
};

} // namespace config::ptool

#endif /* PTOOL_ARGUMENTI_H */
