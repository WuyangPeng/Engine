// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 15:47)

#ifndef NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_THREAD_H
#define NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_THREAD_H

#include "Network/NetworkDll.h"

#include "ExecutorWorkGuardContext.h"

#include <boost/noncopyable.hpp>
#include <thread>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ExecutorWorkGuardContextThread : private boost::noncopyable
    {
    public:
        using ClassType = ExecutorWorkGuardContextThread;

    public:
        ExecutorWorkGuardContextThread();
        ~ExecutorWorkGuardContextThread();
        ExecutorWorkGuardContextThread(const ExecutorWorkGuardContextThread&) = default;
        ExecutorWorkGuardContextThread& operator=(const ExecutorWorkGuardContextThread&) = default;
        ExecutorWorkGuardContextThread(ExecutorWorkGuardContextThread&&) noexcept = default;
        ExecutorWorkGuardContextThread& operator=(ExecutorWorkGuardContextThread&&) noexcept = default;

        CLASS_INVARIANT_DECLARE;

    public:
        IOContextType& GetIOContext() noexcept;
        void StopContext();
        bool IsContextStop() const;
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
