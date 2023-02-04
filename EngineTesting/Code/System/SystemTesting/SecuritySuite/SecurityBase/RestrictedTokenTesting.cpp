///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/29 15:22)

#include "RestrictedTokenTesting.h"
#include "System/Helper/SecuritySidMacro.h"
#include "System/Security/Flags/LookupPrivilegeNameFlags.h"
#include "System/Security/Flags/SecurityBaseFlags.h"
#include "System/Security/LookupPrivilege.h"
#include "System/Security/SecurityBase.h"
#include "System/Security/SecuritySid.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::RestrictedTokenTesting::RestrictedTokenTesting(const OStreamShared& stream)
    : ParentType{ stream },
      specifiesAdditionalPrivilegeOptionses{ SpecifiesAdditionalPrivilegeOptions::Default,
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
    const auto tokenHandle = OpenProcessToken();

    ASSERT_NOT_THROW_EXCEPTION_1(DoCreateRestrictedTokenTest, tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseTokenTest, tokenHandle);
}

void System::RestrictedTokenTesting::DoCreateRestrictedTokenTest(WindowsHandle tokenHandle)
{
    SecuritySIDBufferType sid{};

    auto sidsToDisable = GetSidsToDisable(sid);
    auto privilegesToDelete = GetPrivilegesToDelete();
    auto sidsToRestrict = GetSidsToRestrict(sid);

    RestrictedTest(tokenHandle, sidsToDisable, privilegesToDelete, sidsToRestrict);
}

System::RestrictedTokenTesting::SecuritySidAndAttributesBufferType System::RestrictedTokenTesting::GetSidsToDisable(SecuritySIDBufferType& sid)
{
    SecuritySidAndAttributesBufferType sidsToDisable{};

    auto count = 0;
    for (auto& securitySidAndAttributes : sidsToDisable)
    {
        ASSERT_NOT_THROW_EXCEPTION_3(InitializeSecurityIdentifierTest, sid, count, securitySidAndAttributes);

        ++count;
    }

    return sidsToDisable;
}

void System::RestrictedTokenTesting::InitializeSecurityIdentifierTest(SecuritySIDBufferType& sid, int count, SecuritySidAndAttributes& securitySidAndAttributes)
{
    constexpr WindowsByte subAuthorityCount{ 5 };
    SecuritySIDIndentifierAuthority identifierAuthority SYSTEM_SECURITY_NT_AUTHORITY;
    auto& securitySID = sid.at(count);

    ASSERT_TRUE(InitializeSecurityIdentifier(&securitySID, &identifierAuthority, subAuthorityCount));
    ASSERT_TRUE(IsSecurityIdentifierValid(&securitySID));
    securitySidAndAttributes.Sid = &securitySID;
}

System::RestrictedTokenTesting::LUIDAndAttributesBufferType System::RestrictedTokenTesting::GetPrivilegesToDelete()
{
    LUIDAndAttributesBufferType privilegesToDelete{};

    for (auto& luidAndAttributes : privilegesToDelete)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(GetLookupPrivilegeValueTest, luidAndAttributes);
    }

    return privilegesToDelete;
}

void System::RestrictedTokenTesting::GetLookupPrivilegeValueTest(LUIDAndAttributes& lUIDAndAttributes)
{
    LookupPrivilegeLUID uid{};

    ASSERT_TRUE(GetLookupPrivilegeValue(nullptr, GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::DebugName).c_str(), &uid));

    lUIDAndAttributes.Luid = uid;
    lUIDAndAttributes.Attributes = EnumCastUnderlying(SecurityTokenAttributesPrivilege::Enabled);
}

System::RestrictedTokenTesting::SecuritySidAndAttributesBufferType System::RestrictedTokenTesting::GetSidsToRestrict(SecuritySIDBufferType& sid)
{
    auto count = securityBufferSize;
    SecuritySidAndAttributesBufferType sidsToRestrict{};
    for (auto& securitySidAndAttributes : sidsToRestrict)
    {
        ASSERT_NOT_THROW_EXCEPTION_3(InitializeSecurityIdentifierTest, sid, count, securitySidAndAttributes);

        ++count;
    }

    return sidsToRestrict;
}

void System::RestrictedTokenTesting::RestrictedTest(WindowsHandle tokenHandle,
                                                    SecuritySidAndAttributesBufferType& sidsToDisable,
                                                    LUIDAndAttributesBufferType& privilegesToDelete,
                                                    SecuritySidAndAttributesBufferType& sidsToRestrict)
{
    for (auto specifiesAdditionalPrivilegeOptions : specifiesAdditionalPrivilegeOptionses)
    {
        DoRestrictedTest(tokenHandle, specifiesAdditionalPrivilegeOptions, sidsToDisable, privilegesToDelete, sidsToRestrict);
    }
}

void System::RestrictedTokenTesting::DoRestrictedTest(WindowsHandle tokenHandle,
                                                      SpecifiesAdditionalPrivilegeOptions specifiesAdditionalPrivilegeOptions,
                                                      SecuritySidAndAttributesBufferType& sidsToDisable,
                                                      LUIDAndAttributesBufferType& privilegesToDelete,
                                                      SecuritySidAndAttributesBufferType& sidsToRestrict)
{
    WindowsHandle restrictedTokenHandle{ nullptr };
    ASSERT_TRUE(CreateSystemRestrictedToken(tokenHandle,
                                            specifiesAdditionalPrivilegeOptions,
                                            securityBufferSize,
                                            sidsToDisable.data(),
                                            securityBufferSize,
                                            privilegesToDelete.data(),
                                            securityBufferSize,
                                            sidsToRestrict.data(),
                                            &restrictedTokenHandle));

    ASSERT_TRUE(IsSystemTokenRestricted(restrictedTokenHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CloseTokenTest, restrictedTokenHandle);
}
