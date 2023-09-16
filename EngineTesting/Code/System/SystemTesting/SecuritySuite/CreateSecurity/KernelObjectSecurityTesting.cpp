///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:02)

#include "KernelObjectSecurityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Security/CreateSecurity.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::KernelObjectSecurityTesting::KernelObjectSecurityTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, KernelObjectSecurityTesting)

void System::KernelObjectSecurityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::KernelObjectSecurityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(KernelObjectSecurityTest);
}

void System::KernelObjectSecurityTesting::KernelObjectSecurityTest()
{
    WindowsHandle tokenHandle = OpenProcessToken();

    ASSERT_NOT_THROW_EXCEPTION_1(DoKernelObjectSecurityTest, tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseProcessTokenTest, tokenHandle);
}

void System::KernelObjectSecurityTesting::DoKernelObjectSecurityTest(WindowsHandle tokenHandle)
{
    for (auto securityRequestedInformation : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(SetKernelObjectSecurityTest, tokenHandle, securityRequestedInformation);
    }
}

void System::KernelObjectSecurityTesting::SetKernelObjectSecurityTest(WindowsHandle tokenHandle, SecurityRequestedInformation securityRequestedInformation)
{
    WindowsDWord neededLength{ 0 };
    ASSERT_FALSE(GetSystemKernelObjectSecurity(tokenHandle, securityRequestedInformation, nullptr, 0, &neededLength));

    BufferType buffer(boost::numeric_cast<size_t>(neededLength + 1));

    WindowsDWord newNeededLength{ 0 };
    ASSERT_TRUE(GetSystemKernelObjectSecurity(tokenHandle, securityRequestedInformation, buffer.data(), neededLength, &newNeededLength));
    ASSERT_EQUAL(newNeededLength, neededLength);

    ASSERT_TRUE(SetSystemKernelObjectSecurity(tokenHandle, securityRequestedInformation, buffer.data()));
}
