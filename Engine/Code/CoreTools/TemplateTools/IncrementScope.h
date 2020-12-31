//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 15:20)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_H

#include "CoreTools/CoreToolsDll.h"

#include "SimpleDecrementer.h"
#include "SimpleIncrementer.h"

namespace CoreTools
{
    template <typename T, typename Aquire = SimpleIncrementer<T>, typename Release = SimpleDecrementer<T>>
    class IncrementScope final
    {
    public:
        using ValueType = T;
        using AquireType = Aquire;
        using ReleaseType = Release;
        using ClassType = IncrementScope<T, Aquire, Release>;
        using Reference = ValueType&;

    public:
        explicit IncrementScope(Reference value);
        ~IncrementScope();

        IncrementScope(const IncrementScope&) = delete;
        IncrementScope& operator=(const IncrementScope&) = delete;
        IncrementScope(IncrementScope&&) = delete;
        IncrementScope& operator=(IncrementScope&&) = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        Reference m_Vaule;
    };
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_H
