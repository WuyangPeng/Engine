/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/09 16:52)

#include "CoreTools/CoreToolsExport.h"

#include "GlobalConfig.h"
#include "Detail/GlobalConfigImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, GlobalConfig)

CoreTools::GlobalConfig::GlobalConfig(DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, GlobalConfig)

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

void CoreTools::GlobalConfig::SetDescribe(const String& aDescribe)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetDescribe(aDescribe);
}

void CoreTools::GlobalConfig::SetSuffix(const String& aSuffix)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetSuffix(aSuffix);
}

void CoreTools::GlobalConfig::SetPublicSuffix(const String& aPublicSuffix)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetPublicSuffix(aPublicSuffix);
}

void CoreTools::GlobalConfig::SetDomainName(const String& aDomainName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetPublicSuffix(aDomainName);
}

void CoreTools::GlobalConfig::SetGameSuffix(const String& aGameSuffix)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetPublicSuffix(aGameSuffix);
}

void CoreTools::GlobalConfig::SetPortShifting(int aPortShifting) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetPortShifting(aPortShifting);
}

void CoreTools::GlobalConfig::Load(BasicTree& mainTree)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->SetDescribe(mainTree.get(SYSTEM_TEXT("describe"), SYSTEM_TEXT("")));
    impl->SetSuffix(mainTree.get(SYSTEM_TEXT("suffix"), SYSTEM_TEXT("")));
    impl->SetPublicSuffix(mainTree.get(SYSTEM_TEXT("publicSuffix"), SYSTEM_TEXT("")));
    impl->SetDomainName(mainTree.get(SYSTEM_TEXT("domainName"), SYSTEM_TEXT("")));
    impl->SetGameSuffix(mainTree.get(SYSTEM_TEXT("gameSuffix"), SYSTEM_TEXT("")));
    impl->SetPortShifting(mainTree.get(SYSTEM_TEXT("portShifting"), 0));
}

CoreTools::JsonBase::JsonBaseSharedPtr CoreTools::GlobalConfig::Factory(BasicTree& mainTree)
{
    auto globalConfig = std::make_shared<ClassType>(DisableNotThrow::Disable);
    globalConfig->Load(mainTree);

    return globalConfig;
}