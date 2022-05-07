///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/03 16:05)

#ifndef SYSTEM_SECURITY_SUITE_TOKEN_INFORMATION_TESTING_DETAIL_H
#define SYSTEM_SECURITY_SUITE_TOKEN_INFORMATION_TESTING_DETAIL_H

#include "TokenInformationTesting.h"
#include "System/Security/LookupPrivilege.h"
#include "System/Security/SecurityBase.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/ProcessTools.h"
#include "System/Threading/ThreadTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

template <System::TokenInformationClass TokenInformation, typename SecurityToken>
void System::TokenInformationTesting::DoTokenInformationTest()
{
    WindowsHandle tokenHandle{ nullptr };
    ASSERT_TRUE(OpenSysemProcessToken(GetCurrentProcessHandle(), TokenStandardAccess::Default, TokenSpecificAccess::AllAccess, &tokenHandle));

    WindowsDWord returnLength{ 0 };
    ASSERT_FALSE(GetSystemTokenInformation(tokenHandle, TokenInformation, nullptr, 0, &returnLength));

    ASSERT_LESS_FAILURE_THROW(0u, returnLength, "����ȡϵͳtoken��Ϣʧ�ܣ�TokenInformation = " + std::to_string(TokenInformation));

    std::vector<char> buffer(returnLength);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    auto tokenInformation = reinterpret_cast<SecurityToken*>(buffer.data());
#include STSTEM_WARNING_POP

    WindowsDWord newReturnLength{ 0 };
    ASSERT_TRUE(GetSystemTokenInformation(tokenHandle, TokenInformation, tokenInformation, returnLength, &newReturnLength));

    ASSERT_LESS_EQUAL(newReturnLength, returnLength);

    ASSERT_TRUE(CloseTokenHandle(tokenHandle));
}

#endif  // SYSTEM_SECURITY_SUITE_TOKEN_INFORMATION_TESTING_DETAIL_H