///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 15:48)

#include "InitializeSecurityIdentifierTesting.h"
#include "System/Helper/SecuritySidMacro.h"
#include "System/Security/SecuritySid.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::InitializeSecurityIdentifierTesting::InitializeSecurityIdentifierTesting(const OStreamShared& stream)
    : ParentType{ stream }, securitySIDIndentifierAuthority{}
{
    Init();

    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, InitializeSecurityIdentifierTesting)

void System::InitializeSecurityIdentifierTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::InitializeSecurityIdentifierTesting::Init()
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

void System::InitializeSecurityIdentifierTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitializeSidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AllocateTest);
}

void System::InitializeSecurityIdentifierTesting::InitializeSidTest()
{
    constexpr WindowsByte subAuthorityCount{ 5 };

    for (auto& identifierAuthority : securitySIDIndentifierAuthority)
    {
        SecuritySID sid{};

        ASSERT_TRUE(InitializeSecurityIdentifier(&sid, &identifierAuthority, subAuthorityCount));
        ASSERT_TRUE(IsSecurityIdentifierValid(&sid));
    }
}

void System::InitializeSecurityIdentifierTesting::AllocateTest()
{
    constexpr WindowsByte subAuthorityCount{ 5 };

    for (auto& identifierAuthority : securitySIDIndentifierAuthority)
    {
        SecuritySIDPtr sid{ nullptr };

        ASSERT_TRUE(AllocateAndInitializeSecurityIdentifier(&identifierAuthority, subAuthorityCount, 0, 0, 0, 0, 0, 0, 0, 0, &sid));
        ASSERT_UNEQUAL_NULL_PTR(sid);

        auto ptr = FreeSecurityIdentifier(sid);
        ASSERT_EQUAL_NULL_PTR(ptr);
    }
}
