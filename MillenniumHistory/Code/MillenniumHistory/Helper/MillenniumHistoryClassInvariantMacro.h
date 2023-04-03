///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	千年史策版本：0.9.0.5 (2023/04/03 09:33)

#ifndef MILLENNIUM_HISTORY_MILLENNIUM_HISTORY_CLASS_INVARIANT_MACRO_H
#define MILLENNIUM_HISTORY_MILLENNIUM_HISTORY_CLASS_INVARIANT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

#if !defined(MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL)

    #define MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL 8

#endif  // MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

#if !defined(MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL)

    #define MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL 8

#endif  // MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

static_assert(MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL <= USER_CLASS_INVARIANT_LEVEL, "Class invariant level definition error.");
static_assert(MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL <= USER_CLASS_INVARIANT_CONST_LEVEL, "Class invariant level definition error.");

#if 0 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_0 USER_CLASS_IS_VALID_0
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_0 USER_SELF_CLASS_IS_VALID_0

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL < 0

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_0 (static_cast<void>(0))
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif  // 0 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

#if 1 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_1 USER_CLASS_IS_VALID_1
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_1 USER_SELF_CLASS_IS_VALID_1

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL < 1

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_1 (static_cast<void>(0))
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif  // 1 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

#if 2 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_2 USER_CLASS_IS_VALID_2
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_2 USER_SELF_CLASS_IS_VALID_2

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL < 2

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_2 (static_cast<void>(0))
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif  // 2 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

#if 3 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_3 USER_CLASS_IS_VALID_3
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_3 USER_SELF_CLASS_IS_VALID_3

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL < 3

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_3 (static_cast<void>(0))
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif  // 3 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

#if 4 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_4 USER_CLASS_IS_VALID_4
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_4 USER_SELF_CLASS_IS_VALID_4

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL < 4

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_4 (static_cast<void>(0))
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif  // 4 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

#if 5 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_5 USER_CLASS_IS_VALID_5
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_5 USER_SELF_CLASS_IS_VALID_5

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL < 5

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_5 (static_cast<void>(0))
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif  // 5 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

#if 6 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_6 USER_CLASS_IS_VALID_6
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_6 USER_SELF_CLASS_IS_VALID_6

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL < 6

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_6 (static_cast<void>(0))
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif  // 6 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

#if 7 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_7 USER_CLASS_IS_VALID_7
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_7 USER_SELF_CLASS_IS_VALID_7

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL < 7

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_7 (static_cast<void>(0))
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif  // 7 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

#if 8 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_8 USER_CLASS_IS_VALID_8
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_8 USER_SELF_CLASS_IS_VALID_8

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL < 8

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_8 (static_cast<void>(0))
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif  // 8 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

#if 9 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_9 USER_CLASS_IS_VALID_9
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_9 USER_SELF_CLASS_IS_VALID_9

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL < 9

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_9 (static_cast<void>(0))
    #define MILLENNIUM_HISTORY_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif  // 9 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_LEVEL

#if 0 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_0 USER_CLASS_IS_VALID_CONST_0

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL < 0

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))

#endif  // 0 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_1 USER_CLASS_IS_VALID_CONST_1

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL < 1

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))

#endif  // 1 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_2 USER_CLASS_IS_VALID_CONST_2

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL < 2

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))

#endif  // 2 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_3 USER_CLASS_IS_VALID_CONST_3

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL < 3

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))

#endif  // 3 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_4 USER_CLASS_IS_VALID_CONST_4

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL < 4

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))

#endif  // 4 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_5 USER_CLASS_IS_VALID_CONST_5

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL < 5

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))

#endif  // 5 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_6 USER_CLASS_IS_VALID_CONST_6

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL < 6

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))

#endif  // 6 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_7 USER_CLASS_IS_VALID_CONST_7

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL < 7

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))

#endif  // 7 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_8 USER_CLASS_IS_VALID_CONST_8

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL < 8


    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))

#endif  // 8 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_9 USER_CLASS_IS_VALID_CONST_9

#else  // MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL < 9

    #define MILLENNIUM_HISTORY_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))

#endif  // 9 <= MILLENNIUM_HISTORY_CLASS_INVARIANT_CONST_LEVEL

#endif  // MILLENNIUM_HISTORY_MILLENNIUM_HISTORY_CLASS_INVARIANT_MACRO_H
