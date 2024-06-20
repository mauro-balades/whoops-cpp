
#ifndef __H_WHOOPS_UTILS_H_
#define __H_WHOOPS_UTILS_H_

#ifndef WHOOPS_HIDDEN_SYMBOL
#define WHOOPS_DEFAULT_VISIBILITY __attribute__((visibility("default")))
#else
#define WHOOPS_DEFAULT_VISIBILITY __attribute__((visibility("hidden")))
#endif

namespace whoops {

}  // namespace whoops

#endif  // __H_WHOOPS_UTILS_H_
