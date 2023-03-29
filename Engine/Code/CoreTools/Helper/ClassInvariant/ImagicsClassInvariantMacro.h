///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:45)

#ifndef CORE_TOOLS_HELPER_IMAGICS_CLASS_INVARIANT_MACRO_H
#define CORE_TOOLS_HELPER_IMAGICS_CLASS_INVARIANT_MACRO_H

#include "CoreTools/Helper/ClassInvariantMacro.h"

#if !defined(IMAGICS_CLASS_INVARIANT_LEVEL)

    #define IMAGICS_CLASS_INVARIANT_LEVEL 8

#endif  // IMAGICS_CLASS_INVARIANT_LEVEL

#if !defined(IMAGICS_CLASS_INVARIANT_CONST_LEVEL)

    #define IMAGICS_CLASS_INVARIANT_CONST_LEVEL 1

#endif  // IMAGICS_CLASS_INVARIANT_CONST_LEVEL

static_assert(IMAGICS_CLASS_INVARIANT_LEVEL <= CLASS_INVARIANT_LEVEL, "Imagics class invariant level definition error.");
static_assert(IMAGICS_CLASS_INVARIANT_CONST_LEVEL <= CLASS_INVARIANT_CONST_LEVEL, "Imagics class invariant level definition error.");

#if 0 <= IMAGICS_CLASS_INVARIANT_LEVEL

    #define IMAGICS_CLASS_IS_VALID_0 CLASS_IS_VALID_0
    #define IMAGICS_SELF_CLASS_IS_VALID_0 SELF_CLASS_IS_VALID_0

#else  // IMAGICS_CLASS_INVARIANT_LEVEL < 0

    #define IMAGICS_CLASS_IS_VALID_0 (static_cast<void>(0))
    #define IMAGICS_SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif  //0 <= IMAGICS_CLASS_INVARIANT_LEVEL

#if 1 <= IMAGICS_CLASS_INVARIANT_LEVEL

    #define IMAGICS_CLASS_IS_VALID_1 CLASS_IS_VALID_1
    #define IMAGICS_SELF_CLASS_IS_VALID_1 SELF_CLASS_IS_VALID_1

#else  // IMAGICS_CLASS_INVARIANT_LEVEL < 1

    #define IMAGICS_CLASS_IS_VALID_1 (static_cast<void>(0))
    #define IMAGICS_SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif  // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= IMAGICS_CLASS_INVARIANT_LEVEL

    #define IMAGICS_CLASS_IS_VALID_2 CLASS_IS_VALID_2
    #define IMAGICS_SELF_CLASS_IS_VALID_2 SELF_CLASS_IS_VALID_2

#else  // IMAGICS_CLASS_INVARIANT_LEVEL < 2

    #define IMAGICS_CLASS_IS_VALID_2 (static_cast<void>(0))
    #define IMAGICS_SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif  // 2 <= IMAGICS_CLASS_INVARIANT_LEVEL

#if 3 <= IMAGICS_CLASS_INVARIANT_LEVEL

    #define IMAGICS_CLASS_IS_VALID_3 CLASS_IS_VALID_3
    #define IMAGICS_SELF_CLASS_IS_VALID_3 SELF_CLASS_IS_VALID_3

#else  // IMAGICS_CLASS_INVARIANT_LEVEL < 3

    #define IMAGICS_CLASS_IS_VALID_3 (static_cast<void>(0))
    #define IMAGICS_SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif  // 3 <= IMAGICS_CLASS_INVARIANT_LEVEL

#if 4 <= IMAGICS_CLASS_INVARIANT_LEVEL

    #define IMAGICS_CLASS_IS_VALID_4 CLASS_IS_VALID_4
    #define IMAGICS_SELF_CLASS_IS_VALID_4 SELF_CLASS_IS_VALID_4

#else  // IMAGICS_CLASS_INVARIANT_LEVEL < 4

    #define IMAGICS_CLASS_IS_VALID_4 (static_cast<void>(0))
    #define IMAGICS_SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif  // 4 <= IMAGICS_CLASS_INVARIANT_LEVEL

#if 5 <= IMAGICS_CLASS_INVARIANT_LEVEL

    #define IMAGICS_CLASS_IS_VALID_5 CLASS_IS_VALID_5
    #define IMAGICS_SELF_CLASS_IS_VALID_5 SELF_CLASS_IS_VALID_5

#else  // IMAGICS_CLASS_INVARIANT_LEVEL < 5

    #define IMAGICS_CLASS_IS_VALID_5 (static_cast<void>(0))
    #define IMAGICS_SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif  // 5 <= IMAGICS_CLASS_INVARIANT_LEVEL

#if 6 <= IMAGICS_CLASS_INVARIANT_LEVEL

    #define IMAGICS_CLASS_IS_VALID_6 CLASS_IS_VALID_6
    #define IMAGICS_SELF_CLASS_IS_VALID_6 SELF_CLASS_IS_VALID_6

#else  // CLASS_INVARIANT_LEVEL < 6

    #define IMAGICS_CLASS_IS_VALID_6 (static_cast<void>(0))
    #define IMAGICS_SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif  // 6 <= IMAGICS_CLASS_INVARIANT_LEVEL

#if 7 <= IMAGICS_CLASS_INVARIANT_LEVEL

    #define IMAGICS_CLASS_IS_VALID_7 CLASS_IS_VALID_7
    #define IMAGICS_SELF_CLASS_IS_VALID_7 SELF_CLASS_IS_VALID_7

#else  // IMAGICS_CLASS_INVARIANT_LEVEL < 7

    #define IMAGICS_CLASS_IS_VALID_7 (static_cast<void>(0))
    #define IMAGICS_SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif  // 7 <= IMAGICS_CLASS_INVARIANT_LEVEL

#if 8 <= IMAGICS_CLASS_INVARIANT_LEVEL

    #define IMAGICS_CLASS_IS_VALID_8 CLASS_IS_VALID_8
    #define IMAGICS_SELF_CLASS_IS_VALID_8 SELF_CLASS_IS_VALID_8

#else  // IMAGICS_CLASS_INVARIANT_LEVEL < 8

    #define IMAGICS_CLASS_IS_VALID_8 (static_cast<void>(0))
    #define IMAGICS_SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif  // 8 <= IMAGICS_CLASS_INVARIANT_LEVEL

#if 9 <= IMAGICS_CLASS_INVARIANT_LEVEL

    #define IMAGICS_CLASS_IS_VALID_9 CLASS_IS_VALID_9
    #define IMAGICS_SELF_CLASS_IS_VALID_9 SELF_CLASS_IS_VALID_9

#else  // IMAGICS_CLASS_INVARIANT_LEVEL < 9

    #define IMAGICS_CLASS_IS_VALID_9 (static_cast<void>(0))
    #define IMAGICS_SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif  // 9 <= IMAGICS_CLASS_INVARIANT_LEVEL

#if 0 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

    #define IMAGICS_CLASS_IS_VALID_CONST_0 CLASS_IS_VALID_CONST_0

#else  // IMAGICS_CLASS_INVARIANT_CONST_LEVEL < 0

    #define IMAGICS_CLASS_IS_VALID_CONST_0 (static_cast<void>(0))

#endif  // 0 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

#if 1 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

    #define IMAGICS_CLASS_IS_VALID_CONST_1 CLASS_IS_VALID_CONST_1

#else  // IMAGICS_CLASS_INVARIANT_CONST_LEVEL < 1

    #define IMAGICS_CLASS_IS_VALID_CONST_1 (static_cast<void>(0))

#endif  // 1 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

#if 2 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

    #define IMAGICS_CLASS_IS_VALID_CONST_2 CLASS_IS_VALID_CONST_2

#else  // IMAGICS_CLASS_INVARIANT_CONST_LEVEL < 2

    #define IMAGICS_CLASS_IS_VALID_CONST_2 (static_cast<void>(0))

#endif  // 2 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

#if 3 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

    #define IMAGICS_CLASS_IS_VALID_CONST_3 CLASS_IS_VALID_CONST_3

#else  // IMAGICS_CLASS_INVARIANT_CONST_LEVEL < 3

    #define IMAGICS_CLASS_IS_VALID_CONST_3 (static_cast<void>(0))

#endif  // 3 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

#if 4 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

    #define IMAGICS_CLASS_IS_VALID_CONST_4 CLASS_IS_VALID_CONST_4

#else  // IMAGICS_CLASS_INVARIANT_CONST_LEVEL < 4

    #define IMAGICS_CLASS_IS_VALID_CONST_4 (static_cast<void>(0))

#endif  // 4 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

#if 5 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

    #define IMAGICS_CLASS_IS_VALID_CONST_5 CLASS_IS_VALID_CONST_5

#else  // IMAGICS_CLASS_INVARIANT_CONST_LEVEL < 5

    #define IMAGICS_CLASS_IS_VALID_CONST_5 (static_cast<void>(0))

#endif  // 5 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

#if 6 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

    #define IMAGICS_CLASS_IS_VALID_CONST_6 CLASS_IS_VALID_CONST_6

#else  // IMAGICS_CLASS_INVARIANT_CONST_LEVEL < 6

    #define IMAGICS_CLASS_IS_VALID_CONST_6 (static_cast<void>(0))

#endif  // 6 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

#if 7 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

    #define IMAGICS_CLASS_IS_VALID_CONST_7 CLASS_IS_VALID_CONST_7

#else  // IMAGICS_CLASS_INVARIANT_CONST_LEVEL < 7

    #define IMAGICS_CLASS_IS_VALID_CONST_7 (static_cast<void>(0))

#endif  // 7 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

#if 8 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

    #define IMAGICS_CLASS_IS_VALID_CONST_8 CLASS_IS_VALID_CONST_8

#else  // IMAGICS_CLASS_INVARIANT_CONST_LEVEL < 8

    #define IMAGICS_CLASS_IS_VALID_CONST_8 (static_cast<void>(0))

#endif  // 8 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

#if 9 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

    #define IMAGICS_CLASS_IS_VALID_CONST_9 CLASS_IS_VALID_CONST_9

#else  // IMAGICS_CLASS_INVARIANT_CONST_LEVEL < 9

    #define IMAGICS_CLASS_IS_VALID_CONST_9 (static_cast<void>(0))

#endif  // 9 <= IMAGICS_CLASS_INVARIANT_CONST_LEVEL

#endif  // CORE_TOOLS_HELPER_IMAGICS_CLASS_INVARIANT_MACRO_H
