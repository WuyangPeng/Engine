/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 11:06)

#ifndef CORE_TOOLS_HELPER_SYSTEM_CLASS_INVARIANT_MACRO_H
#define CORE_TOOLS_HELPER_SYSTEM_CLASS_INVARIANT_MACRO_H

#include "CoreTools/Helper/ClassInvariantMacro.h"

#if !defined(SYSTEM_CLASS_INVARIANT_LEVEL)

    #define SYSTEM_CLASS_INVARIANT_LEVEL 8

#endif  // SYSTEM_CLASS_INVARIANT_LEVEL

#if !defined(SYSTEM_CLASS_INVARIANT_CONST_LEVEL)

    #define SYSTEM_CLASS_INVARIANT_CONST_LEVEL 1

#endif  // SYSTEM_CLASS_INVARIANT_CONST_LEVEL

static_assert(SYSTEM_CLASS_INVARIANT_LEVEL <= CLASS_INVARIANT_LEVEL, "Animation class invariant level definition error.");
static_assert(SYSTEM_CLASS_INVARIANT_CONST_LEVEL <= CLASS_INVARIANT_CONST_LEVEL, "Animation class invariant level definition error.");

#if 0 <= SYSTEM_CLASS_INVARIANT_LEVEL

    #define SYSTEM_CLASS_IS_VALID_0 CLASS_IS_VALID_0
    #define SYSTEM_SELF_CLASS_IS_VALID_0 SELF_CLASS_IS_VALID_0

#else  // SYSTEM_CLASS_INVARIANT_LEVEL < 0

    #define SYSTEM_CLASS_IS_VALID_0 (static_cast<void>(0))
    #define SYSTEM_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif  // 0 <= SYSTEM_CLASS_INVARIANT_LEVEL

#if 1 <= SYSTEM_CLASS_INVARIANT_LEVEL

    #define SYSTEM_CLASS_IS_VALID_1 CLASS_IS_VALID_1
    #define SYSTEM_SELF_CLASS_IS_VALID_1 SELF_CLASS_IS_VALID_1

#else  // SYSTEM_CLASS_INVARIANT_LEVEL < 1

    #define SYSTEM_CLASS_IS_VALID_1 (static_cast<void>(0))
    #define SYSTEM_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif  // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= SYSTEM_CLASS_INVARIANT_LEVEL

    #define SYSTEM_CLASS_IS_VALID_2 CLASS_IS_VALID_2
    #define SYSTEM_SELF_CLASS_IS_VALID_2 SELF_CLASS_IS_VALID_2

#else  // SYSTEM_CLASS_INVARIANT_LEVEL < 2

    #define SYSTEM_CLASS_IS_VALID_2 (static_cast<void>(0))
    #define SYSTEM_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif  // 2 <= SYSTEM_CLASS_INVARIANT_LEVEL

#if 3 <= SYSTEM_CLASS_INVARIANT_LEVEL

    #define SYSTEM_CLASS_IS_VALID_3 CLASS_IS_VALID_3
    #define SYSTEM_SELF_CLASS_IS_VALID_3 SELF_CLASS_IS_VALID_3

#else  // SYSTEM_CLASS_INVARIANT_LEVEL < 3

    #define SYSTEM_CLASS_IS_VALID_3 (static_cast<void>(0))
    #define SYSTEM_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif  // 3 <= SYSTEM_CLASS_INVARIANT_LEVEL

#if 4 <= SYSTEM_CLASS_INVARIANT_LEVEL

    #define SYSTEM_CLASS_IS_VALID_4 CLASS_IS_VALID_4
    #define SYSTEM_SELF_CLASS_IS_VALID_4 SELF_CLASS_IS_VALID_4

#else  // SYSTEM_CLASS_INVARIANT_LEVEL < 4

    #define SYSTEM_CLASS_IS_VALID_4 (static_cast<void>(0))
    #define SYSTEM_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif  // 4 <= SYSTEM_CLASS_INVARIANT_LEVEL

#if 5 <= SYSTEM_CLASS_INVARIANT_LEVEL

    #define SYSTEM_CLASS_IS_VALID_5 CLASS_IS_VALID_5
    #define SYSTEM_SELF_CLASS_IS_VALID_5 SELF_CLASS_IS_VALID_5

#else  // SYSTEM_CLASS_INVARIANT_LEVEL < 5

    #define SYSTEM_CLASS_IS_VALID_5 (static_cast<void>(0))
    #define SYSTEM_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif  // 5 <= SYSTEM_CLASS_INVARIANT_LEVEL

#if 6 <= SYSTEM_CLASS_INVARIANT_LEVEL

    #define SYSTEM_CLASS_IS_VALID_6 CLASS_IS_VALID_6
    #define SYSTEM_SELF_CLASS_IS_VALID_6 SELF_CLASS_IS_VALID_6

#else  // CLASS_INVARIANT_LEVEL < 6

    #define SYSTEM_CLASS_IS_VALID_6 (static_cast<void>(0))
    #define SYSTEM_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif  // 6 <= SYSTEM_CLASS_INVARIANT_LEVEL

#if 7 <= SYSTEM_CLASS_INVARIANT_LEVEL

    #define SYSTEM_CLASS_IS_VALID_7 CLASS_IS_VALID_7
    #define SYSTEM_SELF_CLASS_IS_VALID_7 SELF_CLASS_IS_VALID_7

#else  // SYSTEM_CLASS_INVARIANT_LEVEL < 7

    #define SYSTEM_CLASS_IS_VALID_7 (static_cast<void>(0))
    #define SYSTEM_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif  // 7 <= SYSTEM_CLASS_INVARIANT_LEVEL

#if 8 <= SYSTEM_CLASS_INVARIANT_LEVEL

    #define SYSTEM_CLASS_IS_VALID_8 CLASS_IS_VALID_8
    #define SYSTEM_SELF_CLASS_IS_VALID_8 SELF_CLASS_IS_VALID_8

#else  // SYSTEM_CLASS_INVARIANT_LEVEL < 8

    #define SYSTEM_CLASS_IS_VALID_8 (static_cast<void>(0))
    #define SYSTEM_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif  // 8 <= SYSTEM_CLASS_INVARIANT_LEVEL

#if 9 <= SYSTEM_CLASS_INVARIANT_LEVEL

    #define SYSTEM_CLASS_IS_VALID_9 CLASS_IS_VALID_9
    #define SYSTEM_SELF_CLASS_IS_VALID_9 SELF_CLASS_IS_VALID_9

#else  // SYSTEM_CLASS_INVARIANT_LEVEL < 9

    #define SYSTEM_CLASS_IS_VALID_9 (static_cast<void>(0))
    #define SYSTEM_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif  // 9 <= SYSTEM_CLASS_INVARIANT_LEVEL

#if 0 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

    #define SYSTEM_CLASS_IS_VALID_CONST_0 CLASS_IS_VALID_CONST_0

#else  // SYSTEM_CLASS_INVARIANT_CONST_LEVEL < 0

    #define SYSTEM_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))

#endif  // 0 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

    #define SYSTEM_CLASS_IS_VALID_CONST_1 CLASS_IS_VALID_CONST_1

#else  // SYSTEM_CLASS_INVARIANT_CONST_LEVEL < 1

    #define SYSTEM_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))

#endif  // 1 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

    #define SYSTEM_CLASS_IS_VALID_CONST_2 CLASS_IS_VALID_CONST_2

#else  // SYSTEM_CLASS_INVARIANT_CONST_LEVEL < 2

    #define SYSTEM_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))

#endif  // 2 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

    #define SYSTEM_CLASS_IS_VALID_CONST_3 CLASS_IS_VALID_CONST_3

#else  // SYSTEM_CLASS_INVARIANT_CONST_LEVEL < 3

    #define SYSTEM_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))

#endif  // 3 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

    #define SYSTEM_CLASS_IS_VALID_CONST_4 CLASS_IS_VALID_CONST_4

#else  // SYSTEM_CLASS_INVARIANT_CONST_LEVEL < 4

    #define SYSTEM_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))

#endif  // 4 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

    #define SYSTEM_CLASS_IS_VALID_CONST_5 CLASS_IS_VALID_CONST_5

#else  // SYSTEM_CLASS_INVARIANT_CONST_LEVEL < 5

    #define SYSTEM_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))

#endif  // 5 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

    #define SYSTEM_CLASS_IS_VALID_CONST_6 CLASS_IS_VALID_CONST_6

#else  // SYSTEM_CLASS_INVARIANT_CONST_LEVEL < 6

    #define SYSTEM_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))

#endif  // 6 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

    #define SYSTEM_CLASS_IS_VALID_CONST_7 CLASS_IS_VALID_CONST_7

#else  // SYSTEM_CLASS_INVARIANT_CONST_LEVEL < 7

    #define SYSTEM_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))

#endif  // 7 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

    #define SYSTEM_CLASS_IS_VALID_CONST_8 CLASS_IS_VALID_CONST_8

#else  // SYSTEM_CLASS_INVARIANT_CONST_LEVEL < 8

    #define SYSTEM_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))

#endif  // 8 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

    #define SYSTEM_CLASS_IS_VALID_CONST_9 CLASS_IS_VALID_CONST_9

#else  // SYSTEM_CLASS_INVARIANT_CONST_LEVEL < 9

    #define SYSTEM_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))

#endif  // 9 <= SYSTEM_CLASS_INVARIANT_CONST_LEVEL

#endif  // CORE_TOOLS_HELPER_SYSTEM_CLASS_INVARIANT_MACRO_H
