///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/11/01 21:49)

#include "KernelObjectSecurityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Security/CreateSecurity.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/ProcessTools.h"
#include "System/Threading/ThreadTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::vector;

System::KernelObjectSecurityTesting::KernelObjectSecurityTesting(const OStreamShared& stream)
    : ParentType{ stream },
      securityRequestedInformationFlags{ SecurityRequestedInformation::Owner,
                                         SecurityRequestedInformation::Group,
                                         SecurityRequestedInformation::Dacl,
                                         SecurityRequestedInformation::Label }
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
    WindowsHandle tokenHandle{ nullptr };
    ASSERT_TRUE(OpenSysemProcessToken(GetCurrentProcessHandle(), TokenStandardAccess::Default, TokenSpecificAccess::AllAccess, &tokenHandle));

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(tokenHandle, "Token句柄获取失败。");

    for (auto securityRequestedInformation : securityRequestedInformationFlags)
    {
        WindowsDWord neededLength{ 0 };
        ASSERT_FALSE(GetSystemKernelObjectSecurity(tokenHandle, securityRequestedInformation, nullptr, 0, &neededLength));

        vector<char> buffer(boost::numeric_cast<size_t>(neededLength + 1));

        WindowsDWord newNeededLength{ 0 };
        ASSERT_TRUE(GetSystemKernelObjectSecurity(tokenHandle, securityRequestedInformation, buffer.data(), neededLength, &newNeededLength));
        ASSERT_EQUAL(newNeededLength, neededLength);

        ASSERT_TRUE(SetSystemKernelObjectSecurity(tokenHandle, securityRequestedInformation, buffer.data()));
    }

    ASSERT_TRUE(CloseTokenHandle(tokenHandle));
}
