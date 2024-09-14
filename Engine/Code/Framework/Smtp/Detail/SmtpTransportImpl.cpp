/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.1 (2024/09/12 09:35)

#include "Framework/FrameworkExport.h"

#include "SmtpTransportImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/CharacterString/Base64.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/EngineConfiguration/SmtpConfig.h"
#include "CoreTools/Helper//LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Json/JsonAnalysisManager.h"
#include "Network/ServiceWrappers/SocketService.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelper.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

using namespace std::literals;

namespace
{
    const auto lineBreak = "\r\n"s;
}

Framework::SmtpTransportImpl::SmtpTransportImpl(const EnvironmentDirectory& environmentDirectory)
    : smtpConfig{ boost::polymorphic_pointer_cast<SmtpConfig>(JSON_ANALYSIS_MANAGER_SINGLETON.Create(CoreTools::StringConversion::StandardConversionMultiByte(environmentDirectory.GetDirectory(UpperDirectory::Configuration)) + "Smtp.json",
                                                                                                     SmtpConfig::GetCurrentRttiType().GetName())) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, SmtpTransportImpl)

void Framework::SmtpTransportImpl::SendMailMessage(const std::string& title, const std::string& content) const
{
    FRAMEWORK_CLASS_IS_VALID_9;

    const auto configurationStrategy = Network::ConfigurationStrategy::CreateClient(smtpConfig->GetSmtpHost(), smtpConfig->GetSmtpPort());

    SocketService socketService{ configurationStrategy };

    Response(socketService);

    Authenticate(socketService);

    SendMailMessage(socketService, title, content);
}

void Framework::SmtpTransportImpl::Authenticate(SocketService& socketService) const
{
    socketService.SendTextMessage("EHLO " + smtpConfig->GetEhlo() + lineBreak);

    Response(socketService);

    /// 发送AUTH命令使用PLAIN方法
    const auto authCommand = "AUTH PLAIN "s;
    const auto plainCredentials = '\0' + smtpConfig->GetSendUser() + '\0' + smtpConfig->GetPassword();

    const auto base64Encoded = CoreTools::Base64::Encode(plainCredentials);

    socketService.SendTextMessage(authCommand + base64Encoded + lineBreak);

    Response(socketService);
}

void Framework::SmtpTransportImpl::SendMailMessage(SocketService& socketService, const std::string& title, const std::string& content) const
{
    auto index = 0;
    for (const auto& element : smtpConfig->GetReceiveUser())
    {
        socketService.SendTextMessage("MAIL FROM:<" + smtpConfig->GetSendUser() + ">" + lineBreak);

        Response(socketService);

        socketService.SendTextMessage("RCPT TO:<" + element + ">" + lineBreak);

        Response(socketService);

        socketService.SendTextMessage("DATA" + lineBreak + "From: " + smtpConfig->GetSendUser() + lineBreak + "To: " + element + lineBreak + "Subject: " + title + std::to_string(index) + lineBreak + lineBreak + content + lineBreak + "." + lineBreak);

        Response(socketService);

        ++index;
    }

    socketService.SendTextMessage("QUIT" + lineBreak);

    Response(socketService);
}

void Framework::SmtpTransportImpl::Response(SocketService& socketService) const
{
    const auto response = socketService.Response();

    std::vector<std::string> content{};

    split(content, response, boost::is_any_of(lineBreak), boost::token_compress_on);

    for (const auto& line : content)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, line);

        // 解析状态码
        if (line.size() >= 3 && std::isdigit(line[0]) && std::isdigit(line[1]) && std::isdigit(line[2]))
        {
            const auto statusCode = std::stoi(line.substr(0, 3));
            if (statusCode >= 200 && statusCode < 300)
            {
                // 2xx 响应，操作成功
                LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, statusCode);
            }
            else if (statusCode >= 300 && statusCode < 400)
            {
                // 3xx 响应，需要进一步操作
                LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, statusCode);
            }
            else if (statusCode >= 400 && statusCode < 500)
            {
                // 4xx 响应，临时错误
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Framework, statusCode, CoreTools::LogAppenderIOManageSign::TriggerAssert);
            }
            else if (statusCode >= 500 && statusCode < 600)
            {
                // 5xx 响应，永久错误
                THROW_EXCEPTION(SYSTEM_TEXT("永久错误：") + System::ToString(statusCode));
            }
        }
    }
}