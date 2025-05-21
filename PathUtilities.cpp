#include "PathUtilities.h"

// ── допоміжна ──
static bool is_alpha(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// 2-B
bool is_valid_path(const std::string& path)
{
    if (path.size() < 4) return false;          // "C:\a"
    if (!is_alpha(path[0]) || path[1] != ':' || path[2] != '\\')
        return false;

    auto lastSlash = path.find_last_of('\\');
    auto lastDot = path.find_last_of('.');

    // файл + розширення після останнього '\'
    return lastDot != std::string::npos &&
        lastDot > lastSlash + 1;
}

// 2-A
std::string last_directory(const std::string& path)
{
    auto lastSlash = path.find_last_of('\\');
    if (lastSlash == std::string::npos || lastSlash == 2)
        return "\\";             // корінь: "C:\file.ext"

    auto prevSlash = path.find_last_of('\\', lastSlash - 1);
    std::size_t start = (prevSlash == std::string::npos ? 3 : prevSlash + 1);
    return path.substr(start, lastSlash - start);
}
