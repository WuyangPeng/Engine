/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 14:26)

#include "AclInformationTesting.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "System/Security/SecurityAcl.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AclInformationTesting::AclInformationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AclInformationTesting)

void System::AclInformationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AclInformationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(InformationTest, AccessControlListRevision::Revision);
    ASSERT_NOT_THROW_EXCEPTION_1(InformationTest, AccessControlListRevision::RevisionDs);
}

void System::AclInformationTesting::InformationTest(AccessControlListRevision accessControlListRevision)
{
    AccessCheckAcl acl{};

    ASSERT_TRUE(InitializeAccessControlList(&acl, sizeof(AccessCheckAcl), accessControlListRevision));
    ASSERT_TRUE(IsAccessControlListValid(&acl));

    SecurityAclRevisionInformation aclRevisionInformation{};
    ASSERT_TRUE(GetAccessControlListInformation(&acl, &aclRevisionInformation));

    SecurityAclSizeInformation aclSizeInformation{};
    ASSERT_TRUE(GetAccessControlListInformation(&acl, &aclSizeInformation));

    ASSERT_TRUE(SetAccessControlListInformation(&acl, &aclRevisionInformation));
}
