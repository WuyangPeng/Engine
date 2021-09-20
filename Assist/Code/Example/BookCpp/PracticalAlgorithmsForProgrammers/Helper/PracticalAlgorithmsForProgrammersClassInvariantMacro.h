///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:57)

#ifndef PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_HELPER_PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_MACRO_H
#define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_HELPER_PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

#if !defined(PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL)
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL 8
#endif  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

#if !defined(PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL)
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL 8
#endif  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL

static_assert(PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL <= USER_CLASS_INVARIANT_LEVEL, "Class invariant level definition error.");
static_assert(PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL <= USER_CLASS_INVARIANT_CONST_LEVEL, "Class invariant level definition error.");

#if 0 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_0 USER_CLASS_IS_VALID_0
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_0 USER_SELF_CLASS_IS_VALID_0

#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL < 0

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_0 (static_cast<void>(0))
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif  // 0 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

#if 1 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_1 USER_CLASS_IS_VALID_1
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_1 USER_SELF_CLASS_IS_VALID_1

#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL < 1

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_1 (static_cast<void>(0))
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif  // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_2 USER_CLASS_IS_VALID_2
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_2 USER_SELF_CLASS_IS_VALID_2

#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL < 2

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_2 (static_cast<void>(0))
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif  // 2 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

#if 3 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_3 USER_CLASS_IS_VALID_3
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_3 USER_SELF_CLASS_IS_VALID_3

#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL < 3

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_3 (static_cast<void>(0))
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif  // 3 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

#if 4 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_4 USER_CLASS_IS_VALID_4
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_4 USER_SELF_CLASS_IS_VALID_4

#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL < 4

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_4 (static_cast<void>(0))
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif  // 4 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

#if 5 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_5 USER_CLASS_IS_VALID_5
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_5 USER_SELF_CLASS_IS_VALID_5

#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL < 5

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_5 (static_cast<void>(0))
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif  // 5 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

#if 6 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_6 USER_CLASS_IS_VALID_6
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_6 USER_SELF_CLASS_IS_VALID_6

#else  // CLASS_INVARIANT_LEVEL < 6

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_6 (static_cast<void>(0))
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif  // 6 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

#if 7 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_7 USER_CLASS_IS_VALID_7
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_7 USER_SELF_CLASS_IS_VALID_7

#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL < 7

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_7 (static_cast<void>(0))
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif  // 7 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

#if 8 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_8 USER_CLASS_IS_VALID_8
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_8 USER_SELF_CLASS_IS_VALID_8

#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL < 8

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_8 (static_cast<void>(0))
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif  // 8 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

#if 9 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_9 USER_CLASS_IS_VALID_9
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_9 USER_SELF_CLASS_IS_VALID_9

#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL < 9

    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_9 (static_cast<void>(0))
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif  // 9 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_LEVEL

#if 0 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_0 USER_CLASS_IS_VALID_CONST_0
#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL < 0
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))
#endif  // 0 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_1 USER_CLASS_IS_VALID_CONST_1
#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL < 1
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))
#endif  // 1 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_2 USER_CLASS_IS_VALID_CONST_2
#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL < 2
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))
#endif  // 2 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_3 USER_CLASS_IS_VALID_CONST_3
#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL < 3
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))
#endif  // 3 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_4 USER_CLASS_IS_VALID_CONST_4
#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL < 4
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))
#endif  // 4 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_5 USER_CLASS_IS_VALID_CONST_5
#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL < 5
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))
#endif  // 5 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_6 USER_CLASS_IS_VALID_CONST_6
#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL < 6
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))
#endif  // 6 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_7 USER_CLASS_IS_VALID_CONST_7
#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL < 7
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))
#endif  // 7 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_8 USER_CLASS_IS_VALID_CONST_8
#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL < 8
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))
#endif  // 8 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_9 USER_CLASS_IS_VALID_CONST_9
#else  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL < 9
    #define PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))
#endif  // 9 <= PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_CONST_LEVEL

#endif  // PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_HELPER_PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_CLASS_INVARIANT_MACRO_H
