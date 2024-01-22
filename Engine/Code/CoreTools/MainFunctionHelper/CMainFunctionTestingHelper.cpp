/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:37)

#include "CoreTools/CoreToolsExport.h"

#include "CMainFunctionTestingHelper.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

CoreTools::CMainFunctionTestingHelper::CMainFunctionTestingHelper(int argc, char** argv)
    : ParentType{ argc, argv }, testingInformationHelper{ TestingInformationHelper::Create() }, suite{ std::string{}, GetStreamShared(), IsPrintRun() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CMainFunctionTestingHelper::CMainFunctionTestingHelper(int argc, char** argv, const std::string& suiteName)
    : ParentType{ argc, argv }, testingInformationHelper{ TestingInformationHelper::Create() }, suite{ suiteName, GetStreamShared(), IsPrintRun() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CMainFunctionTestingHelper::CMainFunctionTestingHelper(CMainFunctionTestingHelper&& rhs) noexcept
    : ParentType{ std::move(rhs) }, testingInformationHelper{ std::move(rhs.testingInformationHelper) }, suite{ std::move(rhs.suite) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CMainFunctionTestingHelper& CoreTools::CMainFunctionTestingHelper::operator=(CMainFunctionTestingHelper&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (this != &rhs)
    {
        testingInformationHelper = std::move(rhs.testingInformationHelper);
        suite = std::move(rhs.suite);

        ParentType::operator=(std::move(rhs));
    }

    return *this;
}

CoreTools::CMainFunctionTestingHelper::~CMainFunctionTestingHelper()
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CMainFunctionTestingHelper)

void CoreTools::CMainFunctionTestingHelper::AddTest(const std::string& suiteName, Suite& aSuite, const std::string& testName, const UnitTestSharedPtr& unitTest)
{
    try
    {
        if (const auto testLoopCount = testingInformationHelper.GetLoopCount(suiteName, testName); 0 < testLoopCount)
        {
            unitTest->SetTestLoopCount(testLoopCount);
            unitTest->SetRandomSeed(testingInformationHelper.GetRandomSeed());
            aSuite.AddTest(unitTest);
        }
    }
    catch (const Error& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

bool CoreTools::CMainFunctionTestingHelper::IsPrintRun() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return testingInformationHelper.IsPrintRun();
}

int CoreTools::CMainFunctionTestingHelper::RunSuite()
{
    suite.RunUnitTest();
    SystemPause();
    suite.PrintReport();
    SystemPause();

    return suite.GetFailedNumber();
}

void CoreTools::CMainFunctionTestingHelper::AddSuite(const Suite& aSuite)
{
    suite.AddSuite(aSuite);
}

int CoreTools::CMainFunctionTestingHelper::DoRun()
{
    return RunSuite();
}

CoreTools::Suite CoreTools::CMainFunctionTestingHelper::GenerateSuite(const std::string& name) const
{
    return Suite{ name, GetStreamShared(), IsPrintRun() };
}