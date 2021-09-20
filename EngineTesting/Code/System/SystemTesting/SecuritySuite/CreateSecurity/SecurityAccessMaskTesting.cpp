///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/05/30 0:29)

#include "SecurityAccessMaskTesting.h"
#include "System/Security/CreateSecurity.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SecurityAccessMaskTesting::SecurityAccessMaskTesting(const OStreamShared& stream)
    : ParentType{ stream },
      securityRequestedInformationFlags{ SecurityRequestedInformation::Owner,
                                         SecurityRequestedInformation::Group,
                                         SecurityRequestedInformation::Dacl,
                                         SecurityRequestedInformation::Label,
                                         SecurityRequestedInformation::Sacl }
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
    for (auto securityRequestedInformation : securityRequestedInformationFlags)
    {
        WindowsDWord desiredAccess{ 0 };

        SetSystemSecurityAccessMask(securityRequestedInformation, &desiredAccess);

        ASSERT_UNEQUAL(0u, desiredAccess);
    }
}
