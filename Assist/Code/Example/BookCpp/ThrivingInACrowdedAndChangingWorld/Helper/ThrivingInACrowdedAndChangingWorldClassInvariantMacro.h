///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/11/30 21:54)

#ifndef THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_HELPER_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_MACRO_H
#define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_HELPER_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

#if !defined(THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL)
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL 8
#endif  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

#if !defined(THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL)
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL 8
#endif  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL

static_assert(THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL <= USER_CLASS_INVARIANT_LEVEL, "Class invariant level definition error.");
static_assert(THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL <= USER_CLASS_INVARIANT_CONST_LEVEL, "Class invariant level definition error.");

#if 0 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_0 USER_CLASS_IS_VALID_0
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_0 USER_SELF_CLASS_IS_VALID_0

#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL < 0

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_0 (static_cast<void>(0))
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif  // 0 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

#if 1 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_1 USER_CLASS_IS_VALID_1
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_1 USER_SELF_CLASS_IS_VALID_1

#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL < 1

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_1 (static_cast<void>(0))
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif  // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_2 USER_CLASS_IS_VALID_2
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_2 USER_SELF_CLASS_IS_VALID_2

#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL < 2

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_2 (static_cast<void>(0))
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif  // 2 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

#if 3 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_3 USER_CLASS_IS_VALID_3
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_3 USER_SELF_CLASS_IS_VALID_3

#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL < 3

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_3 (static_cast<void>(0))
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif  // 3 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

#if 4 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_4 USER_CLASS_IS_VALID_4
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_4 USER_SELF_CLASS_IS_VALID_4

#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL < 4

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_4 (static_cast<void>(0))
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif  // 4 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

#if 5 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_5 USER_CLASS_IS_VALID_5
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_5 USER_SELF_CLASS_IS_VALID_5

#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL < 5

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_5 (static_cast<void>(0))
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif  // 5 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

#if 6 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_6 USER_CLASS_IS_VALID_6
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_6 USER_SELF_CLASS_IS_VALID_6

#else  // CLASS_INVARIANT_LEVEL < 6

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_6 (static_cast<void>(0))
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif  // 6 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

#if 7 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_7 USER_CLASS_IS_VALID_7
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_7 USER_SELF_CLASS_IS_VALID_7

#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL < 7

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_7 (static_cast<void>(0))
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif  // 7 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

#if 8 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_8 USER_CLASS_IS_VALID_8
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_8 USER_SELF_CLASS_IS_VALID_8

#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL < 8

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_8 (static_cast<void>(0))
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif  // 8 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

#if 9 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_9 USER_CLASS_IS_VALID_9
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_9 USER_SELF_CLASS_IS_VALID_9

#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL < 9

    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_9 (static_cast<void>(0))
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif  // 9 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_LEVEL

#if 0 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_0 USER_CLASS_IS_VALID_CONST_0
#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL < 0
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))
#endif  // 0 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_1 USER_CLASS_IS_VALID_CONST_1
#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL < 1
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))
#endif  // 1 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_2 USER_CLASS_IS_VALID_CONST_2
#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL < 2
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))
#endif  // 2 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_3 USER_CLASS_IS_VALID_CONST_3
#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL < 3
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))
#endif  // 3 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_4 USER_CLASS_IS_VALID_CONST_4
#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL < 4
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))
#endif  // 4 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_5 USER_CLASS_IS_VALID_CONST_5
#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL < 5
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))
#endif  // 5 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_6 USER_CLASS_IS_VALID_CONST_6
#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL < 6
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))
#endif  // 6 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_7 USER_CLASS_IS_VALID_CONST_7
#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL < 7
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))
#endif  // 7 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_8 USER_CLASS_IS_VALID_CONST_8
#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL < 8
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))
#endif  // 8 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_9 USER_CLASS_IS_VALID_CONST_9
#else  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL < 9
    #define THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))
#endif  // 9 <= THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_CONST_LEVEL

#endif  // THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_HELPER_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_CLASS_INVARIANT_MACRO_H
