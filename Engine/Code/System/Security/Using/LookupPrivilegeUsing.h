// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:53)

#ifndef SYSTEM_SECURITY_LOOKUP_PRIVILEGE_USING_H
#define SYSTEM_SECURITY_LOOKUP_PRIVILEGE_USING_H

#include "System/Helper/Platform.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Helper/PragmaWarning.h"

#include <string>

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	using LookupPrivilegeLUID = LUID;
	using LookupPrivilegeLUIDPtr = PLUID;

	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26426)
	const String g_LookupPrivilegeNameCreateTokenName{ SE_CREATE_TOKEN_NAME };
	const String g_LookupPrivilegeNameAssignPrimaryToken{ SE_ASSIGNPRIMARYTOKEN_NAME };
	const String g_LookupPrivilegeNameLockMemoryName{ SE_LOCK_MEMORY_NAME };
	const String g_LookupPrivilegeNameIncreaseQuotaName{ SE_INCREASE_QUOTA_NAME };
	const String g_LookupPrivilegeNameUnsolicitedInputName{ SE_UNSOLICITED_INPUT_NAME };
	const String g_LookupPrivilegeNameMachineAccountName{ SE_MACHINE_ACCOUNT_NAME };
	const String g_LookupPrivilegeNameTcbName{ SE_TCB_NAME };
	const String g_LookupPrivilegeNameSecurityName{ SE_SECURITY_NAME };
	const String g_LookupPrivilegeNameTakeOwnershipName{ SE_TAKE_OWNERSHIP_NAME };
	const String g_LookupPrivilegeNameLoadDriverName{ SE_LOAD_DRIVER_NAME };
	const String g_LookupPrivilegeNameSystemProfileName{ SE_SYSTEM_PROFILE_NAME };
	const String g_LookupPrivilegeNameSystemtimeName{ SE_SYSTEMTIME_NAME };
	const String g_LookupPrivilegeNameProfileSingleProcessName{ SE_PROF_SINGLE_PROCESS_NAME };
	const String g_LookupPrivilegeNamencreaseBasePriorityName{ SE_INC_BASE_PRIORITY_NAME };
	const String g_LookupPrivilegeNameCreatePagefileName{ SE_CREATE_PAGEFILE_NAME };
	const String g_LookupPrivilegeNameCreatePermanentName{ SE_CREATE_PERMANENT_NAME };
	const String g_LookupPrivilegeNameBackupName{ SE_BACKUP_NAME };
	const String g_LookupPrivilegeNameRestoreName{ SE_RESTORE_NAME };
	const String g_LookupPrivilegeNameShutdownName{ SE_SHUTDOWN_NAME };
	const String g_LookupPrivilegeNameDebugName{ SE_DEBUG_NAME };
	const String g_LookupPrivilegeNameAuditName{ SE_AUDIT_NAME };
	const String g_LookupPrivilegeNameSystemEnvironmentName{ SE_SYSTEM_ENVIRONMENT_NAME };
	const String g_LookupPrivilegeNameChangeNotifyName{ SE_CHANGE_NOTIFY_NAME };
	const String g_LookupPrivilegeNameRemoteShutdownName{ SE_REMOTE_SHUTDOWN_NAME };
	const String g_LookupPrivilegeNameUndockName{ SE_UNDOCK_NAME };
	const String g_LookupPrivilegeNameSyncAgentName{ SE_SYNC_AGENT_NAME };
	const String g_LookupPrivilegeNameEnableDelegationName{ SE_ENABLE_DELEGATION_NAME };
	const String g_LookupPrivilegeNameManageVolumeName{ SE_MANAGE_VOLUME_NAME };
	const String g_LookupPrivilegeNameImpersonateName{ SE_IMPERSONATE_NAME };
	const String g_LookupPrivilegeNameCreateGlobalName{ SE_CREATE_GLOBAL_NAME };
	const String g_LookupPrivilegeNameTrustedCredManAccessName{ SE_TRUSTED_CREDMAN_ACCESS_NAME };
	const String g_LookupPrivilegeNameRelabelName{ SE_RELABEL_NAME };
	const String g_LookupPrivilegeNameIncreaseWorkingSetName{ SE_INC_WORKING_SET_NAME };
	const String g_LookupPrivilegeNameTimeZoneName{ SE_TIME_ZONE_NAME };
	const String g_LookupPrivilegeNameCreateSymbolicLinkName{ SE_CREATE_SYMBOLIC_LINK_NAME };
	#include STSTEM_WARNING_POP

#else // !SYSTEM_PLATFORM_WIN32	

	struct LookupPrivilegeLUID
	{
		WindowDWord LowPart;
		WindowLong HighPart;
	};
	using LookupPrivilegeLUIDPtr = LookupPrivilegeLUID*;

	const String g_LookupPrivilegeNameCreateTokenName{ SYSTEM_TEXT("SeCreateTokenPrivilege") };
	const String g_LookupPrivilegeNameAssignPrimaryToken{ SYSTEM_TEXT("SeAssignPrimaryTokenPrivilege") };
	const String g_LookupPrivilegeNameLockMemoryName{ SYSTEM_TEXT("SeLockMemoryPrivilege") };
	const String g_LookupPrivilegeNameIncreaseQuotaName{ SYSTEM_TEXT("SeIncreaseQuotaPrivilege") };
	const String g_LookupPrivilegeNameUnsolicitedInputName{ SYSTEM_TEXT("SeUnsolicitedInputPrivilege") };
	const String g_LookupPrivilegeNameMachineAccountName{ SYSTEM_TEXT("SeMachineAccountPrivilege") };
	const String g_LookupPrivilegeNameTcbName{ SYSTEM_TEXT("SeTcbPrivilege") };
	const String g_LookupPrivilegeNameSecurityName{ SYSTEM_TEXT("SeSecurityPrivilege") };
	const String g_LookupPrivilegeNameTakeOwnershipName{ SYSTEM_TEXT("SeTakeOwnershipPrivilege") };
	const String g_LookupPrivilegeNameLoadDriverName{ SYSTEM_TEXT("SeLoadDriverPrivilege") };
	const String g_LookupPrivilegeNameSystemProfileName{ SYSTEM_TEXT("SeSystemProfilePrivilege") };
	const String g_LookupPrivilegeNameSystemtimeName{ SYSTEM_TEXT("SeSystemtimePrivilege") };
	const String g_LookupPrivilegeNameProfileSingleProcessName{ SYSTEM_TEXT("SeProfileSingleProcessPrivilege") };
	const String g_LookupPrivilegeNamencreaseBasePriorityName{ SYSTEM_TEXT("SeIncreaseBasePriorityPrivilege") };
	const String g_LookupPrivilegeNameCreatePagefileName{ SYSTEM_TEXT("SeCreatePagefilePrivilege") };
	const String g_LookupPrivilegeNameCreatePermanentName{ SYSTEM_TEXT("SeCreatePermanentPrivilege") };
	const String g_LookupPrivilegeNameBackupName{ SYSTEM_TEXT("SeBackupPrivilege") };
	const String g_LookupPrivilegeNameRestoreName{ SYSTEM_TEXT("SeRestorePrivilege") };
	const String g_LookupPrivilegeNameShutdownName{ SYSTEM_TEXT("SeShutdownPrivilege") };
	const String g_LookupPrivilegeNameDebugName{ SYSTEM_TEXT("SeDebugPrivilege") };
	const String g_LookupPrivilegeNameAuditName{ SYSTEM_TEXT("SeAuditPrivilege") };
	const String g_LookupPrivilegeNameSystemEnvironmentName{ SYSTEM_TEXT("SeSystemEnvironmentPrivilege") };
	const String g_LookupPrivilegeNameChangeNotifyName{ SYSTEM_TEXT("SeChangeNotifyPrivilege") };
	const String g_LookupPrivilegeNameRemoteShutdownName{ SYSTEM_TEXT("SeRemoteShutdownPrivilege") };
	const String g_LookupPrivilegeNameUndockName{ SYSTEM_TEXT("SeUndockPrivilege") };
	const String g_LookupPrivilegeNameSyncAgentName{ SYSTEM_TEXT("SeSyncAgentPrivilege") };
	const String g_LookupPrivilegeNameEnableDelegationName{ SYSTEM_TEXT("SeEnableDelegationPrivilege") };
	const String g_LookupPrivilegeNameManageVolumeName{ SYSTEM_TEXT("SeManageVolumePrivilege") };
	const String g_LookupPrivilegeNameImpersonateName{ SYSTEM_TEXT("SeImpersonatePrivilege") };
	const String g_LookupPrivilegeNameCreateGlobalName{ SYSTEM_TEXT("SeCreateGlobalPrivilege") };
	const String g_LookupPrivilegeNameTrustedCredManAccessName{ SYSTEM_TEXT("SeTrustedCredManAccessPrivilege") };
	const String g_LookupPrivilegeNameRelabelName{ SYSTEM_TEXT("SeRelabelPrivilege") };
	const String g_LookupPrivilegeNameIncreaseWorkingSetName{ SYSTEM_TEXT("SeIncreaseWorkingSetPrivilege") };
	const String g_LookupPrivilegeNameTimeZoneName{ SYSTEM_TEXT("SeTimeZonePrivilege") };
	const String g_LookupPrivilegeNameCreateSymbolicLinkName{ SYSTEM_TEXT("SeCreateSymbolicLinkPrivilege") };

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_SECURITY_LOOKUP_PRIVILEGE_USING_H