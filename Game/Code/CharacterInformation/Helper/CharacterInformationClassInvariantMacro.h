///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 15:30)

#ifndef CHARACTER_INFORMATION_HELPER_CLASS_INVARIANT_HELPER_H
#define CHARACTER_INFORMATION_HELPER_CLASS_INVARIANT_HELPER_H

#include "UserMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#if !defined(CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL)

    #define CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL 8

#endif  // CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

#if !defined(CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL)

    #define CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL 8

#endif  // CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

static_assert(CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL <= CLASS_INVARIANT_LEVEL, "Class invariant level definition error.");
static_assert(CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL <= CLASS_INVARIANT_CONST_LEVEL, "Class invariant level definition error.");

#if 0 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_0 CLASS_IS_VALID_0
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_0 SELF_CLASS_IS_VALID_0

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL < 0

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_0 (static_cast<void>(0))
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif  // 0 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

#if 1 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_1 CLASS_IS_VALID_1
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_1 SELF_CLASS_IS_VALID_1

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL < 1

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_1 (static_cast<void>(0))
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif  // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_2 CLASS_IS_VALID_2
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_2 SELF_CLASS_IS_VALID_2

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL < 2

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_2 (static_cast<void>(0))
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif  // 2 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

#if 3 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_3 CLASS_IS_VALID_3
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_3 SELF_CLASS_IS_VALID_3

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL < 3

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_3 (static_cast<void>(0))
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif  // 3 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

#if 4 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_4 CLASS_IS_VALID_4
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_4 SELF_CLASS_IS_VALID_4

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL < 4

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_4 (static_cast<void>(0))
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif  // 4 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

#if 5 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_5 CLASS_IS_VALID_5
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_5 SELF_CLASS_IS_VALID_5

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL < 5

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_5 (static_cast<void>(0))
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif  // 5 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

#if 6 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_6 CLASS_IS_VALID_6
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_6 SELF_CLASS_IS_VALID_6

#else  // CLASS_INVARIANT_LEVEL < 6

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_6 (static_cast<void>(0))
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif  // 6 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

#if 7 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_7 CLASS_IS_VALID_7
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_7 SELF_CLASS_IS_VALID_7

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL < 7

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_7 (static_cast<void>(0))
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif  // 7 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

#if 8 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_8 CLASS_IS_VALID_8
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_8 SELF_CLASS_IS_VALID_8

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL < 8

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_8 (static_cast<void>(0))
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif  // 8 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

#if 9 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_9 CLASS_IS_VALID_9
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_9 SELF_CLASS_IS_VALID_9

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL < 9

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_9 (static_cast<void>(0))
    #define CHARACTER_INFORMATION_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif  // 9 <= CHARACTER_INFORMATION_CLASS_INVARIANT_LEVEL

#if 0 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_0 CLASS_IS_VALID_CONST_0

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL < 0

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))

#endif  // 0 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_1 CLASS_IS_VALID_CONST_1

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL < 1

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))

#endif  // 1 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_2 CLASS_IS_VALID_CONST_2

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL < 2

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))

#endif  // 2 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_3 CLASS_IS_VALID_CONST_3

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL < 3

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))

#endif  // 3 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_4 CLASS_IS_VALID_CONST_4

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL < 4

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))

#endif  // 4 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_5 CLASS_IS_VALID_CONST_5

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL < 5

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))

#endif  // 5 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_6 CLASS_IS_VALID_CONST_6

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL < 6

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))

#endif  // 6 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_7 CLASS_IS_VALID_CONST_7

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL < 7

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))

#endif  // 7 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_8 CLASS_IS_VALID_CONST_8

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL < 8

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))

#endif  // 8 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_9 CLASS_IS_VALID_CONST_9

#else  // CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL < 9

    #define CHARACTER_INFORMATION_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))

#endif  // 9 <= CHARACTER_INFORMATION_CLASS_INVARIANT_CONST_LEVEL

#endif  // CHARACTER_INFORMATION_HELPER_CLASS_INVARIANT_HELPER_H
