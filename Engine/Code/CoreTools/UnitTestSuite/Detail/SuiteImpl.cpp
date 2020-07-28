// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 10:19)

#include "CoreTools/CoreToolsExport.h"

#include "SuiteImpl.h"
#include "SuitePrintManager.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <algorithm>
#include <functional>

using std::string;
using std::vector;
using std::ostream;
using std::for_each;

CoreTools::SuiteImpl
	::SuiteImpl(const string& name, const OStreamShared& osPtr, bool printRunUnitTest)
	:ParentType{ osPtr }, m_SuiteName{ name }, m_UnitTestCollection{}, m_PrintRunUnitTest{ printRunUnitTest }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_3;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::SuiteImpl
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && IsUnitTestValid())
		return true;
	else
		return false;
}

bool CoreTools::SuiteImpl
	::IsUnitTestValid() const noexcept
{
	for (auto unitTest : m_UnitTestCollection)
	{
		if (unitTest == nullptr)
			return false;
	}

	return true;
}
#endif // OPEN_CLASS_INVARIANT

int CoreTools::SuiteImpl
	::GetPassedNumber() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_3;

	auto totalPass = 0;

	EXCEPTION_TRY
	{
		for (const auto& unitTest : m_UnitTestCollection)
		{
			totalPass += unitTest->GetPassedNumber();
		}

		CORE_TOOLS_ASSERTION_2(0 <= totalPass, "返回零或一个正数。");
	}
	EXCEPTION_ALL_CATCH(CoreTools)

	return totalPass;
}

int CoreTools::SuiteImpl
	::GetFailedNumber() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_3;

	auto totalFail = 0;

	EXCEPTION_TRY
	{
		for (const auto& unitTest : m_UnitTestCollection)
		{
			totalFail += unitTest->GetFailedNumber();
		}

		CORE_TOOLS_ASSERTION_2(0 <= totalFail, "返回零或一个正数。");
	}
	EXCEPTION_ALL_CATCH(CoreTools)

	return totalFail;
}

int CoreTools::SuiteImpl
	::GetErrorNumber() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_3;

	auto totalError = 0;

	EXCEPTION_TRY
	{
		for (const auto& unitTest : m_UnitTestCollection)
		{
			totalError += unitTest->GetErrorNumber();
		}

		CORE_TOOLS_ASSERTION_2(0 <= totalError, "返回零或一个正数。");
	}
	EXCEPTION_ALL_CATCH(CoreTools)

	return totalError;
}

void CoreTools::SuiteImpl
	::PrintReport()
{
	CORE_TOOLS_CLASS_IS_VALID_3;

	SuitePrintManager manager{ *this };

	manager.PrintCoreToolsHeader();

	for_each(m_UnitTestCollection.begin(), m_UnitTestCollection.end(), std::mem_fn(&UnitTestComposite::PrintReport));

	manager.PrintSuiteName();
	manager.PrintSuiteResult();
	manager.PrintCurrentTime();
}

void CoreTools::SuiteImpl
	::ClearUnitTestCollection() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_3;

	m_UnitTestCollection.clear();
}

void CoreTools::SuiteImpl
	::ResetTestData()
{
	CORE_TOOLS_CLASS_IS_VALID_3;

	for_each(m_UnitTestCollection.begin(), m_UnitTestCollection.end(), std::mem_fn(&UnitTestComposite::ResetTestData));
} 

void CoreTools::SuiteImpl
	::AddUnitTest(UnitTestPtr unitTest)
{
	CORE_TOOLS_CLASS_IS_VALID_3;
	CORE_TOOLS_ASSERTION_0(unitTest != nullptr, "指针无效");

	m_UnitTestCollection.push_back(unitTest);
	unitTest->ResetTestData();
}

const string CoreTools::SuiteImpl
	::GetName() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_3;

	return m_SuiteName;
}

void CoreTools::SuiteImpl
	::RunUnitTest()
{
	CORE_TOOLS_CLASS_IS_VALID_3;

	for_each(m_UnitTestCollection.begin(), m_UnitTestCollection.end(), [this](auto& value)
	{
		if (m_PrintRunUnitTest)
		{
			value->PrintRunUnitTest();
		}

		value->RunUnitTest();
	});
}

void CoreTools::SuiteImpl
	::PrintRunUnitTest()
{
	CORE_TOOLS_CLASS_IS_VALID_3;

	auto runSuite = "正在运行测试套件 \"" + GetName() + "\"。\n";

	GetStream().GetStream() << runSuite;
}












