/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 14:31)

#include "UserObjectSecurityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "System/Security/SecurityDescriptor.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::UserObjectSecurityTesting::UserObjectSecurityTesting(const OStreamShared& stream)
    : ParentType{ stream },
      securityRequestedInformationContainer{ SecurityRequestedInformation::Owner,
                                             SecurityRequestedInformation::Group,
                                             SecurityRequestedInformation::Dacl,
                                             SecurityRequestedInformation::Label }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, UserObjectSecurityTesting)

void System::UserObjectSecurityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::UserObjectSecurityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(UserObjectSecurityTest);
}

void System::UserObjectSecurityTesting::UserObjectSecurityTest()
{
    for (auto requested : securityRequestedInformationContainer)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoUserObjectSecurityTest, requested);
    }
}

void System::UserObjectSecurityTesting::DoUserObjectSecurityTest(SecurityRequestedInformation requested)
{
    auto buffer = GetUserObjectSecurity(requested);

    const auto length = GetSystemSecurityDescriptorLength(buffer.data());
    ASSERT_EQUAL(buffer.size(), length);

    ASSERT_TRUE(IsSecurityDescriptorValid(buffer.data()));
}
