//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 14:42)

#include "CoreTools/CoreToolsExport.h"

#include "SuiteImpl.h"
#include "SuitePrintManager.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <algorithm>
#include <functional>

using std::for_each;
using std::ostream;
using std::string;
using std::vector;
using namespace std::literals;

CoreTools::SuiteImpl::SuiteImpl(const string& name, const OStreamShared& osPtr, bool printRunUnitTest)
    : ParentType{ osPtr }, m_SuiteName{ name }, m_UnitTestCollection{}, m_PrintRunUnitTest{ printRunUnitTest }
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
    for (auto unitTest : m_UnitTestCollection)
    {
        if (unitTest == nullptr)
            return false;
    }

    return true;
}
#endif  // OPEN_CLASS_INVARIANT

int CoreTools::SuiteImpl::GetPassedNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    auto totalPass = 0;

    for (const auto& unitTest : m_UnitTestCollection)
    {
        totalPass += unitTest->GetPassedNumber();
    }

    return totalPass;
}

int CoreTools::SuiteImpl::GetFailedNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    auto totalFail = 0;

    for (const auto& unitTest : m_UnitTestCollection)
    {
        totalFail += unitTest->GetFailedNumber();
    }

    return totalFail;
}

int CoreTools::SuiteImpl::GetErrorNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    auto totalError = 0;

    for (const auto& unitTest : m_UnitTestCollection)
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

    for_each(m_UnitTestCollection.begin(), m_UnitTestCollection.end(), std::mem_fn(&UnitTestComposite::PrintReport));

    manager.PrintSuiteName();
    manager.PrintSuiteResult();
    manager.PrintCurrentTime();
}

void CoreTools::SuiteImpl::ClearUnitTestCollection() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    m_UnitTestCollection.clear();
}

void CoreTools::SuiteImpl::ResetTestData()
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    for_each(m_UnitTestCollection.begin(), m_UnitTestCollection.end(), std::mem_fn(&UnitTestComposite::ResetTestData));
}

void CoreTools::SuiteImpl::AddUnitTest(const UnitTestCompositeSharedPtr& unitTest)
{
    CORE_TOOLS_CLASS_IS_VALID_3;
    CORE_TOOLS_ASSERTION_0(unitTest != nullptr, "指针无效");

    m_UnitTestCollection.push_back(unitTest);
    unitTest->ResetTestData();
}

const string CoreTools::SuiteImpl::GetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    return m_SuiteName;
}

void CoreTools::SuiteImpl::RunUnitTest()
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    for_each(m_UnitTestCollection.begin(), m_UnitTestCollection.end(), [this](auto& value) {
        if (m_PrintRunUnitTest)
        {
            value->PrintRunUnitTest();
        }

        value->RunUnitTest();
    });
}

void CoreTools::SuiteImpl::PrintRunUnitTest()
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    auto runSuite = "正在运行测试套件 \""s + GetName() + "\"。\n"s;

    GetStream().GetStream() << runSuite;
}
