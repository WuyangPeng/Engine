///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 13:57)

#include "AddAccessAllowedAceTesting.h"
#include "System/Security/AddAccess.h"
#include "System/Security/Flags/SecurityAclFlags.h"
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
    auto aclBuffer = GetAclBuffer(accessControlListRevision);
    const auto acl = GetAccessCheckAclPtr(aclBuffer);

    auto sid = GetSecuritySid();

    for (auto iter = GetSpecificAccessBegin(); iter != GetSpecificAccessEnd(); ++iter)
    {
        AddAccessTest(acl, accessControlListRevision, *iter, sid);
    }
}

void System::AddAccessAllowedAceTesting::AddAccessTest(AccessCheckAclPtr acl, AccessControlListRevision accessControlListRevision, SpecificAccess specificAccess, SecuritySid& sid)
{
    ASSERT_TRUE(AddAccessAllowedAccessControlEntries(acl, accessControlListRevision, specificAccess, &sid));
}
