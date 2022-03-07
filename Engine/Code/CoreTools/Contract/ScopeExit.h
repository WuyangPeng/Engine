///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/10 18:32)

#ifndef CORE_TOOLS_CONTRACT_SCOPE_EXIT_H
#define CORE_TOOLS_CONTRACT_SCOPE_EXIT_H

#include "CoreTools/CoreToolsDll.h"

#include <functional>

namespace CoreTools
{
    template <typename T = std::function<void()>>
    class ScopeExit final
    {
    public:
        using ClassType = ScopeExit;

    public:
        explicit ScopeExit(T function) noexcept(noexcept(T()));
        ~ScopeExit() noexcept;

        CLASS_INVARIANT_DECLARE;

        ScopeExit(const ScopeExit&) = delete;
        ScopeExit& operator=(const ScopeExit&) = delete;
        ScopeExit(ScopeExit&&) noexcept = delete;
        ScopeExit& operator=(ScopeExit&&) noexcept = delete;

    private:
        T function;
    };
}

#endif  // CORE_TOOLS_CONTRACT_SCOPE_EXIT_H
