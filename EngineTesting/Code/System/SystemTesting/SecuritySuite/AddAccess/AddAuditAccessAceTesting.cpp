///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/28 13:56)

#include "AddAuditAccessAceTesting.h"
#include "System/Security/AddAccess.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AddAuditAccessAceTesting::AddAuditAccessAceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AddAuditAccessAceTesting)

void System::AddAuditAccessAceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AddAuditAccessAceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffleFlags);
}

bool System::AddAuditAccessAceTesting::RandomShuffleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffle);

    ASSERT_NOT_THROW_EXCEPTION_1(AddAuditAccessAceTest, AccessControlListRevision::Revision);
    ASSERT_NOT_THROW_EXCEPTION_1(AddAuditAccessAceTest, AccessControlListRevision::RevisionDs);

    return true;
}

void System::AddAuditAccessAceTesting::AddAuditAccessAceTest(AccessControlListRevision accessControlListRevision)
{
    auto aclBuffer = GetACLBuffer(accessControlListRevision);
    auto acl = GetAccessCheckACLPtr(aclBuffer);

    auto sid = GetSecuritySID();

    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        AddAccessTest(index, acl, accessControlListRevision, sid);
    }
}

void System::AddAuditAccessAceTesting::AddAccessTest(size_t index, AccessCheckACLPtr acl, AccessControlListRevision accessControlListRevision, SecuritySID& sid)
{
    const auto controlACEInheritance = GetControlACEInheritance(index);
    const auto specificAccess = GetSpecificAccess(index);

    ASSERT_TRUE(AddAuditAccessAccessControlEntries(acl, accessControlListRevision, specificAccess, &sid, true, false));
    ASSERT_TRUE(AddAuditAccessAccessControlEntries(acl, accessControlListRevision, specificAccess, &sid, true, true));
    ASSERT_TRUE(AddAuditAccessAccessControlEntries(acl, accessControlListRevision, specificAccess, &sid, false, false));
    ASSERT_TRUE(AddAuditAccessAccessControlEntries(acl, accessControlListRevision, specificAccess, &sid, false, true));

    ASSERT_TRUE(AddAuditAccessAccessControlEntries(acl, accessControlListRevision, controlACEInheritance, specificAccess, &sid, true, true));
    ASSERT_TRUE(AddAuditAccessAccessControlEntries(acl, accessControlListRevision, controlACEInheritance, specificAccess, &sid, true, false));
    ASSERT_TRUE(AddAuditAccessAccessControlEntries(acl, accessControlListRevision, controlACEInheritance, specificAccess, &sid, false, true));
    ASSERT_TRUE(AddAuditAccessAccessControlEntries(acl, accessControlListRevision, controlACEInheritance, specificAccess, &sid, false, false));
}
