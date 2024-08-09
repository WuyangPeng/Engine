/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/09 23:15)

#include "TestConfig.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/InitTermRegisterFactory.h"
#include "CoreTools/TextParsing/Json/JsonAnalysisManager.h"

CoreTools::TestConfig::TestConfig(int portShifting) noexcept
    : describe{},
      suffix{},
      publicSuffix{},
      domainName{},
      gameSuffix{},
      portShifting{ portShifting }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TestConfig)
CORE_TOOLS_RTTI_DEFINE(CoreTools, TestConfig)

System::String CoreTools::TestConfig::GetDescribe() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return describe;
}

System::String CoreTools::TestConfig::GetSuffix() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return suffix;
}

System::String CoreTools::TestConfig::GetPublicSuffix() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return publicSuffix;
}

System::String CoreTools::TestConfig::GetDomainName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return domainName;
}

System::String CoreTools::TestConfig::GetGameSuffix() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return gameSuffix;
}

int CoreTools::TestConfig::GetPortShifting() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return portShifting;
}

void CoreTools::TestConfig::SetDescribe(const String& aDescribe)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    describe = aDescribe;
}

void CoreTools::TestConfig::SetSuffix(const String& aSuffix)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    suffix = aSuffix;
}

void CoreTools::TestConfig::SetPublicSuffix(const String& aPublicSuffix)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    publicSuffix = aPublicSuffix;
}

void CoreTools::TestConfig::SetDomainName(const String& aDomainName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    domainName = aDomainName;
}

void CoreTools::TestConfig::SetGameSuffix(const String& aGameSuffix)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    gameSuffix = aGameSuffix;
}

void CoreTools::TestConfig::SetPortShifting(int aPortShifting) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    portShifting = aPortShifting;
}

void CoreTools::TestConfig::Load(BasicTree& mainTree)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    SetDescribe(mainTree.get(SYSTEM_TEXT("describe"), SYSTEM_TEXT("")));
    SetSuffix(mainTree.get(SYSTEM_TEXT("suffix"), SYSTEM_TEXT("")));
    SetPublicSuffix(mainTree.get(SYSTEM_TEXT("publicSuffix"), SYSTEM_TEXT("")));
    SetDomainName(mainTree.get(SYSTEM_TEXT("domainName"), SYSTEM_TEXT("")));
    SetGameSuffix(mainTree.get(SYSTEM_TEXT("gameSuffix"), SYSTEM_TEXT("")));
    SetPortShifting(mainTree.get(SYSTEM_TEXT("portShifting"), 0));
}

CoreTools::JsonBase::JsonBaseSharedPtr CoreTools::TestConfig::Factory(BasicTree& mainTree)
{
    auto globalConfig = std::make_shared<ClassType>(5);
    globalConfig->Load(mainTree);

    return globalConfig;
}

bool CoreTools::TestConfig::RegisterFactory()
{
    static InitTermRegisterFactory registerFactory{ &ClassType::InitializeFactory, &ClassType::TerminateFactory };

    return true;
}

void CoreTools::TestConfig::InitializeFactory()
{
    JSON_ANALYSIS_MANAGER_SINGLETON.Insert(GetCurrentRttiType().GetName(), &ClassType::Factory);
}

void CoreTools::TestConfig::TerminateFactory()
{
    JSON_ANALYSIS_MANAGER_SINGLETON.Remove(GetCurrentRttiType().GetName());
}