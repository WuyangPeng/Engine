/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 14:21)

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
