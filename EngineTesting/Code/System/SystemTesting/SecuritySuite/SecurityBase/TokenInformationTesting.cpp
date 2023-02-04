///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/28 16:59)

#include "TokenInformationTestingDetail.h"
#include "System/Security/SecurityBase.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"

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
    const auto tokenHandle = OpenProcessToken();

    ASSERT_NOT_THROW_EXCEPTION_1(DoTokenImpersonationLevelTest, tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseTokenTest, tokenHandle);
}

void System::TokenInformationTesting::DoTokenImpersonationLevelTest(WindowsHandle tokenHandle)
{
    WindowsHandle impersonatedToken{ nullptr };
    ASSERT_TRUE(DuplicateSystemToken(tokenHandle, SecurityImpersonation, &impersonatedToken));

    ASSERT_NOT_THROW_EXCEPTION_1(GetTokenImpersonationLevelTest, impersonatedToken);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseTokenTest, impersonatedToken);
}

void System::TokenInformationTesting::GetTokenImpersonationLevelTest(WindowsHandle impersonatedToken)
{
    const auto bufferLength = GetBufferLength(impersonatedToken, TokenImpersonationLevel);

    ASSERT_NOT_THROW_EXCEPTION_3(LengthTest, bufferLength, impersonatedToken, TokenImpersonationLevel);
}

void System::TokenInformationTesting::LengthTest(WindowsDWord bufferLength, WindowsHandle impersonatedToken, TokenInformationClass tokenInformation)
{
    BufferType buffer(bufferLength);

    WindowsDWord returnLength{ 0 };
    ASSERT_TRUE(GetSystemTokenInformation(impersonatedToken, tokenInformation, buffer.data(), bufferLength, &returnLength));

    ASSERT_LESS_EQUAL(returnLength, bufferLength);
}
