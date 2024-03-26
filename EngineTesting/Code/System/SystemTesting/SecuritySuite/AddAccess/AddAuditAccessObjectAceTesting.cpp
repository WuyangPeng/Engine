/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 14:20)

#include "AddAuditAccessObjectAceTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/SecuritySidMacro.h"
#include "System/Security/AddAccess.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "System/Security/SecuritySid.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

System::AddAuditAccessObjectAceTesting::AddAuditAccessObjectAceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AddAuditAccessObjectAceTesting)

void System::AddAuditAccessObjectAceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AddAuditAccessObjectAceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffleFlags);
}

bool System::AddAuditAccessObjectAceTesting::RandomShuffleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffle);

    ASSERT_NOT_THROW_EXCEPTION_1(AddAuditAccessObjectAceTest, AccessControlListRevision::Revision);
    ASSERT_NOT_THROW_EXCEPTION_1(AddAuditAccessObjectAceTest, AccessControlListRevision::RevisionDs);

    return true;
}

void System::AddAuditAccessObjectAceTesting::AddAuditAccessObjectAceTest(AccessControlListRevision accessControlListRevision)
{
    auto aclBuffer = GetAclBuffer(accessControlListRevision);
    const auto acl = GetAccessCheckAclPtr(aclBuffer);

    auto sid = GetSecuritySid();

    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        AddAccessTest(index, acl, accessControlListRevision, sid);
    }
}

void System::AddAuditAccessObjectAceTesting::AddAccessTest(size_t index, AccessCheckAclPtr acl, AccessControlListRevision accessControlListRevision, SecuritySid& sid)
{
    const auto controlAceInheritance = GetControlAceInheritance(index);
    const auto specificAccess = GetSpecificAccess(index);

    ASSERT_TRUE(AddAuditAccessObjectAccessControlEntries(acl, accessControlListRevision, controlAceInheritance, specificAccess, nullptr, nullptr, &sid, false, true));
    ASSERT_TRUE(AddAuditAccessObjectAccessControlEntries(acl, accessControlListRevision, controlAceInheritance, specificAccess, nullptr, nullptr, &sid, true, true));
    ASSERT_TRUE(AddAuditAccessObjectAccessControlEntries(acl, accessControlListRevision, controlAceInheritance, specificAccess, nullptr, nullptr, &sid, false, false));
    ASSERT_TRUE(AddAuditAccessObjectAccessControlEntries(acl, accessControlListRevision, controlAceInheritance, specificAccess, nullptr, nullptr, &sid, true, false));
}
