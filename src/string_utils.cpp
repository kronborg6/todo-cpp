#include "string_utils.hpp"
#include <cstddef>
#include <string>
#include <vector>

namespace utils {
std::vector<std::string> split(std::string s, const std::string &target) {
  std::vector<std::string> tokens;
  size_t pos = 0;
  std::string token;
  while ((pos = s.find(target)) != std::string::npos) {
    token = s.substr(0, pos);
    tokens.push_back(token);
    s.erase(0, pos + target.length());
  }
  tokens.push_back(s);

  return tokens;
}
} // namespace utils
