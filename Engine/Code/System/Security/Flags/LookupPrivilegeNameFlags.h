///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 10:40)

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
        SystemtimeName,
        ProfileSingleProcessName,
        IncreaseBasePriorityName,
        CreatePagefileName,
        CreatePermanentName,
        BackupName,
        RestoreName,
        ShutdownName,
        DebugName,
        AuditName,
        SystemEnvironmentName,
        ChangeNotifyName,
        RemoteShutdownName,
        UndockName,
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
