
#ifndef __H_WHOOPS_UTILS_H_
#define __H_WHOOPS_UTILS_H_

#ifndef WHOOPS_HIDDEN_SYMBOL
#define WHOOPS_DEFAULT_VISIBILITY __attribute__((visibility("default")))
#else
#define WHOOPS_DEFAULT_VISIBILITY __attribute__((visibility("hidden")))
#endif

#ifdef __linux__
#define WHOOPS_LINUX
#elif defined(__APPLE__)
#define WHOOPS_MACOS
#elif defined(_WIN32)
#define WHOOPS_WINDOWS
#else
#error "Unsupported platform for whoops"
#endif

namespace whoops {

}  // namespace whoops

#endif  // __H_WHOOPS_UTILS_H_
