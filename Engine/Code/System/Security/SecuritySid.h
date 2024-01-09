/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 16:28)

#ifndef SYSTEM_SECURITY_SECURITY_SID_H
#define SYSTEM_SECURITY_SECURITY_SID_H

#include "System/SystemDll.h"

#include "Using/SecuritySidUsing.h"
#include "System/Windows/Using/WindowsRegistryUsing.h"

// ��ȫ��ʶ��
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE InitializeSecurityIdentifier(SecuritySidPtr sid,
                                                                       SecuritySidIdentifierAuthorityPtr identifierAuthority,
                                                                       WindowsByte subAuthorityCount) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE AllocateAndInitializeSecurityIdentifier(SecuritySidIdentifierAuthorityPtr identifierAuthority,
                                                                                  WindowsByte subAuthorityCount,
                                                                                  WindowsDWord subAuthority0,
                                                                                  WindowsDWord subAuthority1,
                                                                                  WindowsDWord subAuthority2,
                                                                                  WindowsDWord subAuthority3,
                                                                                  WindowsDWord subAuthority4,
                                                                                  WindowsDWord subAuthority5,
                                                                                  WindowsDWord subAuthority6,
                                                                                  WindowsDWord subAuthority7,
                                                                                  SecuritySidPtr* sid) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsSecurityIdentifierValid(SecuritySidPtr sid) noexcept;
    NODISCARD WindowsVoidPtr SYSTEM_DEFAULT_DECLARE FreeSecurityIdentifier(SecuritySidPtr sid) noexcept;

    NODISCARD WindowsDWordPtr SYSTEM_DEFAULT_DECLARE GetSecurityIdentifierSubAuthority(SecuritySidPtr sid, WindowsDWord subAuthority) noexcept;
    NODISCARD WindowsUCharPtr SYSTEM_DEFAULT_DECLARE GetSecurityIdentifierSubAuthorityCount(SecuritySidPtr sid) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE CreateWellKnownSecurityIdentifier(SecurityWellKnownSidType wellKnownSidType,
                                                                            SecuritySidPtr domainSid,
                                                                            SecuritySidPtr sid,
                                                                            WindowsDWord* sidCount) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsWellKnownSecurityIdentifier(SecuritySidPtr sid, SecurityWellKnownSidType wellKnownSidType) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE CopySecurityIdentifier(WindowsDWord destinationSidLength,
                                                                 SecuritySidPtr destinationSid,
                                                                 SecuritySidPtr sourceSid) noexcept;

    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetLengthSecurityIdentifier(SecuritySidPtr sid) noexcept;
}

#endif  // SYSTEM_SECURITY_SECURITY_SID_H