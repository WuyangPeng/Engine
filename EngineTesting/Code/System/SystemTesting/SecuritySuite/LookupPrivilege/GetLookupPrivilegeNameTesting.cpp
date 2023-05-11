///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/25 11:53)

#include "GetLookupPrivilegeNameTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Security/Flags/LookupPrivilegeNameFlags.h"
#include "System/Security/LookupPrivilege.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetLookupPrivilegeNameTesting::GetLookupPrivilegeNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetLookupPrivilegeNameTesting)

void System::GetLookupPrivilegeNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetLookupPrivilegeNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetLookupPrivilegeNameTest);
}

void System::GetLookupPrivilegeNameTesting::GetLookupPrivilegeNameTest()
{
    for (const auto& lookupPrivilegeName : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoGetLookupPrivilegeNameTest, lookupPrivilegeName);
    }
}

void System::GetLookupPrivilegeNameTesting::DoGetLookupPrivilegeNameTest(const String& lookupPrivilegeName)
{
    LookupPrivilegeLUID uid{};
    ASSERT_TRUE(GetLookupPrivilegeValue(nullptr, lookupPrivilegeName.c_str(), &uid));

    BufferType buffer{};
    auto size = boost::numeric_cast<WindowsDWord>(bufferSize);
    ASSERT_TRUE(GetLookupPrivilegeName(nullptr, &uid, buffer.data(), &size));

    String resultLookupPrivilegeName{ buffer.data() };

    ASSERT_EQUAL(size, resultLookupPrivilegeName.size());
    ASSERT_EQUAL(resultLookupPrivilegeName, lookupPrivilegeName);
}