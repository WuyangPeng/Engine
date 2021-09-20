///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/06/02 14:36)

#include "SecurityDescriptorGroupTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "System/Security/SecurityDescriptor.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::vector;

System::SecurityDescriptorGroupTesting::SecurityDescriptorGroupTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SecurityDescriptorGroupTesting)

void System::SecurityDescriptorGroupTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SecurityDescriptorGroupTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GroupTest);
}

void System::SecurityDescriptorGroupTesting::GroupTest()
{
    WindowsDWord lengthNeeded{ 0 };
    ASSERT_FALSE(GetUserObjectSystemSecurity(GetCurrentSystemThread(), SecurityRequestedInformation::Dacl, nullptr, 0, &lengthNeeded));

    ASSERT_LESS(0u, lengthNeeded);
    vector<char> buffer(lengthNeeded);

    WindowsDWord newLengthNeeded{ 0 };
    ASSERT_TRUE(GetUserObjectSystemSecurity(GetCurrentSystemThread(), SecurityRequestedInformation::Dacl, buffer.data(), lengthNeeded, &newLengthNeeded));

    ASSERT_EQUAL(newLengthNeeded, lengthNeeded);

    SecurityDescriptor securityDescriptor{};
    ASSERT_TRUE(InitializeSystemSecurityDescriptor(&securityDescriptor));

    SecuritySIDPtr group{ nullptr };
    auto groupDefaulted = false;
    ASSERT_TRUE(GetSystemSecurityDescriptorGroup(buffer.data(), &group, &groupDefaulted));
    ASSERT_TRUE(SetSystemSecurityDescriptorGroup(&securityDescriptor, group, false));
}
