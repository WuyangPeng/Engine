///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/29 20:13)

#include "SecurityDescriptorResourceManagerControlTesting.h" 
#include "System/Security/SecurityDescriptor.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SecurityDescriptorResourceManagerControlTesting::SecurityDescriptorResourceManagerControlTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SecurityDescriptorResourceManagerControlTesting)

void System::SecurityDescriptorResourceManagerControlTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SecurityDescriptorResourceManagerControlTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ResourceManagerControlTest);
}

void System::SecurityDescriptorResourceManagerControlTesting::ResourceManagerControlTest()
{
    SecurityDescriptor securityDescriptor{};
    ASSERT_TRUE(InitializeSystemSecurityDescriptor(&securityDescriptor));

    WindowsUChar resourceManagerControl{ 0x1 };
    ASSERT_TRUE(SetSecurityDescriptorResourceManagerControl(&securityDescriptor, &resourceManagerControl));

    WindowsUChar resultResourceManagerControl{ 0 };
    ASSERT_TRUE(GetSecurityDescriptorResourceManagerControl(&securityDescriptor, &resultResourceManagerControl));

    ASSERT_EQUAL(resourceManagerControl, resultResourceManagerControl);
}
