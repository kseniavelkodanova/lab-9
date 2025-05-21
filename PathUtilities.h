#pragma once
#include <string>

/// 2-B. Перевірка, чи є 'path' повним шляхом виду «X:\dir\file.ext».
bool is_valid_path(const std::string& path);

/// 2-A. Повертає назву останнього каталогу або "\" для кореня.
std::string last_directory(const std::string& path);
