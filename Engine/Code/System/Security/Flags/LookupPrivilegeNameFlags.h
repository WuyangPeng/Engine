/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 16:25)

#ifndef SYSTEM_SECURITY_LOOKUP_PRIVILEGE_NAME_FLAGS_H
#define SYSTEM_SECURITY_LOOKUP_PRIVILEGE_NAME_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
    enum class LookupPrivilegeNameDescription
    {
        CreateTokenName,
        AssignPrimaryToken,
        LockMemoryName,
        IncreaseQuotaName,
        UnsolicitedInputName,
        MachineAccountName,
        TcbName,
        SecurityName,
        TakeOwnershipName,
        LoadDriverName,
        SystemProfileName,
        SystemTimeName,
        ProfileSingleProcessName,
        IncreaseBasePriorityName,
        CreatePageFileName,
        CreatePermanentName,
        BackupName,
        RestoreName,
        ShutdownName,
        DebugName,
        AuditName,
        SystemEnvironmentName,
        ChangeNotifyName,
        RemoteShutdownName,
        UnDockName,
        SyncAgentName,
        EnableDelegationName,
        ManageVolumeName,
        ImpersonateName,
        CreateGlobalName,
        TrustedCredManAccessName,
        RelabelName,
        IncreaseWorkingSetName,
        TimeZoneName,
        CreateSymbolicLinkName,
    };
}

#endif  // SYSTEM_SECURITY_LOOKUP_PRIVILEGE_NAME_FLAGS_H
