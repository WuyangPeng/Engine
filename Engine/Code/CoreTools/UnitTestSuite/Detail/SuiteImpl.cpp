/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 11:31)

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

CoreTools::SuiteImpl::SuiteImpl(std::string name, const OStreamShared& streamShared, bool printRunUnitTest) noexcept
    : ParentType{ streamShared }, suiteName{ std::move(name) }, unitTestCollection{}, printRunUnitTest{ printRunUnitTest }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_3;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::SuiteImpl::IsValid() const noexcept
{
    return ParentType::IsValid() && IsUnitTestValid();
}

bool CoreTools::SuiteImpl::IsUnitTestValid() const noexcept
{
    return std::ranges::all_of(unitTestCollection, [](const auto& element) noexcept {
        return element != nullptr;
    });
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
    CORE_TOOLS_ASSERTION_0(unitTest != nullptr, "ָ����Ч");

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

    std::ranges::for_each(unitTestCollection, [isPrint = printRunUnitTest](auto& unitTest) {
        if (isPrint)
        {
            unitTest->PrintRunUnitTest();
        }

        unitTest->RunUnitTest();
    });
}

void CoreTools::SuiteImpl::PrintRunUnitTest()
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    const auto runSuite = "�������в����׼� \"" + GetName() + "\"��\n";

    LOG_ASYNCHRONOUS_SINGLETON.Registered(GetStream(), runSuite);
}
