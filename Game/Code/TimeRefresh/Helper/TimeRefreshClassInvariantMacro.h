///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/15 14:42)

#ifndef ACTIVITY_HELPER_CLASS_INVARIANT_HELPER_H
#define ACTIVITY_HELPER_CLASS_INVARIANT_HELPER_H

#include "UserMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#if !defined(ACTIVITY_CLASS_INVARIANT_LEVEL)
    #define ACTIVITY_CLASS_INVARIANT_LEVEL 8
#endif  // ACTIVITY_CLASS_INVARIANT_LEVEL

#if !defined(ACTIVITY_CLASS_INVARIANT_CONST_LEVEL)
    #define ACTIVITY_CLASS_INVARIANT_CONST_LEVEL 8
#endif  // ACTIVITY_CLASS_INVARIANT_CONST_LEVEL

static_assert(ACTIVITY_CLASS_INVARIANT_LEVEL <= CLASS_INVARIANT_LEVEL, "Class invariant level definition error.");
static_assert(ACTIVITY_CLASS_INVARIANT_CONST_LEVEL <= CLASS_INVARIANT_CONST_LEVEL, "Class invariant level definition error.");

#if 0 <= ACTIVITY_CLASS_INVARIANT_LEVEL

    #define ACTIVITY_CLASS_IS_VALID_0 CLASS_IS_VALID_0
    #define ACTIVITY_SELF_CLASS_IS_VALID_0 SELF_CLASS_IS_VALID_0

#else  // ACTIVITY_CLASS_INVARIANT_LEVEL < 0

    #define ACTIVITY_CLASS_IS_VALID_0 ((void)0)
    #define ACTIVITY_SELF_CLASS_IS_VALID_0 ((void)0)

#endif  // 0 <= ACTIVITY_CLASS_INVARIANT_LEVEL

#if 1 <= ACTIVITY_CLASS_INVARIANT_LEVEL

    #define ACTIVITY_CLASS_IS_VALID_1 CLASS_IS_VALID_1
    #define ACTIVITY_SELF_CLASS_IS_VALID_1 SELF_CLASS_IS_VALID_1

#else  // ACTIVITY_CLASS_INVARIANT_LEVEL < 1

    #define ACTIVITY_CLASS_IS_VALID_1 ((void)0)
    #define ACTIVITY_SELF_CLASS_IS_VALID_1 ((void)0)

#endif  // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= ACTIVITY_CLASS_INVARIANT_LEVEL

    #define ACTIVITY_CLASS_IS_VALID_2 CLASS_IS_VALID_2
    #define ACTIVITY_SELF_CLASS_IS_VALID_2 SELF_CLASS_IS_VALID_2

#else  // ACTIVITY_CLASS_INVARIANT_LEVEL < 2

    #define ACTIVITY_CLASS_IS_VALID_2 ((void)0)
    #define ACTIVITY_SELF_CLASS_IS_VALID_2 ((void)0)

#endif  // 2 <= ACTIVITY_CLASS_INVARIANT_LEVEL

#if 3 <= ACTIVITY_CLASS_INVARIANT_LEVEL

    #define ACTIVITY_CLASS_IS_VALID_3 CLASS_IS_VALID_3
    #define ACTIVITY_SELF_CLASS_IS_VALID_3 SELF_CLASS_IS_VALID_3

#else  // ACTIVITY_CLASS_INVARIANT_LEVEL < 3

    #define ACTIVITY_CLASS_IS_VALID_3 ((void)0)
    #define ACTIVITY_SELF_CLASS_IS_VALID_3 ((void)0)

#endif  // 3 <= ACTIVITY_CLASS_INVARIANT_LEVEL

#if 4 <= ACTIVITY_CLASS_INVARIANT_LEVEL

    #define ACTIVITY_CLASS_IS_VALID_4 CLASS_IS_VALID_4
    #define ACTIVITY_SELF_CLASS_IS_VALID_4 SELF_CLASS_IS_VALID_4

#else  // ACTIVITY_CLASS_INVARIANT_LEVEL < 4

    #define ACTIVITY_CLASS_IS_VALID_4 ((void)0)
    #define ACTIVITY_SELF_CLASS_IS_VALID_4 ((void)0)

#endif  // 4 <= ACTIVITY_CLASS_INVARIANT_LEVEL

#if 5 <= ACTIVITY_CLASS_INVARIANT_LEVEL

    #define ACTIVITY_CLASS_IS_VALID_5 CLASS_IS_VALID_5
    #define ACTIVITY_SELF_CLASS_IS_VALID_5 SELF_CLASS_IS_VALID_5

#else  // ACTIVITY_CLASS_INVARIANT_LEVEL < 5

    #define ACTIVITY_CLASS_IS_VALID_5 ((void)0)
    #define ACTIVITY_SELF_CLASS_IS_VALID_5 ((void)0)

#endif  // 5 <= ACTIVITY_CLASS_INVARIANT_LEVEL

#if 6 <= ACTIVITY_CLASS_INVARIANT_LEVEL

    #define ACTIVITY_CLASS_IS_VALID_6 CLASS_IS_VALID_6
    #define ACTIVITY_SELF_CLASS_IS_VALID_6 SELF_CLASS_IS_VALID_6

#else  // CLASS_INVARIANT_LEVEL < 6

    #define ACTIVITY_CLASS_IS_VALID_6 ((void)0)
    #define ACTIVITY_SELF_CLASS_IS_VALID_6 ((void)0)

#endif  // 6 <= ACTIVITY_CLASS_INVARIANT_LEVEL

#if 7 <= ACTIVITY_CLASS_INVARIANT_LEVEL

    #define ACTIVITY_CLASS_IS_VALID_7 CLASS_IS_VALID_7
    #define ACTIVITY_SELF_CLASS_IS_VALID_7 SELF_CLASS_IS_VALID_7

#else  // ACTIVITY_CLASS_INVARIANT_LEVEL < 7

    #define ACTIVITY_CLASS_IS_VALID_7 ((void)0)
    #define ACTIVITY_SELF_CLASS_IS_VALID_7 ((void)0)

#endif  // 7 <= ACTIVITY_CLASS_INVARIANT_LEVEL

#if 8 <= ACTIVITY_CLASS_INVARIANT_LEVEL

    #define ACTIVITY_CLASS_IS_VALID_8 CLASS_IS_VALID_8
    #define ACTIVITY_SELF_CLASS_IS_VALID_8 SELF_CLASS_IS_VALID_8

#else  // ACTIVITY_CLASS_INVARIANT_LEVEL < 8

    #define ACTIVITY_CLASS_IS_VALID_8 ((void)0)
    #define ACTIVITY_SELF_CLASS_IS_VALID_8 ((void)0)

#endif  // 8 <= ACTIVITY_CLASS_INVARIANT_LEVEL

#if 9 <= ACTIVITY_CLASS_INVARIANT_LEVEL

    #define ACTIVITY_CLASS_IS_VALID_9 CLASS_IS_VALID_9
    #define ACTIVITY_SELF_CLASS_IS_VALID_9 SELF_CLASS_IS_VALID_9

#else  // ACTIVITY_CLASS_INVARIANT_LEVEL < 9

    #define ACTIVITY_CLASS_IS_VALID_9 ((void)0)
    #define ACTIVITY_SELF_CLASS_IS_VALID_9 ((void)0)

#endif  // 9 <= ACTIVITY_CLASS_INVARIANT_LEVEL

#if 0 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL
    #define ACTIVITY_CLASS_IS_VALID_CONST_0 CLASS_IS_VALID_CONST_0
#else  // ACTIVITY_CLASS_INVARIANT_CONST_LEVEL < 0
    #define ACTIVITY_CLASS_IS_VALID_CONST_0 ((void)0)
#endif  // 0 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL
    #define ACTIVITY_CLASS_IS_VALID_CONST_1 CLASS_IS_VALID_CONST_1
#else  // ACTIVITY_CLASS_INVARIANT_CONST_LEVEL < 1
    #define ACTIVITY_CLASS_IS_VALID_CONST_1 ((void)0)
#endif  // 1 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL
    #define ACTIVITY_CLASS_IS_VALID_CONST_2 CLASS_IS_VALID_CONST_2
#else  // ACTIVITY_CLASS_INVARIANT_CONST_LEVEL < 2
    #define ACTIVITY_CLASS_IS_VALID_CONST_2 ((void)0)
#endif  // 2 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL
    #define ACTIVITY_CLASS_IS_VALID_CONST_3 CLASS_IS_VALID_CONST_3
#else  // ACTIVITY_CLASS_INVARIANT_CONST_LEVEL < 3
    #define ACTIVITY_CLASS_IS_VALID_CONST_3 ((void)0)
#endif  // 3 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL
    #define ACTIVITY_CLASS_IS_VALID_CONST_4 CLASS_IS_VALID_CONST_4
#else  // ACTIVITY_CLASS_INVARIANT_CONST_LEVEL < 4
    #define ACTIVITY_CLASS_IS_VALID_CONST_4 ((void)0)
#endif  // 4 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL
    #define ACTIVITY_CLASS_IS_VALID_CONST_5 CLASS_IS_VALID_CONST_5
#else  // ACTIVITY_CLASS_INVARIANT_CONST_LEVEL < 5
    #define ACTIVITY_CLASS_IS_VALID_CONST_5 ((void)0)
#endif  // 5 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL
    #define ACTIVITY_CLASS_IS_VALID_CONST_6 CLASS_IS_VALID_CONST_6
#else  // ACTIVITY_CLASS_INVARIANT_CONST_LEVEL < 6
    #define ACTIVITY_CLASS_IS_VALID_CONST_6 ((void)0)
#endif  // 6 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL
    #define ACTIVITY_CLASS_IS_VALID_CONST_7 CLASS_IS_VALID_CONST_7
#else  // ACTIVITY_CLASS_INVARIANT_CONST_LEVEL < 7
    #define ACTIVITY_CLASS_IS_VALID_CONST_7 ((void)0)
#endif  // 7 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL
    #define ACTIVITY_CLASS_IS_VALID_CONST_8 CLASS_IS_VALID_CONST_8
#else  // ACTIVITY_CLASS_INVARIANT_CONST_LEVEL < 8
    #define ACTIVITY_CLASS_IS_VALID_CONST_8 ((void)0)
#endif  // 8 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL
    #define ACTIVITY_CLASS_IS_VALID_CONST_9 CLASS_IS_VALID_CONST_9
#else  // ACTIVITY_CLASS_INVARIANT_CONST_LEVEL < 9
    #define ACTIVITY_CLASS_IS_VALID_CONST_9 ((void)0)
#endif  // 9 <= ACTIVITY_CLASS_INVARIANT_CONST_LEVEL

#endif  // ACTIVITY_HELPER_CLASS_INVARIANT_HELPER_H
