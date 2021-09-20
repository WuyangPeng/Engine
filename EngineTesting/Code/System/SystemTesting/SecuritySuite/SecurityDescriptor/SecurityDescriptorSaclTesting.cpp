///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/02 14:45)

#include "SecurityDescriptorSaclTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "System/Security/SecurityAcl.h"
#include "System/Security/SecurityDescriptor.h"
#include "System/Threading/Process.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::vector;

System::SecurityDescriptorSaclTesting::SecurityDescriptorSaclTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SecurityDescriptorSaclTesting)

void System::SecurityDescriptorSaclTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SecurityDescriptorSaclTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SaclTest);
}

void System::SecurityDescriptorSaclTesting::SaclTest()
{
    AccessCheckACL acl{};

    ASSERT_TRUE(InitializeAccessControlList(&acl, sizeof(AccessCheckACL), AccessControlListRevision::Revision));
    ASSERT_TRUE(IsAccessControlListValid(&acl));

    SecurityDescriptor securityDescriptor{};
    ASSERT_TRUE(InitializeSystemSecurityDescriptor(&securityDescriptor));
    ASSERT_TRUE(SetSecurityDescriptorSystemAccessControlList(&securityDescriptor, true, &acl, true));

    WindowsBool daclPresent{ g_False };
    AccessCheckACLPtr sacl{ nullptr };
    auto daclDefaulted = false;
    ASSERT_TRUE(GetSecurityDescriptorSystemAccessControlList(&securityDescriptor, &daclPresent, &sacl, &daclDefaulted));

    ASSERT_UNEQUAL_NULL_PTR(sacl);
}
