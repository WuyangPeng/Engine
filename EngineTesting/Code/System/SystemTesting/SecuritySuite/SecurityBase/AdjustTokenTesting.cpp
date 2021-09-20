///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/06/04 10:22)

#include "AdjustTokenTesting.h"
#include "System/Helper/SecuritySidMacro.h"
#include "System/Security/Flags/LookupPrivilegeNameFlags.h"
#include "System/Security/Flags/SecurityBaseFlags.h"
#include "System/Security/LookupPrivilege.h"
#include "System/Security/SecurityBase.h"
#include "System/Security/SecuritySid.h"
#include "System/Security/Using/SecurityBaseUsing.h"
#include "System/Security/Using/SecuritySidUsing.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/ProcessTools.h"
#include "System/Threading/ThreadTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;

System::AdjustTokenTesting::AdjustTokenTesting(const OStreamShared& stream)
    : ParentType{ stream },
      lookupPrivilegeName{ GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::CreateTokenName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::AssignPrimaryToken),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::LockMemoryName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::IncreaseQuotaName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::MachineAccountName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::TcbName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::SecurityName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::TakeOwnershipName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::LoadDriverName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::SystemProfileName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::SystemtimeName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::ProfileSingleProcessName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::IncreaseBasePriorityName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::CreatePagefileName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::CreatePermanentName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::BackupName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::RestoreName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::ShutdownName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::DebugName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::AuditName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::SystemEnvironmentName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::ChangeNotifyName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::RemoteShutdownName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::UndockName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::SyncAgentName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::EnableDelegationName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::ManageVolumeName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::ImpersonateName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::CreateGlobalName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::TrustedCredManAccessName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::RelabelName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::IncreaseWorkingSetName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::TimeZoneName),
                           GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::CreateSymbolicLinkName) },
      securityTokenAttributesGroupFlags{ SecurityTokenAttributesGroup::Mandatory,
                                         SecurityTokenAttributesGroup::EnabledByDefault,
                                         SecurityTokenAttributesGroup::Enabled,
                                         SecurityTokenAttributesGroup::Owner,
                                         SecurityTokenAttributesGroup::UseForDenyOnly,
                                         SecurityTokenAttributesGroup::Integrity,
                                         SecurityTokenAttributesGroup::IntegrityEnabled,
                                         SecurityTokenAttributesGroup::LogonId,
                                         SecurityTokenAttributesGroup::Resource,
                                         SecurityTokenAttributesGroup::ValidAttributes }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AdjustTokenTesting)

void System::AdjustTokenTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AdjustTokenTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetAdjustTokenPrivilegesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetAdjustTokenGroupsTest);
}

void System::AdjustTokenTesting::GetAdjustTokenPrivilegesTest()
{
    for (const auto& value : lookupPrivilegeName)
    {
        LookupPrivilegeLUID uid{};
        ASSERT_TRUE(GetLookupPrivilegeValue(nullptr, value.c_str(), &uid));
        ASSERT_LESS(0u, uid.LowPart);

        WindowsHandle tokenHandle{ nullptr };
        ASSERT_TRUE(OpenSysemProcessToken(GetCurrentProcessHandle(), TokenStandardAccess::Default, TokenSpecificAccess::AllAccess, &tokenHandle));

        SecurityTokenPrivileges tp{};
        tp.PrivilegeCount = 1;
        tp.Privileges[0].Luid = uid;
        tp.Privileges[0].Attributes = EnumCastUnderlying(SecurityTokenAttributesPrivilege::Enabled);

        SecurityTokenPrivileges previousState{};
        WindowsDWord returnLength{ 0 };
        ASSERT_TRUE(GetAdjustTokenPrivileges(tokenHandle, false, &tp, sizeof(tp), &previousState, &returnLength));
    }
}

void System::AdjustTokenTesting::GetAdjustTokenGroupsTest()
{
    WindowsHandle tokenHandle{ nullptr };
    ASSERT_TRUE(OpenSysemProcessToken(GetCurrentProcessHandle(), TokenStandardAccess::Default, TokenSpecificAccess::AllAccess, &tokenHandle));

    for (auto securityTokenAttributesGroup : securityTokenAttributesGroupFlags)
    {
        SecuritySID sid{};

        SecuritySIDIndentifierAuthority identifierAuthority SYSTEM_SECURITY_NT_AUTHORITY;

        constexpr WindowsByte subAuthorityCount{ 5 };

        ASSERT_TRUE(InitializeSecurityIdentifier(&sid, &identifierAuthority, subAuthorityCount));
        ASSERT_TRUE(IsSecurityIdentifierValid(&sid));

        SecurityTokenGroups newState{};
        newState.GroupCount = 1;
        (*newState.Groups).Sid = &sid;
        (*newState.Groups).Attributes = EnumCastUnderlying(securityTokenAttributesGroup);

        SecurityTokenGroups previousState{};
        WindowsDWord returnLength{ 0 };
        ASSERT_TRUE(GetAdjustTokenGroups(tokenHandle, true, &newState, sizeof(newState), &previousState, &returnLength));
    }

    ASSERT_TRUE(CloseTokenHandle(tokenHandle));
}
