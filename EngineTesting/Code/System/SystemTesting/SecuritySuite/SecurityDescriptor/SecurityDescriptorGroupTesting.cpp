/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 14:30)

#include "SecurityDescriptorGroupTesting.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "System/Security/SecurityDescriptor.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
    auto buffer = GetUserObjectSecurity(SecurityRequestedInformation::Dacl);

    SecuritySidPtr group{ nullptr };
    auto groupDefaulted = false;
    ASSERT_TRUE(GetSystemSecurityDescriptorGroup(buffer.data(), &group, &groupDefaulted));

    SecurityDescriptor securityDescriptor{};
    ASSERT_TRUE(InitializeSystemSecurityDescriptor(&securityDescriptor));

    ASSERT_TRUE(SetSystemSecurityDescriptorGroup(&securityDescriptor, group, false));
}
