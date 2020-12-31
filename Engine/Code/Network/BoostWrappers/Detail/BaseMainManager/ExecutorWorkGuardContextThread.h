//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 16:27)

#ifndef NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_THREAD_H
#define NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_THREAD_H

#include "Network/NetworkDll.h"

#include "ExecutorWorkGuardContext.h"

#include <thread>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ExecutorWorkGuardContextThread
    {
    public:
        using ClassType = ExecutorWorkGuardContextThread;

    public:
        ExecutorWorkGuardContextThread();
        ~ExecutorWorkGuardContextThread() noexcept;
        ExecutorWorkGuardContextThread(const ExecutorWorkGuardContextThread&) = delete;
        ExecutorWorkGuardContextThread& operator=(const ExecutorWorkGuardContextThread&) = delete;
        ExecutorWorkGuardContextThread(ExecutorWorkGuardContextThread&&) noexcept = delete;
        ExecutorWorkGuardContextThread& operator=(ExecutorWorkGuardContextThread&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    public:
        [[nodiscard]] IOContextType& GetIOContext() noexcept;
        void StopContext();
        [[nodiscard]] bool IsContextStop() const;
        void RestartContext();

    private:
        using ThreadType = std::thread;
        using ThreadTypePtr = std::unique_ptr<ThreadType>;

    private:
        void InitThread();
        void JoinThreads();

    private:
        ExecutorWorkGuardContext m_ExecutorWorkGuardContext;
        ThreadTypePtr m_Thread;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_THREAD_H
