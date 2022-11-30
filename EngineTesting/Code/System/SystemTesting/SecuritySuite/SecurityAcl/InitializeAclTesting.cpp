///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/11/01 21:44)

#include "InitializeAclTesting.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "System/Security/SecurityAcl.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::InitializeAclTesting::InitializeAclTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, InitializeAclTesting)

void System::InitializeAclTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::InitializeAclTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RevisionInitializeAclTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RevisionDsInitializeAclTest);
}

void System::InitializeAclTesting::RevisionInitializeAclTest()
{
    AccessCheckACL acl{};

    ASSERT_TRUE(InitializeAccessControlList(&acl, sizeof(AccessCheckACL), AccessControlListRevision::Revision));
    ASSERT_TRUE(IsAccessControlListValid(&acl));
}

void System::InitializeAclTesting::RevisionDsInitializeAclTest()
{
    AccessCheckACL acl{};

    ASSERT_TRUE(InitializeAccessControlList(&acl, sizeof(AccessCheckACL), AccessControlListRevision::RevisionDs));
    ASSERT_TRUE(IsAccessControlListValid(&acl));
}
