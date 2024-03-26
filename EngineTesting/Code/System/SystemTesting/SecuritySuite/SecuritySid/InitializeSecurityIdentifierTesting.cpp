/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 14:31)

#include "InitializeSecurityIdentifierTesting.h"
#include "System/Security/SecuritySid.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::InitializeSecurityIdentifierTesting::InitializeSecurityIdentifierTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, InitializeSecurityIdentifierTesting)

void System::InitializeSecurityIdentifierTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::InitializeSecurityIdentifierTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitializeSidTest);
}

void System::InitializeSecurityIdentifierTesting::InitializeSidTest()
{
    for (auto& identifierAuthority : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoInitializeSidTest, identifierAuthority);
    }
}

void System::InitializeSecurityIdentifierTesting::DoInitializeSidTest(SecuritySidIdentifierAuthority& identifierAuthority)
{
    constexpr WindowsByte subAuthorityCount{ 5 };

    SecuritySid sid{};

    ASSERT_TRUE(InitializeSecurityIdentifier(&sid, &identifierAuthority, subAuthorityCount));
    ASSERT_TRUE(IsSecurityIdentifierValid(&sid));
}
