/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/09 23:18)

#include "JsonBaseTesting.h"
#include "Detail/TestConfig.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/TextParsing/Json/JsonAnalysisManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::JsonBaseTesting::JsonBaseTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonBaseTesting)

void CoreTools::JsonBaseTesting::DoRunUnitTest()
{
    InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    InitTerm::ExecuteTerminator();
}

void CoreTools::JsonBaseTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TestConfigTest);
}

void CoreTools::JsonBaseTesting::TestConfigTest()
{
    const auto jsonBase = JSON_ANALYSIS_MANAGER_SINGLETON.Create("Configuration/TestConfig.json", TestConfig::GetCurrentRttiType().GetName());

    const auto testConfig = boost::polymorphic_pointer_downcast<TestConfig>(jsonBase);

    ASSERT_EQUAL(testConfig->GetDescribe(), SYSTEM_TEXT("tcre"));
    ASSERT_EQUAL(testConfig->GetSuffix(), SYSTEM_TEXT("suffix"));
    ASSERT_EQUAL(testConfig->GetPublicSuffix(), SYSTEM_TEXT("tcre_suffix"));
    ASSERT_EQUAL(testConfig->GetDomainName(), SYSTEM_TEXT("www.tcre.com"));
    ASSERT_EQUAL(testConfig->GetGameSuffix(), SYSTEM_TEXT("tcre_game"));
    ASSERT_EQUAL(testConfig->GetPortShifting(), 10);
}