///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/11/01 21:40)

#include "UserObjectSecurityTesting.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "System/Security/SecurityDescriptor.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::vector;

System::UserObjectSecurityTesting::UserObjectSecurityTesting(const OStreamShared& stream)
    : ParentType{ stream },
      securityRequestedInformationFlags{ SecurityRequestedInformation::Owner,
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
    for (auto requested : securityRequestedInformationFlags)
    {
        WindowsDWord lengthNeeded{ 0 };
        ASSERT_FALSE(GetUserObjectSystemSecurity(GetCurrentSystemThread(), requested, nullptr, 0, &lengthNeeded));

        ASSERT_LESS(0u, lengthNeeded);
        vector<char> buffer(lengthNeeded);

        WindowsDWord newLengthNeeded{ 0 };
        ASSERT_TRUE(GetUserObjectSystemSecurity(GetCurrentSystemThread(), requested, buffer.data(), lengthNeeded, &newLengthNeeded));

        ASSERT_EQUAL(newLengthNeeded, lengthNeeded);

        const auto length = GetSystemSecurityDescriptorLength(buffer.data());
        ASSERT_EQUAL(newLengthNeeded, length);

        ASSERT_TRUE(IsSecurityDescriptorValid(buffer.data()));
    }
}
