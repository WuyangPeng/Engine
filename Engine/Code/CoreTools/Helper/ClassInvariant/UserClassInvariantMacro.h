///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:46)

#ifndef CORE_TOOLS_HELPER_USER_CLASS_INVARIANT_MACRO_H
#define CORE_TOOLS_HELPER_USER_CLASS_INVARIANT_MACRO_H

#include "CoreTools/Helper/ClassInvariantMacro.h"

#if !defined(USER_CLASS_INVARIANT_LEVEL)

    #define USER_CLASS_INVARIANT_LEVEL 8

#endif  // USER_CLASS_INVARIANT_LEVEL

#if !defined(USER_CLASS_INVARIANT_CONST_LEVEL)

    #define USER_CLASS_INVARIANT_CONST_LEVEL 8

#endif  // USER_CLASS_INVARIANT_CONST_LEVEL

static_assert(USER_CLASS_INVARIANT_LEVEL <= CLASS_INVARIANT_LEVEL, "User class invariant level definition error.");
static_assert(USER_CLASS_INVARIANT_CONST_LEVEL <= CLASS_INVARIANT_CONST_LEVEL, "User class invariant level definition error.");

#if 0 <= USER_CLASS_INVARIANT_LEVEL

    #define USER_CLASS_IS_VALID_0 CLASS_IS_VALID_0
    #define USER_SELF_CLASS_IS_VALID_0 SELF_CLASS_IS_VALID_0

#else  // USER_CLASS_INVARIANT_LEVEL < 0

    #define USER_CLASS_IS_VALID_0 (static_cast<void>(0))
    #define USER_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif  //0 <= USER_CLASS_INVARIANT_LEVEL

#if 1 <= USER_CLASS_INVARIANT_LEVEL

    #define USER_CLASS_IS_VALID_1 CLASS_IS_VALID_1
    #define USER_SELF_CLASS_IS_VALID_1 SELF_CLASS_IS_VALID_1

#else  // USER_CLASS_INVARIANT_LEVEL < 1

    #define USER_CLASS_IS_VALID_1 (static_cast<void>(0))
    #define USER_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif  // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= USER_CLASS_INVARIANT_LEVEL

    #define USER_CLASS_IS_VALID_2 CLASS_IS_VALID_2
    #define USER_SELF_CLASS_IS_VALID_2 SELF_CLASS_IS_VALID_2

#else  // USER_CLASS_INVARIANT_LEVEL < 2

    #define USER_CLASS_IS_VALID_2 (static_cast<void>(0))
    #define USER_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif  // 2 <= USER_CLASS_INVARIANT_LEVEL

#if 3 <= USER_CLASS_INVARIANT_LEVEL

    #define USER_CLASS_IS_VALID_3 CLASS_IS_VALID_3
    #define USER_SELF_CLASS_IS_VALID_3 SELF_CLASS_IS_VALID_3

#else  // USER_CLASS_INVARIANT_LEVEL < 3

    #define USER_CLASS_IS_VALID_3 (static_cast<void>(0))
    #define USER_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif  // 3 <= USER_CLASS_INVARIANT_LEVEL

#if 4 <= USER_CLASS_INVARIANT_LEVEL

    #define USER_CLASS_IS_VALID_4 CLASS_IS_VALID_4
    #define USER_SELF_CLASS_IS_VALID_4 SELF_CLASS_IS_VALID_4

#else  // USER_CLASS_INVARIANT_LEVEL < 4

    #define USER_CLASS_IS_VALID_4 (static_cast<void>(0))
    #define USER_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif  // 4 <= USER_CLASS_INVARIANT_LEVEL

#if 5 <= USER_CLASS_INVARIANT_LEVEL

    #define USER_CLASS_IS_VALID_5 CLASS_IS_VALID_5
    #define USER_SELF_CLASS_IS_VALID_5 SELF_CLASS_IS_VALID_5

#else  // USER_CLASS_INVARIANT_LEVEL < 5

    #define USER_CLASS_IS_VALID_5 (static_cast<void>(0))
    #define USER_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif  // 5 <= USER_CLASS_INVARIANT_LEVEL

#if 6 <= USER_CLASS_INVARIANT_LEVEL

    #define USER_CLASS_IS_VALID_6 CLASS_IS_VALID_6
    #define USER_SELF_CLASS_IS_VALID_6 SELF_CLASS_IS_VALID_6

#else  // CLASS_INVARIANT_LEVEL < 6

    #define USER_CLASS_IS_VALID_6 (static_cast<void>(0))
    #define USER_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif  // 6 <= USER_CLASS_INVARIANT_LEVEL

#if 7 <= USER_CLASS_INVARIANT_LEVEL

    #define USER_CLASS_IS_VALID_7 CLASS_IS_VALID_7
    #define USER_SELF_CLASS_IS_VALID_7 SELF_CLASS_IS_VALID_7

#else  // USER_CLASS_INVARIANT_LEVEL < 7

    #define USER_CLASS_IS_VALID_7 (static_cast<void>(0))
    #define USER_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif  // 7 <= USER_CLASS_INVARIANT_LEVEL

#if 8 <= USER_CLASS_INVARIANT_LEVEL

    #define USER_CLASS_IS_VALID_8 CLASS_IS_VALID_8
    #define USER_SELF_CLASS_IS_VALID_8 SELF_CLASS_IS_VALID_8

#else  // USER_CLASS_INVARIANT_LEVEL < 8

    #define USER_CLASS_IS_VALID_8 (static_cast<void>(0))
    #define USER_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif  // 8 <= USER_CLASS_INVARIANT_LEVEL

#if 9 <= USER_CLASS_INVARIANT_LEVEL

    #define USER_CLASS_IS_VALID_9 CLASS_IS_VALID_9
    #define USER_SELF_CLASS_IS_VALID_9 SELF_CLASS_IS_VALID_9

#else  // USER_CLASS_INVARIANT_LEVEL < 9

    #define USER_CLASS_IS_VALID_9 (static_cast<void>(0))
    #define USER_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif  // 9 <= USER_CLASS_INVARIANT_LEVEL

#if 0 <= USER_CLASS_INVARIANT_CONST_LEVEL

    #define USER_CLASS_IS_VALID_CONST_0 CLASS_IS_VALID_CONST_0

#else  // USER_CLASS_INVARIANT_CONST_LEVEL < 0

    #define USER_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))

#endif  // 0 <= USER_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= USER_CLASS_INVARIANT_CONST_LEVEL

    #define USER_CLASS_IS_VALID_CONST_1 CLASS_IS_VALID_CONST_1

#else  // USER_CLASS_INVARIANT_CONST_LEVEL < 1

    #define USER_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))

#endif  // 1 <= USER_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= USER_CLASS_INVARIANT_CONST_LEVEL

    #define USER_CLASS_IS_VALID_CONST_2 CLASS_IS_VALID_CONST_2

#else  // USER_CLASS_INVARIANT_CONST_LEVEL < 2

    #define USER_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))

#endif  // 2 <= USER_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= USER_CLASS_INVARIANT_CONST_LEVEL

    #define USER_CLASS_IS_VALID_CONST_3 CLASS_IS_VALID_CONST_3

#else  // USER_CLASS_INVARIANT_CONST_LEVEL < 3

    #define USER_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))

#endif  // 3 <= USER_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= USER_CLASS_INVARIANT_CONST_LEVEL

    #define USER_CLASS_IS_VALID_CONST_4 CLASS_IS_VALID_CONST_4

#else  // USER_CLASS_INVARIANT_CONST_LEVEL < 4

    #define USER_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))

#endif  // 4 <= USER_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= USER_CLASS_INVARIANT_CONST_LEVEL

    #define USER_CLASS_IS_VALID_CONST_5 CLASS_IS_VALID_CONST_5

#else  // USER_CLASS_INVARIANT_CONST_LEVEL < 5

    #define USER_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))

#endif  // 5 <= USER_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= USER_CLASS_INVARIANT_CONST_LEVEL

    #define USER_CLASS_IS_VALID_CONST_6 CLASS_IS_VALID_CONST_6

#else  // USER_CLASS_INVARIANT_CONST_LEVEL < 6

    #define USER_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))

#endif  // 6 <= USER_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= USER_CLASS_INVARIANT_CONST_LEVEL

    #define USER_CLASS_IS_VALID_CONST_7 CLASS_IS_VALID_CONST_7

#else  // USER_CLASS_INVARIANT_CONST_LEVEL < 7

    #define USER_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))

#endif  // 7 <= USER_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= USER_CLASS_INVARIANT_CONST_LEVEL

    #define USER_CLASS_IS_VALID_CONST_8 CLASS_IS_VALID_CONST_8

#else  // USER_CLASS_INVARIANT_CONST_LEVEL < 8

    #define USER_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))

#endif  // 8 <= USER_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= USER_CLASS_INVARIANT_CONST_LEVEL

    #define USER_CLASS_IS_VALID_CONST_9 CLASS_IS_VALID_CONST_9

#else  // USER_CLASS_INVARIANT_CONST_LEVEL < 9

    #define USER_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))

#endif  // 9 <= USER_CLASS_INVARIANT_CONST_LEVEL

#endif  // CORE_TOOLS_HELPER_USER_CLASS_INVARIANT_MACRO_H
