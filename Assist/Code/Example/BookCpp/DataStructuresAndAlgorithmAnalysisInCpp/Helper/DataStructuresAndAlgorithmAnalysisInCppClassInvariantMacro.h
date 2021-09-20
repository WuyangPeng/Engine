///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:57)

#ifndef DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_HELPER_DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_MACRO_H
#define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_HELPER_DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

#if !defined(DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL)
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL 8
#endif  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

#if !defined(DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL)
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL 8
#endif  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

static_assert(DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL <= USER_CLASS_INVARIANT_LEVEL, "Class invariant level definition error.");
static_assert(DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL <= USER_CLASS_INVARIANT_CONST_LEVEL, "Class invariant level definition error.");

#if 0 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_0 USER_CLASS_IS_VALID_0
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_0 USER_SELF_CLASS_IS_VALID_0

#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL < 0

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_0 (static_cast<void>(0))
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif  // 0 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

#if 1 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_1 USER_CLASS_IS_VALID_1
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_1 USER_SELF_CLASS_IS_VALID_1

#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL < 1

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_1 (static_cast<void>(0))
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif  // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_2 USER_CLASS_IS_VALID_2
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_2 USER_SELF_CLASS_IS_VALID_2

#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL < 2

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_2 (static_cast<void>(0))
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif  // 2 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

#if 3 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_3 USER_CLASS_IS_VALID_3
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_3 USER_SELF_CLASS_IS_VALID_3

#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL < 3

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_3 (static_cast<void>(0))
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif  // 3 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

#if 4 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_4 USER_CLASS_IS_VALID_4
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_4 USER_SELF_CLASS_IS_VALID_4

#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL < 4

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_4 (static_cast<void>(0))
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif  // 4 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

#if 5 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_5 USER_CLASS_IS_VALID_5
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_5 USER_SELF_CLASS_IS_VALID_5

#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL < 5

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_5 (static_cast<void>(0))
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif  // 5 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

#if 6 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_6 USER_CLASS_IS_VALID_6
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_6 USER_SELF_CLASS_IS_VALID_6

#else  // CLASS_INVARIANT_LEVEL < 6

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_6 (static_cast<void>(0))
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif  // 6 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

#if 7 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_7 USER_CLASS_IS_VALID_7
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_7 USER_SELF_CLASS_IS_VALID_7

#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL < 7

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_7 (static_cast<void>(0))
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif  // 7 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

#if 8 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_8 USER_CLASS_IS_VALID_8
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_8 USER_SELF_CLASS_IS_VALID_8

#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL < 8

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_8 (static_cast<void>(0))
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif  // 8 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

#if 9 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_9 USER_CLASS_IS_VALID_9
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_9 USER_SELF_CLASS_IS_VALID_9

#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL < 9

    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_9 (static_cast<void>(0))
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif  // 9 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_LEVEL

#if 0 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_0 USER_CLASS_IS_VALID_CONST_0
#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 0
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))
#endif  // 0 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_1 USER_CLASS_IS_VALID_CONST_1
#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 1
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))
#endif  // 1 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_2 USER_CLASS_IS_VALID_CONST_2
#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 2
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))
#endif  // 2 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_3 USER_CLASS_IS_VALID_CONST_3
#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 3
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))
#endif  // 3 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_4 USER_CLASS_IS_VALID_CONST_4
#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 4
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))
#endif  // 4 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_5 USER_CLASS_IS_VALID_CONST_5
#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 5
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))
#endif  // 5 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_6 USER_CLASS_IS_VALID_CONST_6
#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 6
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))
#endif  // 6 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_7 USER_CLASS_IS_VALID_CONST_7
#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 7
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))
#endif  // 7 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_8 USER_CLASS_IS_VALID_CONST_8
#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 8
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))
#endif  // 8 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_9 USER_CLASS_IS_VALID_CONST_9
#else  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL < 9
    #define DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))
#endif  // 9 <= DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_CONST_LEVEL

#endif  // DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_HELPER_DATA_STRUCTURES_AND_ALGORITHM_ANALYSIS_IN_CPP_CLASS_INVARIANT_MACRO_H
