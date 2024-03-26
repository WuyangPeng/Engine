/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 14:26)

#include "InitializeAclTesting.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "System/Security/SecurityAcl.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::InitializeAclTesting::InitializeAclTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, InitializeAclTesting)

void System::InitializeAclTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::InitializeAclTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(RevisionInitializeAclTest, AccessControlListRevision::Revision);
    ASSERT_NOT_THROW_EXCEPTION_1(RevisionInitializeAclTest, AccessControlListRevision::RevisionDs);
}

void System::InitializeAclTesting::RevisionInitializeAclTest(AccessControlListRevision accessControlListRevision)
{
    AccessCheckAcl acl{};

    ASSERT_TRUE(InitializeAccessControlList(&acl, sizeof(AccessCheckAcl), accessControlListRevision));
    ASSERT_TRUE(IsAccessControlListValid(&acl));
}
