///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/06/04 14:27)

#include "AccessCheckTesting.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/SecuritySidMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Security/AccessCheck.h"
#include "System/Security/CreateSecurity.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "System/Security/SecurityBase.h"
#include "System/Security/SecuritySid.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/ProcessTools.h"
#include "System/Threading/ThreadTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;
using namespace std::literals;

System::AccessCheckTesting::AccessCheckTesting(const OStreamShared& stream)
    : ParentType{ stream },
      fileHandleDesiredAccess{ FileHandleDesiredAccess::Read, FileHandleDesiredAccess::Write, FileHandleDesiredAccess::Execute, FileHandleDesiredAccess::ReadWrite }
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
    ASSERT_NOT_THROW_EXCEPTION_0(AccessCheckByTypeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessCheckByTypeResultListTest);
}

void System::AccessCheckTesting::AccessCheckTest()
{
    const auto existingFileName = SYSTEM_TEXT("Resource/FileTesting/CreateExistingFile.txt"s);

    const auto requestedInformation = (SecurityRequestedInformation::Owner) | (SecurityRequestedInformation::Group) | (SecurityRequestedInformation::Dacl);
    WindowsDWord neededLength{ 0 };

    ASSERT_FALSE(GetSystemFileSecurity(existingFileName, requestedInformation, nullptr, 0, &neededLength));

    constexpr WindowsDWord bufferSize{ 512 };

    array<char, bufferSize> buffer{};

    ASSERT_LESS(neededLength, bufferSize);

    WindowsDWord newNeededLength{ 0 };
    ASSERT_TRUE(GetSystemFileSecurity(existingFileName, requestedInformation, buffer.data(), neededLength, &newNeededLength));
    ASSERT_EQUAL(newNeededLength, neededLength);

    WindowsHandle tokenHandle{ nullptr };
    ASSERT_TRUE(OpenSysemProcessToken(GetCurrentProcessHandle(), TokenStandardAccess::Default, TokenSpecificAccess::AllAccess, &tokenHandle));

    WindowsHandle impersonatedToken{ nullptr };
    ASSERT_TRUE(DuplicateSystemToken(tokenHandle, SecurityImpersonation, &impersonatedToken));

    for (auto accessMask : fileHandleDesiredAccess)
    {
        AccessCheckGenericMapping genericMapping{};

        const auto fileMapGenericMask = GetFileMapGenericMask(accessMask, genericMapping);

        SecurityPrivilegeSet privileges{};

        WindowsDWord grantedAccess{ 0 };
        WindowsDWord privLength{ sizeof(privileges) };
        auto accessStatus = false;

        ASSERT_TRUE(GetAccessCheck(buffer.data(), impersonatedToken, fileMapGenericMask, &genericMapping, &privileges, &privLength, &grantedAccess, &accessStatus));

        ASSERT_EQUAL(grantedAccess, EnumCastUnderlying<WindowsDWord>(fileMapGenericMask));
        ASSERT_EQUAL(privLength, sizeof(privileges));
        ASSERT_EQUAL(accessStatus, true);
    }

    ASSERT_TRUE(CloseTokenHandle(tokenHandle));
    ASSERT_TRUE(CloseTokenHandle(impersonatedToken));
}

void System::AccessCheckTesting::AccessCheckByTypeTest()
{
    const auto existingFileName = SYSTEM_TEXT("Resource/FileTesting/CreateExistingFile.txt"s);

    const auto requestedInformation = (SecurityRequestedInformation::Owner) | (SecurityRequestedInformation::Group) | (SecurityRequestedInformation::Dacl);
    WindowsDWord neededLength{ 0 };

    ASSERT_FALSE(GetSystemFileSecurity(existingFileName, requestedInformation, nullptr, 0, &neededLength));

    constexpr WindowsDWord bufferSize{ 512 };

    array<char, bufferSize> buffer{};

    ASSERT_LESS(neededLength, bufferSize);

    WindowsDWord newNeededLength{ 0 };
    ASSERT_TRUE(GetSystemFileSecurity(existingFileName, requestedInformation, buffer.data(), neededLength, &newNeededLength));
    ASSERT_EQUAL(newNeededLength, neededLength);

    WindowsHandle tokenHandle{ nullptr };
    ASSERT_TRUE(OpenSysemProcessToken(GetCurrentProcessHandle(), TokenStandardAccess::Default, TokenSpecificAccess::AllAccess, &tokenHandle));

    WindowsHandle impersonatedToken{ nullptr };
    ASSERT_TRUE(DuplicateSystemToken(tokenHandle, SecurityImpersonation, &impersonatedToken));

    for (auto accessMask : fileHandleDesiredAccess)
    {
        AccessCheckGenericMapping genericMapping{};

        const auto fileMapGenericMask = GetFileMapGenericMask(accessMask, genericMapping);

        SecurityPrivilegeSet privileges{};

        WindowsDWord grantedAccess{ 0 };
        WindowsDWord privLength{ sizeof(privileges) };
        auto accessStatus = false;

        ASSERT_TRUE(GetAccessCheckByType(buffer.data(), nullptr, impersonatedToken, fileMapGenericMask, nullptr, 0, &genericMapping, &privileges, &privLength, &grantedAccess, &accessStatus));

        ASSERT_EQUAL(grantedAccess, EnumCastUnderlying<WindowsDWord>(fileMapGenericMask));
        ASSERT_EQUAL(privLength, sizeof(privileges));
        ASSERT_EQUAL(accessStatus, true);
    }

    ASSERT_TRUE(CloseTokenHandle(tokenHandle));
    ASSERT_TRUE(CloseTokenHandle(impersonatedToken));
}

void System::AccessCheckTesting::AccessCheckByTypeResultListTest()
{
    const auto existingFileName = SYSTEM_TEXT("Resource/FileTesting/CreateExistingFile.txt"s);

    const auto requestedInformation = (SecurityRequestedInformation::Owner) | (SecurityRequestedInformation::Group) | (SecurityRequestedInformation::Dacl);
    WindowsDWord neededLength{ 0 };

    ASSERT_FALSE(GetSystemFileSecurity(existingFileName, requestedInformation, nullptr, 0, &neededLength));

    constexpr WindowsDWord bufferSize{ 512 };

    array<char, bufferSize> buffer{};

    ASSERT_LESS(neededLength, bufferSize);

    WindowsDWord newNeededLength{ 0 };
    ASSERT_TRUE(GetSystemFileSecurity(existingFileName, requestedInformation, buffer.data(), neededLength, &newNeededLength));
    ASSERT_EQUAL(newNeededLength, neededLength);

    WindowsHandle tokenHandle{ nullptr };
    ASSERT_TRUE(OpenSysemProcessToken(GetCurrentProcessHandle(), TokenStandardAccess::Default, TokenSpecificAccess::AllAccess, &tokenHandle));

    WindowsHandle impersonatedToken{ nullptr };
    ASSERT_TRUE(DuplicateSystemToken(tokenHandle, SecurityImpersonation, &impersonatedToken));

    SecuritySID sid{};
    SecuritySIDIndentifierAuthority identifierAuthority SYSTEM_SECURITY_NT_AUTHORITY;

    constexpr WindowsByte subAuthorityCount{ 5 };

    ASSERT_TRUE(InitializeSecurityIdentifier(&sid, &identifierAuthority, subAuthorityCount));
    ASSERT_TRUE(IsSecurityIdentifierValid(&sid));

    for (auto accessMask : fileHandleDesiredAccess)
    {
        AccessCheckGenericMapping genericMapping{};

        const auto fileMapGenericMask = GetFileMapGenericMask(accessMask, genericMapping);

        SecurityPrivilegeSet privileges{};
        WindowsDWord privLength{ sizeof(privileges) };
        WindowsDWord grantedAccessList{ 0 };
        WindowsDWord accessStatusList{ 0 };
        SystemGUID objectType = { 0 };
        SecurityObjectTypeList objectTypeList{ 0, 1, &objectType };

        ASSERT_TRUE(GetAccessCheckByTypeResultList(buffer.data(), &sid, impersonatedToken, fileMapGenericMask, &objectTypeList, 1, &genericMapping, &privileges, &privLength, &grantedAccessList, &accessStatusList));

        ASSERT_EQUAL(grantedAccessList, EnumCastUnderlying<WindowsDWord>(fileMapGenericMask));
        ASSERT_EQUAL(privLength, sizeof(privileges));
    }

    ASSERT_TRUE(CloseTokenHandle(tokenHandle));
    ASSERT_TRUE(CloseTokenHandle(impersonatedToken));
}
