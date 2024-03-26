/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 14:31)

#include "CopySecurityIdentifierTesting.h"
#include "System/Security/SecuritySid.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CopySecurityIdentifierTesting::CopySecurityIdentifierTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CopySecurityIdentifierTesting)

void System::CopySecurityIdentifierTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CopySecurityIdentifierTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CopySecurityIdentifierTest);
}

void System::CopySecurityIdentifierTesting::CopySecurityIdentifierTest()
{
    for (auto& identifierAuthority : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoCopySecurityIdentifierTest, identifierAuthority);
    }
}

void System::CopySecurityIdentifierTesting::DoCopySecurityIdentifierTest(SecuritySidIdentifierAuthority& identifierAuthority)
{
    constexpr WindowsByte subAuthorityCount{ 5 };

    SecuritySid sid{};

    ASSERT_TRUE(InitializeSecurityIdentifier(&sid, &identifierAuthority, subAuthorityCount));
    ASSERT_TRUE(IsSecurityIdentifierValid(&sid));

    const auto length = GetLengthSecurityIdentifier(&sid);

    BufferType buffer(length);

    ASSERT_TRUE(CopySecurityIdentifier(length, &sid, buffer.data()));
}
