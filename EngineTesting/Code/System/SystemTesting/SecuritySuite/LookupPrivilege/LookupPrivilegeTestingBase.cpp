///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/25 11:50)

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