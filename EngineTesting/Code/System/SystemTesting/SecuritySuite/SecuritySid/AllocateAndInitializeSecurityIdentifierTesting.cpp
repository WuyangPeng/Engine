/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 14:31)

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

void System::AllocateAndInitializeSecurityIdentifierTesting::DoAllocateTest(SecuritySidIdentifierAuthority& identifierAuthority)
{
    constexpr WindowsByte subAuthorityCount{ 5 };

    SecuritySidPtr sid{ nullptr };

    ASSERT_TRUE(AllocateAndInitializeSecurityIdentifier(&identifierAuthority, subAuthorityCount, 0, 0, 0, 0, 0, 0, 0, 0, &sid));
    ASSERT_UNEQUAL_NULL_PTR(sid);

    const auto result = FreeSecurityIdentifier(sid);
    ASSERT_EQUAL_NULL_PTR(result);
}
