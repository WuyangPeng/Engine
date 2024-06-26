/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 14:21)

#include "CreatePrivateObjectSecurityWithMultipleInheritanceTesting.h"
#include "System/Security/CreateSecurity.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreatePrivateObjectSecurityWithMultipleInheritanceTesting::CreatePrivateObjectSecurityWithMultipleInheritanceTesting(const OStreamShared& stream)
    : ParentType{ stream },
      setFileName{ SYSTEM_TEXT("Resource/AttributesTesting/AttributesTestFile.txt") }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreatePrivateObjectSecurityWithMultipleInheritanceTesting)

void System::CreatePrivateObjectSecurityWithMultipleInheritanceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreatePrivateObjectSecurityWithMultipleInheritanceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreatePrivateObjectSecurityTest);
}

void System::CreatePrivateObjectSecurityWithMultipleInheritanceTesting::CreatePrivateObjectSecurityTest()
{
    WindowsHandle tokenHandle = OpenProcessToken();

    ASSERT_NOT_THROW_EXCEPTION_1(DoCreatePrivateObjectSecurityTest, tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseProcessTokenTest, tokenHandle);
}

void System::CreatePrivateObjectSecurityWithMultipleInheritanceTesting::DoCreatePrivateObjectSecurityTest(WindowsHandle tokenHandle)
{
    for (auto iter = GetSecurityAutoInheritBegin(); iter != GetSecurityAutoInheritEnd(); ++iter)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(CreateSecurityTest, *iter, tokenHandle);
    }
}

void System::CreatePrivateObjectSecurityWithMultipleInheritanceTesting::CreateSecurityTest(SecurityAutoInherit securityAutoInherit, WindowsHandle tokenHandle)
{
    SecurityDescriptorPtr descriptor{ nullptr };
    auto genericMapping = GetAccessCheckGenericMapping();
    ASSERT_TRUE(CreateSystemPrivateObjectSecurityWithMultipleInheritance(nullptr, nullptr, &descriptor, nullptr, 0, false, securityAutoInherit, tokenHandle, &genericMapping));
    ASSERT_UNEQUAL_NULL_PTR(descriptor);

    if (GetTokenIsElevated())
    {
        ASSERT_TRUE(SetSystemFileSecurity(setFileName, SecurityRequestedInformation::Owner, descriptor));
    }

    ASSERT_NOT_THROW_EXCEPTION_1(DestroyPrivateObjectSecurityTest, descriptor);
}
