#include <string>
#include <algorithm>

// Lowercase text
void toLowercase(std::string& text);
std::string toLowercaseCopy(std::string text);

// Trim whitespace
void trim(std::string& str, const unsigned char ch);

void appendString(std::string& str);
void findAndReplace(std::string& str, const std::string& query, const std::string& replacement);
