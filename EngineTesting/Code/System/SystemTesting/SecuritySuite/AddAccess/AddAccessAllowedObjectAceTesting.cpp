/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:47)

#include "AddAccessAllowedObjectAceTesting.h"
#include "System/Security/AddAccess.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AddAccessAllowedObjectAceTesting::AddAccessAllowedObjectAceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AddAccessAllowedObjectAceTesting)

void System::AddAccessAllowedObjectAceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AddAccessAllowedObjectAceTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::AddAccessAllowedObjectAceTesting::RandomShuffleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffle);

    ASSERT_NOT_THROW_EXCEPTION_1(AddAccessAllowedObjectAceTest, AccessControlListRevision::Revision);
    ASSERT_NOT_THROW_EXCEPTION_1(AddAccessAllowedObjectAceTest, AccessControlListRevision::RevisionDs);

    return true;
}

void System::AddAccessAllowedObjectAceTesting::AddAccessAllowedObjectAceTest(AccessControlListRevision accessControlListRevision)
{
    auto aclBuffer = GetAclBuffer(accessControlListRevision);
    const auto acl = GetAccessCheckAclPtr(aclBuffer);

    auto sid = GetSecuritySid();

    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        AddAccessTest(index, acl, accessControlListRevision, sid);
    }
}

void System::AddAccessAllowedObjectAceTesting::AddAccessTest(size_t index, AccessCheckAclPtr acl, AccessControlListRevision accessControlListRevision, SecuritySid& sid)
{
    const auto controlAceInheritance = GetControlAceInheritance(index);
    const auto specificAccess = GetSpecificAccess(index);

    ASSERT_TRUE(AddAccessAllowedObjectAccessControlEntries(acl, accessControlListRevision, controlAceInheritance, specificAccess, nullptr, nullptr, &sid));
}
