/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 16:02)

#ifndef SYSTEM_THREADING_MUTEX_H
#define SYSTEM_THREADING_MUTEX_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/MutexUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

// �������Ĵ��������١�
namespace System
{
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemMutex(WindowSecurityAttributesPtr mutexAttributes,
                                                                         bool initialOwner,
                                                                         const TChar* name) noexcept;
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemMutex(WindowSecurityAttributesPtr mutexAttributes,
                                                                         const TChar* name,
                                                                         MutexCreate flag,
                                                                         MutexStandardAccess desiredAccess,
                                                                         MutexSpecificAccess specificAccess) noexcept;
    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemMutex() noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseSystemMutex(WindowsHandle handle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE ReleaseSystemMutex(WindowsHandle handle) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowsHandle handle) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowsHandle handle,
                                                                        WindowsDWord milliseconds) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowsHandle handle,
                                                                        WindowsDWord milliseconds,
                                                                        bool alertable) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowsDWord count,
                                                                        const WindowsHandle* handle,
                                                                        bool waitAll,
                                                                        WindowsDWord milliseconds,
                                                                        bool alertable) noexcept;
    NODISCARD MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowsDWord count,
                                                                        const WindowsHandle* handle,
                                                                        bool waitAll,
                                                                        WindowsDWord milliseconds) noexcept;

    MAYBE_NULLPTR WindowsHandle SYSTEM_DEFAULT_DECLARE OpenThreadingMutex(MutexStandardAccess desiredAccess,
                                                                          MutexSpecificAccess specificAccess,
                                                                          bool inheritHandle,
                                                                          const TChar* name) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsSystemMutexValid(WindowsHandle handle) noexcept;

    NODISCARD PThreadResult SYSTEM_DEFAULT_DECLARE PThreadMutexAttributeInit(PThreadMutexAttrT* attribute) noexcept;
    NODISCARD PThreadResult SYSTEM_DEFAULT_DECLARE PThreadMutexAttributeSetType(PThreadMutexAttrT* attribute) noexcept;
    NODISCARD PThreadResult SYSTEM_DEFAULT_DECLARE PThreadMutexInit(PThreadMutexAttrT* attribute, PThreadMutexT* mutex) noexcept;
    NODISCARD PThreadResult SYSTEM_DEFAULT_DECLARE PThreadMutexDestroy(PThreadMutexT* mutex) noexcept;
    NODISCARD PThreadResult SYSTEM_DEFAULT_DECLARE PThreadMutexAttributeDestroy(PThreadMutexAttrT* attribute) noexcept;
    NODISCARD PThreadResult SYSTEM_DEFAULT_DECLARE PThreadMutexLock(PThreadMutexT* mutex) noexcept;
    NODISCARD PThreadResult SYSTEM_DEFAULT_DECLARE PThreadMutexUnlock(PThreadMutexT* mutex) noexcept;
    NODISCARD PThreadResult SYSTEM_DEFAULT_DECLARE PThreadMutexTryLock(PThreadMutexT* mutex) noexcept;
}

#endif  // SYSTEM_THREADING_MUTEX_H