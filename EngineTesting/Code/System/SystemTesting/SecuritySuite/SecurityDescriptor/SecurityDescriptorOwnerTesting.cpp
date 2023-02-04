///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/29 20:12)

#include "SecurityDescriptorOwnerTesting.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "System/Security/SecurityDescriptor.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
    auto buffer = GetUserObjectSecurity(SecurityRequestedInformation::Dacl);

    SecuritySIDPtr owner{ nullptr };
    auto ownerDefaulted = false;
    ASSERT_TRUE(GetSystemSecurityDescriptorOwner(buffer.data(), &owner, &ownerDefaulted));

    SecurityDescriptor securityDescriptor{};
    ASSERT_TRUE(InitializeSystemSecurityDescriptor(&securityDescriptor));

    ASSERT_TRUE(SetSystemSecurityDescriptorOwner(&securityDescriptor, owner, false));
}
