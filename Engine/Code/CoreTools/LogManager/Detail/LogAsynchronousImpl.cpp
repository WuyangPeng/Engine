///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/28 15:19)

#include "CoreTools/CoreToolsExport.h"

#include "LogAsynchronousImpl.h"
#include "OStreamAsynchronousParameter.h"
#include "System/SystemOutput/SystemOutput.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::LogAsynchronousImpl::LogAsynchronousImpl() noexcept
    : logContainer{}, thread{}, mutex{}, conditionVariable{}, isStop{ false }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogAsynchronousImpl)

void CoreTools::LogAsynchronousImpl::Registered(const LogMessage& message, const AppenderManagerSharedPtr& appenderManager)
{
    std::lock_guard lockGuard{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    logContainer.emplace_back(std::make_shared<LogAsynchronousParameter>(message, appenderManager));

    conditionVariable.notify_one();
}

void CoreTools::LogAsynchronousImpl::Registered(const String& fileName, const LogMessage& message, const AppenderManagerSharedPtr& appenderManager)
{
    std::lock_guard lockGuard{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    logContainer.emplace_back(std::make_shared<LogAsynchronousParameter>(fileName, message, appenderManager));

    conditionVariable.notify_one();
}

void CoreTools::LogAsynchronousImpl::Registered(const OStreamShared& streamShared, const std::string& message, LogLevel logLevel)
{
    std::lock_guard lockGuard{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    logContainer.emplace_back(std::make_shared<OStreamAsynchronousParameter>(streamShared, message, logLevel));

    conditionVariable.notify_one();
}

CoreTools::LogAsynchronousImpl::LogAsynchronousParameterBaseSharedPtr CoreTools::LogAsynchronousImpl::ExtractNextLog() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto logParameter = logContainer.front();

    logContainer.pop_front();

    return logParameter;
}

void CoreTools::LogAsynchronousImpl::SetThread()
{
    std::lock_guard lockGuard{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    isStop = false;

    thread = std::thread{ &ClassType::WaitThread, this };
}

void CoreTools::LogAsynchronousImpl::Stop()
{
    std::lock_guard lockGuard{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    isStop = true;

    conditionVariable.notify_one();
}

void CoreTools::LogAsynchronousImpl::Join()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (thread.joinable())
    {
        thread.join();
    }
}

void CoreTools::LogAsynchronousImpl::WaitThread()
{
    do
    {
        std::unique_lock uniqueLock{ mutex };
        conditionVariable.wait(uniqueLock, [this] {
            return isStop || !logContainer.empty();
        });

        Execution();

    } while (!isStop || !logContainer.empty());
}

void CoreTools::LogAsynchronousImpl::Execution()
{
    if (!logContainer.empty())
    {
        try
        {
            const auto logAsynchronousParameter = ExtractNextLog();

            logAsynchronousParameter->Write();
        }
        catch (...)
        {
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("��־д�����"));
        }
    }
}
