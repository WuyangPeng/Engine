/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:36)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_ASYNCHRONOUS_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_ASYNCHRONOUS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/LogManager/Detail/LogAsynchronousParameter.h"
#include "CoreTools/LogManager/LogManagerFwd.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

#include <condition_variable>
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
        void Registered(const OStreamShared& streamShared, const std::string& message, LogLevel logLevel);

        void SetThread();
        void Stop();
        void Join();

        void Wait();

    private:
        using LogAsynchronousParameterBaseSharedPtr = std::shared_ptr<AsynchronousParameterBase>;
        using LogContainer = std::deque<LogAsynchronousParameterBaseSharedPtr>;

    private:
        NODISCARD LogAsynchronousParameterBaseSharedPtr ExtractNextLog() noexcept;

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
