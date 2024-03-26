/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 14:23)

#include "LookupPrivilegeTestingBase.h"
#include "System/Security/Flags/LookupPrivilegeNameFlags.h"
#include "System/Security/LookupPrivilege.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::LookupPrivilegeTestingBase::LookupPrivilegeTestingBase(const OStreamShared& stream)
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

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LookupPrivilegeTestingBase)

System::LookupPrivilegeTestingBase::LookupPrivilegeNameContainerConstIter System::LookupPrivilegeTestingBase::begin() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return lookupPrivilegeNames.cbegin();
}

System::LookupPrivilegeTestingBase::LookupPrivilegeNameContainerConstIter System::LookupPrivilegeTestingBase::end() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return lookupPrivilegeNames.cend();
}
