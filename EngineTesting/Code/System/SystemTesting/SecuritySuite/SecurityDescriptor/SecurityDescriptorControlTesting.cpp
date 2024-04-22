/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 14:30)

#include "SecurityDescriptorControlTesting.h"
#include "System/Security/Flags/SecurityDescriptorFlags.h"
#include "System/Security/SecurityDescriptor.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SecurityDescriptorControlTesting::SecurityDescriptorControlTesting(const OStreamShared& stream)
    : ParentType{ stream },
      securityDescriptorControlBitsContainer{ SecurityDescriptorControlBits::DaclAutoInheritReq,
                                              SecurityDescriptorControlBits::SaclAutoInheritReq,
                                              SecurityDescriptorControlBits::DaclAutoInherited,
                                              SecurityDescriptorControlBits::SaclAutoInherited,
                                              SecurityDescriptorControlBits::DaclProtected,
                                              SecurityDescriptorControlBits::SaclProtected }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SecurityDescriptorControlTesting)

void System::SecurityDescriptorControlTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SecurityDescriptorControlTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ControlTest);
}

void System::SecurityDescriptorControlTesting::ControlTest()
{
    SecurityDescriptor securityDescriptor;
    ASSERT_TRUE(InitializeSystemSecurityDescriptor(&securityDescriptor));

    for (auto bits : securityDescriptorControlBitsContainer)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoControlTest, securityDescriptor, bits);
    }
}

void System::SecurityDescriptorControlTesting::DoControlTest(SecurityDescriptor& securityDescriptor, SecurityDescriptorControlBits bits)
{
    ASSERT_TRUE(SetSystemSecurityDescriptorControl(&securityDescriptor, bits, bits));

    auto result = SecurityDescriptorControlBits::Clear;

    WindowsDWord revision{ 0 };
    ASSERT_TRUE(GetSystemSecurityDescriptorControl(&securityDescriptor, &result, &revision));
    ASSERT_EQUAL(result, bits);

    ASSERT_TRUE(SetSystemSecurityDescriptorControl(&securityDescriptor, bits, SecurityDescriptorControlBits::Clear));

    ASSERT_TRUE(GetSystemSecurityDescriptorControl(&securityDescriptor, &result, &revision));
    ASSERT_EQUAL(result, SecurityDescriptorControlBits::Clear);
}
