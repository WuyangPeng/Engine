//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 14:09)

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
        ncreaseBasePriorityName,
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
