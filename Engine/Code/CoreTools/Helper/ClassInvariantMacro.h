///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.2 (2023/02/06 14:30)

// 类不变式所需要的宏
#ifndef CORE_TOOLS_HELPER_CLASS_INVARIANT_MACRO_H
#define CORE_TOOLS_HELPER_CLASS_INVARIANT_MACRO_H

#include "FunctionDescribedMacro.h"

#ifdef OPEN_CLASS_INVARIANT

    #include "CoreTools/Contract/CheckInvariantDetail.h"

    #define CLASS_INVARIANT_STUB_DEFINE(namespaceName, className) \
        bool namespaceName::className::IsValid() const noexcept   \
        {                                                         \
            return true;                                          \
        }

    #define CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(namespaceName, className) \
        bool namespaceName::className::IsValid() const noexcept              \
        {                                                                    \
            return ParentType::IsValid();                                    \
        }

#else  // !OPEN_CLASS_INVARIANT

    #define CLASS_INVARIANT_STUB_DEFINE(namespaceName, className)
    #define CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(namespaceName, className)

#endif  // OPEN_CLASS_INVARIANT

// 用来启用或禁用各种类不变式子系统的宏。
// 目前类不变式系统只在Microsoft Visual Studio中实现。

#if defined(OPEN_CLASS_INVARIANT)

    #define CLASS_IS_VALID \
        CoreTools::CheckInvariant<ClassType>{ (*this), (CORE_TOOLS_FUNCTION_DESCRIBED) }
    #define CLASS_IS_VALID_CONST \
        CoreTools::CheckInvariant<ClassType>{ (*this), (CORE_TOOLS_FUNCTION_DESCRIBED), (CoreTools::CheckInvariantConditions::OnlyPostCondition) }
    #define SELF_CLASS_IS_VALID \
        CoreTools::CheckInvariant<ClassType>{ (*this), (CORE_TOOLS_FUNCTION_DESCRIBED), (CoreTools::CheckInvariantConditions::OnlyPreCondition) }

#else  // !OPEN_CLASS_INVARIANT

    #define CLASS_IS_VALID (static_cast<void>(0))
    #define SELF_CLASS_IS_VALID (static_cast<void>(0))
    #define CLASS_IS_VALID_CONST (static_cast<void>(0))

#endif  // OPEN_CLASS_INVARIANT

// 0：运行时间为常量，且非常重要的不变式。
// 1：运行时间为常量的普通不变式。
// 2：运行时间为log(n)的不变式。
// 3：运行时间为n的不变式。
// 4：运行时间为n log(n)的不变式。
// 5：运行时间为n平方的不变式。
// 6：运行时间超过n平方的不变式。
// 7：内部类不变式，运行时间为常量的不变式。
// 8：内部类不变式，运行时间超过常量的不变式。
// 9：存根类不变式。
#if !defined(CLASS_INVARIANT_LEVEL)

    #define CLASS_INVARIANT_LEVEL 9

#endif  // CLASS_INVARIANT_LEVEL

#if !defined(CLASS_INVARIANT_CONST_LEVEL)

    #define CLASS_INVARIANT_CONST_LEVEL 8

#endif  // CLASS_INVARIANT_CONST_LEVEL

#if 0 <= CLASS_INVARIANT_LEVEL

    #define CLASS_IS_VALID_0 CLASS_IS_VALID
    #define SELF_CLASS_IS_VALID_0 SELF_CLASS_IS_VALID

#else  // CLASS_INVARIANT_LEVEL < 0

    #define CLASS_IS_VALID_0 (static_cast<void>(0))
    #define SELF_CLASS_IS_VALID_0 (static_cast<void>(0))

#endif  //0 <= CLASS_INVARIANT_LEVEL

#if 1 <= CLASS_INVARIANT_LEVEL

    #define CLASS_IS_VALID_1 CLASS_IS_VALID
    #define SELF_CLASS_IS_VALID_1 SELF_CLASS_IS_VALID

#else  // CLASS_INVARIANT_LEVEL < 1

    #define CLASS_IS_VALID_1 (static_cast<void>(0))
    #define SELF_CLASS_IS_VALID_1 (static_cast<void>(0))

#endif  // 1 <= CLASS_INVARIANT_LEVEL

#if 2 <= CLASS_INVARIANT_LEVEL

    #define CLASS_IS_VALID_2 CLASS_IS_VALID
    #define SELF_CLASS_IS_VALID_2 SELF_CLASS_IS_VALID

#else  // CLASS_INVARIANT_LEVEL < 2

    #define CLASS_IS_VALID_2 (static_cast<void>(0))
    #define SELF_CLASS_IS_VALID_2 (static_cast<void>(0))

#endif  // 2 <= CLASS_INVARIANT_LEVEL

#if 3 <= CLASS_INVARIANT_LEVEL

    #define CLASS_IS_VALID_3 CLASS_IS_VALID
    #define SELF_CLASS_IS_VALID_3 SELF_CLASS_IS_VALID

#else  // CLASS_INVARIANT_LEVEL < 3

    #define CLASS_IS_VALID_3 (static_cast<void>(0))
    #define SELF_CLASS_IS_VALID_3 (static_cast<void>(0))

#endif  // 3 <= CLASS_INVARIANT_LEVEL

#if 4 <= CLASS_INVARIANT_LEVEL

    #define CLASS_IS_VALID_4 CLASS_IS_VALID
    #define SELF_CLASS_IS_VALID_4 SELF_CLASS_IS_VALID

#else  // CLASS_INVARIANT_LEVEL < 4

    #define CLASS_IS_VALID_4 (static_cast<void>(0))
    #define SELF_CLASS_IS_VALID_4 (static_cast<void>(0))

#endif  // 4 <= CLASS_INVARIANT_LEVEL

#if 5 <= CLASS_INVARIANT_LEVEL

    #define CLASS_IS_VALID_5 CLASS_IS_VALID
    #define SELF_CLASS_IS_VALID_5 SELF_CLASS_IS_VALID

#else  // CLASS_INVARIANT_LEVEL < 5

    #define CLASS_IS_VALID_5 (static_cast<void>(0))
    #define SELF_CLASS_IS_VALID_5 (static_cast<void>(0))

#endif  // 5 <= CLASS_INVARIANT_LEVEL

#if 6 <= CLASS_INVARIANT_LEVEL

    #define CLASS_IS_VALID_6 CLASS_IS_VALID
    #define SELF_CLASS_IS_VALID_6 SELF_CLASS_IS_VALID

#else  // CLASS_INVARIANT_LEVEL < 6

    #define CLASS_IS_VALID_6 (static_cast<void>(0))
    #define SELF_CLASS_IS_VALID_6 (static_cast<void>(0))

#endif  // 6 <= CLASS_INVARIANT_LEVEL

#if 7 <= CLASS_INVARIANT_LEVEL

    #define CLASS_IS_VALID_7 CLASS_IS_VALID
    #define SELF_CLASS_IS_VALID_7 SELF_CLASS_IS_VALID

#else  // CLASS_INVARIANT_LEVEL < 7

    #define CLASS_IS_VALID_7 (static_cast<void>(0))
    #define SELF_CLASS_IS_VALID_7 (static_cast<void>(0))

#endif  // 7 <= CLASS_INVARIANT_LEVEL

#if 8 <= CLASS_INVARIANT_LEVEL

    #define CLASS_IS_VALID_8 CLASS_IS_VALID
    #define SELF_CLASS_IS_VALID_8 SELF_CLASS_IS_VALID

#else  // CLASS_INVARIANT_LEVEL < 8

    #define CLASS_IS_VALID_8 (static_cast<void>(0))
    #define SELF_CLASS_IS_VALID_8 (static_cast<void>(0))

#endif  // 8 <= CLASS_INVARIANT_LEVEL

#if 9 <= CLASS_INVARIANT_LEVEL

    #define CLASS_IS_VALID_9 CLASS_IS_VALID
    #define SELF_CLASS_IS_VALID_9 SELF_CLASS_IS_VALID

#else  // CLASS_INVARIANT_LEVEL < 9

    #define CLASS_IS_VALID_9 (static_cast<void>(0))
    #define SELF_CLASS_IS_VALID_9 (static_cast<void>(0))

#endif  // 9 <= CLASS_INVARIANT_LEVEL

#if 0 <= CLASS_INVARIANT_CONST_LEVEL

    #define CLASS_IS_VALID_CONST_0 CLASS_IS_VALID_CONST

#else  // CLASS_INVARIANT_CONST_LEVEL < 0

    #define CLASS_IS_VALID_CONST_0 (static_cast<void>(0))

#endif  // 0 <= CLASS_INVARIANT_CONST_LEVEL

#if 1 <= CLASS_INVARIANT_CONST_LEVEL

    #define CLASS_IS_VALID_CONST_1 CLASS_IS_VALID_CONST

#else  // CLASS_INVARIANT_CONST_LEVEL < 1

    #define CLASS_IS_VALID_CONST_1 (static_cast<void>(0))

#endif  // 1 <= CLASS_INVARIANT_CONST_LEVEL

#if 2 <= CLASS_INVARIANT_CONST_LEVEL

    #define CLASS_IS_VALID_CONST_2 CLASS_IS_VALID_CONST

#else  // CLASS_INVARIANT_CONST_LEVEL < 2

    #define CLASS_IS_VALID_CONST_2 (static_cast<void>(0))

#endif  // 2 <= CLASS_INVARIANT_CONST_LEVEL

#if 3 <= CLASS_INVARIANT_CONST_LEVEL

    #define CLASS_IS_VALID_CONST_3 CLASS_IS_VALID_CONST

#else  // CLASS_INVARIANT_CONST_LEVEL < 3

    #define CLASS_IS_VALID_CONST_3 (static_cast<void>(0))

#endif  // 3 <= CLASS_INVARIANT_CONST_LEVEL

#if 4 <= CLASS_INVARIANT_CONST_LEVEL

    #define CLASS_IS_VALID_CONST_4 CLASS_IS_VALID_CONST

#else  // CLASS_INVARIANT_CONST_LEVEL < 4

    #define CLASS_IS_VALID_CONST_4 (static_cast<void>(0))

#endif  // 4 <= CLASS_INVARIANT_CONST_LEVEL

#if 5 <= CLASS_INVARIANT_CONST_LEVEL

    #define CLASS_IS_VALID_CONST_5 CLASS_IS_VALID_CONST

#else  // CLASS_INVARIANT_CONST_LEVEL < 5

    #define CLASS_IS_VALID_CONST_5 (static_cast<void>(0))

#endif  // 5 <= CLASS_INVARIANT_CONST_LEVEL

#if 6 <= CLASS_INVARIANT_CONST_LEVEL

    #define CLASS_IS_VALID_CONST_6 CLASS_IS_VALID_CONST

#else  // CLASS_INVARIANT_CONST_LEVEL < 6

    #define CLASS_IS_VALID_CONST_6 (static_cast<void>(0))

#endif  // 6 <= CLASS_INVARIANT_CONST_LEVEL

#if 7 <= CLASS_INVARIANT_CONST_LEVEL

    #define CLASS_IS_VALID_CONST_7 CLASS_IS_VALID_CONST

#else  // CLASS_INVARIANT_CONST_LEVEL < 7

    #define CLASS_IS_VALID_CONST_7 (static_cast<void>(0))

#endif  // 7 <= CLASS_INVARIANT_CONST_LEVEL

#if 8 <= CLASS_INVARIANT_CONST_LEVEL

    #define CLASS_IS_VALID_CONST_8 CLASS_IS_VALID_CONST

#else  // CLASS_INVARIANT_CONST_LEVEL < 8

    #define CLASS_IS_VALID_CONST_8 (static_cast<void>(0))

#endif  // 8 <= CLASS_INVARIANT_CONST_LEVEL

#if 9 <= CLASS_INVARIANT_CONST_LEVEL

    #define CLASS_IS_VALID_CONST_9 CLASS_IS_VALID_CONST

#else  // CLASS_INVARIANT_CONST_LEVEL < 9

    #define CLASS_IS_VALID_CONST_9 (static_cast<void>(0))

#endif  // 9 <= CLASS_INVARIANT_CONST_LEVEL

#endif  // CORE_TOOLS_HELPER_CLASS_INVARIANT_MACRO_H
