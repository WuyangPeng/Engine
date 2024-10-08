/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.1 (2024/09/19 20:11)

#ifndef FRAMEWORK_SMTP_SMTP_TRANSPORT_ASYNCHRONOUS_H
#define FRAMEWORK_SMTP_SMTP_TRANSPORT_ASYNCHRONOUS_H

#include "Framework/FrameworkDll.h"

#include "SmtpTransportParameter.h"
#include "Framework/Smtp/SmtpTransport.h"

#include <condition_variable>
#include <deque>
#include <mutex>
#include <thread>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE SmtpTransportAsynchronous
    {
    public:
        using ClassType = SmtpTransportAsynchronous;

    public:
        explicit SmtpTransportAsynchronous(const EnvironmentDirectory& environmentDirectory);
        ~SmtpTransportAsynchronous() noexcept;
        SmtpTransportAsynchronous(const SmtpTransportAsynchronous& rhs) = delete;
        SmtpTransportAsynchronous& operator=(const SmtpTransportAsynchronous& rhs) = delete;
        SmtpTransportAsynchronous(SmtpTransportAsynchronous&& rhs) noexcept = delete;
        SmtpTransportAsynchronous& operator=(SmtpTransportAsynchronous&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void Registered(const std::string& title, const std::string& content);

    private:
        using SmtpTransportParameterSharedPtr = std::shared_ptr<SmtpTransportParameter>;
        using SmtpTransportContainer = std::deque<SmtpTransportParameterSharedPtr>;

    private:
        NODISCARD SmtpTransportParameterSharedPtr ExtractNextSmtpTransport() noexcept;

        void WaitThread();
        void Stop();
        void Join();

    private:
        SmtpTransport smtpTransport;
        SmtpTransportContainer smtpTransportContainer;
        std::thread thread;
        std::mutex mutex;
        std::condition_variable conditionVariable;
        volatile bool isStop;
    };
}

#endif  // FRAMEWORK_SMTP_SMTP_TRANSPORT_ASYNCHRONOUS_H
