///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:09)

#include "SecurityDescriptorDiscretionaryAccessControlListTesting.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "System/Security/SecurityDescriptor.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SecurityDescriptorDiscretionaryAccessControlListTesting::SecurityDescriptorDiscretionaryAccessControlListTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SecurityDescriptorDiscretionaryAccessControlListTesting)

void System::SecurityDescriptorDiscretionaryAccessControlListTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SecurityDescriptorDiscretionaryAccessControlListTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DiscretionaryAccessControlListTest);
}

void System::SecurityDescriptorDiscretionaryAccessControlListTesting::DiscretionaryAccessControlListTest()
{
    auto buffer = GetUserObjectSecurity(SecurityRequestedInformation::Dacl);

    AccessCheckAclPtr dacl{ nullptr };
    auto daclPresent = false;
    auto daclDefaulted = false;
    ASSERT_TRUE(GetSecurityDescriptorDiscretionaryAccessControlList(buffer.data(), &daclPresent, &dacl, &daclDefaulted));

    ASSERT_UNEQUAL_NULL_PTR(dacl);

    SecurityDescriptor securityDescriptor{};
    ASSERT_TRUE(InitializeSystemSecurityDescriptor(&securityDescriptor));

    ASSERT_TRUE(SetSecurityDescriptorDiscretionaryAccessControlList(&securityDescriptor, false, dacl, false));
}
