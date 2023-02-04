///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/27 23:53)

#include "AddAccessAllowedAceTesting.h"
#include "System/Security/AddAccess.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "System/Security/SecurityAcl.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AddAccessAllowedAceTesting::AddAccessAllowedAceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AddAccessAllowedAceTesting)

void System::AddAccessAllowedAceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AddAccessAllowedAceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(AddAccessAllowedAccessControlEntriesTest, AccessControlListRevision::Revision);
    ASSERT_NOT_THROW_EXCEPTION_1(AddAccessAllowedAccessControlEntriesTest, AccessControlListRevision::RevisionDs);
}

void System::AddAccessAllowedAceTesting::AddAccessAllowedAccessControlEntriesTest(AccessControlListRevision accessControlListRevision)
{
    auto aclBuffer = GetACLBuffer(accessControlListRevision);
    auto acl = GetAccessCheckACLPtr(aclBuffer);

    auto sid = GetSecuritySID();

    for (auto iter = GetSpecificAccessBegin(); iter != GetSpecificAccessEnd(); ++iter)
    {
        AddAccessTest(acl, accessControlListRevision, *iter, sid);
    }
}

void System::AddAccessAllowedAceTesting::AddAccessTest(AccessCheckACLPtr acl, AccessControlListRevision accessControlListRevision, SpecificAccess specificAccess, SecuritySID& sid)
{
    ASSERT_TRUE(AddAccessAllowedAccessControlEntries(acl, accessControlListRevision, specificAccess, &sid));
}
