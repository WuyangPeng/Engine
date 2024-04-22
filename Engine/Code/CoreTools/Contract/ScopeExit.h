/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 15:54)

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

        ScopeExit(const ScopeExit&) = delete;
        ScopeExit& operator=(const ScopeExit&) = delete;
        ScopeExit(ScopeExit&&) noexcept = delete;
        ScopeExit& operator=(ScopeExit&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        T function;
    };
}

#endif  // CORE_TOOLS_CONTRACT_SCOPE_EXIT_H
