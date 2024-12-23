/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:48)

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
