///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/06/03 14:09)

#include "AddAuditAccessObjectAceTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/SecuritySidMacro.h"
#include "System/Security/AddAccess.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "System/Security/SecurityAcl.h"
#include "System/Security/SecuritySid.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "System/Security/Flags/AddAccessFlags.h"
#include "System/Security/Flags/SecurityAceFlags.h"

#include <array>

using std::array;
using std::max;
using std::vector;

System::AddAuditAccessObjectAceTesting::AddAuditAccessObjectAceTesting(const OStreamShared& stream)
    : ParentType{ stream },
      controlACEInheritanceFlags{ ControlACEInheritance::ObjectInheritAce,
                                  ControlACEInheritance::ContainerInheritAce,
                                  ControlACEInheritance::NoPropagateInheritAce,
                                  ControlACEInheritance::InheritOnlyAce,
                                  ControlACEInheritance::InheritedAce,
                                  ControlACEInheritance::ValidInheritFlags },
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
                           SpecificAccess::WinstaAllAccess },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ max(controlACEInheritanceFlags.size(), specificAccessFlags.size()) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AddAuditAccessObjectAceTesting)

void System::AddAuditAccessObjectAceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AddAuditAccessObjectAceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffleFlags);
}

bool System::AddAuditAccessObjectAceTesting::RandomShuffleFlags()
{
    shuffle(controlACEInheritanceFlags.begin(), controlACEInheritanceFlags.end(), randomEngine);
    shuffle(specificAccessFlags.begin(), specificAccessFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(AddAuditAccessObjectAceTest);

    return true;
}

void System::AddAuditAccessObjectAceTesting::AddAuditAccessObjectAceTest()
{
    constexpr WindowsDWord newAclSize{ 2048 };

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

    for (auto index = 0u; index < maxSize; ++index)
    {
        auto controlACEInheritance = controlACEInheritanceFlags.at(index % controlACEInheritanceFlags.size());
        auto specificAccess = specificAccessFlags.at(index % specificAccessFlags.size());

        ASSERT_TRUE(AddAuditAccessObjectAccessControlEntries(acl, AccessControlListRevision::Revision, controlACEInheritance, specificAccess, nullptr, nullptr, &sid, false, true));
        ASSERT_TRUE(AddAuditAccessObjectAccessControlEntries(acl, AccessControlListRevision::Revision, controlACEInheritance, specificAccess, nullptr, nullptr, &sid, true, true));
        ASSERT_TRUE(AddAuditAccessObjectAccessControlEntries(acl, AccessControlListRevision::Revision, controlACEInheritance, specificAccess, nullptr, nullptr, &sid, false, false));
        ASSERT_TRUE(AddAuditAccessObjectAccessControlEntries(acl, AccessControlListRevision::Revision, controlACEInheritance, specificAccess, nullptr, nullptr, &sid, true, false));
    }
}
