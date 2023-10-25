///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:04)

#include "CoreTools/CoreToolsExport.h"

#include "SuiteImpl.h"
#include "SuitePrintManager.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/LogManager/LogAsynchronous.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <algorithm>
#include <functional>

using namespace std::literals;

CoreTools::SuiteImpl::SuiteImpl(const std::string& name, const OStreamShared& streamShared, bool printRunUnitTest)
    : ParentType{ streamShared }, suiteName{ name }, unitTestCollection{}, printRunUnitTest{ printRunUnitTest }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_3;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::SuiteImpl::IsValid() const noexcept
{
    if (ParentType::IsValid() && IsUnitTestValid())
        return true;
    else
        return false;
}

bool CoreTools::SuiteImpl::IsUnitTestValid() const noexcept
{
    for (const auto& unitTest : unitTestCollection)
    {
        if (unitTest == nullptr)
        {
            return false;
        }
    }

    return true;
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::SuiteImpl::GetPassedNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    auto totalPass = 0;

    for (const auto& unitTest : unitTestCollection)
    {
        totalPass += unitTest->GetPassedNumber();
    }

    return totalPass;
}

int CoreTools::SuiteImpl::GetFailedNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    auto totalFail = 0;

    for (const auto& unitTest : unitTestCollection)
    {
        totalFail += unitTest->GetFailedNumber();
    }

    return totalFail;
}

int CoreTools::SuiteImpl::GetErrorNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    auto totalError = 0;

    for (const auto& unitTest : unitTestCollection)
    {
        totalError += unitTest->GetErrorNumber();
    }

    return totalError;
}

void CoreTools::SuiteImpl::PrintReport()
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    SuitePrintManager manager{ *this };

    manager.PrintCoreToolsHeader();

    std::ranges::for_each(unitTestCollection, std::mem_fn(&UnitTestComposite::PrintReport));

    manager.PrintSuiteName();
    manager.PrintSuiteResult();
    manager.PrintCurrentTime();
}

void CoreTools::SuiteImpl::ClearUnitTestCollection() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    unitTestCollection.clear();
}

void CoreTools::SuiteImpl::ResetTestData()
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    std::ranges::for_each(unitTestCollection, std::mem_fn(&UnitTestComposite::ResetTestData));
}

void CoreTools::SuiteImpl::AddUnitTest(const UnitTestCompositeSharedPtr& unitTest)
{
    CORE_TOOLS_CLASS_IS_VALID_3;
    CORE_TOOLS_ASSERTION_0(unitTest != nullptr, "指针无效");

    unitTestCollection.emplace_back(unitTest);
    unitTest->ResetTestData();
}

std::string CoreTools::SuiteImpl::GetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    return suiteName;
}

void CoreTools::SuiteImpl::RunUnitTest()
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    std::ranges::for_each(unitTestCollection, [printRunUnitTest = printRunUnitTest](auto& unitTest) {
        if (printRunUnitTest)
        {
            unitTest->PrintRunUnitTest();
        }

        unitTest->RunUnitTest();
    });
}

void CoreTools::SuiteImpl::PrintRunUnitTest()
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    const auto runSuite = "正在运行测试套件 \""s + GetName() + "\"。\n"s;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(GetStream(), runSuite);
}
