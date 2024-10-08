﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/09 22:30)

#include "CoreTools/CoreToolsExport.h"

#include "GlobalConfig.h"
#include "Detail/GlobalConfigImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/InitTermRegisterFactory.h"
#include "CoreTools/TextParsing/Json/JsonAnalysisManager.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, GlobalConfig)

CoreTools::GlobalConfig::GlobalConfig(DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, GlobalConfig)
CORE_TOOLS_RTTI_DEFINE(CoreTools, GlobalConfig)

System::String CoreTools::GlobalConfig::GetDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetDescribe();
}

System::String CoreTools::GlobalConfig::GetSuffix() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSuffix();
}

System::String CoreTools::GlobalConfig::GetPublicSuffix() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetPublicSuffix();
}

System::String CoreTools::GlobalConfig::GetDomainName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetDomainName();
}

System::String CoreTools::GlobalConfig::GetGameSuffix() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetGameSuffix();
}

int CoreTools::GlobalConfig::GetPortShifting() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetPortShifting();
}

void CoreTools::GlobalConfig::SetDescribe(const String& describe)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetDescribe(describe);
}

void CoreTools::GlobalConfig::SetSuffix(const String& suffix)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetSuffix(suffix);
}

void CoreTools::GlobalConfig::SetPublicSuffix(const String& publicSuffix)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetPublicSuffix(publicSuffix);
}

void CoreTools::GlobalConfig::SetDomainName(const String& domainName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetDomainName(domainName);
}

void CoreTools::GlobalConfig::SetGameSuffix(const String& gameSuffix)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetGameSuffix(gameSuffix);
}

void CoreTools::GlobalConfig::SetPortShifting(int portShifting) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetPortShifting(portShifting);
}

void CoreTools::GlobalConfig::Load(BasicTree& mainTree)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    SetDescribe(mainTree.get(SYSTEM_TEXT("describe"), SYSTEM_TEXT("")));
    SetSuffix(mainTree.get(SYSTEM_TEXT("suffix"), SYSTEM_TEXT("")));
    SetPublicSuffix(mainTree.get(SYSTEM_TEXT("publicSuffix"), SYSTEM_TEXT("")));
    SetDomainName(mainTree.get(SYSTEM_TEXT("domainName"), SYSTEM_TEXT("")));
    SetGameSuffix(mainTree.get(SYSTEM_TEXT("gameSuffix"), SYSTEM_TEXT("")));
    SetPortShifting(mainTree.get(SYSTEM_TEXT("portShifting"), 0));
}

CoreTools::JsonBase::JsonBaseSharedPtr CoreTools::GlobalConfig::Factory(BasicTree& mainTree)
{
    auto globalConfig = std::make_shared<ClassType>(DisableNotThrow::Disable);
    globalConfig->Load(mainTree);

    return globalConfig;
}

bool CoreTools::GlobalConfig::RegisterFactory()
{
    static InitTermRegisterFactory registerFactory{ &ClassType::InitializeFactory, &ClassType::TerminateFactory };

    return true;
}

void CoreTools::GlobalConfig::InitializeFactory()
{
    JSON_ANALYSIS_MANAGER_SINGLETON.Insert(GetCurrentRttiType().GetName(), &ClassType::Factory);
}

void CoreTools::GlobalConfig::TerminateFactory()
{
    JSON_ANALYSIS_MANAGER_SINGLETON.Remove(GetCurrentRttiType().GetName());
}