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

/* 
 * Old DOSBox names GCC_LIKELY/GCC_UNLIKELY are not precise, since this
 * feature is supported by other compilers as well (e.g. Clang, Intel).
 * '!!' trick is used to assure macro semantics match user expectations.
 */

#if C_HAS_BUILTIN_EXPECT
# define LIKELY(x)       __builtin_expect(!!(x), 1)
# define UNLIKELY(x)     __builtin_expect(!!(x), 0)
# define GCC_LIKELY(x)   __builtin_expect(!!(x), 1)
# define GCC_UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
# define LIKELY       (x) (x)
# define UNLIKELY     (x) (x)
# define GCC_LIKELY   (x) (x)
# define GCC_UNLIKELY (x) (x)
#endif

#endif /* DOSBOX_COMPILER_H */
