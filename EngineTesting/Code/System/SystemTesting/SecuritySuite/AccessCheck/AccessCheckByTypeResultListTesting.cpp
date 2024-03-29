/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:35)

#include "AccessCheckByTypeResultListTesting.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/SecuritySidMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Security/AccessCheck.h"
#include "System/Security/CreateSecurity.h"
#include "System/Security/SecuritySid.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::AccessCheckByTypeResultListTesting::AccessCheckByTypeResultListTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AccessCheckByTypeResultListTesting)

void System::AccessCheckByTypeResultListTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AccessCheckByTypeResultListTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AccessCheckByTypeResultListTest);
}

void System::AccessCheckByTypeResultListTesting::AccessCheckByTypeResultListTest()
{
    const auto tokenHandle = OpenProcessToken();

    ASSERT_NOT_THROW_EXCEPTION_1(DuplicateTokenTest, tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseTokenTest, tokenHandle);
}

void System::AccessCheckByTypeResultListTesting::DuplicateTokenTest(WindowsHandle tokenHandle)
{
    const auto impersonatedToken = DuplicateToken(tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DoAccessCheckTest, impersonatedToken);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseTokenTest, impersonatedToken);
}

void System::AccessCheckByTypeResultListTesting::DoAccessCheckTest(WindowsHandle impersonatedToken)
{
    auto buffer = GetFileSecurityBuffer();

    for (auto accessMask : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_3(GetAccessCheckTest, accessMask, buffer, impersonatedToken);
    }
}

void System::AccessCheckByTypeResultListTesting::GetAccessCheckTest(FileHandleDesiredAccess accessMask, CharBufferType& buffer, WindowsHandle impersonatedToken)
{
    AccessCheckGenericMapping genericMapping{};
    const auto fileMapGenericMask = GetFileMapGenericMask(accessMask, genericMapping);

    SecurityPrivilegeSet privileges{};
    WindowsDWord privilegeLength{ sizeof(privileges) };
    WindowsDWord grantedAccessList{ 0 };
    WindowsDWord accessStatusList{ 0 };
    SystemGloballyUniqueIdentifier objectType = { 0 };
    SecurityObjectTypeList objectTypeList{ 0, 1, &objectType };

    auto sid = GetSecuritySid();
    ASSERT_TRUE(GetAccessCheckByTypeResultList(buffer.data(), &sid, impersonatedToken, fileMapGenericMask, &objectTypeList, 1, &genericMapping, &privileges, &privilegeLength, &grantedAccessList, &accessStatusList));

    ASSERT_EQUAL(grantedAccessList, EnumCastUnderlying<WindowsDWord>(fileMapGenericMask));
    ASSERT_EQUAL(privilegeLength, sizeof(privileges));
}

System::SecuritySid System::AccessCheckByTypeResultListTesting::GetSecuritySid()
{
    SecuritySid sid{};
    SecuritySidIdentifierAuthority identifierAuthority SYSTEM_SECURITY_NT_AUTHORITY;

    constexpr WindowsByte subAuthorityCount{ 5 };

    ASSERT_TRUE(InitializeSecurityIdentifier(&sid, &identifierAuthority, subAuthorityCount));
    ASSERT_TRUE(IsSecurityIdentifierValid(&sid));

    return sid;
}
