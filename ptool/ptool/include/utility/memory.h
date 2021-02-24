//
//  project: ptool
//  filename: memory.h
//

#ifndef PTOOL_MEMORY_H
#define PTOOL_MEMORY_H

#include <iostream>
#include <memory>

namespace ptool::utility
{
namespace memory
{

  template<class T>
  T* release(std::shared_ptr<T>& sp)
  {
    T* p(sp.get());
    sp.reset();
    
    return p;
  }

} // memory
} // namespace utility::ptool


#endif /* PTOOL_MEMORY_H */
