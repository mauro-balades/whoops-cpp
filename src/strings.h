
#ifndef __H_WHOOPS_STRINGS_H_
#define __H_WHOOPS_STRINGS_H_

#ifndef WHOOPS_CUSTOM_STRING
#include <string>
#endif

#include "./utils.h"

namespace WHOOPS_DEFAULT_VISIBILITY whoops {

#ifndef WHOOPS_CUSTOM_STRING
using StringT = std::string;
#else
using StringT = WHOOPS_CUSTOM_STRING;
#endif

inline static StringT StartsWith(const StringT& str, const StringT& prefix) {
  return str.substr(0, prefix.size()) == prefix;
}

inline static StringT EndsWith(const StringT& str, const StringT& suffix) {
  return str.size() >= suffix.size() &&
         str.substr(str.size() - suffix.size()) == suffix;
}

inline static StringT Trim(const StringT& str) {
  auto start = str.find_first_not_of(" \t\n");
  if (start == StringT::npos) {
    return "";
  }
  auto end = str.find_last_not_of(" \t\n");
  return str.substr(start, end - start + 1);
}

inline static StringT Replace(const StringT& str, const StringT& from,
                       const StringT& to) {
  StringT result = str;
  size_t start_pos = 0;
  while ((start_pos = result.find(from, start_pos)) != StringT::npos) {
    result.replace(start_pos, from.length(), to);
    start_pos += to.length();
  }
  return result;
}

inline static std::vector<StringT> Split(const StringT& str, const StringT& delim) {
  std::vector<StringT> tokens;
  size_t start = 0;
  size_t end = 0;
  while ((end = str.find(delim, start)) != StringT::npos) {
    tokens.push_back(str.substr(start, end - start));
    start = end + delim.length();
  }
  tokens.push_back(str.substr(start));
  return tokens;
}

inline static StringT Join(const std::vector<StringT>& tokens, const StringT& delim) {
  StringT result;
  for (size_t i = 0; i < tokens.size(); ++i) {
    if (i > 0) {
      result += delim;
    }
    result += tokens[i];
  }
  return result;
}

inline static StringT ToLower(const StringT& str) {
  StringT result = str;
  std::transform(result.begin(), result.end(), result.begin(), ::tolower);
  return result;
}

inline static StringT ToUpper(const StringT& str) {
  StringT result = str;
  std::transform(result.begin(), result.end(), result.begin(), ::toupper);
  return result;
}

}

#endif // __H_WHOOPS_STRINGS_H_
