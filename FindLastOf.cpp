#include "FindLastOf.h"

size_t my_find_last_of(const char* src,
    const char* chars,
    size_t pos)
{
    if (!src || !chars) return static_cast<size_t>(-1);

    // ── довжина src ──────────────────────────────────────────
    size_t len = 0;
    while (src[len] != '\0') ++len;

    if (len == 0) return static_cast<size_t>(-1);

    size_t i = (pos == static_cast<size_t>(-1) || pos >= len) ? len - 1 : pos;

    // ── пошук з кінця ────────────────────────────────────────
    for (;;)
    {
        char current = src[i];

        // чи входить current у chars?
        for (size_t j = 0; chars[j] != '\0'; ++j)
            if (current == chars[j])
                return i;

        if (i == 0) break;   // вийти, щойно дійшли до початку
        --i;
    }
    return static_cast<size_t>(-1);
}
