/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 11:10)

#ifndef CORE_TOOLS_THREADING_THREAD_GUARD_IMPL_H
#define CORE_TOOLS_THREADING_THREAD_GUARD_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <thread>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ThreadGuardImpl final
    {
    public:
        using ClassType = ThreadGuardImpl;

    public:
        explicit ThreadGuardImpl(std::thread thread) noexcept;
        ~ThreadGuardImpl() noexcept;
        ThreadGuardImpl(const ThreadGuardImpl& rhs) noexcept = delete;
        ThreadGuardImpl& operator=(const ThreadGuardImpl& rhs) noexcept = delete;
        ThreadGuardImpl(ThreadGuardImpl&& rhs) noexcept = delete;
        ThreadGuardImpl& operator=(ThreadGuardImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        void Join() noexcept;

    private:
        std::thread thread;
    };
}

#endif  // CORE_TOOLS_THREADING_THREAD_GUARD_IMPL_H
