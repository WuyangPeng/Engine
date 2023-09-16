///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:02)

#include "AddAccessControlEntriesTesting.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "System/Security/SecurityAce.h"
#include "System/Security/SecurityAcl.h"
#include "System/Security/Using/SecurityAceUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AddAccessControlEntriesTesting::AddAccessControlEntriesTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AddAccessControlEntriesTesting)

void System::AddAccessControlEntriesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AddAccessControlEntriesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetAccessControlEntriesTest);
}

void System::AddAccessControlEntriesTesting::GetAccessControlEntriesTest()
{
    auto buffer = GetUserObjectSecurity();

    const auto dacl = GetDacl(buffer);
    SecurityAclSizeInformation aclSizeInformation{};
    ASSERT_TRUE(GetAccessControlListInformation(dacl, &aclSizeInformation));

    auto aclBuffer = GetAcl(buffer, aclSizeInformation.AclBytesInUse);

    ASSERT_NOT_THROW_EXCEPTION_3(ResultTest, aclSizeInformation, dacl, GetAccessCheckAclPtr(aclBuffer));
}

void System::AddAccessControlEntriesTesting::ResultTest(const SecurityAclSizeInformation& aclSizeInformation, AccessCheckAclPtr dacl, AccessCheckAclPtr acl)
{
    WindowsVoidPtr ace{ nullptr };

    for (auto i = 0u; i < aclSizeInformation.AceCount; ++i)
    {
        ASSERT_TRUE(GetAccessControlEntries(dacl, i, &ace));

        ASSERT_TRUE(AddAccessControlEntries(acl, AccessControlListRevision::Revision, gMaxDWord, ace, static_cast<AceHeaderPtr>(ace)->AceSize));

        ASSERT_EQUAL(acl->AceCount, i + 1);
    }

    for (auto i = 0u; i < aclSizeInformation.AceCount; ++i)
    {
        ASSERT_TRUE(DeleteAccessControlEntries(acl, aclSizeInformation.AceCount - i - 1));

        ASSERT_EQUAL(acl->AceCount, aclSizeInformation.AceCount - i - 1);
    }
}
