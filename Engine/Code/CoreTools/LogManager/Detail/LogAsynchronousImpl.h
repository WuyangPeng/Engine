///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/06 21:37)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_ASYNCHRONOUS_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_ASYNCHRONOUS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/LogManager/Detail/LogAsynchronousParameter.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <deque>
#include <mutex>
#include <thread>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE LogAsynchronousImpl
    {
    public:
        using ClassType = LogAsynchronousImpl;
        using String = System::String;
        using AppenderManagerSharedPtr = std::shared_ptr<AppenderManager>;

    public:
        LogAsynchronousImpl() noexcept;
        ~LogAsynchronousImpl() noexcept = default;
        LogAsynchronousImpl(const LogAsynchronousImpl& rhs) = delete;
        LogAsynchronousImpl& operator=(const LogAsynchronousImpl& rhs) = delete;
        LogAsynchronousImpl(LogAsynchronousImpl&& rhs) noexcept = delete;
        LogAsynchronousImpl& operator=(LogAsynchronousImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void Registered(const LogMessage& message, const AppenderManagerSharedPtr& appenderManager);
        void Registered(const String& fileName, const LogMessage& message, const AppenderManagerSharedPtr& appenderManager);

        void SetThread();
        void Stop();
        void Join();

    private:
        using LogContainer = std::deque<LogAsynchronousParameter>;

    private:
        NODISCARD LogAsynchronousParameter ExtractNextLog() noexcept;

        void WaitThread();
        void Execution();

    private:
        LogContainer logContainer;
        std::thread thread;
        std::mutex mutex;
        std::condition_variable conditionVariable;
        volatile bool isStop;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_ASYNCHRONOUS_IMPL_H
