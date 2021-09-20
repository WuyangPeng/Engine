///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/06/02 15:51)

#include "AddAccessAllowedAceTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/SecuritySidMacro.h"
#include "System/Security/AddAccess.h"
#include "System/Security/Flags/AddAccessFlags.h"
#include "System/Security/Flags/SecurityAceFlags.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "System/Security/SecurityAcl.h"
#include "System/Security/SecuritySid.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;
using std::vector;

System::AddAccessAllowedAceTesting::AddAccessAllowedAceTesting(const OStreamShared& stream)
    : ParentType{ stream },
      specificAccessFlags{ SpecificAccess::DesktopReadObjects,
                           SpecificAccess::DesktopCreateWindow,
                           SpecificAccess::DesktopCreateMenu,
                           SpecificAccess::DesktopHookControl,
                           SpecificAccess::DesktopJournalRecord,
                           SpecificAccess::DesktopJournalPlayBack,
                           SpecificAccess::DesktopEnumerate,
                           SpecificAccess::DesktopWriteObjects,
                           SpecificAccess::DesktopSwitchDesktop,
                           SpecificAccess::DesktopAllAccess,
                           SpecificAccess::WinstaEnumDesktops,
                           SpecificAccess::WinstaReadAttributes,
                           SpecificAccess::WinstaAccessClipboard,
                           SpecificAccess::WinstaCreateDesktop,
                           SpecificAccess::WinstaWriteAttributes,
                           SpecificAccess::WinstaAccessGlobatoms,
                           SpecificAccess::WinstaExitWindows,
                           SpecificAccess::WinstaEnumerate,
                           SpecificAccess::WinstaReadScreen,
                           SpecificAccess::WinstaAllAccess }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AddAccessAllowedAceTesting)

void System::AddAccessAllowedAceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AddAccessAllowedAceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AddAccessAllowedAccessControlEntriesTest);
}

void System::AddAccessAllowedAceTesting::AddAccessAllowedAccessControlEntriesTest()
{
    constexpr WindowsDWord newAclSize{ 512 };

    array<char, newAclSize> aclbuffer{};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    auto acl = reinterpret_cast<AccessCheckACLPtr>(aclbuffer.data());
#include STSTEM_WARNING_POP

    ASSERT_TRUE(InitializeAccessControlList(acl, newAclSize, AccessControlListRevision::Revision));
    ASSERT_TRUE(IsAccessControlListValid(acl));

    SecuritySID sid{};

    SecuritySIDIndentifierAuthority identifierAuthority SYSTEM_SECURITY_MANDATORY_LABEL_AUTHORITY;

    constexpr WindowsByte subAuthorityCount{ 1 };

    ASSERT_TRUE(InitializeSecurityIdentifier(&sid, &identifierAuthority, subAuthorityCount));
    ASSERT_TRUE(IsSecurityIdentifierValid(&sid));

    for (auto specificAccess : specificAccessFlags)
    {
        ASSERT_TRUE(AddAccessAllowedAccessControlEntries(acl, AccessControlListRevision::Revision, specificAccess, &sid));
    }
}
