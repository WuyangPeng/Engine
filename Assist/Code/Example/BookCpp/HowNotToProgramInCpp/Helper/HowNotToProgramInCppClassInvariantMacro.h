///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/23 16:06)

#ifndef HOW_NOT_TO_PROGRAM_IN_CPP_HELPER_HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_MACRO_H
#define HOW_NOT_TO_PROGRAM_IN_CPP_HELPER_HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

#if !defined(HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL)
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL 8
#endif  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

#if !defined(HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL)
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL 8
#endif  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

static_assert(HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL <= USER_CLASS_INVARIANT_LEVEL, "Class invariant level definition error.");
static_assert(HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL <= USER_CLASS_INVARIANT_CONST_LEVEL, "Class invariant level definition error.");

#if 0 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_0 USER_CLASS_IS_VALID_0
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_0 USER_SELF_CLASS_IS_VALID_0

#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL < 0

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_0 (static_cast<void>(0))
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif  // 0 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

#if 1 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_1 USER_CLASS_IS_VALID_1
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_1 USER_SELF_CLASS_IS_VALID_1

#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL < 1

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_1 (static_cast<void>(0))
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif  // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_2 USER_CLASS_IS_VALID_2
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_2 USER_SELF_CLASS_IS_VALID_2

#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL < 2

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_2 (static_cast<void>(0))
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif  // 2 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

#if 3 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_3 USER_CLASS_IS_VALID_3
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_3 USER_SELF_CLASS_IS_VALID_3

#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL < 3

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_3 (static_cast<void>(0))
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif  // 3 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

#if 4 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_4 USER_CLASS_IS_VALID_4
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_4 USER_SELF_CLASS_IS_VALID_4

#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL < 4

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_4 (static_cast<void>(0))
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif  // 4 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

#if 5 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_5 USER_CLASS_IS_VALID_5
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_5 USER_SELF_CLASS_IS_VALID_5

#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL < 5

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_5 (static_cast<void>(0))
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif  // 5 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

#if 6 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_6 USER_CLASS_IS_VALID_6
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_6 USER_SELF_CLASS_IS_VALID_6

#else  // CLASS_INVARIANT_LEVEL < 6

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_6 (static_cast<void>(0))
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif  // 6 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

#if 7 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_7 USER_CLASS_IS_VALID_7
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_7 USER_SELF_CLASS_IS_VALID_7

#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL < 7

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_7 (static_cast<void>(0))
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif  // 7 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

#if 8 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_8 USER_CLASS_IS_VALID_8
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_8 USER_SELF_CLASS_IS_VALID_8

#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL < 8

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_8 (static_cast<void>(0))
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif  // 8 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

#if 9 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_9 USER_CLASS_IS_VALID_9
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_9 USER_SELF_CLASS_IS_VALID_9

#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL < 9

    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_9 (static_cast<void>(0))
    #define HOW_NOT_TO_PROGRAM_IN_CPP_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif  // 9 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_LEVEL

#if 0 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_0 USER_CLASS_IS_VALID_CONST_0
#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 0
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))
#endif  // 0 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_1 USER_CLASS_IS_VALID_CONST_1
#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 1
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))
#endif  // 1 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_2 USER_CLASS_IS_VALID_CONST_2
#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 2
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))
#endif  // 2 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_3 USER_CLASS_IS_VALID_CONST_3
#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 3
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))
#endif  // 3 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_4 USER_CLASS_IS_VALID_CONST_4
#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 4
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))
#endif  // 4 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_5 USER_CLASS_IS_VALID_CONST_5
#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 5
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))
#endif  // 5 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_6 USER_CLASS_IS_VALID_CONST_6
#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 6
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))
#endif  // 6 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_7 USER_CLASS_IS_VALID_CONST_7
#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 7
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))
#endif  // 7 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_8 USER_CLASS_IS_VALID_CONST_8
#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 8
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))
#endif  // 8 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_9 USER_CLASS_IS_VALID_CONST_9
#else  // HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 9
    #define HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))
#endif  // 9 <= HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#endif  // HOW_NOT_TO_PROGRAM_IN_CPP_HELPER_HOW_NOT_TO_PROGRAM_IN_CPP_CLASS_INVARIANT_MACRO_H
