// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 16:13)

#ifndef SYSTEM_THREADING_SLIM_READER_WRITER_H
#define SYSTEM_THREADING_SLIM_READER_WRITER_H

#include "System/SystemDll.h"

#include "Using/SlimReaderWriterUsing.h"

namespace System
{
	// ��д���������ͷš�

	void SYSTEM_DEFAULT_DECLARE InitializeSlimReaderWriterLock(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
	void SYSTEM_DEFAULT_DECLARE ReleaseSlimReaderWriterLockExclusive(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
	void SYSTEM_DEFAULT_DECLARE ReleaseSlimReaderWriterLockShared(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
	void SYSTEM_DEFAULT_DECLARE AcquireSlimReaderWriterLockExclusive(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
	void SYSTEM_DEFAULT_DECLARE AcquireSlimReaderWriterLockShared(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
	bool SYSTEM_DEFAULT_DECLARE TryAcquireSlimReaderWriterLockExclusive(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
	bool SYSTEM_DEFAULT_DECLARE TryAcquireSlimReaderWriterLockShared(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept;
}

#endif // SYSTEM_THREADING_SLIM_READER_WRITER_H