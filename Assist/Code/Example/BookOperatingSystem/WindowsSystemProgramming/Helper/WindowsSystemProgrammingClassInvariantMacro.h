///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/12 16:57)

#ifndef WINDOWS_SYSTEM_PROGRAMMING_HELPER_WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_MACRO_H
#define WINDOWS_SYSTEM_PROGRAMMING_HELPER_WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

#if !defined(WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL)
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL 8
#endif  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

#if !defined(WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL)
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL 8
#endif  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL

static_assert(WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL <= USER_CLASS_INVARIANT_LEVEL, "Class invariant level definition error.");
static_assert(WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL <= USER_CLASS_INVARIANT_CONST_LEVEL, "Class invariant level definition error.");

#if 0 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_0 USER_CLASS_IS_VALID_0
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_0 USER_SELF_CLASS_IS_VALID_0

#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL < 0

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_0 (static_cast<void>(0))
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif  // 0 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

#if 1 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_1 USER_CLASS_IS_VALID_1
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_1 USER_SELF_CLASS_IS_VALID_1

#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL < 1

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_1 (static_cast<void>(0))
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif  // 1 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

#if 2 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_2 USER_CLASS_IS_VALID_2
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_2 USER_SELF_CLASS_IS_VALID_2

#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL < 2

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_2 (static_cast<void>(0))
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif  // 2 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

#if 3 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_3 USER_CLASS_IS_VALID_3
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_3 USER_SELF_CLASS_IS_VALID_3

#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL < 3

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_3 (static_cast<void>(0))
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif  // 3 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

#if 4 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_4 USER_CLASS_IS_VALID_4
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_4 USER_SELF_CLASS_IS_VALID_4

#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL < 4

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_4 (static_cast<void>(0))
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif  // 4 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

#if 5 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_5 USER_CLASS_IS_VALID_5
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_5 USER_SELF_CLASS_IS_VALID_5

#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL < 5

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_5 (static_cast<void>(0))
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif  // 5 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

#if 6 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_6 USER_CLASS_IS_VALID_6
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_6 USER_SELF_CLASS_IS_VALID_6

#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL < 6

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_6 (static_cast<void>(0))
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif  // 6 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

#if 7 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_7 USER_CLASS_IS_VALID_7
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_7 USER_SELF_CLASS_IS_VALID_7

#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL < 7

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_7 (static_cast<void>(0))
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif  // 7 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

#if 8 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_8 USER_CLASS_IS_VALID_8
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_8 USER_SELF_CLASS_IS_VALID_8

#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL < 8

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_8 (static_cast<void>(0))
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif  // 8 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

#if 9 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_9 USER_CLASS_IS_VALID_9
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_9 USER_SELF_CLASS_IS_VALID_9

#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL < 9

    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_9 (static_cast<void>(0))
    #define WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif  // 9 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_LEVEL

#if 0 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_0 USER_CLASS_IS_VALID_CONST_0
#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL < 0
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))
#endif  // 0 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_1 USER_CLASS_IS_VALID_CONST_1
#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL < 1
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))
#endif  // 1 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_2 USER_CLASS_IS_VALID_CONST_2
#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL < 2
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))
#endif  // 2 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_3 USER_CLASS_IS_VALID_CONST_3
#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL < 3
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))
#endif  // 3 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_4 USER_CLASS_IS_VALID_CONST_4
#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL < 4
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))
#endif  // 4 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_5 USER_CLASS_IS_VALID_CONST_5
#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL < 5
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))
#endif  // 5 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_6 USER_CLASS_IS_VALID_CONST_6
#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL < 6
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))
#endif  // 6 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_7 USER_CLASS_IS_VALID_CONST_7
#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL < 7
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))
#endif  // 7 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_8 USER_CLASS_IS_VALID_CONST_8
#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL < 8
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))
#endif  // 8 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_9 USER_CLASS_IS_VALID_CONST_9
#else  // WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL < 9
    #define WINDOWS_SYSTEM_PROGRAMMING_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))
#endif  // 9 <= WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_CONST_LEVEL

#endif  // WINDOWS_SYSTEM_PROGRAMMING_HELPER_WINDOWS_SYSTEM_PROGRAMMING_CLASS_INVARIANT_MACRO_H
