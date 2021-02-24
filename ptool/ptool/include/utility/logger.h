//
//  project: ptool
//  filename: logger.h
//

#ifndef PTOOL_LOGGER_H
#define PTOOL_LOGGER_H

#include <iostream>

#include "platform.h"

namespace ptool::utility
{

class Logger
{
private:
  Logger() = delete;
  bool operator==(const Logger&) = delete;
  Logger& operator=(const Logger&) = delete;
  Logger(const Logger&) = delete;
  ~Logger() = delete;
  
  static void log(std::string_view level, std::string_view filename, long lineno, std::string_view message);
  
  static constexpr auto development_string = "DEVELOPMENT";
  static constexpr auto trace_string       = "TRACE";
  static constexpr auto debug_string       = "DEBUG";
  static constexpr auto info_string        = "INFO";
  static constexpr auto warning_string     = "WARNING";
  static constexpr auto error_string       = "ERROR";
  static constexpr auto fatal_string       = "FATAL";
  
public:
  enum class LogLevel : int16_t
  {
    LL_DEVELOPMENT = 0,
    LL_TRACE,
    LL_DEBUG,
    LL_INFO,
    LL_WARNING,
    LL_ERROR,
    LL_FATAL
  };
  
  struct development_struct {};
  struct trace_struct {};
  struct debug_struct {};
  struct info_struct {};
  struct warning_struct {};
  struct error_struct {};
  struct fatal_struct {};
  
  static constexpr development_struct development_obj = development_struct{};
  static constexpr trace_struct       trace_obj   = trace_struct{};
  static constexpr debug_struct       debug_obj   = debug_struct{};
  static constexpr info_struct        info_obj    = info_struct{};
  static constexpr warning_struct     warning_obj = warning_struct{};
  static constexpr error_struct       error_obj   = error_struct{};
  static constexpr fatal_struct       fatal_obj   = fatal_struct{};
  
  static void log(development_struct type, std::string_view filename, long lineno, std::string_view message);
  static void log(trace_struct       type, std::string_view filename, long lineno, std::string_view message);
  static void log(debug_struct       type, std::string_view filename, long lineno, std::string_view message);
  static void log(info_struct        type, std::string_view filename, long lineno, std::string_view message);
  static void log(warning_struct     type, std::string_view filename, long lineno, std::string_view message);
  static void log(error_struct       type, std::string_view filename, long lineno, std::string_view message);
  static void log(fatal_struct       type, std::string_view filename, long lineno, std::string_view message);
  
};

#define LOGGER_DEVELOPMENT(message) { \
ptool::utility::Logger::log(ptool::utility::Logger::development_obj, \
ptool::system::platform::basename(__FILE__), __LINE__, message); \
}

#define LOGGER_TRACE(message) { \
ptool::utility::Logger::log(ptool::utility::Logger::trace_obj, \
ptool::system::platform::basename(__FILE__), __LINE__, message); \
}

#define LOGGER_DEBUG(message) { \
ptool::utility::Logger::log(ptool::utility::Logger::debug_obj, \
ptool::system::platform::basename(__FILE__), __LINE__, message); \
}

#define LOGGER_INFO(message) { \
ptool::utility::Logger::log(ptool::utility::Logger::info_obj, \
ptool::system::platform::basename(__FILE__), __LINE__, message); \
}

#define LOGGER_WARNING(message) { \
ptool::utility::Logger::log(ptool::utility::Logger::warning_obj, \
ptool::system::platform::basename(__FILE__), __LINE__, message); \
}

#define LOGGER_ERROR(message) { \
ptool::utility::Logger::log(ptool::utility::Logger::error_obj, \
ptool::system::platform::basename(__FILE__), __LINE__, message); \
}

#define LOGGER_FATAL(message) { \
ptool::utility::Logger::log(ptool::utility::Logger::fatal_obj, \
ptool::system::platform::basename(__FILE__), __LINE__, message); \
}

} // namespace utility::ptool

#endif /* PTOOL_LOGGER_H */

