/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/10 00:10)

#include "GlobalConfigTesting.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/EngineConfiguration/GlobalConfig.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/TextParsing/Json/JsonAnalysisManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::GlobalConfigTesting::GlobalConfigTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, GlobalConfigTesting)

void CoreTools::GlobalConfigTesting::DoRunUnitTest()
{
    InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    InitTerm::ExecuteTerminator();
}

void CoreTools::GlobalConfigTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GlobalConfigTest);
}

void CoreTools::GlobalConfigTesting::GlobalConfigTest()
{
    const auto jsonBase = JSON_ANALYSIS_MANAGER_SINGLETON.Create("Configuration/TestConfig.json", GlobalConfig::GetCurrentRttiType().GetName());

    const auto globalConfig = boost::polymorphic_pointer_downcast<GlobalConfig>(jsonBase);

    ASSERT_EQUAL(globalConfig->GetDescribe(), SYSTEM_TEXT("tcre"));
    ASSERT_EQUAL(globalConfig->GetSuffix(), SYSTEM_TEXT("suffix"));
    ASSERT_EQUAL(globalConfig->GetPublicSuffix(), SYSTEM_TEXT("tcre_suffix"));
    ASSERT_EQUAL(globalConfig->GetDomainName(), SYSTEM_TEXT("www.tcre.com"));
    ASSERT_EQUAL(globalConfig->GetGameSuffix(), SYSTEM_TEXT("tcre_game"));
    ASSERT_EQUAL(globalConfig->GetPortShifting(), 10);
}