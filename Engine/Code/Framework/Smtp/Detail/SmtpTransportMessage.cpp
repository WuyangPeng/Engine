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
#include "CoreTools/CharacterString/Base64.h"
#include "CoreTools/EngineConfiguration/SmtpConfig.h"
#include "CoreTools/Helper//LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

namespace
{
    const auto lineBreak = "\r\n"s;
}

Framework::SmtpTransportMessage::SmtpTransportMessage(const SmtpConfig& smtpConfig, std::string title, std::string content)
    : smtpConfig{ smtpConfig },
      socketService{ Network::ConfigurationStrategy::CreateClient(smtpConfig.GetSmtpHost(), smtpConfig.GetSmtpPort()) },
      title{ std::move(title) },
      content{ std::move(content) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, SmtpTransportMessage)

void Framework::SmtpTransportMessage::Authenticate()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    socketService.SendTextMessage("EHLO " + smtpConfig.GetEhlo() + lineBreak);

    Response();

    /// 发送AUTH命令使用PLAIN方法
    const auto authCommand = "AUTH PLAIN "s;
    const auto plainCredentials = '\0' + smtpConfig.GetSendUser() + '\0' + smtpConfig.GetPassword();

    const auto base64Encoded = CoreTools::Base64::Encode(plainCredentials);

    socketService.SendTextMessage(authCommand + base64Encoded + lineBreak);

    Response();
}

void Framework::SmtpTransportMessage::SendMailMessage()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    auto index = 0;
    for (const auto& receiveUser : smtpConfig.GetReceiveUser())
    {
        SendMailMessage(index, receiveUser);

        ++index;
    }

    socketService.SendTextMessage("QUIT" + lineBreak);

    Response();
}

void Framework::SmtpTransportMessage::SendMailMessage(int index, const std::string& receiveUser)
{
    socketService.SendTextMessage(GetFromMessage());

    Response();

    socketService.SendTextMessage(GetRcptMessage(receiveUser));

    Response();

    socketService.SendTextMessage(GetTextMessage(index, receiveUser));

    Response();
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

    const auto response = socketService.Response();

    SplitType splitContent{};

    split(splitContent, response, boost::is_any_of(lineBreak), boost::token_compress_on);

    for (const auto& line : splitContent)
    {
        Analysis(line);
    }
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
