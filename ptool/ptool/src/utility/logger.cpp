//
//  project: ptool
//  filename: logger.cpp
//

#include <iostream>
#include <iomanip>
#include <map>

#include "../../include/utility/logger.h"
#include "../../include/system/platform/platform.h"
#include "../../include/parser/grammar/tokenizer.h"

namespace ptool::utility
{

void Logger::log(std::string_view level, std::string_view filename, long lineno, std::string_view message)
{
  time_t now(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
 
  std::cerr << std::put_time(localtime(&now), "%F %T")
  << " "
  << filename
  << ":"
  << lineno
  << " ["
  << level
  << "] > "
  << message
  << std::endl;
}

constexpr Logger::development_struct utility::Logger::development_obj;
constexpr utility::Logger::trace_struct       utility::Logger::trace_obj;
constexpr utility::Logger::debug_struct       utility::Logger::debug_obj;
constexpr utility::Logger::info_struct        utility::Logger::info_obj;
constexpr utility::Logger::warning_struct     utility::Logger::warning_obj;
constexpr utility::Logger::error_struct       utility::Logger::error_obj;
constexpr utility::Logger::fatal_struct       utility::Logger::fatal_obj;

void utility::Logger::log(development_struct type, std::string_view filename, long lineno, std::string_view message)
{
  utility::Logger::log(Logger::development_string, filename, lineno, message);
}

void utility::Logger::log(trace_struct type, std::string_view filename, long lineno, std::string_view message)
{
  utility::Logger::log(Logger::trace_string, filename, lineno, message);
}

void utility::Logger::log(debug_struct type, std::string_view filename, long lineno, std::string_view message)
{
  utility::Logger::log(Logger::debug_string, filename, lineno, message);
}

void utility::Logger::log(info_struct type, std::string_view filename, long lineno, std::string_view message)
{
  utility::Logger::log(Logger::info_string, filename, lineno, message);
}

void utility::Logger::log(warning_struct type, std::string_view filename, long lineno, std::string_view message)
{
  utility::Logger::log(Logger::warning_string, filename, lineno, message);
}

void utility::Logger::log(error_struct type, std::string_view filename, long lineno, std::string_view message)
{
  utility::Logger::log(Logger::error_string, filename, lineno, message);
}

void utility::Logger::log(fatal_struct type, std::string_view filename, long lineno, std::string_view message)
{
  utility::Logger::log(Logger::fatal_string, filename, lineno, message);
}

} // namespace ptool::utility

