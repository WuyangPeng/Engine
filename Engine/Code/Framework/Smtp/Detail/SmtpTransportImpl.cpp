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
#include "SmtpTransportMessage.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/TextParsing/Json/JsonAnalysisManager.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelper.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

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

    SmtpTransportMessage smtpTransportMessage{ *smtpConfig, title, content };

    smtpTransportMessage.Response();
    smtpTransportMessage.Authenticate();
    smtpTransportMessage.SendMailMessage();
}
