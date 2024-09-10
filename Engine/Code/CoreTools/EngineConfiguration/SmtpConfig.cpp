/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/09 22:30)

#include "CoreTools/CoreToolsExport.h"

#include "SmtpConfig.h"
#include "Detail/SmtpConfigImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/InitTermRegisterFactory.h"
#include "CoreTools/TextParsing/Json/JsonAnalysisManager.h"

#include <ranges>

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, SmtpConfig)

CoreTools::SmtpConfig::SmtpConfig(DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SmtpConfig)

CORE_TOOLS_RTTI_DEFINE(CoreTools, SmtpConfig)

System::String CoreTools::SmtpConfig::GetSmtpHost() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSmtpHost();
}

bool CoreTools::SmtpConfig::GetSmtpSslEnable() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSmtpSslEnable();
}

bool CoreTools::SmtpConfig::GetSmtpAuth() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSmtpAuth();
}

System::String CoreTools::SmtpConfig::GetSendUser() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSendUser();
}

System::String CoreTools::SmtpConfig::GetPassword() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetPassword();
}

CoreTools::SmtpConfig::ReceiveUserType CoreTools::SmtpConfig::GetReceiveUser() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetReceiveUser();
}

void CoreTools::SmtpConfig::SetSmtpHost(const String& smtpHost)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetSmtpHost(smtpHost);
}

void CoreTools::SmtpConfig::SetSmtpSslEnable(bool smtpSslEnable) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetSmtpSslEnable(smtpSslEnable);
}

void CoreTools::SmtpConfig::SetSmtpAuth(bool smtpAuth) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetSmtpAuth(smtpAuth);
}

void CoreTools::SmtpConfig::SetSendUser(const String& sendUser)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetSendUser(sendUser);
}

void CoreTools::SmtpConfig::SetPassword(const String& password)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetPassword(password);
}

void CoreTools::SmtpConfig::SetReceiveUser(const ReceiveUserType& receiveUser)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetReceiveUser(receiveUser);
}

void CoreTools::SmtpConfig::Load(BasicTree& mainTree)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    SetSmtpHost(mainTree.get(SYSTEM_TEXT("smtpHost"), SYSTEM_TEXT("smtp.qq.com")));
    SetSmtpSslEnable(mainTree.get(SYSTEM_TEXT("smtpSslEnable"), false));
    SetSmtpAuth(mainTree.get(SYSTEM_TEXT("smtpAuth"), true));
    SetSendUser(mainTree.get(SYSTEM_TEXT("sendUser"), SYSTEM_TEXT("")));
    SetPassword(mainTree.get(SYSTEM_TEXT("password"), SYSTEM_TEXT("")));

    for (const auto receiveUser = mainTree.get_child(SYSTEM_TEXT("receiveUser"));
         const auto& element : receiveUser | std::views::values)
    {
        impl->AddReceiveUser(element.data());
    }
}

CoreTools::JsonBase::JsonBaseSharedPtr CoreTools::SmtpConfig::Factory(BasicTree& mainTree)
{
    auto smtpConfig = std::make_shared<ClassType>(DisableNotThrow::Disable);
    smtpConfig->Load(mainTree);

    return smtpConfig;
}

bool CoreTools::SmtpConfig::RegisterFactory()
{
    static InitTermRegisterFactory registerFactory{ &ClassType::InitializeFactory, &ClassType::TerminateFactory };

    return true;
}

void CoreTools::SmtpConfig::InitializeFactory()
{
    JSON_ANALYSIS_MANAGER_SINGLETON.Insert(GetCurrentRttiType().GetName(), &ClassType::Factory);
}

void CoreTools::SmtpConfig::TerminateFactory()
{
    JSON_ANALYSIS_MANAGER_SINGLETON.Remove(GetCurrentRttiType().GetName());
}