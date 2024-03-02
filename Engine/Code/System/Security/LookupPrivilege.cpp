/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/28 11:00)

#include "System/SystemExport.h"

#include "LookupPrivilege.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Security/Flags/LookupPrivilegeNameFlags.h"

#include <map>

bool System::GetLookupPrivilegeValue(const TChar* systemName, const TChar* name, LookupPrivilegeLocallyUniqueIdentifierPtr locallyUniqueIdentifier) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return (::LookupPrivilegeValue(systemName, name, locallyUniqueIdentifier)) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(systemName, name, locallyUniqueIdentifier);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetLookupPrivilegeName(const TChar* systemName, LookupPrivilegeLocallyUniqueIdentifierPtr locallyUniqueIdentifier, TChar* name, WindowsDWordPtr nameSize) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return (::LookupPrivilegeName(systemName, locallyUniqueIdentifier, name, nameSize)) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(systemName, locallyUniqueIdentifier, name, nameSize);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetLookupPrivilegeDisplayName(const TChar* systemName, const TChar* name, TChar* displayName, WindowsDWordPtr displayNameSize, WindowsDWordPtr languageId) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return (::LookupPrivilegeDisplayName(systemName, name, displayName, displayNameSize, languageId)) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(systemName, name, displayName, displayNameSize, languageId);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::String System::GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription lookupPrivilegeName)
{
#ifdef SYSTEM_PLATFORM_WIN32

    using DescriptionType = std::map<LookupPrivilegeNameDescription, String>;

    static const DescriptionType description{ { LookupPrivilegeNameDescription::CreateTokenName, SE_CREATE_TOKEN_NAME },
                                              { LookupPrivilegeNameDescription::AssignPrimaryToken, SE_ASSIGNPRIMARYTOKEN_NAME },
                                              { LookupPrivilegeNameDescription::LockMemoryName, SE_LOCK_MEMORY_NAME },
                                              { LookupPrivilegeNameDescription::IncreaseQuotaName, SE_INCREASE_QUOTA_NAME },
                                              { LookupPrivilegeNameDescription::UnsolicitedInputName, SE_UNSOLICITED_INPUT_NAME },
                                              { LookupPrivilegeNameDescription::MachineAccountName, SE_MACHINE_ACCOUNT_NAME },
                                              { LookupPrivilegeNameDescription::TcbName, SE_TCB_NAME },
                                              { LookupPrivilegeNameDescription::SecurityName, SE_SECURITY_NAME },
                                              { LookupPrivilegeNameDescription::TakeOwnershipName, SE_TAKE_OWNERSHIP_NAME },
                                              { LookupPrivilegeNameDescription::LoadDriverName, SE_LOAD_DRIVER_NAME },
                                              { LookupPrivilegeNameDescription::SystemProfileName, SE_SYSTEM_PROFILE_NAME },
                                              { LookupPrivilegeNameDescription::SystemTimeName, SE_SYSTEMTIME_NAME },
                                              { LookupPrivilegeNameDescription::ProfileSingleProcessName, SE_PROF_SINGLE_PROCESS_NAME },
                                              { LookupPrivilegeNameDescription::IncreaseBasePriorityName, SE_INC_BASE_PRIORITY_NAME },
                                              { LookupPrivilegeNameDescription::CreatePageFileName, SE_CREATE_PAGEFILE_NAME },
                                              { LookupPrivilegeNameDescription::CreatePermanentName, SE_CREATE_PERMANENT_NAME },
                                              { LookupPrivilegeNameDescription::BackupName, SE_BACKUP_NAME },
                                              { LookupPrivilegeNameDescription::RestoreName, SE_RESTORE_NAME },
                                              { LookupPrivilegeNameDescription::ShutdownName, SE_SHUTDOWN_NAME },
                                              { LookupPrivilegeNameDescription::DebugName, SE_DEBUG_NAME },
                                              { LookupPrivilegeNameDescription::AuditName, SE_AUDIT_NAME },
                                              { LookupPrivilegeNameDescription::SystemEnvironmentName, SE_SYSTEM_ENVIRONMENT_NAME },
                                              { LookupPrivilegeNameDescription::ChangeNotifyName, SE_CHANGE_NOTIFY_NAME },
                                              { LookupPrivilegeNameDescription::RemoteShutdownName, SE_REMOTE_SHUTDOWN_NAME },
                                              { LookupPrivilegeNameDescription::UnDockName, SE_UNDOCK_NAME },
                                              { LookupPrivilegeNameDescription::SyncAgentName, SE_SYNC_AGENT_NAME },
                                              { LookupPrivilegeNameDescription::EnableDelegationName, SE_ENABLE_DELEGATION_NAME },
                                              { LookupPrivilegeNameDescription::ManageVolumeName, SE_MANAGE_VOLUME_NAME },
                                              { LookupPrivilegeNameDescription::ImpersonateName, SE_IMPERSONATE_NAME },
                                              { LookupPrivilegeNameDescription::CreateGlobalName, SE_CREATE_GLOBAL_NAME },
                                              { LookupPrivilegeNameDescription::TrustedCredManAccessName, SE_TRUSTED_CREDMAN_ACCESS_NAME },
                                              { LookupPrivilegeNameDescription::RelabelName, SE_RELABEL_NAME },
                                              { LookupPrivilegeNameDescription::IncreaseWorkingSetName, SE_INC_WORKING_SET_NAME },
                                              { LookupPrivilegeNameDescription::TimeZoneName, SE_TIME_ZONE_NAME },
                                              { LookupPrivilegeNameDescription::CreateSymbolicLinkName, SE_CREATE_SYMBOLIC_LINK_NAME } };

    if (const auto iter = description.find(lookupPrivilegeName);
        iter != description.cend())
    {
        return iter->second;
    }

#endif  // SYSTEM_PLATFORM_WIN32

    return String{};
}
