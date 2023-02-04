///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/29 20:16)

#include "SecurityDescriptorSystemAccessControlListTesting.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "System/Security/SecurityAcl.h"
#include "System/Security/SecurityDescriptor.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SecurityDescriptorSystemAccessControlListTesting::SecurityDescriptorSystemAccessControlListTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SecurityDescriptorSystemAccessControlListTesting)

void System::SecurityDescriptorSystemAccessControlListTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SecurityDescriptorSystemAccessControlListTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SystemAccessControlListTest);
}

void System::SecurityDescriptorSystemAccessControlListTesting::SystemAccessControlListTest()
{
    AccessCheckACL acl{};

    ASSERT_TRUE(InitializeAccessControlList(&acl, sizeof(AccessCheckACL), AccessControlListRevision::Revision));
    ASSERT_TRUE(IsAccessControlListValid(&acl));

    SecurityDescriptor securityDescriptor{};
    ASSERT_TRUE(InitializeSystemSecurityDescriptor(&securityDescriptor));
    ASSERT_TRUE(SetSecurityDescriptorSystemAccessControlList(&securityDescriptor, true, &acl, true));

    auto daclPresent = false;
    AccessCheckACLPtr sacl{ nullptr };
    auto daclDefaulted = false;
    ASSERT_TRUE(GetSecurityDescriptorSystemAccessControlList(&securityDescriptor, &daclPresent, &sacl, &daclDefaulted));

    ASSERT_UNEQUAL_NULL_PTR(sacl);
}
