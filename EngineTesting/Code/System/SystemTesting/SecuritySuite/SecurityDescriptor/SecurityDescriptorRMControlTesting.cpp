///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/02 14:44)

#include "SecurityDescriptorRMControlTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Security/SecurityDescriptor.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::vector;

System::SecurityDescriptorRMControlTesting::SecurityDescriptorRMControlTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SecurityDescriptorRMControlTesting)

void System::SecurityDescriptorRMControlTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SecurityDescriptorRMControlTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RMControlTest);
}

void System::SecurityDescriptorRMControlTesting::RMControlTest()
{
    SecurityDescriptor securityDescriptor{};
    ASSERT_TRUE(InitializeSystemSecurityDescriptor(&securityDescriptor));

    WindowsUChar rmControl{ 0x1 };
    ASSERT_TRUE(SetSecurityDescriptorResourceManagerControl(&securityDescriptor, &rmControl));

    WindowsUChar resultRMControl{ 0 };
    ASSERT_TRUE(GetSecurityDescriptorResourceManagerControl(&securityDescriptor, &resultRMControl));

    ASSERT_EQUAL(rmControl, resultRMControl);
}
