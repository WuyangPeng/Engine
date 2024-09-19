/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.1 (2024/09/14 15:23)

#include "Framework/FrameworkExport.h"

#include "SmtpTransportMessage.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/Base64.h"
#include "CoreTools/EngineConfiguration/SmtpConfig.h"
#include "CoreTools/Helper//LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <future>

using namespace std::literals;

namespace
{
    const auto lineBreak = "\r\n"s;
}

Framework::SmtpTransportMessage::SmtpTransportMessageSharedPtr Framework::SmtpTransportMessage::Create(const SmtpConfig& smtpConfig, const std::string& title, const std::string& content)
{
    return std::make_shared<ClassType>(smtpConfig, title, content, SmtpTransportMessageCreate::Init);
}

Framework::SmtpTransportMessage::SmtpTransportMessage(const SmtpConfig& smtpConfig, std::string title, std::string content, SmtpTransportMessageCreate smtpTransportMessageCreate)
    : smtpConfig{ smtpConfig },
      socketService{ Network::ConfigurationStrategy::CreateClient(smtpConfig.GetSmtpHost(), smtpConfig.GetSmtpPort()) },
      title{ std::move(title) },
      content{ std::move(content) },
      message{ "EHLO " + smtpConfig.GetEhlo() + lineBreak,
               GetBase64Encoded() },
      sendIndex{ 0 }
{
    System::UnusedFunction(smtpTransportMessageCreate);

    AddMailMessage();

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

void Framework::SmtpTransportMessage::AddMailMessage()
{
    auto index = 0;
    for (const auto& receiveUser : smtpConfig.GetReceiveUser())
    {
        AddMailMessage(index, receiveUser);

        ++index;
    }

    message.emplace_back("QUIT" + lineBreak);
}

void Framework::SmtpTransportMessage::AddMailMessage(int index, const std::string& receiveUser)
{
    message.emplace_back(GetFromMessage());
    message.emplace_back(GetRcptMessage(receiveUser));
    message.emplace_back(GetTextMessage(index, receiveUser));
}

CLASS_INVARIANT_STUB_DEFINE(Framework, SmtpTransportMessage)

void Framework::SmtpTransportMessage::SendMailMessage()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    Response();
}

std::string Framework::SmtpTransportMessage::GetBase64Encoded() const
{
    /// 发送AUTH命令使用PLAIN方法
    const auto authCommand = "AUTH PLAIN "s;
    const auto plainCredentials = '\0' + smtpConfig.GetSendUser() + '\0' + smtpConfig.GetPassword();

    const auto base64Encoded = CoreTools::Base64::Encode(plainCredentials);

    return authCommand + base64Encoded + lineBreak;
}

std::string Framework::SmtpTransportMessage::GetFromMessage() const
{
    return "MAIL FROM:<" + smtpConfig.GetSendUser() + ">" + lineBreak;
}

std::string Framework::SmtpTransportMessage::GetRcptMessage(const std::string& receiveUser)
{
    return "RCPT TO:<" + receiveUser + ">" + lineBreak;
}

std::string Framework::SmtpTransportMessage::GetTextMessage(int index, const std::string& receiveUser) const
{
    return "DATA" + lineBreak + "From: " + smtpConfig.GetSendUser() + lineBreak + "To: " + receiveUser + lineBreak + "Subject: " + title + std::to_string(index) + lineBreak + lineBreak + content + lineBreak + "." + lineBreak;
}

void Framework::SmtpTransportMessage::Response()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    std::promise<void> promise{};
    const auto future = promise.get_future();

    Response(promise);

    future.wait();
}

void Framework::SmtpTransportMessage::Response(std::promise<void>& promise)
{
    const auto self = shared_from_this();

    socketService.Response([self, &promise](const std::string& response) {
        SplitType splitContent{};
        split(splitContent, response, boost::is_any_of(lineBreak), boost::token_compress_on);

        for (const auto& line : splitContent)
        {
            if (!line.empty())
            {
                self->Analysis(line);
            }
        }

        if (boost::numeric_cast<int>(self->message.size()) <= self->sendIndex)
        {
            promise.set_value();
            return;
        }

        self->socketService.SendTextMessage(self->message.at(self->sendIndex++));
        self->Response(promise);
    });
}

void Framework::SmtpTransportMessage::Analysis(const std::string& line)
{
    LOG_SINGLETON_FILE_APPENDER(Info, Framework, SYSTEM_TEXT("Smtp"), line);

    /// 解析状态码
    if (3 <= line.size() && std::isdigit(line.at(0)) && std::isdigit(line.at(1)) && std::isdigit(line.at(2)))
    {
        DoAnalysis(line);
    }
}

void Framework::SmtpTransportMessage::DoAnalysis(const std::string& line)
{
    if (const auto statusCode = std::stoi(line.substr(0, 3));
        200 <= statusCode && statusCode < 300)
    {
        /// 2xx 响应，操作成功
    }
    else if (300 <= statusCode && statusCode < 400)
    {
        /// 3xx 响应，需要进一步操作
    }
    else if (400 <= statusCode && statusCode < 500)
    {
        /// 4xx 响应，临时错误
        LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Warn, Framework, SYSTEM_TEXT("Smtp"), SYSTEM_TEXT("临时错误, statusCode ="), statusCode, CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
    else if (500 <= statusCode && statusCode < 600)
    {
        /// 5xx 响应，永久错误
        THROW_EXCEPTION(SYSTEM_TEXT("永久错误, statusCode =") + System::ToString(statusCode))
    }
}
