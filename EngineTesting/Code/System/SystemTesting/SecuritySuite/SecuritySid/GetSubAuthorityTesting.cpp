/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 14:31)

#include "GetSubAuthorityTesting.h"
#include "System/Security/SecuritySid.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetSubAuthorityTesting::GetSubAuthorityTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetSubAuthorityTesting)

void System::GetSubAuthorityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetSubAuthorityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetSubAuthorityTest);
}

void System::GetSubAuthorityTesting::GetSubAuthorityTest()
{
    for (auto& identifierAuthority : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoGetSubAuthorityTest, identifierAuthority);
    }
}

void System::GetSubAuthorityTesting::DoGetSubAuthorityTest(SecuritySidIdentifierAuthority& identifierAuthority)
{
    auto sid = GetSecuritySid(identifierAuthority);

    auto securityIdentifierSubAuthorityCount = GetSecurityIdentifierSubAuthorityCount(&sid);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(securityIdentifierSubAuthorityCount, "securityIdentifierSubAuthorityCount 是空指针。");

    ASSERT_NOT_THROW_EXCEPTION_2(NextSubAuthorityCountTest, securityIdentifierSubAuthorityCount, sid);
}

System::SecuritySid System::GetSubAuthorityTesting::GetSecuritySid(SecuritySidIdentifierAuthority& identifierAuthority)
{
    SecuritySid sid{};

    ASSERT_TRUE(InitializeSecurityIdentifier(&sid, &identifierAuthority, subAuthorityCount));
    ASSERT_TRUE(IsSecurityIdentifierValid(&sid));

    return sid;
}

void System::GetSubAuthorityTesting::NextSubAuthorityCountTest(WindowsUCharPtr securityIdentifierSubAuthorityCount, SecuritySid& sid)
{
    if (securityIdentifierSubAuthorityCount != nullptr)
    {
        ASSERT_EQUAL(*securityIdentifierSubAuthorityCount, subAuthorityCount);

        *securityIdentifierSubAuthorityCount = subAuthorityCount - 1;

        auto nextSubAuthorityCount = GetSecurityIdentifierSubAuthorityCount(&sid);

        ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(nextSubAuthorityCount, "nextSubAuthorityCount 是空指针。");

        ASSERT_NOT_THROW_EXCEPTION_3(GetSecurityIdentifierSubAuthorityTest, securityIdentifierSubAuthorityCount, nextSubAuthorityCount, sid);
    }
}

void System::GetSubAuthorityTesting::GetSecurityIdentifierSubAuthorityTest(const WindowsUChar* nextSubAuthorityCount, const WindowsUChar* securityIdentifierSubAuthorityCount, SecuritySid& sid)
{
    if (securityIdentifierSubAuthorityCount != nullptr && nextSubAuthorityCount != nullptr)
    {
        ASSERT_EQUAL(*securityIdentifierSubAuthorityCount, *nextSubAuthorityCount);

        const auto resultSecurityIdentifierSubAuthority = GetSecurityIdentifierSubAuthority(&sid, *securityIdentifierSubAuthorityCount - 1);

        ASSERT_UNEQUAL_NULL_PTR(resultSecurityIdentifierSubAuthority);
    }
}
