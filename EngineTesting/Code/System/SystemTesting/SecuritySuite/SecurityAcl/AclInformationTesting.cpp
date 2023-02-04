///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/28 16:36)

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
    AccessCheckACL acl{};

    ASSERT_TRUE(InitializeAccessControlList(&acl, sizeof(AccessCheckACL), accessControlListRevision));
    ASSERT_TRUE(IsAccessControlListValid(&acl));

    SecurityAclRevisionInformation aclRevisionInformation{};
    ASSERT_TRUE(GetAccessControlListInformation(&acl, &aclRevisionInformation));

    SecurityAclSizeInformation aclSizeInformation{};
    ASSERT_TRUE(GetAccessControlListInformation(&acl, &aclSizeInformation));

    ASSERT_TRUE(SetAccessControlListInformation(&acl, &aclRevisionInformation));
}
