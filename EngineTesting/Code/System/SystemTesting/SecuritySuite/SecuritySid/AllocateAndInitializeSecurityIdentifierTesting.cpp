///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/29 20:45)

#include "AllocateAndInitializeSecurityIdentifierTesting.h"
#include "System/Security/SecuritySid.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AllocateAndInitializeSecurityIdentifierTesting::AllocateAndInitializeSecurityIdentifierTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AllocateAndInitializeSecurityIdentifierTesting)

void System::AllocateAndInitializeSecurityIdentifierTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AllocateAndInitializeSecurityIdentifierTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AllocateTest);
}

void System::AllocateAndInitializeSecurityIdentifierTesting::AllocateTest()
{
    for (auto& identifierAuthority : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoAllocateTest, identifierAuthority);
    }
}

void System::AllocateAndInitializeSecurityIdentifierTesting::DoAllocateTest(SecuritySIDIndentifierAuthority& identifierAuthority)
{
    constexpr WindowsByte subAuthorityCount{ 5 };

    SecuritySIDPtr sid{ nullptr };

    ASSERT_TRUE(AllocateAndInitializeSecurityIdentifier(&identifierAuthority, subAuthorityCount, 0, 0, 0, 0, 0, 0, 0, 0, &sid));
    ASSERT_UNEQUAL_NULL_PTR(sid);

    const auto result = FreeSecurityIdentifier(sid);
    ASSERT_EQUAL_NULL_PTR(result);
}
