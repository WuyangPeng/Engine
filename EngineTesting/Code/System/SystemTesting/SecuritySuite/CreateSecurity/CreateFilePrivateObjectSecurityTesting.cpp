///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:00)

#include "CreateFilePrivateObjectSecurityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Security/CreateSecurity.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::CreateFilePrivateObjectSecurityTesting::CreateFilePrivateObjectSecurityTesting(const OStreamShared& stream)
    : ParentType{ stream },
      existingFileName{ SYSTEM_TEXT("Resource/FileTesting/CreateExistingFile.txt"s) },
      setFileName{ SYSTEM_TEXT("Resource/AttributesTesting/AttributesTestFile.txt"s) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateFilePrivateObjectSecurityTesting)

void System::CreateFilePrivateObjectSecurityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateFilePrivateObjectSecurityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreatePrivateObjectSecurityTest);
}

void System::CreateFilePrivateObjectSecurityTesting::CreatePrivateObjectSecurityTest()
{
    const auto tokenHandle = OpenProcessToken();

    ASSERT_NOT_THROW_EXCEPTION_1(DoCreatePrivateObjectSecurityTest, tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseProcessTokenTest, tokenHandle);
}

void System::CreateFilePrivateObjectSecurityTesting::DoCreatePrivateObjectSecurityTest(WindowsHandle tokenHandle)
{
    for (auto securityRequestedInformation : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(CreateSecurityTest, securityRequestedInformation, tokenHandle);
    }
}

void System::CreateFilePrivateObjectSecurityTesting::CreateSecurityTest(SecurityRequestedInformation securityRequestedInformation, WindowsHandle tokenHandle)
{
    auto buffer = GetSystemFileSecurityTest(securityRequestedInformation);

    SecurityDescriptorPtr descriptor{ nullptr };
    AccessCheckGenericMapping genericMapping = GetAccessCheckGenericMapping();
    ASSERT_TRUE(CreateSystemPrivateObjectSecurity(nullptr, buffer.data(), &descriptor, false, tokenHandle, &genericMapping));
    ASSERT_UNEQUAL_NULL_PTR(descriptor);

    ASSERT_NOT_THROW_EXCEPTION_2(SetSystemFileSecurityTest, securityRequestedInformation, descriptor);

    ASSERT_NOT_THROW_EXCEPTION_1(DestroyPrivateObjectSecurityTest, descriptor);
}

System::CreateFilePrivateObjectSecurityTesting::BufferType System::CreateFilePrivateObjectSecurityTesting::GetSystemFileSecurityTest(SecurityRequestedInformation securityRequestedInformation)
{
    WindowsDWord neededLength{ 0 };
    ASSERT_FALSE(GetSystemFileSecurity(existingFileName, securityRequestedInformation, nullptr, 0, &neededLength));

    BufferType buffer(boost::numeric_cast<size_t>(neededLength + 1));

    WindowsDWord resultNeededLength{ 0 };
    ASSERT_TRUE(GetSystemFileSecurity(existingFileName, securityRequestedInformation, buffer.data(), neededLength, &resultNeededLength));
    ASSERT_EQUAL(resultNeededLength, neededLength);

    return buffer;
}

void System::CreateFilePrivateObjectSecurityTesting::SetSystemFileSecurityTest(SecurityRequestedInformation securityRequestedInformation, SecurityDescriptorPtr descriptor)
{
    if (GetTokenIsElevated())
    {
        ASSERT_TRUE(SetSystemFileSecurity(setFileName, securityRequestedInformation, descriptor));
    }
}
