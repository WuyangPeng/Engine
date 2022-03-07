///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/22 19:20)

#ifndef NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_THREAD_H
#define NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_THREAD_H

#include "Network/NetworkDll.h"

#include "ExecutorWorkGuardContext.h"
#include "CoreTools/Contract/ContractFwd.h"

#include <thread>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ExecutorWorkGuardContextThread
    {
    public:
        using ClassType = ExecutorWorkGuardContextThread;

    public:
        explicit ExecutorWorkGuardContextThread(CoreTools::DisableNotThrow disableNotThrow);
        ~ExecutorWorkGuardContextThread() noexcept;
        ExecutorWorkGuardContextThread(const ExecutorWorkGuardContextThread&) = delete;
        ExecutorWorkGuardContextThread& operator=(const ExecutorWorkGuardContextThread&) = delete;
        ExecutorWorkGuardContextThread(ExecutorWorkGuardContextThread&&) noexcept = delete;
        ExecutorWorkGuardContextThread& operator=(ExecutorWorkGuardContextThread&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD IOContextType& GetIOContext() noexcept;
        void StopContext();
        NODISCARD bool IsContextStop() const;
        void RestartContext();

    private:
        using ThreadType = std::thread;
        using ThreadTypeUniquePtr = std::unique_ptr<ThreadType>;

    private:
        void InitThread();
        void JoinThreads();

    private:
        ExecutorWorkGuardContext executorWorkGuardContext;
        ThreadTypeUniquePtr thread;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_THREAD_H
