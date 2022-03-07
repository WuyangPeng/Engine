///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/29 22:30)

#include "CoreTools/CoreToolsExport.h"

#include "CMainFunctionTestingHelper.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

using std::string;

CoreTools::CMainFunctionTestingHelper::CMainFunctionTestingHelper(int argc, char** argv)
    : ParentType{ argc, argv }, testingInformationHelper{ TestingInformationHelper::Create() }, m_Suite{ string{}, GetStreamShared(), IsPrintRun() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CMainFunctionTestingHelper::CMainFunctionTestingHelper(int argc, char** argv, const string& suiteName)
    : ParentType{ argc, argv }, testingInformationHelper{ TestingInformationHelper::Create() }, m_Suite{ suiteName, GetStreamShared(), IsPrintRun() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CMainFunctionTestingHelper::CMainFunctionTestingHelper(CMainFunctionTestingHelper&& rhs) noexcept
    : ParentType{ std::move(rhs) }, testingInformationHelper{ std::move(rhs.testingInformationHelper) }, m_Suite{ std::move(rhs.m_Suite) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CMainFunctionTestingHelper& CoreTools::CMainFunctionTestingHelper::operator=(CMainFunctionTestingHelper&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (this != &rhs)
    {
        ParentType::operator=(std::move(rhs));

        testingInformationHelper = std::move(rhs.testingInformationHelper);
        m_Suite = std::move(rhs.m_Suite);
    }

    return *this;
}

CoreTools::CMainFunctionTestingHelper::~CMainFunctionTestingHelper()
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CMainFunctionTestingHelper)

void CoreTools::CMainFunctionTestingHelper::AddTest(const string& suiteName, Suite& suite, const string& testName, const UnitTestSharedPtr& unitTest)
{
    try
    {
        const auto testLoopCount = testingInformationHelper.GetLoopCount(suiteName, testName);

        if (0 < testLoopCount)
        {
            unitTest->SetTestLoopCount(testLoopCount);
            unitTest->SetRandomSeed(testingInformationHelper.GetRandomSeed());
            suite.AddTest(unitTest);
        }
    }
    catch (const Error& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << error
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

bool CoreTools::CMainFunctionTestingHelper::IsPrintRun() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return testingInformationHelper.IsPrintRun();
}

int CoreTools::CMainFunctionTestingHelper::RunSuite()
{
    m_Suite.RunUnitTest();
    SystemPause();
    m_Suite.PrintReport();
    SystemPause();

    return m_Suite.GetFailedNumber();
}

void CoreTools::CMainFunctionTestingHelper::AddSuite(const Suite& suite)
{
    m_Suite.AddSuite(suite);
}

int CoreTools::CMainFunctionTestingHelper::DoRun()
{
    return RunSuite();
}

CoreTools::Suite CoreTools::CMainFunctionTestingHelper::GenerateSuite(const string& name)
{
    return Suite{ name, GetStreamShared(), IsPrintRun() };
}