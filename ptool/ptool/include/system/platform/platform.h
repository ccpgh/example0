//
//  project: ptool
//  filename: platform.h
//

#ifndef PTOOL_PLATFORM_H
#define PTOOL_PLATFORM_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)

  error "Unsupported platform"
  #ifdef _WIN64
  #else
  #endif

#elif __APPLE__

  #include "../platform/apple/platform_functions.h"
  #include <TargetConditionals.h>
  
  #if TARGET_IPHONE_SIMULATOR
  #elif TARGET_OS_IPHONE
  #elif TARGET_OS_MAC
  #else
  #endif

#elif __linux__
  error "Unsupported platform"

#elif __unix__ // all unices not caught above
  error "Unsupported platform"

#elif defined(_POSIX_VERSION)
  error "Unsupported platform"

#else
  error "Unsupported platform"

#endif

#endif /* PTOOL_PLATFORM_H */
