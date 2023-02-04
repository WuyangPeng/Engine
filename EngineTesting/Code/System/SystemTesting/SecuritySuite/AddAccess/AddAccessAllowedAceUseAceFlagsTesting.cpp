///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/28 13:02)

#include "AddAccessAllowedAceUseAceFlagsTesting.h"
#include "System/Security/AddAccess.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AddAccessAllowedAceUseAceFlagsTesting::AddAccessAllowedAceUseAceFlagsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AddAccessAllowedAceUseAceFlagsTesting)

void System::AddAccessAllowedAceUseAceFlagsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AddAccessAllowedAceUseAceFlagsTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::AddAccessAllowedAceUseAceFlagsTesting::RandomShuffleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffle);

    ASSERT_NOT_THROW_EXCEPTION_1(AddAccessAllowedAccessControlEntriesTest, AccessControlListRevision::Revision);
    ASSERT_NOT_THROW_EXCEPTION_1(AddAccessAllowedAccessControlEntriesTest, AccessControlListRevision::RevisionDs);

    return true;
}

void System::AddAccessAllowedAceUseAceFlagsTesting::AddAccessAllowedAccessControlEntriesTest(AccessControlListRevision accessControlListRevision)
{
    auto aclBuffer = GetACLBuffer(accessControlListRevision);
    auto acl = GetAccessCheckACLPtr(aclBuffer);

    auto sid = GetSecuritySID();

    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        AddAccessTest(index, acl, accessControlListRevision, sid);
    }
}

void System::AddAccessAllowedAceUseAceFlagsTesting::AddAccessTest(size_t index, AccessCheckACLPtr acl, AccessControlListRevision accessControlListRevision, SecuritySID& sid)
{
    const auto controlACEInheritance = GetControlACEInheritance(index);
    const auto specificAccess = GetSpecificAccess(index);

    ASSERT_TRUE(AddAccessAllowedAccessControlEntries(acl, accessControlListRevision, controlACEInheritance, specificAccess, &sid));
}
