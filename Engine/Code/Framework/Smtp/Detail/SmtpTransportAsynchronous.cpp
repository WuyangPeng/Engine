/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.1 (2024/09/19 20:11)

#include "Framework/FrameworkExport.h"

#include "SmtpTransportAsynchronous.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Framework/Smtp/SmtpTransport.h"

Framework::SmtpTransportAsynchronous::SmtpTransportAsynchronous(const EnvironmentDirectory& environmentDirectory)
    : smtpTransport{ environmentDirectory },
      smtpTransportContainer{},
      thread{ &ClassType::WaitThread, this },
      mutex{},
      conditionVariable{},
      isStop{ false }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::SmtpTransportAsynchronous::~SmtpTransportAsynchronous() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        Stop();
        Join();
    }
    EXCEPTION_ALL_CATCH(Framework)
}

CLASS_INVARIANT_STUB_DEFINE(Framework, SmtpTransportAsynchronous)

void Framework::SmtpTransportAsynchronous::Registered(const std::string& title, const std::string& content)
{
    std::lock_guard lockGuard{ mutex };

    FRAMEWORK_CLASS_IS_VALID_9;

    smtpTransportContainer.emplace_back(std::make_shared<SmtpTransportParameter>(title, content));

    conditionVariable.notify_one();
}

void Framework::SmtpTransportAsynchronous::Stop()
{
    std::lock_guard lockGuard{ mutex };

    FRAMEWORK_CLASS_IS_VALID_9;

    isStop = true;

    conditionVariable.notify_one();
}

void Framework::SmtpTransportAsynchronous::Join()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (thread.joinable())
    {
        thread.join();
    }
}

void Framework::SmtpTransportAsynchronous::WaitThread()
{
    do
    {
        std::unique_lock uniqueLock{ mutex };
        conditionVariable.wait(uniqueLock, [this] {
            return isStop || !smtpTransportContainer.empty();
        });

        if (!smtpTransportContainer.empty())
        {
            const auto nextSmtpTransport = ExtractNextSmtpTransport();

            uniqueLock.unlock();

            smtpTransport.SendMailMessage(nextSmtpTransport->GetTitle(), nextSmtpTransport->GetTitle());
        }

    } while (!isStop || !smtpTransportContainer.empty());
}

Framework::SmtpTransportAsynchronous::SmtpTransportParameterSharedPtr Framework::SmtpTransportAsynchronous::ExtractNextSmtpTransport() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    auto parameter = smtpTransportContainer.front();

    smtpTransportContainer.pop_front();

    return parameter;
}
