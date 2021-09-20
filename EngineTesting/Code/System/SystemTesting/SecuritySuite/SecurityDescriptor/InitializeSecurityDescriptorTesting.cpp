///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/06/02 14:04)

#include "InitializeSecurityDescriptorTesting.h"
#include "System/Security/SecurityDescriptor.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::InitializeSecurityDescriptorTesting::InitializeSecurityDescriptorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, InitializeSecurityDescriptorTesting)

void System::InitializeSecurityDescriptorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::InitializeSecurityDescriptorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitializeSecurityDescriptorTest);
}

void System::InitializeSecurityDescriptorTesting::InitializeSecurityDescriptorTest()
{
    SecurityDescriptor securityDescriptor{};
    ASSERT_TRUE(InitializeSystemSecurityDescriptor(&securityDescriptor));
}
