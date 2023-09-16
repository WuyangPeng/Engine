///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:08)

#include "SecurityBaseTestingBase.h"
#include "System/Helper/SecuritySidMacro.h"
#include "System/Security/SecurityBase.h"
#include "System/Security/SecuritySid.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/ProcessTools.h"
#include "System/Threading/ThreadTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SecurityBaseTestingBase::SecurityBaseTestingBase(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SecurityBaseTestingBase)

System::WindowsHandle System::SecurityBaseTestingBase::OpenProcessToken()
{
    SYSTEM_CLASS_IS_VALID_1;

    WindowsHandle tokenHandle{ nullptr };
    ASSERT_TRUE(OpenSystemProcessToken(GetCurrentProcessHandle(), TokenStandardAccess::Default, TokenSpecificAccess::AllAccess, &tokenHandle));

    return tokenHandle;
}

System::WindowsDWord System::SecurityBaseTestingBase::GetBufferLength(WindowsHandle tokenHandle, TokenInformationClass tokenInformation)
{
    SYSTEM_CLASS_IS_VALID_1;

    WindowsDWord bufferLength{ 0 };
    ASSERT_FALSE(GetSystemTokenInformation(tokenHandle, tokenInformation, nullptr, 0, &bufferLength));

    ASSERT_LESS_FAILURE_THROW(0u, bufferLength, "，获取系统token信息失败，TokenInformation = " + std::to_string(tokenInformation));

    return bufferLength;
}

void System::SecurityBaseTestingBase::CloseTokenTest(WindowsHandle tokenHandle)
{
    SYSTEM_CLASS_IS_VALID_1;

    ASSERT_TRUE(CloseTokenHandle(tokenHandle));
}

System::SecuritySid System::SecurityBaseTestingBase::GetSecuritySid()
{
    SYSTEM_CLASS_IS_VALID_1;

    SecuritySid sid{};

    SecuritySidIdentifierAuthority identifierAuthority SYSTEM_SECURITY_NT_AUTHORITY;

    constexpr WindowsByte subAuthorityCount{ 5 };

    ASSERT_TRUE(InitializeSecurityIdentifier(&sid, &identifierAuthority, subAuthorityCount));
    ASSERT_TRUE(IsSecurityIdentifierValid(&sid));

    return sid;
}
