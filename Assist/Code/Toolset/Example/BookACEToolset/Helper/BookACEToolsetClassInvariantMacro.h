///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.4 (2021/06/12 0:08)

#ifndef BOOK_ACE_TOOLSET_HELPER_BOOK_ACE_TOOLSET_CLASS_INVARIANT_MACRO_H
#define BOOK_ACE_TOOLSET_HELPER_BOOK_ACE_TOOLSET_CLASS_INVARIANT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

#if !defined(BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL)
    #define BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL 8
#endif  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

#if !defined(BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL)
    #define BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL 8
#endif  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL

static_assert(BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL <= USER_CLASS_INVARIANT_LEVEL, "Class invariant level definition error.");
static_assert(BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL <= USER_CLASS_INVARIANT_CONST_LEVEL, "Class invariant level definition error.");

#if 0 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_0 USER_CLASS_IS_VALID_0
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_0 USER_SELF_CLASS_IS_VALID_0

#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL < 0

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_0 (static_cast<void>(0))
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif  // 0 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

#if 1 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_1 USER_CLASS_IS_VALID_1
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_1 USER_SELF_CLASS_IS_VALID_1

#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL < 1

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_1 (static_cast<void>(0))
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif  // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_2 USER_CLASS_IS_VALID_2
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_2 USER_SELF_CLASS_IS_VALID_2

#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL < 2

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_2 (static_cast<void>(0))
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif  // 2 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

#if 3 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_3 USER_CLASS_IS_VALID_3
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_3 USER_SELF_CLASS_IS_VALID_3

#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL < 3

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_3 (static_cast<void>(0))
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif  // 3 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

#if 4 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_4 USER_CLASS_IS_VALID_4
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_4 USER_SELF_CLASS_IS_VALID_4

#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL < 4

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_4 (static_cast<void>(0))
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif  // 4 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

#if 5 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_5 USER_CLASS_IS_VALID_5
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_5 USER_SELF_CLASS_IS_VALID_5

#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL < 5

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_5 (static_cast<void>(0))
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif  // 5 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

#if 6 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_6 USER_CLASS_IS_VALID_6
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_6 USER_SELF_CLASS_IS_VALID_6

#else  // CLASS_INVARIANT_LEVEL < 6

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_6 (static_cast<void>(0))
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif  // 6 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

#if 7 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_7 USER_CLASS_IS_VALID_7
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_7 USER_SELF_CLASS_IS_VALID_7

#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL < 7

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_7 (static_cast<void>(0))
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif  // 7 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

#if 8 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_8 USER_CLASS_IS_VALID_8
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_8 USER_SELF_CLASS_IS_VALID_8

#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL < 8

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_8 (static_cast<void>(0))
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif  // 8 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

#if 9 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_9 USER_CLASS_IS_VALID_9
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_9 USER_SELF_CLASS_IS_VALID_9

#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL < 9

    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_9 (static_cast<void>(0))
    #define BOOK_ACE_TOOLSET_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif  // 9 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_LEVEL

#if 0 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_0 USER_CLASS_IS_VALID_CONST_0
#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL < 0
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))
#endif  // 0 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_1 USER_CLASS_IS_VALID_CONST_1
#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL < 1
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))
#endif  // 1 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_2 USER_CLASS_IS_VALID_CONST_2
#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL < 2
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))
#endif  // 2 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_3 USER_CLASS_IS_VALID_CONST_3
#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL < 3
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))
#endif  // 3 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_4 USER_CLASS_IS_VALID_CONST_4
#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL < 4
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))
#endif  // 4 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_5 USER_CLASS_IS_VALID_CONST_5
#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL < 5
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))
#endif  // 5 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_6 USER_CLASS_IS_VALID_CONST_6
#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL < 6
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))
#endif  // 6 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_7 USER_CLASS_IS_VALID_CONST_7
#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL < 7
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))
#endif  // 7 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_8 USER_CLASS_IS_VALID_CONST_8
#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL < 8
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))
#endif  // 8 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_9 USER_CLASS_IS_VALID_CONST_9
#else  // BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL < 9
    #define BOOK_ACE_TOOLSET_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))
#endif  // 9 <= BOOK_ACE_TOOLSET_CLASS_INVARIANT_CONST_LEVEL

#endif  // BOOK_ACE_TOOLSET_HELPER_BOOK_ACE_TOOLSET_CLASS_INVARIANT_MACRO_H
