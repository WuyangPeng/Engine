/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 19:31)

#include "SlimReaderWriterPacking.h"
#include "System/Threading/SlimReaderWriter.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"

System::SlimReaderWriterPacking::SlimReaderWriterPacking(SlimReaderWriterLock& slimReaderWriterLock) noexcept
    : slimReaderWriterLock{ slimReaderWriterLock }
{
    AcquireSlimReaderWriterLockExclusive(&slimReaderWriterLock);

    SYSTEM_SELF_CLASS_IS_VALID_1;
}

System::SlimReaderWriterPacking::~SlimReaderWriterPacking() noexcept
{
    SYSTEM_SELF_CLASS_IS_VALID_1;

    ReleaseSlimReaderWriterLockExclusive(&slimReaderWriterLock);
}

CLASS_INVARIANT_STUB_DEFINE(System, SlimReaderWriterPacking)
