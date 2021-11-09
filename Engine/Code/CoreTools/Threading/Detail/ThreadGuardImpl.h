///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/01 18:01)

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
