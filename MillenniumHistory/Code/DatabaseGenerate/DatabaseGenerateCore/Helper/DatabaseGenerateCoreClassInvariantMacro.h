/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 20:42)

#ifndef DATABASE_GENERATE_CORE_HELPER_DATABASE_GENERATE_CORE_CLASS_INVARIANT_MACRO_H
#define DATABASE_GENERATE_CORE_HELPER_DATABASE_GENERATE_CORE_CLASS_INVARIANT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#if !defined(DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL)

    #define DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL 8

#endif  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

#if !defined(DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL)

    #define DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL 8

#endif  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

static_assert(DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL <= CLASS_INVARIANT_LEVEL, "Class invariant level definition error.");
static_assert(DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL <= CLASS_INVARIANT_CONST_LEVEL, "Class invariant level definition error.");

#if 0 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_0 CLASS_IS_VALID_0
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_0 SELF_CLASS_IS_VALID_0

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL < 0

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_0 (static_cast<void>(0))
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif  // 0 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

#if 1 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_1 CLASS_IS_VALID_1
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1 SELF_CLASS_IS_VALID_1

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL < 1

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_1 (static_cast<void>(0))
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif  // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_2 CLASS_IS_VALID_2
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_2 SELF_CLASS_IS_VALID_2

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL < 2

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_2 (static_cast<void>(0))
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif  // 2 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

#if 3 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_3 CLASS_IS_VALID_3
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_3 SELF_CLASS_IS_VALID_3

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL < 3

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_3 (static_cast<void>(0))
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif  // 3 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

#if 4 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_4 CLASS_IS_VALID_4
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_4 SELF_CLASS_IS_VALID_4

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL < 4

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_4 (static_cast<void>(0))
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif  // 4 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

#if 5 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_5 CLASS_IS_VALID_5
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_5 SELF_CLASS_IS_VALID_5

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL < 5

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_5 (static_cast<void>(0))
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif  // 5 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

#if 6 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_6 CLASS_IS_VALID_6
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_6 SELF_CLASS_IS_VALID_6

#else  // CLASS_INVARIANT_LEVEL < 6

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_6 (static_cast<void>(0))
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif  // 6 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

#if 7 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_7 CLASS_IS_VALID_7
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_7 SELF_CLASS_IS_VALID_7

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL < 7

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_7 (static_cast<void>(0))
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif  // 7 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

#if 8 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_8 CLASS_IS_VALID_8
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_8 SELF_CLASS_IS_VALID_8

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL < 8

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_8 (static_cast<void>(0))
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif  // 8 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

#if 9 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_9 CLASS_IS_VALID_9
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_9 SELF_CLASS_IS_VALID_9

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL < 9

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_9 (static_cast<void>(0))
    #define DATABASE_GENERATE_CORE_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif  // 9 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_LEVEL

#if 0 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_0 CLASS_IS_VALID_CONST_0

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL < 0

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))

#endif  // 0 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1 CLASS_IS_VALID_CONST_1

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL < 1

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))

#endif  // 1 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_2 CLASS_IS_VALID_CONST_2

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL < 2

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))

#endif  // 2 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_3 CLASS_IS_VALID_CONST_3

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL < 3

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))

#endif  // 3 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_4 CLASS_IS_VALID_CONST_4

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL < 4

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))

#endif  // 4 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_5 CLASS_IS_VALID_CONST_5

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL < 5

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))

#endif  // 5 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_6 CLASS_IS_VALID_CONST_6

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL < 6

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))

#endif  // 6 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_7 CLASS_IS_VALID_CONST_7

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL < 7

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))

#endif  // 7 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_8 CLASS_IS_VALID_CONST_8

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL < 8

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))

#endif  // 8 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9 CLASS_IS_VALID_CONST_9

#else  // DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL < 9

    #define DATABASE_GENERATE_CORE_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))

#endif  // 9 <= DATABASE_GENERATE_CORE_CLASS_INVARIANT_CONST_LEVEL

#endif  // DATABASE_GENERATE_CORE_HELPER_DATABASE_GENERATE_CORE_CLASS_INVARIANT_MACRO_H