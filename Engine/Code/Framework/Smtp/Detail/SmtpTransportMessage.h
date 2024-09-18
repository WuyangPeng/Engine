/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.1 (2024/09/14 15:23)

#ifndef FRAMEWORK_SMTP_SMTP_TRANSPORT_MESSAGE_H
#define FRAMEWORK_SMTP_SMTP_TRANSPORT_MESSAGE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/EngineConfiguration/SmtpConfig.h"
#include "Network/ServiceWrappers/SocketService.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE SmtpTransportMessage : public std::enable_shared_from_this<SmtpTransportMessage>
    {
    public:
        using ClassType = SmtpTransportMessage;

        using SmtpTransportMessageSharedPtr = std::shared_ptr<ClassType>;
        using SmtpConfig = CoreTools::SmtpConfig;

    private:
        enum class SmtpTransportMessageCreate
        {
            Init
        };

    public:
        NODISCARD static SmtpTransportMessageSharedPtr Create(const SmtpConfig& smtpConfig, const std::string& title, const std::string& content);
        SmtpTransportMessage(const SmtpConfig& smtpConfig, std::string title, std::string content, SmtpTransportMessageCreate smtpTransportMessageCreate);

        CLASS_INVARIANT_DECLARE;

        void SendMailMessage();

    private:
        using SocketService = Network::SocketService;
        using SplitType = std::vector<std::string>;

    private:
        NODISCARD std::string GetBase64Encoded() const;
        NODISCARD std::string GetFromMessage() const;
        NODISCARD static std::string GetRcptMessage(const std::string& receiveUser);
        NODISCARD std::string GetTextMessage(int index, const std::string& receiveUser) const;
        void AddMailMessage();
        void AddMailMessage(int index, const std::string& receiveUser);

        static void Analysis(const std::string& line);
        static void DoAnalysis(const std::string& line);
        void Response();

    private:
        SmtpConfig smtpConfig;
        SocketService socketService;
        std::string title;
        std::string content;
        SplitType message;
        int sendIndex;
    };
}

#endif  // FRAMEWORK_SMTP_SMTP_TRANSPORT_MESSAGE_H