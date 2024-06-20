
#ifndef __H_WHOOPS_FILESYSTEM_H_
#define __H_WHOOPS_FILESYSTEM_H_

#include "./utils.h"
#include "./strings.h"

namespace WHOOPS_DEFAULT_VISIBILITY whoops {

inline static StringT GetCwd() {
  char cwd[1024];
  if (getcwd(cwd, sizeof(cwd)) != nullptr) {
    return cwd;
  }
  return "";
}

inline static StringT GetExecutablePath() {
#ifdef WHOOPS_LINUX
  char path[1024];
  ssize_t len = readlink("/proc/self/exe", path, sizeof(path) - 1);
  if (len != -1) {
    path[len] = '\0';
    return path;
  }
#elif defined(WHOOPS_MACOS)
  char path[1024];
  uint32_t size = sizeof(path);
  if (_NSGetExecutablePath(path, &size) == 0) {
    return path;
  }
#elif defined(WHOOPS_WINDOWS)
  char path[1024];
  if (GetModuleFileNameA(nullptr, path, sizeof(path)) != 0) {
    return path;
  }
#endif
}

inline static StringT GetExecutableDir() {
  return GetExecutablePath().substr(0, GetExecutablePath().find_last_of("/\\"));
}

inline static StringT ReadFile(const StringT& path) {
  std::ifstream file(path);
  if (file.is_open()) {
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
  }
  return "";
}

inline static void WriteFile(const StringT& path, const StringT& content) {
  std::ofstream file(path);
  if (file.is_open()) {
    file << content;
  }
}

inline static void AppendFile(const StringT& path, const StringT& content) {
  std::ofstream file(path, std::ios_base::app);
  if (file.is_open()) {
    file << content;
  }
}

}  // namespace whoops

#endif  // __H_WHOOPS_FILESYSTEM_H_
