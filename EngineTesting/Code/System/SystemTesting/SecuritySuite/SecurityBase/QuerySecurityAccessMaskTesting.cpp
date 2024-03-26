/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 14:29)

#include "QuerySecurityAccessMaskTesting.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "System/Security/SecurityBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::QuerySecurityAccessMaskTesting::QuerySecurityAccessMaskTesting(const OStreamShared& stream)
    : ParentType{ stream },
      securityRequestedInformationContainer{ SecurityRequestedInformation::Owner,
                                             SecurityRequestedInformation::Group,
                                             SecurityRequestedInformation::Dacl,
                                             SecurityRequestedInformation::Sacl,
                                             SecurityRequestedInformation::Label }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, QuerySecurityAccessMaskTesting)

void System::QuerySecurityAccessMaskTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::QuerySecurityAccessMaskTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySecurityAccessMaskTest);
}

void System::QuerySecurityAccessMaskTesting::QuerySecurityAccessMaskTest()
{
    for (auto securityRequestedInformation : securityRequestedInformationContainer)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoQuerySecurityAccessMaskTest, securityRequestedInformation);
    }
}

void System::QuerySecurityAccessMaskTesting::DoQuerySecurityAccessMaskTest(SecurityRequestedInformation securityRequestedInformation)
{
    WindowsDWord desiredAccess{ 0 };

    QuerySystemSecurityAccessMask(securityRequestedInformation, &desiredAccess);
    ASSERT_LESS(0u, desiredAccess);
}
