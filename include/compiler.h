/*
 *  Copyright (C) 2019  The DOSBox Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef DOSBOX_COMPILER_H
#define DOSBOX_COMPILER_H

// fallback for old compilers missing attribute queries
// 
#ifndef __has_cpp_attribute
#  define __has_cpp_attribute(x) 0
#endif

/* 
 * Old DOSBox names GCC_LIKELY/GCC_UNLIKELY are not precise, since this
 * feature is supported by other compilers as well (e.g. Clang, Intel).
 * '!!' trick is used to assure macro semantics match user expectations.
 */

// FIXME this is how it's supposed to work according to spec, but
// it does not work in GCC 9 yet (feature seems incomplete, even with
// -std=c++2a

// if LIKELY (a > 0) {
// 	…
// }

/*

#if __has_cpp_attribute(likely)
#  define LIKELY(x) (x) [[likely]]
#elif C_HAS_BUILTIN_EXPECT
#  define LIKELY(x) (__builtin_expect(!!(x), 1))
#else
#  define LIKELY
#endif

#if __has_cpp_attribute(unlikely)
#  define UNLIKELY(x) (x) [[unlikely]]
#elif C_HAS_BUILTIN_EXPECT
#  define UNLIKELY(x) (__builtin_expect(!!(x), 0))
#else
#  define UNLIKELY
#endif

*/

// if (GCC_LIKELY(a > 0)) {
// 	…
// }

#if C_HAS_BUILTIN_EXPECT
# define GCC_LIKELY(x)   __builtin_expect(!!(x), 1)
# define GCC_UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
# define GCC_LIKELY
# define GCC_UNLIKELY
#endif

#endif /* DOSBOX_COMPILER_H */
