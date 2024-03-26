/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 14:29)

#include "AdjustTokenPrivilegesTesting.h"
#include "System/Helper/SecuritySidMacro.h"
#include "System/Security/Flags/LookupPrivilegeNameFlags.h"
#include "System/Security/Flags/SecurityBaseFlags.h"
#include "System/Security/LookupPrivilege.h"
#include "System/Security/SecurityBase.h"
#include "System/Security/Using/SecurityBaseUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AdjustTokenPrivilegesTesting::AdjustTokenPrivilegesTesting(const OStreamShared& stream)
    : ParentType{ stream },
      lookupPrivilegeNames{ GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::CreateTokenName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::AssignPrimaryToken),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::LockMemoryName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::IncreaseQuotaName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::MachineAccountName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::TcbName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::SecurityName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::TakeOwnershipName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::LoadDriverName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::SystemProfileName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::SystemTimeName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::ProfileSingleProcessName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::IncreaseBasePriorityName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::CreatePageFileName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::CreatePermanentName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::BackupName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::RestoreName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::ShutdownName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::DebugName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::AuditName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::SystemEnvironmentName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::ChangeNotifyName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::RemoteShutdownName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::UnDockName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::SyncAgentName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::EnableDelegationName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::ManageVolumeName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::ImpersonateName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::CreateGlobalName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::TrustedCredManAccessName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::RelabelName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::IncreaseWorkingSetName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::TimeZoneName),
                            GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::CreateSymbolicLinkName) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AdjustTokenPrivilegesTesting)

void System::AdjustTokenPrivilegesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AdjustTokenPrivilegesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetAdjustTokenPrivilegesTest);
}

void System::AdjustTokenPrivilegesTesting::GetAdjustTokenPrivilegesTest()
{
    const auto tokenHandle = OpenProcessToken();

    ASSERT_NOT_THROW_EXCEPTION_1(DoGetAdjustTokenPrivilegesTest, tokenHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseTokenTest, tokenHandle);
}

void System::AdjustTokenPrivilegesTesting::DoGetAdjustTokenPrivilegesTest(WindowsHandle tokenHandle)
{
    for (const auto& lookupPrivilegeName : lookupPrivilegeNames)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(PrivilegesTest, lookupPrivilegeName, tokenHandle);
    }
}

void System::AdjustTokenPrivilegesTesting::PrivilegesTest(const String& lookupPrivilegeName, WindowsHandle tokenHandle)
{
    LookupPrivilegeLocallyUniqueIdentifier uid{};
    ASSERT_TRUE(GetLookupPrivilegeValue(nullptr, lookupPrivilegeName.c_str(), &uid));
    ASSERT_LESS(0u, uid.LowPart);

    SecurityTokenPrivileges state{};
    state.PrivilegeCount = 1;
    state.Privileges[0].Luid = uid;
    state.Privileges[0].Attributes = EnumCastUnderlying(SecurityTokenAttributesPrivilege::Enabled);

    SecurityTokenPrivileges previousState{};
    WindowsDWord returnLength{ 0 };
    ASSERT_TRUE(GetAdjustTokenPrivileges(tokenHandle, false, &state, sizeof(state), &previousState, &returnLength));
}
