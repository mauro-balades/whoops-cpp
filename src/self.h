
#ifndef __H_WHOOPS_SELF_H_
#define __H_WHOOPS_SELF_H_

#include "./utils.h"

namespace WHOOPS_DEFAULT_VISIBILITY whoops {

template <typename... Ts>
class Self;

template <typename X, typename... Ts>
class Self<X, Ts...> : public Ts... {
 public:
  Self() = default;
  
 protected:
  typedef X self;
};

}  // namespace whoops

#endif  // __H_WHOOPS_SELF_H_
