///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:02)

#include "SecurityAccessMaskTesting.h"
#include "System/Security/CreateSecurity.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SecurityAccessMaskTesting::SecurityAccessMaskTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SecurityAccessMaskTesting)

void System::SecurityAccessMaskTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SecurityAccessMaskTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetSecurityAccessMaskTest);
}

void System::SecurityAccessMaskTesting::SetSecurityAccessMaskTest()
{
    for (auto securityRequestedInformation : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoSetSecurityAccessMaskTest, securityRequestedInformation);
    }
}

void System::SecurityAccessMaskTesting::DoSetSecurityAccessMaskTest(SecurityRequestedInformation securityRequestedInformation)
{
    WindowsDWord desiredAccess{ 0 };

    SetSystemSecurityAccessMask(securityRequestedInformation, &desiredAccess);

    ASSERT_UNEQUAL(0u, desiredAccess);
}
