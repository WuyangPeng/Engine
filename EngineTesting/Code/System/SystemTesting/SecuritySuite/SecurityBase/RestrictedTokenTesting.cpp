///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 15:46)

#include "RestrictedTokenTesting.h"
#include "System/Helper/SecuritySidMacro.h"
#include "System/Security/Flags/LookupPrivilegeNameFlags.h"
#include "System/Security/Flags/SecurityBaseFlags.h"
#include "System/Security/LookupPrivilege.h"
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

System::RestrictedTokenTesting::RestrictedTokenTesting(const OStreamShared& stream)
    : ParentType{ stream },
      specifiesAdditionalPrivilegeOptionsFlags{ SpecifiesAdditionalPrivilegeOptions::Default,
                                                SpecifiesAdditionalPrivilegeOptions::DisableMaxPrivilege,
                                                SpecifiesAdditionalPrivilegeOptions::SandboxInert,
                                                SpecifiesAdditionalPrivilegeOptions::LuaToken,
                                                SpecifiesAdditionalPrivilegeOptions::WriteRestricted }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, RestrictedTokenTesting)

void System::RestrictedTokenTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::RestrictedTokenTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateRestrictedTokenTest);
}

void System::RestrictedTokenTesting::CreateRestrictedTokenTest()
{
    WindowsHandle tokenHandle{ nullptr };
    ASSERT_TRUE(OpenSysemProcessToken(GetCurrentProcessHandle(), TokenStandardAccess::Default, TokenSpecificAccess::AllAccess, &tokenHandle));

    constexpr WindowsDWord bufferSize{ 2 };
    array<SecuritySID, bufferSize * 2> sid{};
    array<SecuritySidAndAttributes, bufferSize> sidsToDisable{};

    int count{ 0 };
    for (auto& securitySidAndAttributes : sidsToDisable)
    {
        constexpr WindowsByte subAuthorityCount{ 5 };
        SecuritySIDIndentifierAuthority identifierAuthority SYSTEM_SECURITY_NT_AUTHORITY;
        auto& securitySID = sid.at(count);

        ASSERT_TRUE(InitializeSecurityIdentifier(&securitySID, &identifierAuthority, subAuthorityCount));
        ASSERT_TRUE(IsSecurityIdentifierValid(&securitySID));
        securitySidAndAttributes.Sid = &securitySID;

        ++count;
    }

    array<LUIDAndAttributes, bufferSize> privilegesToDelete{};

    for (auto& lUIDAndAttributes : privilegesToDelete)
    {
        LookupPrivilegeLUID uid{};

        ASSERT_TRUE(GetLookupPrivilegeValue(nullptr, GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::DebugName).c_str(), &uid));

        lUIDAndAttributes.Luid = uid;
        lUIDAndAttributes.Attributes = EnumCastUnderlying(SecurityTokenAttributesPrivilege::Enabled);
    }

    array<SecuritySidAndAttributes, bufferSize> sidsToRestrict{};
    for (auto& securitySidAndAttributes : sidsToRestrict)
    {
        SecuritySIDIndentifierAuthority identifierAuthority SYSTEM_SECURITY_NT_AUTHORITY;
        constexpr WindowsByte subAuthorityCount{ 5 };
        auto& securitySID = sid.at(count);

        ASSERT_TRUE(InitializeSecurityIdentifier(&securitySID, &identifierAuthority, subAuthorityCount));
        ASSERT_TRUE(IsSecurityIdentifierValid(&securitySID));
        securitySidAndAttributes.Sid = &securitySID;

        ++count;
    }

    for (auto specifiesAdditionalPrivilegeOptions : specifiesAdditionalPrivilegeOptionsFlags)
    {
        WindowsHandle newTokenHandle{ nullptr };
        ASSERT_TRUE(CreateSystemRestrictedToken(tokenHandle,
                                                specifiesAdditionalPrivilegeOptions,
                                                bufferSize,
                                                sidsToDisable.data(),
                                                bufferSize,
                                                privilegesToDelete.data(),
                                                bufferSize,
                                                sidsToRestrict.data(),
                                                &newTokenHandle));

        ASSERT_TRUE(IsSystemTokenRestricted(newTokenHandle));

        ASSERT_TRUE(CloseTokenHandle(newTokenHandle));
    }

    ASSERT_TRUE(CloseTokenHandle(tokenHandle));
}
