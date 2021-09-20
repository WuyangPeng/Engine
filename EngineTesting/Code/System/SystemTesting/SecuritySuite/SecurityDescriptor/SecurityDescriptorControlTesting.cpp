///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/06/02 14:32)

#include "SecurityDescriptorControlTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Security/Flags/SecurityDescriptorFlags.h"
#include "System/Security/SecurityDescriptor.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::vector;

System::SecurityDescriptorControlTesting::SecurityDescriptorControlTesting(const OStreamShared& stream)
    : ParentType{ stream },
      securityDescriptorControlBitsFlags{ SecurityDescriptorControlBits::DaclAutoInheritReq,
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

    for (auto bits : securityDescriptorControlBitsFlags)
    {
        ASSERT_TRUE(SetSystemSecurityDescriptorControl(&securityDescriptor, bits, bits));

        auto result = SecurityDescriptorControlBits::Clear;

        WindowsDWord revision{ 0 };
        ASSERT_TRUE(GetSystemSecurityDescriptorControl(&securityDescriptor, &result, &revision));
        ASSERT_ENUM_EQUAL(result, bits);

        ASSERT_TRUE(SetSystemSecurityDescriptorControl(&securityDescriptor, bits, SecurityDescriptorControlBits::Clear));

        ASSERT_TRUE(GetSystemSecurityDescriptorControl(&securityDescriptor, &result, &revision));
        ASSERT_ENUM_EQUAL(result, SecurityDescriptorControlBits::Clear);
    }
}