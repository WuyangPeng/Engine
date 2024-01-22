/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:23)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_H

#include "CoreTools/CoreToolsDll.h"

#include "SimpleDecrementer.h"
#include "SimpleIncrementer.h"

namespace CoreTools
{
    template <typename T, typename Acquire = SimpleIncrementer<T>, typename Release = SimpleDecrementer<T>>
    class IncrementScope final
    {
    public:
        using ValueType = T;
        using AcquireType = Acquire;
        using ReleaseType = Release;
        using ClassType = IncrementScope<T, Acquire, Release>;

        using Reference = ValueType&;

    public:
        explicit IncrementScope(Reference value) noexcept;
        ~IncrementScope();

        IncrementScope(const IncrementScope&) = delete;
        IncrementScope& operator=(const IncrementScope&) = delete;
        IncrementScope(IncrementScope&&) noexcept = delete;
        IncrementScope& operator=(IncrementScope&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        Reference value;
    };
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_H
