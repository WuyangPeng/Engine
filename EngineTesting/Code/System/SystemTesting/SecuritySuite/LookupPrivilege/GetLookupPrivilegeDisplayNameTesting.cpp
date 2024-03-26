/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 14:22)

#include "GetLookupPrivilegeDisplayNameTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Security/LookupPrivilege.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetLookupPrivilegeDisplayNameTesting::GetLookupPrivilegeDisplayNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetLookupPrivilegeDisplayNameTesting)

void System::GetLookupPrivilegeDisplayNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetLookupPrivilegeDisplayNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetLookupPrivilegeDisplayNameTest);
}

void System::GetLookupPrivilegeDisplayNameTesting::GetLookupPrivilegeDisplayNameTest()
{
    for (const auto& lookupPrivilegeName : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoGetLookupPrivilegeDisplayNameTest, lookupPrivilegeName);
    }
}

void System::GetLookupPrivilegeDisplayNameTesting::DoGetLookupPrivilegeDisplayNameTest(const String& lookupPrivilegeName)
{
    TCharBufferType buffer{};

    WindowsDWord languageId{ 0 };
    auto size = boost::numeric_cast<WindowsDWord>(defaultBufferSize);
    ASSERT_TRUE(GetLookupPrivilegeDisplayName(nullptr, lookupPrivilegeName.c_str(), buffer.data(), &size, &languageId));

    const String resultLookupPrivilegeDisplayName{ buffer.data() };

    ASSERT_EQUAL(size, resultLookupPrivilegeDisplayName.size());
}
