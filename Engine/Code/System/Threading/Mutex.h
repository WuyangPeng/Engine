//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 15:25)

#ifndef SYSTEM_THREADING_MUTEX_H
#define SYSTEM_THREADING_MUTEX_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/MutexUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
    // �������Ĵ��������١�

    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemMutex(WindowSecurityAttributesPtr mutexAttributes, bool initialOwner, const TChar* name) noexcept;
    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemMutex(WindowSecurityAttributesPtr mutexAttributes, const TChar* name, MutexCreate flag,
                                                                        MutexStandardAccess desiredAccess, MutexSpecificAccess specificAccess) noexcept;
    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemMutex() noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CloseSystemMutex(WindowHandle handle) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ReleaseSystemMutex(WindowHandle handle) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowHandle handle) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowHandle handle, WindowDWord milliseconds) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowHandle handle, WindowDWord milliseconds, bool alertable) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept;
    [[nodiscard]] MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemMutex(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds) noexcept;
    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE OpenThreadingMutex(MutexStandardAccess desiredAccess, MutexSpecificAccess specificAccess, bool inheritHandle, const TChar* name) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsSystemMutexValid(WindowHandle handle) noexcept;
    [[nodiscard]] PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexAttributeInit(PthreadMutexattrT* attribute) noexcept;
    [[nodiscard]] PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexAttributeSetType(PthreadMutexattrT* attribute) noexcept;
    [[nodiscard]] PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexInit(PthreadMutexattrT* attribute, PthreadMutexT* mutex) noexcept;
    [[nodiscard]] PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexDestroy(PthreadMutexT* mutex) noexcept;
    [[nodiscard]] PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexAttributeDestroy(PthreadMutexattrT* attribute) noexcept;
    [[nodiscard]] PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexLock(PthreadMutexT* mutex) noexcept;
    [[nodiscard]] PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexUnlock(PthreadMutexT* mutex) noexcept;
    [[nodiscard]] PthreadResult SYSTEM_DEFAULT_DECLARE PthreadMutexTrylock(PthreadMutexT* mutex) noexcept;
}

#endif  // SYSTEM_THREADING_MUTEX_H