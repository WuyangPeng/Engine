/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/09 23:18)

#include "JsonAnalysisManagerTesting.h"
#include "Detail/TestConfig.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/TextParsing/Json/JsonAnalysisManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::JsonAnalysisManagerTesting::JsonAnalysisManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonAnalysisManagerTesting)

void CoreTools::JsonAnalysisManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::JsonAnalysisManagerTesting::MainTest()
{
    ASSERT_THROW_EXCEPTION_0(CreateTestConfigExceptionTest);
    ASSERT_THROW_EXCEPTION_0(TestConfigExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TestConfigInsertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TestConfigTest);
}

void CoreTools::JsonAnalysisManagerTesting::CreateTestConfigExceptionTest()
{
    std::ignore = JSON_ANALYSIS_MANAGER_SINGLETON.Create("Configuration/TestConfig.json", TestConfig::GetCurrentRttiType().GetName());
}

void CoreTools::JsonAnalysisManagerTesting::TestConfigExceptionTest()
{
    std::ignore = JSON_ANALYSIS_MANAGER_SINGLETON.Find(TestConfig::GetCurrentRttiType().GetName());
}

void CoreTools::JsonAnalysisManagerTesting::TestConfigInsertTest()
{
    JSON_ANALYSIS_MANAGER_SINGLETON.Insert(TestConfig::GetCurrentRttiType().GetName(), TestConfig::Factory);

    const auto factoryFunction = JSON_ANALYSIS_MANAGER_SINGLETON.Find(TestConfig::GetCurrentRttiType().GetName());

    ASSERT_EQUAL(factoryFunction, TestConfig::Factory);

    JSON_ANALYSIS_MANAGER_SINGLETON.Remove(TestConfig::GetCurrentRttiType().GetName());

    ASSERT_THROW_EXCEPTION_0(TestConfigExceptionTest);
}

void CoreTools::JsonAnalysisManagerTesting::TestConfigTest()
{
    JSON_ANALYSIS_MANAGER_SINGLETON.Insert(TestConfig::GetCurrentRttiType().GetName(), TestConfig::Factory);

    const auto jsonBase = JSON_ANALYSIS_MANAGER_SINGLETON.Create("Configuration/TestConfig.json", TestConfig::GetCurrentRttiType().GetName());

    std::ignore = boost::polymorphic_pointer_downcast<TestConfig>(jsonBase);

    JSON_ANALYSIS_MANAGER_SINGLETON.Remove(TestConfig::GetCurrentRttiType().GetName());

    ASSERT_THROW_EXCEPTION_0(CreateTestConfigExceptionTest);
}
