///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:22)

#ifndef SYSTEM_THREADING_SUITE_SLIM_READER_WRITER_PACKING_H
#define SYSTEM_THREADING_SUITE_SLIM_READER_WRITER_PACKING_H

#include "System/Threading/Using/SlimReaderWriterUsing.h"
#include "CoreTools/Helper/UserMacro.h"

namespace System
{
    class SlimReaderWriterPacking
    {
    public:
        using ClassType = SlimReaderWriterPacking;

    public:
        explicit SlimReaderWriterPacking(SlimReaderWriterLock& slimReaderWriterLock) noexcept;
        ~SlimReaderWriterPacking() noexcept;
        SlimReaderWriterPacking(const SlimReaderWriterPacking& rhs) = delete;
        SlimReaderWriterPacking& operator=(const SlimReaderWriterPacking& rhs) = delete;
        SlimReaderWriterPacking(SlimReaderWriterPacking&& rhs) noexcept = delete;
        SlimReaderWriterPacking& operator=(SlimReaderWriterPacking&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        SlimReaderWriterLock& slimReaderWriterLock;
    };
}

#endif  // SYSTEM_THREADING_SUITE_SLIM_READER_WRITER_PACKING_H