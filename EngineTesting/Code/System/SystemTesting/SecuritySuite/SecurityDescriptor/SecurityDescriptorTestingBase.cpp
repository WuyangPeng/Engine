/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 14:31)

#include "SecurityDescriptorTestingBase.h"
#include "System/Security/SecurityDescriptor.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SecurityDescriptorTestingBase::SecurityDescriptorTestingBase(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SecurityDescriptorTestingBase)

System::SecurityDescriptorTestingBase::BufferType System::SecurityDescriptorTestingBase::GetUserObjectSecurity(SecurityRequestedInformation requested)
{
    SYSTEM_CLASS_IS_VALID_1;

    WindowsDWord lengthNeeded{ 0 };
    ASSERT_FALSE(GetUserObjectSystemSecurity(GetCurrentSystemThread(), requested, nullptr, 0, &lengthNeeded));

    ASSERT_LESS(0u, lengthNeeded);
    BufferType buffer(lengthNeeded);

    WindowsDWord resultLengthNeeded{ 0 };
    ASSERT_TRUE(GetUserObjectSystemSecurity(GetCurrentSystemThread(), requested, buffer.data(), lengthNeeded, &resultLengthNeeded));

    ASSERT_EQUAL(resultLengthNeeded, lengthNeeded);

    return buffer;
}
