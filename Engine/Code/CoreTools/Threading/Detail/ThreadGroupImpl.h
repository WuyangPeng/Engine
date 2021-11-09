///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/02 11:14)

#ifndef CORE_TOOLS_THREADING_THREAD_GROUP_IMPL_H
#define CORE_TOOLS_THREADING_THREAD_GROUP_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <thread>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ThreadGroupImpl final
    {
    public:
        using ClassType = ThreadGroupImpl;

    public:
        ThreadGroupImpl() noexcept;
        ~ThreadGroupImpl() noexcept;
        ThreadGroupImpl(const ThreadGroupImpl& rhs) noexcept = delete;
        ThreadGroupImpl& operator=(const ThreadGroupImpl& rhs) noexcept = delete;
        ThreadGroupImpl(ThreadGroupImpl&& rhs) noexcept = delete;
        ThreadGroupImpl& operator=(ThreadGroupImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void AddThread(std::thread thread);

    private:
        using ThreadContainer = std::vector<std::thread>;

    private:
        void Join() noexcept;

    private:
        ThreadContainer threads;
    };
}

#endif  // CORE_TOOLS_THREADING_THREAD_GROUP_IMPL_H
