/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 14:22)

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
