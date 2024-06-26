/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:14)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_BASE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_BASE_H

#include "CoreTools/CoreToolsDll.h"

/// 约束：类D是类B的派生类或相同类型
namespace CoreTools
{
    template <typename Derive, typename Base>
    struct MustHaveBase
    {
        MustHaveBase() noexcept = default;
        MustHaveBase(const MustHaveBase& rhs) noexcept = default;
        MustHaveBase& operator=(const MustHaveBase& rhs) noexcept = default;
        MustHaveBase(MustHaveBase&& rhs) noexcept = default;
        MustHaveBase& operator=(MustHaveBase&& rhs) noexcept = default;

        ~MustHaveBase()
        {
            MAYBE_UNUSED void (*ptr)(Derive*, Base*) = Constraint;
        }

    private:
        static void Constraint(Derive* derivePtr, Base* basePtr) noexcept
        {
            basePtr = derivePtr;
        }
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_BASE_H
