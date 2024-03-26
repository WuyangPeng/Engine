/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 14:19)

#include "AddAccessDeniedAceTesting.h"
#include "System/Security/AddAccess.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AddAccessDeniedAceTesting::AddAccessDeniedAceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AddAccessDeniedAceTesting)

void System::AddAccessDeniedAceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AddAccessDeniedAceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffleFlags);
}

bool System::AddAccessDeniedAceTesting::RandomShuffleFlags()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffle);

    ASSERT_NOT_THROW_EXCEPTION_1(AddAccessDeniedAceTest, AccessControlListRevision::Revision);
    ASSERT_NOT_THROW_EXCEPTION_1(AddAccessDeniedAceTest, AccessControlListRevision::RevisionDs);

    return true;
}

void System::AddAccessDeniedAceTesting::AddAccessDeniedAceTest(AccessControlListRevision accessControlListRevision)
{
    auto aclBuffer = GetAclBuffer(accessControlListRevision);
    const auto acl = GetAccessCheckAclPtr(aclBuffer);

    auto sid = GetSecuritySid();

    for (auto index = 0u; index < GetMaxSize(); ++index)
    {
        AddAccessTest(index, acl, accessControlListRevision, sid);
    }
}

void System::AddAccessDeniedAceTesting::AddAccessTest(size_t index, AccessCheckAclPtr acl, AccessControlListRevision accessControlListRevision, SecuritySid& sid)
{
    const auto controlAceInheritance = GetControlAceInheritance(index);
    const auto specificAccess = GetSpecificAccess(index);

    ASSERT_TRUE(AddAccessDeniedAccessControlEntries(acl, accessControlListRevision, specificAccess, &sid));
    ASSERT_TRUE(AddAccessDeniedAccessControlEntries(acl, accessControlListRevision, controlAceInheritance, specificAccess, &sid));
}
