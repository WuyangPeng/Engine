///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.4 (2021/06/06 21:47)

#ifndef THE_ACE_PROGRAMMERS_GUIDE_HELPER_THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_MACRO_H
#define THE_ACE_PROGRAMMERS_GUIDE_HELPER_THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

#if !defined(THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL)
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL 8
#endif  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

#if !defined(THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL)
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL 8
#endif  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL

static_assert(THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL <= USER_CLASS_INVARIANT_LEVEL, "Class invariant level definition error.");
static_assert(THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL <= USER_CLASS_INVARIANT_CONST_LEVEL, "Class invariant level definition error.");

#if 0 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_0 USER_CLASS_IS_VALID_0
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_0 USER_SELF_CLASS_IS_VALID_0

#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL < 0

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_0 (static_cast<void>(0))
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif  // 0 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

#if 1 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_1 USER_CLASS_IS_VALID_1
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_1 USER_SELF_CLASS_IS_VALID_1

#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL < 1

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_1 (static_cast<void>(0))
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif  // 1 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

#if 2 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_2 USER_CLASS_IS_VALID_2
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_2 USER_SELF_CLASS_IS_VALID_2

#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL < 2

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_2 (static_cast<void>(0))
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif  // 2 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

#if 3 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_3 USER_CLASS_IS_VALID_3
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_3 USER_SELF_CLASS_IS_VALID_3

#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL < 3

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_3 (static_cast<void>(0))
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif  // 3 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

#if 4 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_4 USER_CLASS_IS_VALID_4
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_4 USER_SELF_CLASS_IS_VALID_4

#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL < 4

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_4 (static_cast<void>(0))
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif  // 4 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

#if 5 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_5 USER_CLASS_IS_VALID_5
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_5 USER_SELF_CLASS_IS_VALID_5

#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL < 5

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_5 (static_cast<void>(0))
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif  // 5 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

#if 6 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_6 USER_CLASS_IS_VALID_6
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_6 USER_SELF_CLASS_IS_VALID_6

#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL < 6

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_6 (static_cast<void>(0))
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif  // 6 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

#if 7 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_7 USER_CLASS_IS_VALID_7
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_7 USER_SELF_CLASS_IS_VALID_7

#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL < 7

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_7 (static_cast<void>(0))
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif  // 7 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

#if 8 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_8 USER_CLASS_IS_VALID_8
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_8 USER_SELF_CLASS_IS_VALID_8

#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL < 8

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_8 (static_cast<void>(0))
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif  // 8 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

#if 9 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_9 USER_CLASS_IS_VALID_9
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_9 USER_SELF_CLASS_IS_VALID_9

#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL < 9

    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_9 (static_cast<void>(0))
    #define THE_ACE_PROGRAMMERS_GUIDE_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif  // 9 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_LEVEL

#if 0 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_0 USER_CLASS_IS_VALID_CONST_0
#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL < 0
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))
#endif  // 0 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_1 USER_CLASS_IS_VALID_CONST_1
#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL < 1
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))
#endif  // 1 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_2 USER_CLASS_IS_VALID_CONST_2
#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL < 2
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))
#endif  // 2 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_3 USER_CLASS_IS_VALID_CONST_3
#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL < 3
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))
#endif  // 3 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_4 USER_CLASS_IS_VALID_CONST_4
#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL < 4
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))
#endif  // 4 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_5 USER_CLASS_IS_VALID_CONST_5
#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL < 5
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))
#endif  // 5 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_6 USER_CLASS_IS_VALID_CONST_6
#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL < 6
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))
#endif  // 6 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_7 USER_CLASS_IS_VALID_CONST_7
#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL < 7
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))
#endif  // 7 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_8 USER_CLASS_IS_VALID_CONST_8
#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL < 8
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))
#endif  // 8 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_9 USER_CLASS_IS_VALID_CONST_9
#else  // THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL < 9
    #define THE_ACE_PROGRAMMERS_GUIDE_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))
#endif  // 9 <= THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_CONST_LEVEL

#endif  // THE_ACE_PROGRAMMERS_GUIDE_HELPER_THE_ACE_PROGRAMMERS_GUIDE_CLASS_INVARIANT_MACRO_H
