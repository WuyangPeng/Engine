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
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/CharacterString/Base64Encode.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/EngineConfiguration/SmtpConfig.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
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

void Framework::SmtpTransportImpl::SendMailMessage(const String& title, const String& content)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    const Network::ConfigurationStrategy configurationStrategy{ CoreTools::StringConversion::StandardConversionMultiByte(smtpConfig->GetSmtpHost()),
                                                                smtpConfig->GetSmtpPort() };

    SocketService socketService{ configurationStrategy };

    Authenticate(socketService);

    SendMailMessage(socketService, title, content);
}

void Framework::SmtpTransportImpl::Authenticate(SocketService& socketService) const
{
    socketService.SendTextMessage("EHLO " + CoreTools::StringConversion::StandardConversionMultiByte(smtpConfig->GetEhlo()) + lineBreak);
    socketService.SendTextMessage("STARTTLS a" + lineBreak);

    // 发送AUTH命令使用PLAIN方法
    const auto authCommand = "AUTH PLAIN "s;
    const auto plainCredentials = '\0' + CoreTools::StringConversion::StandardConversionMultiByte(smtpConfig->GetSendUser()) + '\0' + CoreTools::StringConversion::StandardConversionMultiByte(smtpConfig->GetPassword());

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    const auto base64Encoded = CoreTools::Base64Encode::Encode(reinterpret_cast<const uint8_t*>(plainCredentials.c_str()), boost::numeric_cast<int>(plainCredentials.size()));

#include SYSTEM_WARNING_POP

    socketService.SendTextMessage(base64Encoded + lineBreak);
}

void Framework::SmtpTransportImpl::SendMailMessage(SocketService& socketService, const String& title, const String& content) const
{
    socketService.SendTextMessage("MAIL FROM:<" + CoreTools::StringConversion::StandardConversionMultiByte(smtpConfig->GetSendUser()) + ">" + lineBreak);

    for (const auto& element : smtpConfig->GetReceiveUser())
    {
        socketService.SendTextMessage("RCPT TO:<" + CoreTools::StringConversion::StandardConversionMultiByte(element) + ">" + lineBreak);

        socketService.SendTextMessage("DATA" + lineBreak);

        socketService.SendTextMessage("From: " + CoreTools::StringConversion::StandardConversionMultiByte(smtpConfig->GetSendUser()) + lineBreak);
        socketService.SendTextMessage("To: " + CoreTools::StringConversion::StandardConversionMultiByte(element) + lineBreak);

        socketService.SendTextMessage(CoreTools::StringConversion::StandardConversionMultiByte(title) + lineBreak);
        socketService.SendTextMessage(CoreTools::StringConversion::StandardConversionMultiByte(content) + lineBreak);
    }

    socketService.SendTextMessage("QUIT" + lineBreak);
}