/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:35)

#include "AccessCheckTesting.h"
#include "System/Security/AccessCheck.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AccessCheckTesting::AccessCheckTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AccessCheckTesting)

void System::AccessCheckTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AccessCheckTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AccessCheckTest);
}

void System::AccessCheckTesting::AccessCheckTest()
{
    const auto tokenHandle = OpenProcessToken();

    ASSERT_NOT_THROW_EXCEPTION_1(DuplicateTokenTest, tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseTokenTest, tokenHandle);
}

void System::AccessCheckTesting::DuplicateTokenTest(WindowsHandle tokenHandle)
{
    const auto impersonatedToken = DuplicateToken(tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DoAccessCheckTest, impersonatedToken);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseTokenTest, impersonatedToken);
}

void System::AccessCheckTesting::DoAccessCheckTest(WindowsHandle impersonatedToken)
{
    auto buffer = GetFileSecurityBuffer();

    for (auto accessMask : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_3(GetAccessCheckTest, accessMask, buffer, impersonatedToken);
    }
}

void System::AccessCheckTesting::GetAccessCheckTest(FileHandleDesiredAccess accessMask, CharBufferType& buffer, WindowsHandle impersonatedToken)
{
    AccessCheckGenericMapping genericMapping{};
    const auto fileMapGenericMask = GetFileMapGenericMask(accessMask, genericMapping);

    SecurityPrivilegeSet privileges{};
    WindowsDWord grantedAccess{ 0 };
    WindowsDWord privilegeLength{ sizeof(privileges) };
    auto accessStatus = false;

    ASSERT_TRUE(GetAccessCheck(buffer.data(), impersonatedToken, fileMapGenericMask, &genericMapping, &privileges, &privilegeLength, &grantedAccess, &accessStatus));

    ASSERT_EQUAL(grantedAccess, EnumCastUnderlying<WindowsDWord>(fileMapGenericMask));
    ASSERT_EQUAL(privilegeLength, sizeof(privileges));
    ASSERT_EQUAL(accessStatus, true);
}
