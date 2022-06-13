///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 10:51)

#include "System/SystemExport.h"

#include "LookupPrivilege.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Security/Flags/LookupPrivilegeNameFlags.h"

#include <map>

using namespace std::literals;

bool System::GetLookupPrivilegeValue(const TChar* systemName, const TChar* name, LookupPrivilegeLUIDPtr luid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::LookupPrivilegeValue(systemName, name, luid)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(systemName, name, luid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetLookupPrivilegeName(const TChar* systemName, LookupPrivilegeLUIDPtr luid, TChar* name, WindowsDWordPtr nameSize) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::LookupPrivilegeName(systemName, luid, name, nameSize)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(systemName, luid, name, nameSize);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetLookupPrivilegeDisplayName(const TChar* systemName, const TChar* name, TChar* displayName, WindowsDWordPtr displayNameSize, WindowsDWordPtr languageID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::LookupPrivilegeDisplayName(systemName, name, displayName, displayNameSize, languageID)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(systemName, name, displayName, displayNameSize, languageID);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::String System::GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription lookupPrivilegeName)
{
#ifdef SYSTEM_PLATFORM_WIN32

    using DescriptionType = std::map<LookupPrivilegeNameDescription, String>;

    static const DescriptionType description{ { System::LookupPrivilegeNameDescription::CreateTokenName, SE_CREATE_TOKEN_NAME },
                                              { System::LookupPrivilegeNameDescription::AssignPrimaryToken, SE_ASSIGNPRIMARYTOKEN_NAME },
                                              { System::LookupPrivilegeNameDescription::LockMemoryName, SE_LOCK_MEMORY_NAME },
                                              { System::LookupPrivilegeNameDescription::IncreaseQuotaName, SE_INCREASE_QUOTA_NAME },
                                              { System::LookupPrivilegeNameDescription::UnsolicitedInputName, SE_UNSOLICITED_INPUT_NAME },
                                              { System::LookupPrivilegeNameDescription::MachineAccountName, SE_MACHINE_ACCOUNT_NAME },
                                              { System::LookupPrivilegeNameDescription::TcbName, SE_TCB_NAME },
                                              { System::LookupPrivilegeNameDescription::SecurityName, SE_SECURITY_NAME },
                                              { System::LookupPrivilegeNameDescription::TakeOwnershipName, SE_TAKE_OWNERSHIP_NAME },
                                              { System::LookupPrivilegeNameDescription::LoadDriverName, SE_LOAD_DRIVER_NAME },
                                              { System::LookupPrivilegeNameDescription::SystemProfileName, SE_SYSTEM_PROFILE_NAME },
                                              { System::LookupPrivilegeNameDescription::SystemtimeName, SE_SYSTEMTIME_NAME },
                                              { System::LookupPrivilegeNameDescription::ProfileSingleProcessName, SE_PROF_SINGLE_PROCESS_NAME },
                                              { System::LookupPrivilegeNameDescription::IncreaseBasePriorityName, SE_INC_BASE_PRIORITY_NAME },
                                              { System::LookupPrivilegeNameDescription::CreatePagefileName, SE_CREATE_PAGEFILE_NAME },
                                              { System::LookupPrivilegeNameDescription::CreatePermanentName, SE_CREATE_PERMANENT_NAME },
                                              { System::LookupPrivilegeNameDescription::BackupName, SE_BACKUP_NAME },
                                              { System::LookupPrivilegeNameDescription::RestoreName, SE_RESTORE_NAME },
                                              { System::LookupPrivilegeNameDescription::ShutdownName, SE_SHUTDOWN_NAME },
                                              { System::LookupPrivilegeNameDescription::DebugName, SE_DEBUG_NAME },
                                              { System::LookupPrivilegeNameDescription::AuditName, SE_AUDIT_NAME },
                                              { System::LookupPrivilegeNameDescription::SystemEnvironmentName, SE_SYSTEM_ENVIRONMENT_NAME },
                                              { System::LookupPrivilegeNameDescription::ChangeNotifyName, SE_CHANGE_NOTIFY_NAME },
                                              { System::LookupPrivilegeNameDescription::RemoteShutdownName, SE_REMOTE_SHUTDOWN_NAME },
                                              { System::LookupPrivilegeNameDescription::UndockName, SE_UNDOCK_NAME },
                                              { System::LookupPrivilegeNameDescription::SyncAgentName, SE_SYNC_AGENT_NAME },
                                              { System::LookupPrivilegeNameDescription::EnableDelegationName, SE_ENABLE_DELEGATION_NAME },
                                              { System::LookupPrivilegeNameDescription::ManageVolumeName, SE_MANAGE_VOLUME_NAME },
                                              { System::LookupPrivilegeNameDescription::ImpersonateName, SE_IMPERSONATE_NAME },
                                              { System::LookupPrivilegeNameDescription::CreateGlobalName, SE_CREATE_GLOBAL_NAME },
                                              { System::LookupPrivilegeNameDescription::TrustedCredManAccessName, SE_TRUSTED_CREDMAN_ACCESS_NAME },
                                              { System::LookupPrivilegeNameDescription::RelabelName, SE_RELABEL_NAME },
                                              { System::LookupPrivilegeNameDescription::IncreaseWorkingSetName, SE_INC_WORKING_SET_NAME },
                                              { System::LookupPrivilegeNameDescription::TimeZoneName, SE_TIME_ZONE_NAME },
                                              { System::LookupPrivilegeNameDescription::CreateSymbolicLinkName, SE_CREATE_SYMBOLIC_LINK_NAME } };

    const auto iter = description.find(lookupPrivilegeName);
    if (iter != description.cend())
    {
        return iter->second;
    }

    return String{};

#else  // !SYSTEM_PLATFORM_WIN32

    return SYSTEM_TEXT(""s);

#endif  // SYSTEM_PLATFORM_WIN32
}
