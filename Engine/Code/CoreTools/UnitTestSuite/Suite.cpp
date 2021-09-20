//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 14:48)

#include "CoreTools/CoreToolsExport.h"

#include "Suite.h"
#include "UnitTest.h"
#include "Detail/SuiteImpl.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::ostream;
using std::string;

CoreTools::Suite::Suite(const string& name, const OStreamShared& streamShared, bool printRunUnitTest)
    : impl{ make_shared<SuiteImpl>(name, streamShared, printRunUnitTest) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::Suite::Suite(Suite&& rhs) noexcept
    : impl{ std::move(rhs.impl) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::Suite& CoreTools::Suite::operator=(Suite&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    impl = std::move(rhs.impl);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Suite)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Suite, GetName, const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Suite, GetPassedNumber, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Suite, GetFailedNumber, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Suite, GetErrorNumber, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Suite, GetStream, CoreTools::OStreamShared&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Suite, PrintReport, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Suite, ClearUnitTestCollection, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Suite, RunUnitTest, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Suite, ResetTestData, void)

void CoreTools::Suite::AddTest(const UnitTestPtr& unitTest)
{
    CORE_TOOLS_CLASS_IS_VALID_1;
    CORE_TOOLS_ASSERTION_0(unitTest != nullptr, "指针无效");

    return impl->AddUnitTest(unitTest);
}

void CoreTools::Suite::AddSuite(const Suite& suite)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->AddUnitTest(suite.impl);
}
