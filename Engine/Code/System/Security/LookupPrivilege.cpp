///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.4 (2021/05/25 18:39)

#include "System/SystemExport.h"

#include "LookupPrivilege.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Security/Flags/LookupPrivilegeNameFlags.h"

using namespace std::literals;

bool System::GetLookupPrivilegeValue(const TChar* systemName, const TChar* name, LookupPrivilegeLUIDPtr luid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::LookupPrivilegeValue(systemName, name, luid)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<const TChar*, const TChar*, LookupPrivilegeLUIDPtr>(systemName, name, luid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetLookupPrivilegeName(const TChar* systemName, LookupPrivilegeLUIDPtr luid, TChar* name, WindowsDWordPtr nameSize) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::LookupPrivilegeName(systemName, luid, name, nameSize)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<const TChar*, LookupPrivilegeLUIDPtr, TChar*, WindowsDWordPtr>(systemName, luid, name, nameSize);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetLookupPrivilegeDisplayName(const TChar* systemName, const TChar* name, TChar* displayName, WindowsDWordPtr displayNameSize, WindowsDWordPtr languageID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::LookupPrivilegeDisplayName(systemName, name, displayName, displayNameSize, languageID)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<const TChar*, const TChar*, TChar*, WindowsDWordPtr, WindowsDWordPtr>(systemName, name, displayName, displayNameSize, languageID);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::String System::GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription lookupPrivilegeName)
{
#ifdef SYSTEM_PLATFORM_WIN32

    switch (lookupPrivilegeName)
    {
        case System::LookupPrivilegeNameDescription::CreateTokenName:
            return SE_CREATE_TOKEN_NAME;
        case System::LookupPrivilegeNameDescription::AssignPrimaryToken:
            return SE_ASSIGNPRIMARYTOKEN_NAME;
        case System::LookupPrivilegeNameDescription::LockMemoryName:
            return SE_LOCK_MEMORY_NAME;
        case System::LookupPrivilegeNameDescription::IncreaseQuotaName:
            return SE_INCREASE_QUOTA_NAME;
        case System::LookupPrivilegeNameDescription::UnsolicitedInputName:
            return SE_UNSOLICITED_INPUT_NAME;
        case System::LookupPrivilegeNameDescription::MachineAccountName:
            return SE_MACHINE_ACCOUNT_NAME;
        case System::LookupPrivilegeNameDescription::TcbName:
            return SE_TCB_NAME;
        case System::LookupPrivilegeNameDescription::SecurityName:
            return SE_SECURITY_NAME;
        case System::LookupPrivilegeNameDescription::TakeOwnershipName:
            return SE_TAKE_OWNERSHIP_NAME;
        case System::LookupPrivilegeNameDescription::LoadDriverName:
            return SE_LOAD_DRIVER_NAME;
        case System::LookupPrivilegeNameDescription::SystemProfileName:
            return SE_SYSTEM_PROFILE_NAME;
        case System::LookupPrivilegeNameDescription::SystemtimeName:
            return SE_SYSTEMTIME_NAME;
        case System::LookupPrivilegeNameDescription::ProfileSingleProcessName:
            return SE_PROF_SINGLE_PROCESS_NAME;
        case System::LookupPrivilegeNameDescription::IncreaseBasePriorityName:
            return SE_INC_BASE_PRIORITY_NAME;
        case System::LookupPrivilegeNameDescription::CreatePagefileName:
            return SE_CREATE_PAGEFILE_NAME;
        case System::LookupPrivilegeNameDescription::CreatePermanentName:
            return SE_CREATE_PERMANENT_NAME;
        case System::LookupPrivilegeNameDescription::BackupName:
            return SE_BACKUP_NAME;
        case System::LookupPrivilegeNameDescription::RestoreName:
            return SE_RESTORE_NAME;
        case System::LookupPrivilegeNameDescription::ShutdownName:
            return SE_SHUTDOWN_NAME;
        case System::LookupPrivilegeNameDescription::DebugName:
            return SE_DEBUG_NAME;
        case System::LookupPrivilegeNameDescription::AuditName:
            return SE_AUDIT_NAME;
        case System::LookupPrivilegeNameDescription::SystemEnvironmentName:
            return SE_SYSTEM_ENVIRONMENT_NAME;
        case System::LookupPrivilegeNameDescription::ChangeNotifyName:
            return SE_CHANGE_NOTIFY_NAME;
        case System::LookupPrivilegeNameDescription::RemoteShutdownName:
            return SE_REMOTE_SHUTDOWN_NAME;
        case System::LookupPrivilegeNameDescription::UndockName:
            return SE_UNDOCK_NAME;
        case System::LookupPrivilegeNameDescription::SyncAgentName:
            return SE_SYNC_AGENT_NAME;
        case System::LookupPrivilegeNameDescription::EnableDelegationName:
            return SE_ENABLE_DELEGATION_NAME;
        case System::LookupPrivilegeNameDescription::ManageVolumeName:
            return SE_MANAGE_VOLUME_NAME;
        case System::LookupPrivilegeNameDescription::ImpersonateName:
            return SE_IMPERSONATE_NAME;
        case System::LookupPrivilegeNameDescription::CreateGlobalName:
            return SE_CREATE_GLOBAL_NAME;
        case System::LookupPrivilegeNameDescription::TrustedCredManAccessName:
            return SE_TRUSTED_CREDMAN_ACCESS_NAME;
        case System::LookupPrivilegeNameDescription::RelabelName:
            return SE_RELABEL_NAME;
        case System::LookupPrivilegeNameDescription::IncreaseWorkingSetName:
            return SE_INC_WORKING_SET_NAME;
        case System::LookupPrivilegeNameDescription::TimeZoneName:
            return SE_TIME_ZONE_NAME;
        case System::LookupPrivilegeNameDescription::CreateSymbolicLinkName:
            return SE_CREATE_SYMBOLIC_LINK_NAME;
        default:
            return SYSTEM_TEXT(""s);
    }

#else  // !SYSTEM_PLATFORM_WIN32

    return SYSTEM_TEXT(""s);

#endif  // SYSTEM_PLATFORM_WIN32
}
