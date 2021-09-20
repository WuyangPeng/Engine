///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/19 23:08)

#ifndef IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_HELPER_IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_MACRO_H
#define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_HELPER_IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"

#if !defined(IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL)
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL 8
#endif  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

#if !defined(IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL)
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL 8
#endif  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL

static_assert(IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL <= USER_CLASS_INVARIANT_LEVEL, "Class invariant level definition error.");
static_assert(IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL <= USER_CLASS_INVARIANT_CONST_LEVEL, "Class invariant level definition error.");

#if 0 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_0 USER_CLASS_IS_VALID_0
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_0 USER_SELF_CLASS_IS_VALID_0

#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL < 0

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_0 (static_cast<void>(0))
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif  // 0 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

#if 1 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_1 USER_CLASS_IS_VALID_1
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_1 USER_SELF_CLASS_IS_VALID_1

#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL < 1

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_1 (static_cast<void>(0))
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif  // 1 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

#if 2 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_2 USER_CLASS_IS_VALID_2
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_2 USER_SELF_CLASS_IS_VALID_2

#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL < 2

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_2 (static_cast<void>(0))
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif  // 2 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

#if 3 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_3 USER_CLASS_IS_VALID_3
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_3 USER_SELF_CLASS_IS_VALID_3

#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL < 3

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_3 (static_cast<void>(0))
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif  // 3 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

#if 4 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_4 USER_CLASS_IS_VALID_4
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_4 USER_SELF_CLASS_IS_VALID_4

#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL < 4

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_4 (static_cast<void>(0))
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif  // 4 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

#if 5 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_5 USER_CLASS_IS_VALID_5
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_5 USER_SELF_CLASS_IS_VALID_5

#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL < 5

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_5 (static_cast<void>(0))
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif  // 5 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

#if 6 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_6 USER_CLASS_IS_VALID_6
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_6 USER_SELF_CLASS_IS_VALID_6

#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL < 6

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_6 (static_cast<void>(0))
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif  // 6 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

#if 7 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_7 USER_CLASS_IS_VALID_7
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_7 USER_SELF_CLASS_IS_VALID_7

#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL < 7

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_7 (static_cast<void>(0))
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif  // 7 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

#if 8 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_8 USER_CLASS_IS_VALID_8
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_8 USER_SELF_CLASS_IS_VALID_8

#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL < 8

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_8 (static_cast<void>(0))
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif  // 8 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

#if 9 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_9 USER_CLASS_IS_VALID_9
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_9 USER_SELF_CLASS_IS_VALID_9

#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL < 9

    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_9 (static_cast<void>(0))
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif  // 9 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_LEVEL

#if 0 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_0 USER_CLASS_IS_VALID_CONST_0
#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL < 0
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))
#endif  // 0 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_1 USER_CLASS_IS_VALID_CONST_1
#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL < 1
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))
#endif  // 1 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_2 USER_CLASS_IS_VALID_CONST_2
#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL < 2
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))
#endif  // 2 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_3 USER_CLASS_IS_VALID_CONST_3
#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL < 3
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))
#endif  // 3 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_4 USER_CLASS_IS_VALID_CONST_4
#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL < 4
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))
#endif  // 4 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_5 USER_CLASS_IS_VALID_CONST_5
#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL < 5
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))
#endif  // 5 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_6 USER_CLASS_IS_VALID_CONST_6
#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL < 6
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))
#endif  // 6 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_7 USER_CLASS_IS_VALID_CONST_7
#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL < 7
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))
#endif  // 7 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_8 USER_CLASS_IS_VALID_CONST_8
#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL < 8
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))
#endif  // 8 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_9 USER_CLASS_IS_VALID_CONST_9
#else  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL < 9
    #define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))
#endif  // 9 <= IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_CONST_LEVEL

#endif  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_HELPER_IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_CLASS_INVARIANT_MACRO_H
