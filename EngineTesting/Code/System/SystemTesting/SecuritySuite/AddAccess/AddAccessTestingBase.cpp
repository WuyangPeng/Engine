/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 14:20)

#include "AddAccessTestingBase.h"
#include "System/Helper/SecuritySidMacro.h"
#include "System/Security/AddAccess.h"
#include "System/Security/Flags/AddAccessFlags.h"
#include "System/Security/Flags/SecurityAceFlags.h"
#include "System/Security/SecurityAcl.h"
#include "System/Security/SecuritySid.h"
#include "System/Security/Using/SecuritySidUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AddAccessTestingBase::AddAccessTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      controlAceInheritances{ ControlAceInheritance::ObjectInheritAce,
                              ControlAceInheritance::ContainerInheritAce,
                              ControlAceInheritance::NoPropagateInheritAce,
                              ControlAceInheritance::InheritOnlyAce,
                              ControlAceInheritance::InheritedAce,
                              ControlAceInheritance::ValidInheritFlags },
      specificAccesses{ SpecificAccess::DesktopReadObjects,
                        SpecificAccess::DesktopCreateWindow,
                        SpecificAccess::DesktopCreateMenu,
                        SpecificAccess::DesktopHookControl,
                        SpecificAccess::DesktopJournalRecord,
                        SpecificAccess::DesktopJournalPlayBack,
                        SpecificAccess::DesktopEnumerate,
                        SpecificAccess::DesktopWriteObjects,
                        SpecificAccess::DesktopSwitchDesktop,
                        SpecificAccess::DesktopAllAccess,
                        SpecificAccess::WinStaEnumDesktops,
                        SpecificAccess::WinStaReadAttributes,
                        SpecificAccess::WinStaAccessClipboard,
                        SpecificAccess::WinStaCreateDesktop,
                        SpecificAccess::WinStaWriteAttributes,
                        SpecificAccess::WinStaAccessGlobalAtoms,
                        SpecificAccess::WinStaExitWindows,
                        SpecificAccess::WinStaEnumerate,
                        SpecificAccess::WinStaReadScreen,
                        SpecificAccess::WinStaAllAccess },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ std::max(controlAceInheritances.size(), specificAccesses.size()) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AddAccessTestingBase)

void System::AddAccessTestingBase::RandomShuffle()
{
    SYSTEM_CLASS_IS_VALID_1;

    std::ranges::shuffle(controlAceInheritances, randomEngine);
    std::ranges::shuffle(specificAccesses, randomEngine);
}

System::AddAccessTestingBase::SpecificAccessContainerConstIter System::AddAccessTestingBase::GetSpecificAccessBegin() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return specificAccesses.cbegin();
}

System::AddAccessTestingBase::SpecificAccessContainerConstIter System::AddAccessTestingBase::GetSpecificAccessEnd() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return specificAccesses.cend();
}

System::AddAccessTestingBase::AclBufferType System::AddAccessTestingBase::GetAclBuffer(AccessControlListRevision accessControlListRevision)
{
    SYSTEM_CLASS_IS_VALID_1;

    AclBufferType aclBuffer{};

    const auto acl = GetAccessCheckAclPtr(aclBuffer);

    ASSERT_TRUE(InitializeAccessControlList(acl, aclBufferSize, accessControlListRevision));
    ASSERT_TRUE(IsAccessControlListValid(acl));

    return aclBuffer;
}

System::AccessCheckAclPtr System::AddAccessTestingBase::GetAccessCheckAclPtr(AclBufferType& aclBuffer) const noexcept
{
    SYSTEM_CLASS_IS_VALID_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<AccessCheckAclPtr>(aclBuffer.data());

#include SYSTEM_WARNING_POP
}

System::SecuritySid System::AddAccessTestingBase::GetSecuritySid()
{
    SYSTEM_CLASS_IS_VALID_1;

    SecuritySid sid{};
    SecuritySidIdentifierAuthority identifierAuthority SYSTEM_SECURITY_MANDATORY_LABEL_AUTHORITY;
    constexpr WindowsByte subAuthorityCount{ 1 };

    ASSERT_TRUE(InitializeSecurityIdentifier(&sid, &identifierAuthority, subAuthorityCount));
    ASSERT_TRUE(IsSecurityIdentifierValid(&sid));

    return sid;
}

size_t System::AddAccessTestingBase::GetMaxSize() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return maxSize;
}

System::SpecificAccess System::AddAccessTestingBase::GetSpecificAccess(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return specificAccesses.at(index % specificAccesses.size());
}

System::ControlAceInheritance System::AddAccessTestingBase::GetControlAceInheritance(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return controlAceInheritances.at(index % controlAceInheritances.size());
}
