///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/21 10:04)

#ifndef CORE_TOOLS_CONTRACT_SCOPE_EXIT_H
#define CORE_TOOLS_CONTRACT_SCOPE_EXIT_H

#include "CoreTools/CoreToolsDll.h"

#include <functional>

namespace CoreTools
{
    template <typename T = std::function<void(void)>>
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
        T Function;
    };
}

#endif  // CORE_TOOLS_CONTRACT_SCOPE_EXIT_H
