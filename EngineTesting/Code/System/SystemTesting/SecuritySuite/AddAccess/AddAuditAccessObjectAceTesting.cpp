///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/28 14:03)

#include "AddAuditAccessObjectAceTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/SecuritySidMacro.h"
#include "System/Security/AddAccess.h"
#include "System/Security/Flags/AddAccessFlags.h"
#include "System/Security/Flags/SecurityAceFlags.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "System/Security/SecurityAcl.h"
#include "System/Security/SecuritySid.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;
using std::max;
using std::vector;

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
    auto aclBuffer = GetACLBuffer(accessControlListRevision);
    auto acl = GetAccessCheckACLPtr(aclBuffer);

    auto sid = GetSecuritySID();

    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        AddAccessTest(index, acl, accessControlListRevision, sid);
    }
}

void System::AddAuditAccessObjectAceTesting::AddAccessTest(size_t index, AccessCheckACLPtr acl, AccessControlListRevision accessControlListRevision, SecuritySID& sid)
{
    const auto controlACEInheritance = GetControlACEInheritance(index);
    const auto specificAccess = GetSpecificAccess(index);

    ASSERT_TRUE(AddAuditAccessObjectAccessControlEntries(acl, accessControlListRevision, controlACEInheritance, specificAccess, nullptr, nullptr, &sid, false, true));
    ASSERT_TRUE(AddAuditAccessObjectAccessControlEntries(acl, accessControlListRevision, controlACEInheritance, specificAccess, nullptr, nullptr, &sid, true, true));
    ASSERT_TRUE(AddAuditAccessObjectAccessControlEntries(acl, accessControlListRevision, controlACEInheritance, specificAccess, nullptr, nullptr, &sid, false, false));
    ASSERT_TRUE(AddAuditAccessObjectAccessControlEntries(acl, accessControlListRevision, controlACEInheritance, specificAccess, nullptr, nullptr, &sid, true, false));
}
