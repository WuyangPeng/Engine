///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/25 20:35)

#include "ConvertToAutoInheritPrivateObjectSecurityTesting.h"
#include "System/Security/CreateSecurity.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConvertToAutoInheritPrivateObjectSecurityTesting::ConvertToAutoInheritPrivateObjectSecurityTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConvertToAutoInheritPrivateObjectSecurityTesting)

void System::ConvertToAutoInheritPrivateObjectSecurityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ConvertToAutoInheritPrivateObjectSecurityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConvertToAutoInheritPrivateObjectSecurityTest);
}

void System::ConvertToAutoInheritPrivateObjectSecurityTesting::ConvertToAutoInheritPrivateObjectSecurityTest()
{
    const auto tokenHandle = OpenProcessToken();

    ASSERT_NOT_THROW_EXCEPTION_1(DoConvertToAutoInheritPrivateObjectSecurityTest, tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseProcessTokenTest, tokenHandle);
}

void System::ConvertToAutoInheritPrivateObjectSecurityTesting::DoConvertToAutoInheritPrivateObjectSecurityTest(WindowsHandle tokenHandle)
{
    SecurityDescriptorPtr descriptor{ nullptr };
    CreatePrivateObjectSecurity(tokenHandle, descriptor);

    ASSERT_NOT_THROW_EXCEPTION_1(ConvertTest, descriptor);

    ASSERT_NOT_THROW_EXCEPTION_1(DestroyPrivateObjectSecurityTest, descriptor);
}

void System::ConvertToAutoInheritPrivateObjectSecurityTesting::ConvertTest(SecurityDescriptorPtr& descriptor)
{
    SecurityDescriptorPtr convertDescriptor{ nullptr };
    auto genericMapping = GetAccessCheckGenericMapping();

    ASSERT_TRUE(SystemConvertToAutoInheritPrivateObjectSecurity(nullptr, descriptor, &convertDescriptor, nullptr, false, &genericMapping));
    ASSERT_UNEQUAL_NULL_PTR(convertDescriptor);

    ASSERT_NOT_THROW_EXCEPTION_1(DestroyPrivateObjectSecurityTest, convertDescriptor);
}
