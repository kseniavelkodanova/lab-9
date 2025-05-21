#pragma once
#include <cstddef>   // size_t

/// Повертає індекс останнього символу з 'chars' у рядку 'src',
/// починаючи з позиції 'pos' і рухаючись ліворуч.
/// Якщо не знайдено — повертає size_t(-1).
size_t my_find_last_of(const char* src,
    const char* chars,
    size_t pos = static_cast<size_t>(-1));
