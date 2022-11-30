///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/11/01 21:38)

#include "SecurityDescriptorDaclTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "System/Security/SecurityDescriptor.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::vector;

System::SecurityDescriptorDaclTesting::SecurityDescriptorDaclTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SecurityDescriptorDaclTesting)

void System::SecurityDescriptorDaclTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SecurityDescriptorDaclTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DaclTest);
}

void System::SecurityDescriptorDaclTesting::DaclTest()
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

    WindowsBool daclPresent{ gFalse };
    AccessCheckACLPtr dacl{ nullptr };
    auto daclDefaulted = false;
    ASSERT_TRUE(GetSecurityDescriptorDiscretionaryAccessControlList(buffer.data(), &daclPresent, &dacl, &daclDefaulted));

    ASSERT_UNEQUAL_NULL_PTR(dacl);

    ASSERT_TRUE(SetSecurityDescriptorDiscretionaryAccessControlList(&securityDescriptor, false, dacl, false));
}
