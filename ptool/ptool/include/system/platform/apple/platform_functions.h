//
//  project: ptool
//  filename: platform-functions.h
//
//  general apple
//

#ifndef PTOOL_PLATFORM_FUNCTIONS_H
#define PTOOL_PLATFORM_FUNCTIONS_H

namespace ptool::system::platform
{
    constexpr char path_separator = '/';

    constexpr const char* str_end(const char *s)
    {
      return *s ? str_end(s + 1) : s;
    }

    constexpr bool str_slant(const char *s)
    {
      return *s == path_separator ? true : (*s ? str_slant(s + 1) : false);
    }

    constexpr const char* r_slant(const char* s)
    {
      return *s == path_separator ? (s + 1) : r_slant(s - 1);
    }

    constexpr const char* basename(const char* s)
    {
      return str_slant(s) ? r_slant(str_end(s)) : s;
    }
  
} // namespace platform::system::ptool

#endif /* PTOOL_PLATFORM_FUNCTIONS_H */

 
