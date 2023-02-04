///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/27 23:42)

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
      controlACEInheritances{ ControlACEInheritance::ObjectInheritAce,
                              ControlACEInheritance::ContainerInheritAce,
                              ControlACEInheritance::NoPropagateInheritAce,
                              ControlACEInheritance::InheritOnlyAce,
                              ControlACEInheritance::InheritedAce,
                              ControlACEInheritance::ValidInheritFlags },
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
      maxSize{ std::max(controlACEInheritances.size(), specificAccesses.size()) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AddAccessTestingBase)

void System::AddAccessTestingBase::RandomShuffle()
{
    SYSTEM_CLASS_IS_VALID_1;

    shuffle(controlACEInheritances.begin(), controlACEInheritances.end(), randomEngine);
    shuffle(specificAccesses.begin(), specificAccesses.end(), randomEngine);
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

System::AddAccessTestingBase::ACLBufferType System::AddAccessTestingBase::GetACLBuffer(AccessControlListRevision accessControlListRevision)
{
    SYSTEM_CLASS_IS_VALID_1;

    ACLBufferType aclBuffer{};

    auto acl = GetAccessCheckACLPtr(aclBuffer);

    ASSERT_TRUE(InitializeAccessControlList(acl, aclBufferSize, accessControlListRevision));
    ASSERT_TRUE(IsAccessControlListValid(acl));

    return aclBuffer;
}

System::AccessCheckACLPtr System::AddAccessTestingBase::GetAccessCheckACLPtr(ACLBufferType& aclBuffer) const noexcept
{
    SYSTEM_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<AccessCheckACLPtr>(aclBuffer.data());

#include STSTEM_WARNING_POP
}

System::SecuritySID System::AddAccessTestingBase::GetSecuritySID()
{
    SYSTEM_CLASS_IS_VALID_1;

    SecuritySID sid{};
    SecuritySIDIndentifierAuthority identifierAuthority SYSTEM_SECURITY_MANDATORY_LABEL_AUTHORITY;
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

System::ControlACEInheritance System::AddAccessTestingBase::GetControlACEInheritance(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return controlACEInheritances.at(index % controlACEInheritances.size());
}
