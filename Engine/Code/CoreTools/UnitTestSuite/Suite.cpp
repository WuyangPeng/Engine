// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 10:21)

#include "CoreTools/CoreToolsExport.h"

#include "Suite.h"
#include "UnitTest.h"
#include "Detail/SuiteImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::ostream;
using std::make_shared;

CoreTools::Suite
	::Suite(const string& name, ostream* osPtr, bool printRunUnitTest)
	:m_Impl{ make_shared<SuiteImpl>(name,osPtr,printRunUnitTest) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, Suite)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Suite, GetName, const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Suite, GetPassedNumber, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Suite, GetFailedNumber, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Suite, GetErrorNumber, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Suite, GetStream, ostream*)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Suite, PrintReport, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Suite, ClearUnitTestCollection, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Suite, RunUnitTest, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Suite, ResetTestData, void)

void CoreTools::Suite
	::SetStream(ostream* osPtr)
{
	CORE_TOOLS_CLASS_IS_VALID_1;
	CORE_TOOLS_ASSERTION_0(osPtr != nullptr, "指针无效");

	return m_Impl->SetStream(osPtr);
}

void CoreTools::Suite
	::AddTest(const UnitTestPtr& unitTest)
{
	CORE_TOOLS_CLASS_IS_VALID_1;
	CORE_TOOLS_ASSERTION_0(unitTest != nullptr, "指针无效");

	return m_Impl->AddUnitTest(unitTest);
}

void CoreTools::Suite
	::AddSuite(const Suite& suite)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return m_Impl->AddUnitTest(suite.m_Impl);
}
