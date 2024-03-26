/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 13:35)

#include "AccessCheckByTypeTesting.h"
#include "System/Security/AccessCheck.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AccessCheckByTypeTesting::AccessCheckByTypeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AccessCheckByTypeTesting)

void System::AccessCheckByTypeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AccessCheckByTypeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AccessCheckByTypeTest);
}

void System::AccessCheckByTypeTesting::AccessCheckByTypeTest()
{
    const auto tokenHandle = OpenProcessToken();

    ASSERT_NOT_THROW_EXCEPTION_1(DuplicateTokenTest, tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseTokenTest, tokenHandle);
}

void System::AccessCheckByTypeTesting::DuplicateTokenTest(WindowsHandle tokenHandle)
{
    const auto impersonatedToken = DuplicateToken(tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DoAccessCheckByTypeTest, impersonatedToken);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseTokenTest, impersonatedToken);
}

void System::AccessCheckByTypeTesting::DoAccessCheckByTypeTest(WindowsHandle impersonatedToken)
{
    auto buffer = GetFileSecurityBuffer();

    for (auto accessMask : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_3(GetAccessCheckTest, accessMask, buffer, impersonatedToken);
    }
}

void System::AccessCheckByTypeTesting::GetAccessCheckTest(FileHandleDesiredAccess accessMask, CharBufferType& buffer, WindowsHandle impersonatedToken)
{
    AccessCheckGenericMapping genericMapping{};
    const auto fileMapGenericMask = GetFileMapGenericMask(accessMask, genericMapping);

    SecurityPrivilegeSet privileges{};
    WindowsDWord grantedAccess{ 0 };
    WindowsDWord privilegeLength{ sizeof(privileges) };
    auto accessStatus = false;

    ASSERT_TRUE(GetAccessCheckByType(buffer.data(), nullptr, impersonatedToken, fileMapGenericMask, nullptr, 0, &genericMapping, &privileges, &privilegeLength, &grantedAccess, &accessStatus));

    ASSERT_EQUAL(grantedAccess, EnumCastUnderlying<WindowsDWord>(fileMapGenericMask));
    ASSERT_EQUAL(privilegeLength, sizeof(privileges));
    ASSERT_EQUAL(accessStatus, true);
}
