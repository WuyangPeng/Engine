///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:15)

#include "CoreTools/CoreToolsExport.h"

#include "Suite.h"
#include "UnitTest.h"
#include "Detail/SuiteImpl.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Suite::Suite(const std::string& name, const OStreamShared& streamShared, bool printRunUnitTest)
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

    if (this != &rhs)
    {
        impl = std::move(rhs.impl);
    }

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Suite)

std::string CoreTools::Suite::GetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetName();
}

int CoreTools::Suite::GetPassedNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetPassedNumber();
}

int CoreTools::Suite::GetFailedNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetFailedNumber();
}

int CoreTools::Suite::GetErrorNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetErrorNumber();
}

CoreTools::OStreamShared& CoreTools::Suite::GetStream() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->GetStream();
}

void CoreTools::Suite::PrintReport()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->PrintReport();
}

void CoreTools::Suite::RunUnitTest()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->RunUnitTest();
}

void CoreTools::Suite::ClearUnitTestCollection()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->ClearUnitTestCollection();
}

void CoreTools::Suite::ResetTestData()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->ResetTestData();
}

void CoreTools::Suite::AddTest(const UnitTestSharedPtr& unitTest)
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
