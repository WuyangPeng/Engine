///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/23 09:41)

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
