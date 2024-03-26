/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 14:20)

#include "CreatePrivateObjectSecurityTesting.h"
#include "System/Security/CreateSecurity.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreatePrivateObjectSecurityTesting::CreatePrivateObjectSecurityTesting(const OStreamShared& stream)
    : ParentType{ stream },
      setFileName{ SYSTEM_TEXT("Resource/AttributesTesting/AttributesTestFile.txt") }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreatePrivateObjectSecurityTesting)

void System::CreatePrivateObjectSecurityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreatePrivateObjectSecurityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreatePrivateObjectSecurityTest);
}

void System::CreatePrivateObjectSecurityTesting::CreatePrivateObjectSecurityTest()
{
    const auto tokenHandle = OpenProcessToken();

    ASSERT_NOT_THROW_EXCEPTION_1(DoCreatePrivateObjectSecurityTest, tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseProcessTokenTest, tokenHandle);
}

void System::CreatePrivateObjectSecurityTesting::DoCreatePrivateObjectSecurityTest(WindowsHandle tokenHandle)
{
    auto genericMapping = GetAccessCheckGenericMapping();

    SecurityDescriptorPtr descriptor{ nullptr };
    ASSERT_TRUE(CreateSystemPrivateObjectSecurity(nullptr, nullptr, &descriptor, false, tokenHandle, &genericMapping));
    ASSERT_UNEQUAL_NULL_PTR(descriptor);

    ASSERT_NOT_THROW_EXCEPTION_1(SetSystemFileSecurityTest, descriptor);

    ASSERT_NOT_THROW_EXCEPTION_1(DestroyPrivateObjectSecurityTest, descriptor);
}

void System::CreatePrivateObjectSecurityTesting::SetSystemFileSecurityTest(SecurityDescriptorPtr newDescriptor)
{
    if (GetTokenIsElevated())
    {
        for (const auto securityRequestedInformation : *this)
        {
            ASSERT_TRUE(SetSystemFileSecurity(setFileName, securityRequestedInformation, newDescriptor));
        }
    }
}
