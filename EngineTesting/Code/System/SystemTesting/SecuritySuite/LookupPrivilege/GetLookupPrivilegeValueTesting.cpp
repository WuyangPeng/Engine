///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:02)

#include "GetLookupPrivilegeValueTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Security/Flags/LookupPrivilegeNameFlags.h"
#include "System/Security/LookupPrivilege.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetLookupPrivilegeValueTesting::GetLookupPrivilegeValueTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetLookupPrivilegeValueTesting)

void System::GetLookupPrivilegeValueTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetLookupPrivilegeValueTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetLookupPrivilegeValueTest);
}

void System::GetLookupPrivilegeValueTesting::GetLookupPrivilegeValueTest()
{
    for (const auto& lookupPrivilegeName : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoGetLookupPrivilegeValueTesting, lookupPrivilegeName);
    }
}

void System::GetLookupPrivilegeValueTesting::DoGetLookupPrivilegeValueTesting(const String& lookupPrivilegeName)
{
    LookupPrivilegeLuid uid{};

    ASSERT_TRUE(GetLookupPrivilegeValue(nullptr, lookupPrivilegeName.c_str(), &uid));

    ASSERT_LESS(0u, uid.LowPart);
}
