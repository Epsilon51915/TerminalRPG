#include "textEditor.hpp"

using namespace std;

// Lowercase text

void toLowercase(std::string& text) {
    std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c) {
        return std::tolower(c);
        });
}

std::string toLowercaseCopy(std::string text) {
    std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c) {
        return std::tolower(c);
        });
    return text;
}

// Trim whitespace

void trim(string& str, const unsigned char ch) {
    // Trim left.
    str.erase(str.begin(), find_if(str.begin(), str.end(), [ch](const unsigned char chIn) {
        return chIn != ch;
        }));
    // Trim right.
    str.erase(find_if(str.rbegin(), str.rend(), [ch](const unsigned char chIn) {
        return chIn != ch;
        }).base(), str.end());
}

void appendString(string& str)
{
    toLowercase(str);
    trim(str, ' ');
}