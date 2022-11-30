///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/11/01 21:38)

#include "SecurityDescriptorOwnerTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "System/Security/SecurityDescriptor.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::vector;

System::SecurityDescriptorOwnerTesting::SecurityDescriptorOwnerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SecurityDescriptorOwnerTesting)

void System::SecurityDescriptorOwnerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SecurityDescriptorOwnerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OwnerTest);
}

void System::SecurityDescriptorOwnerTesting::OwnerTest()
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

    SecuritySIDPtr owner{ nullptr };
    auto ownerDefaulted = false;
    ASSERT_TRUE(GetSystemSecurityDescriptorOwner(buffer.data(), &owner, &ownerDefaulted));
    ASSERT_TRUE(SetSystemSecurityDescriptorOwner(&securityDescriptor, owner, false));
}
