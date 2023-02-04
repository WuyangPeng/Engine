///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/28 16:00)

#include "FindFirstFreeAccessControlEntriesTesting.h"
#include "System/Security/SecurityAce.h"
#include "System/Security/SecurityAcl.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FindFirstFreeAccessControlEntriesTesting::FindFirstFreeAccessControlEntriesTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FindFirstFreeAccessControlEntriesTesting)

void System::FindFirstFreeAccessControlEntriesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FindFirstFreeAccessControlEntriesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FindFirstFreeAccessControlEntriesTest);
}

void System::FindFirstFreeAccessControlEntriesTesting::FindFirstFreeAccessControlEntriesTest()
{
    auto buffer = GetUserObjectSecurity();

    auto dacl = GetDacl(buffer);
    SecurityAclSizeInformation aclSizeInformation{};
    ASSERT_TRUE(GetAccessControlListInformation(dacl, &aclSizeInformation));

    auto aclbuffer = GetACL(buffer, aclSizeInformation.AclBytesInUse);

    WindowsVoidPtr ace{ nullptr };
    ASSERT_TRUE(FindFirstFreeAccessControlEntries(GetAccessCheckACLPtr(aclbuffer), &ace));
}
