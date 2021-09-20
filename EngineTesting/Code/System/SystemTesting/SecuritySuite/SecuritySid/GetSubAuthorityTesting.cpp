///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/05/31 22:19)

#include "GetSubAuthorityTesting.h"
#include "System/Helper/SecuritySidMacro.h"
#include "System/Security/SecuritySid.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetSubAuthorityTesting::GetSubAuthorityTesting(const OStreamShared& stream)
    : ParentType{ stream }, securitySIDIndentifierAuthority{}
{
    Init();

    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetSubAuthorityTesting)

void System::GetSubAuthorityTesting::Init()
{
    securitySIDIndentifierAuthority.emplace_back(SecuritySIDIndentifierAuthority SYSTEM_SECURITY_NULL_SID_AUTHORITY);
    securitySIDIndentifierAuthority.emplace_back(SecuritySIDIndentifierAuthority SYSTEM_SECURITY_WORLD_SID_AUTHORITY);
    securitySIDIndentifierAuthority.emplace_back(SecuritySIDIndentifierAuthority SYSTEM_SECURITY_LOCAL_SID_AUTHORITY);
    securitySIDIndentifierAuthority.emplace_back(SecuritySIDIndentifierAuthority SYSTEM_SECURITY_CREATOR_SID_AUTHORITY);
    securitySIDIndentifierAuthority.emplace_back(SecuritySIDIndentifierAuthority SYSTEM_SECURITY_NON_UNIQUE_AUTHORITY);
    securitySIDIndentifierAuthority.emplace_back(SecuritySIDIndentifierAuthority SYSTEM_SECURITY_RESOURCE_MANAGER_AUTHORITY);
    securitySIDIndentifierAuthority.emplace_back(SecuritySIDIndentifierAuthority SYSTEM_SECURITY_NT_AUTHORITY);
    securitySIDIndentifierAuthority.emplace_back(SecuritySIDIndentifierAuthority SYSTEM_SECURITY_MANDATORY_LABEL_AUTHORITY);
}

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
    for (const auto& identifierAuthority : securitySIDIndentifierAuthority)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoGetSubAuthorityTest, identifierAuthority);
    }
}

void System::GetSubAuthorityTesting::DoGetSubAuthorityTest(SecuritySIDIndentifierAuthority identifierAuthority)
{
    constexpr WindowsByte subAuthorityCount{ 5 };
    SecuritySID sid{};

    ASSERT_TRUE(InitializeSecurityIdentifier(&sid, &identifierAuthority, subAuthorityCount));
    ASSERT_TRUE(IsSecurityIdentifierValid(&sid));

    auto resultSubAuthorityCount = GetSecurityIdentifierSubAuthorityCount(&sid);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(resultSubAuthorityCount, "resultSubAuthorityCount 是空指针。");

    if (resultSubAuthorityCount != nullptr)
    {
        ASSERT_EQUAL(*resultSubAuthorityCount, subAuthorityCount);

        *resultSubAuthorityCount = subAuthorityCount - 1;

        WindowsUCharPtr nextSubAuthorityCount = GetSecurityIdentifierSubAuthorityCount(&sid);

        ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(nextSubAuthorityCount, "nextSubAuthorityCount 是空指针。");

        if (nextSubAuthorityCount != nullptr)
        {
            ASSERT_EQUAL(*resultSubAuthorityCount, *nextSubAuthorityCount);

            auto securityIdentifierSubAuthority = GetSecurityIdentifierSubAuthority(&sid, *resultSubAuthorityCount - 1);

            ASSERT_UNEQUAL_NULL_PTR(securityIdentifierSubAuthority);
        }
    }
}
