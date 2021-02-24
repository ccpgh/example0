//
//  project: ptool
//  filename: argumentI.cpp
//

#include "../../include/config/argument.h"
#include "../../include/utility/logger.h"

namespace ptool::config
{

long ArgumentI::_argumentNo = 0;

ArgumentI::ArgumentI(const std::string_view name,
           const std::string_view defaultValue,
           ArgumentCharacteristics::OptionalOrMandatory optionalOrMandatory,
           ArgumentCharacteristics::UniqueOrMultiple uniqueOrMultiple) : _name(name),
              _defaultValue(defaultValue), _optionalOrMandatory(optionalOrMandatory),
              _uniqueOrMultiple(uniqueOrMultiple),
              _assignedOrDefault(ArgumentCharacteristics::AssignedOrDefault::DA_NONE),
              _validOrInvalid(ArgumentCharacteristics::ValidOrInvalid::VI_NONE),
              _values(), _diagnosticMessages(), _argumentValueNo(0)
{
}

ArgumentI::ArgumentI(const ArgumentI& argument)
{
  this->_name                 = argument._name;
  this->_defaultValue         = argument._defaultValue;
  this->_optionalOrMandatory  = argument._optionalOrMandatory;
  this->_uniqueOrMultiple     = argument._uniqueOrMultiple;
  this->_assignedOrDefault    = argument._assignedOrDefault;
  this->_validOrInvalid       = argument._validOrInvalid;
  this->_values               = argument._values;  // NYI - fix - better copy
  this->_diagnosticMessages   = argument._diagnosticMessages; // NYI - fix - better copy
  this->_argumentValueNo      = argument._argumentValueNo;
}

bool ArgumentI::operator==(const ArgumentI& argument) const
{
  return this->_name          == argument._name &&
  this->_defaultValue         == argument._defaultValue &&
  this->_optionalOrMandatory  == argument._optionalOrMandatory &&
  this->_uniqueOrMultiple     == argument._uniqueOrMultiple &&
  this->_assignedOrDefault    == argument._assignedOrDefault &&
  this->_validOrInvalid       == argument._validOrInvalid &&
  this->_values               == argument._values &&  // NYI - fix - better copy
  this->_diagnosticMessages   == argument._diagnosticMessages && // NYI - fix - better copy
  this->_argumentValueNo      == argument._argumentValueNo
  ;
}

ArgumentI& ArgumentI::operator=(const ArgumentI& argument)
{
  this->_name                 = argument._name;
  this->_defaultValue         = argument._defaultValue;
  this->_optionalOrMandatory  = argument._optionalOrMandatory;
  this->_uniqueOrMultiple     = argument._uniqueOrMultiple;
  this->_assignedOrDefault    = argument._assignedOrDefault;
  this->_validOrInvalid       = argument._validOrInvalid;
  this->_values               = argument._values;  // NYI - fix - better copy
  this->_diagnosticMessages   = argument._diagnosticMessages; // NYI - fix - better copy
  this->_argumentValueNo      = argument._argumentValueNo;
  ;
  
  return (*this);
}
  
} // namespace config::ptool
