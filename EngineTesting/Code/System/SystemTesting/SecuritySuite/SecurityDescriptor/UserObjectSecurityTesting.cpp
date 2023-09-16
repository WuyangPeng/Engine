///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:10)

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
