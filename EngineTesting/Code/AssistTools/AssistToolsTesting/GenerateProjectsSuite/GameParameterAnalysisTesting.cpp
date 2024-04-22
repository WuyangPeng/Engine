///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	°æ±¾£º1.0.0.0 (2023/11/09 15:34)

#include "GameParameterAnalysisTesting.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Time/Year.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/Flags/GameParameterType.h"
#include "AssistTools/GenerateProjects/Flags/ProjectServiceType.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/GameParameterAnalysis.h"
#include "AssistTools/GenerateProjects/MiddleLayerModule.h"

AssistTools::GameParameterAnalysisTesting::GameParameterAnalysisTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GameParameterAnalysisTesting)

void AssistTools::GameParameterAnalysisTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AssistTools::GameParameterAnalysisTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ParameterTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ParameterDefaultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ModuleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MiddleLayerTest);
}

void AssistTools::GameParameterAnalysisTesting::ParameterTest()
{
    const GameParameterAnalysis gameParameterAnalysis{ "Configuration/GameParameter0.json" };

    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::CoreName), SYSTEM_TEXT("Test"));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::CoreCapital), SYSTEM_TEXT("TEST"));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::ProjectChineseName), SYSTEM_TEXT("²âÊÔ"));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::ProjectDescribeName), SYSTEM_TEXT("The Test"));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::ProjectName), SYSTEM_TEXT("TheTest"));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::ProjectCapital), SYSTEM_TEXT("THE_TEST"));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::ProjectAbbreviation), SYSTEM_TEXT("TT"));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::EndYear), SYSTEM_TEXT("2021"));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::Version), SYSTEM_TEXT("1.0.0.0"));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::VersionNum), SYSTEM_TEXT("1000000"));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::TestingName), SYSTEM_TEXT("TheTesting"));
}

void AssistTools::GameParameterAnalysisTesting::ParameterDefaultTest()
{
    const GameParameterAnalysis gameParameterAnalysis{ "Configuration/GameParameter1.json" };

    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::CoreName), SYSTEM_TEXT("Core"));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::CoreCapital), SYSTEM_TEXT("CORE"));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::ProjectChineseName), SYSTEM_TEXT(""));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::ProjectDescribeName), SYSTEM_TEXT(""));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::ProjectName), SYSTEM_TEXT(""));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::ProjectCapital), SYSTEM_TEXT(""));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::ProjectAbbreviation), SYSTEM_TEXT(""));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::EndYear), System::ToString(CoreTools::Year::GetCurrentYear()));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::Version), CoreTools::StringConversion::MultiByteConversionStandard(CoreTools::Version::GetVersion()));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::VersionNum), System::ToString(CoreTools::Version::GetTcreFullVersion()));
    ASSERT_EQUAL(gameParameterAnalysis.GetGameParameter(GameParameterType::TestingName), SYSTEM_TEXT(""));
}

void AssistTools::GameParameterAnalysisTesting::ModuleTest()
{
    const GameParameterAnalysis gameParameterAnalysis{ "Configuration/GameParameter0.json" };

    ASSERT_EQUAL(gameParameterAnalysis.GetModuleCount(), 16);

    for (auto iter = gameParameterAnalysis.GetModuleBegin();
         iter != gameParameterAnalysis.GetModuleEnd();
         ++iter)
    {
        ASSERT_EQUAL(iter->GetProjectServiceType(), ProjectServiceType::Server);
        ASSERT_FALSE(iter->GetChineseName().empty());
        ASSERT_FALSE(iter->GetUppercaseName().empty());
        ASSERT_FALSE(iter->GetModuleName().empty());
    }
}

void AssistTools::GameParameterAnalysisTesting::ModuleDefaultTest()
{
    const GameParameterAnalysis gameParameterAnalysis{ "Configuration/GameParameter1.json" };

    ASSERT_EQUAL(gameParameterAnalysis.GetModuleCount(), 20);

    for (auto iter = gameParameterAnalysis.GetModuleBegin();
         iter != gameParameterAnalysis.GetModuleEnd();
         ++iter)
    {
        ASSERT_EQUAL(iter->GetProjectServiceType(), ProjectServiceType::Tools);
        ASSERT_TRUE(iter->GetChineseName().empty());
        ASSERT_TRUE(iter->GetUppercaseName().empty());
        ASSERT_FALSE(iter->GetModuleName().empty());
    }
}

void AssistTools::GameParameterAnalysisTesting::MiddleLayerTest()
{
    const GameParameterAnalysis gameParameterAnalysis{ "Configuration/GameParameter0.json" };

    for (auto iter = gameParameterAnalysis.GetMiddleLayerBegin();
         iter != gameParameterAnalysis.GetMiddleLayerEnd();
         ++iter)
    {
        ASSERT_FALSE(iter->GetUppercaseName().empty());
        ASSERT_FALSE(iter->GetMiddleLayerName().empty());
        ASSERT_TRUE(iter->IsManager());
    }
}

void AssistTools::GameParameterAnalysisTesting::MiddleLayerDefaultTest()
{
    const GameParameterAnalysis gameParameterAnalysis{ "Configuration/GameParameter1.json" };

    for (auto iter = gameParameterAnalysis.GetMiddleLayerBegin();
         iter != gameParameterAnalysis.GetMiddleLayerEnd();
         ++iter)
    {
        ASSERT_TRUE(iter->GetUppercaseName().empty());
        ASSERT_FALSE(iter->GetMiddleLayerName().empty());
        ASSERT_FALSE(iter->IsManager());
    }
}
