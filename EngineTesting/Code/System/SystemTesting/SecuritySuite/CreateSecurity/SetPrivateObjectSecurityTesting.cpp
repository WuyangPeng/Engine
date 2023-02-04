///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/25 19:05)

#include "SetPrivateObjectSecurityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Security/CreateSecurity.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SetPrivateObjectSecurityTesting::SetPrivateObjectSecurityTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SetPrivateObjectSecurityTesting)

void System::SetPrivateObjectSecurityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SetPrivateObjectSecurityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetPrivateObjectSecurityTest);
}

void System::SetPrivateObjectSecurityTesting::SetPrivateObjectSecurityTest()
{
    const auto tokenHandle = OpenProcessToken();

    ASSERT_NOT_THROW_EXCEPTION_1(DoSetPrivateObjectSecurityTest, tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseProcessTokenTest, tokenHandle);
}

void System::SetPrivateObjectSecurityTesting::DoSetPrivateObjectSecurityTest(WindowsHandle tokenHandle)
{
    SecurityDescriptorPtr descriptor{ nullptr };
    CreatePrivateObjectSecurity(tokenHandle, descriptor);

    ASSERT_NOT_THROW_EXCEPTION_2(PrivateObjectSecurityTest, descriptor, tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DestroyPrivateObjectSecurityTest, descriptor);
}

void System::SetPrivateObjectSecurityTesting::PrivateObjectSecurityTest(SecurityDescriptorPtr& descriptor, WindowsHandle tokenHandle)
{
    for (auto securityRequestedInformation : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoPrivateObjectSecurityTest, descriptor, securityRequestedInformation, tokenHandle);
    }
}

void System::SetPrivateObjectSecurityTesting::DoPrivateObjectSecurityTest(SecurityDescriptorPtr& descriptor, SecurityRequestedInformation securityRequestedInformation, WindowsHandle tokenHandle)
{
    WindowsDWord neededLength{ 0 };
    ASSERT_FALSE(GetSystemPrivateObjectSecurity(descriptor, securityRequestedInformation, nullptr, 0, &neededLength));

    BufferType buffer(boost::numeric_cast<size_t>(neededLength + 1));

    WindowsDWord newNeededLength{ 0 };
    ASSERT_TRUE(GetSystemPrivateObjectSecurity(descriptor, securityRequestedInformation, buffer.data(), neededLength, &newNeededLength));
    ASSERT_EQUAL(newNeededLength, neededLength);

    SetSystemPrivateObjectSecurityTest(securityRequestedInformation, descriptor, tokenHandle, buffer);
}

void System::SetPrivateObjectSecurityTesting::SetSystemPrivateObjectSecurityTest(SecurityRequestedInformation securityRequestedInformation, SecurityDescriptorPtr& descriptor, WindowsHandle tokenHandle, BufferType& buffer)
{
    auto genericMapping = GetAccessCheckGenericMapping();

    ASSERT_TRUE(SetSystemPrivateObjectSecurity(securityRequestedInformation, buffer.data(), &descriptor, &genericMapping, tokenHandle));

    for (auto iter = GetSecurityAutoInheritBegin(); iter != GetSecurityAutoInheritEnd(); ++iter)
    {
        ASSERT_TRUE(SetSystemPrivateObjectSecurity(securityRequestedInformation, buffer.data(), &descriptor, *iter, &genericMapping, tokenHandle));
    }
}
