///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.1 (2023/01/30 13:19)

#ifndef SYSTEM_THREADING_SLIM_READER_WRITER_H
#define SYSTEM_THREADING_SLIM_READER_WRITER_H

#include "System/SystemDll.h"

#include "Using/SlimReaderWriterUsing.h"

// ��д���������ͷš�
namespace System
{
    void SYSTEM_DEFAULT_DECLARE InitializeSlimReaderWriterLock(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
    void SYSTEM_DEFAULT_DECLARE ReleaseSlimReaderWriterLockExclusive(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
    void SYSTEM_DEFAULT_DECLARE ReleaseSlimReaderWriterLockShared(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;

    void SYSTEM_DEFAULT_DECLARE AcquireSlimReaderWriterLockExclusive(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
    void SYSTEM_DEFAULT_DECLARE AcquireSlimReaderWriterLockShared(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE TryAcquireSlimReaderWriterLockExclusive(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE TryAcquireSlimReaderWriterLockShared(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
}

#endif  // SYSTEM_THREADING_SLIM_READER_WRITER_H