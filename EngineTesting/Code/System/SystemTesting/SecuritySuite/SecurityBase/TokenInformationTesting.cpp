///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 15:46)

#include "TokenInformationTestingDetail.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"

using std::vector;

System::TokenInformationTesting::TokenInformationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, TokenInformationTesting)

void System::TokenInformationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::TokenInformationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TokenInformationTest);
}

void System::TokenInformationTesting::TokenInformationTest()
{
    DoTokenInformationTest<TokenUser, SecurityTokenUser>();
    DoTokenInformationTest<TokenGroups, SecurityTokenGroups>();
    DoTokenInformationTest<TokenPrivileges, SecurityTokenPrivileges>();
    DoTokenInformationTest<TokenOwner, SecurityTokenOwner>();
    DoTokenInformationTest<TokenPrimaryGroup, SecurityTokenPrimaryGroup>();
    DoTokenInformationTest<TokenDefaultDacl, SecurityTokenDefaultDacl>();
    DoTokenInformationTest<TokenSource, SecurityTokenSource>();
    DoTokenInformationTest<TokenType, SecurityTokenType>();
    ASSERT_NOT_THROW_EXCEPTION_0(TokenImpersonationLevelTest);
    DoTokenInformationTest<TokenStatistics, SecurityTokenStatistics>();
    DoTokenInformationTest<TokenRestrictedSids, SecurityTokenGroups>();
    DoTokenInformationTest<TokenSessionId, WindowsDWord>();
    DoTokenInformationTest<TokenGroupsAndPrivileges, SecurityTokenGroupsAndPrivileges>();
    DoTokenInformationTest<TokenSandBoxInert, WindowsDWord>();
    DoTokenInformationTest<TokenOrigin, SecurityTokenOrigin>();
    DoTokenInformationTest<TokenElevationType, SecurityTokenElevationType>();
    DoTokenInformationTest<TokenLinkedToken, SecurityTokenLinkedToken>();
    DoTokenInformationTest<TokenElevation, SecurityTokenElevation>();
    DoTokenInformationTest<TokenHasRestrictions, WindowsDWord>();
    DoTokenInformationTest<TokenAccessInformation, SecurityTokenAccessInformation>();
    DoTokenInformationTest<TokenVirtualizationAllowed, WindowsDWord>();
    DoTokenInformationTest<TokenVirtualizationEnabled, WindowsDWord>();
    DoTokenInformationTest<TokenIntegrityLevel, SecurityTokenMandatoryLabel>();
    DoTokenInformationTest<TokenUIAccess, WindowsDWord>();
    DoTokenInformationTest<TokenMandatoryPolicy, SecurityTokenMandatoryPolicy>();
    DoTokenInformationTest<TokenLogonSid, SecurityTokenGroups>();
}

void System::TokenInformationTesting::TokenImpersonationLevelTest()
{
    WindowsHandle tokenHandle{ nullptr };
    ASSERT_TRUE(OpenSysemProcessToken(GetCurrentProcessHandle(), TokenStandardAccess::Default, TokenSpecificAccess::AllAccess, &tokenHandle));

    WindowsHandle impersonatedToken{ nullptr };
    ASSERT_TRUE(DuplicateSystemToken(tokenHandle, SecurityImpersonation, &impersonatedToken));

    WindowsDWord returnLength{ 0 };
    ASSERT_FALSE(GetSystemTokenInformation(impersonatedToken, TokenImpersonationLevel, nullptr, 0, &returnLength));

    ASSERT_LESS_FAILURE_THROW(0u, returnLength, "，获取系统token信息失败。");

    vector<char> buffer(returnLength);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    auto tokenInformation = reinterpret_cast<SecurityImpersonationLevel*>(buffer.data());

#include STSTEM_WARNING_POP

    WindowsDWord newReturnLength{ 0 };
    ASSERT_TRUE(GetSystemTokenInformation(impersonatedToken, TokenImpersonationLevel, tokenInformation, returnLength, &newReturnLength));

    ASSERT_EQUAL(newReturnLength, returnLength);

    ASSERT_TRUE(CloseTokenHandle(impersonatedToken));
    ASSERT_TRUE(CloseTokenHandle(tokenHandle));
}
