///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 18:53)

#ifndef SYSTEM_SECURITY_SECURITY_SID_H
#define SYSTEM_SECURITY_SECURITY_SID_H

#include "System/SystemDll.h"

#include "Using/SecuritySidUsing.h"
#include "System/Windows/Using/WindowsRegistryUsing.h"

namespace System
{
    // ��ȫ��ʶ��

    NODISCARD bool SYSTEM_DEFAULT_DECLARE InitializeSecurityIdentifier(SecuritySIDPtr sid,
                                                                       SecuritySIDIndentifierAuthorityPtr identifierAuthority,
                                                                       WindowsByte subAuthorityCount) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE AllocateAndInitializeSecurityIdentifier(SecuritySIDIndentifierAuthorityPtr identifierAuthority,
                                                                                  WindowsByte subAuthorityCount,
                                                                                  WindowsDWord subAuthority0,
                                                                                  WindowsDWord subAuthority1,
                                                                                  WindowsDWord subAuthority2,
                                                                                  WindowsDWord subAuthority3,
                                                                                  WindowsDWord subAuthority4,
                                                                                  WindowsDWord subAuthority5,
                                                                                  WindowsDWord subAuthority6,
                                                                                  WindowsDWord subAuthority7,
                                                                                  SecuritySIDPtr* sid) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsSecurityIdentifierValid(SecuritySIDPtr sid) noexcept;
    NODISCARD WindowsVoidPtr SYSTEM_DEFAULT_DECLARE FreeSecurityIdentifier(SecuritySIDPtr sid) noexcept;

    NODISCARD WindowsDWordPtr SYSTEM_DEFAULT_DECLARE GetSecurityIdentifierSubAuthority(SecuritySIDPtr sid, WindowsDWord subAuthority) noexcept;
    NODISCARD WindowsUCharPtr SYSTEM_DEFAULT_DECLARE GetSecurityIdentifierSubAuthorityCount(SecuritySIDPtr sid) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE CreateWellKnownSecurityIdentifier(SecurityWellKnownSidType wellKnownSidType,
                                                                            SecuritySIDPtr domainSid,
                                                                            SecuritySIDPtr sid,
                                                                            WindowsDWord* sidCount) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsWellKnownSecurityIdentifier(SecuritySIDPtr sid, SecurityWellKnownSidType wellKnownSidType) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE CopySecurityIdentifier(WindowsDWord destinationSidLength,
                                                                 SecuritySIDPtr destinationSid,
                                                                 SecuritySIDPtr sourceSid) noexcept;

    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetLengthSecurityIdentifier(SecuritySIDPtr sid) noexcept;
}

#endif  // SYSTEM_SECURITY_SECURITY_SID_H