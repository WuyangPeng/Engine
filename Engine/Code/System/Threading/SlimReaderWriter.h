///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.3 (2021/04/25 14:41)

#ifndef SYSTEM_THREADING_SLIM_READER_WRITER_H
#define SYSTEM_THREADING_SLIM_READER_WRITER_H

#include "System/SystemDll.h"

#include "Using/SlimReaderWriterUsing.h"

namespace System
{
    // 读写锁创建和释放。

    void SYSTEM_DEFAULT_DECLARE InitializeSlimReaderWriterLock(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
    void SYSTEM_DEFAULT_DECLARE ReleaseSlimReaderWriterLockExclusive(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
    void SYSTEM_DEFAULT_DECLARE ReleaseSlimReaderWriterLockShared(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;

    void SYSTEM_DEFAULT_DECLARE AcquireSlimReaderWriterLockExclusive(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
    void SYSTEM_DEFAULT_DECLARE AcquireSlimReaderWriterLockShared(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE TryAcquireSlimReaderWriterLockExclusive(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE TryAcquireSlimReaderWriterLockShared(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
}

#endif  // SYSTEM_THREADING_SLIM_READER_WRITER_H