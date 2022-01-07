///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 15:18)

// 约束：类D是类B的派生类或相同类型
#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_BASE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_BASE_H

#include "CoreTools/CoreToolsDll.h"

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
            MAYBE_UNUSED void (*ptr)(Derive*, Base*) = Constranints;
        }

    private:
        static void Constranints(Derive* derivePtr, Base* basePtr) noexcept
        {
            basePtr = derivePtr;
        }
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_BASE_H
