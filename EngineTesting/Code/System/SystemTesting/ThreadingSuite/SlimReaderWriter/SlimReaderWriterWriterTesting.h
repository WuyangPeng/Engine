///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/04/29 18:40)

#ifndef SYSTEM_THREADING_SUITE_SLIM_READER_WRITER_WRITER_TESTING_H
#define SYSTEM_THREADING_SUITE_SLIM_READER_WRITER_WRITER_TESTING_H

#include "System/Threading/Using/SlimReaderWriterUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SlimReaderWriterWriterTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SlimReaderWriterWriterTesting;
        using ParentType = UnitTest;

    public:
        explicit SlimReaderWriterWriterTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ThreadTest();
        void ReaderThread(SlimReaderWriterLock slimReaderWriterLock) noexcept;
        void WriterThread(SlimReaderWriterLock slimReaderWriterLock) noexcept;
        void TryReaderThreadFailure(SlimReaderWriterLock slimReaderWriterLock);
        void TryWriterThreadFailure(SlimReaderWriterLock slimReaderWriterLock);
        void TryWriterThreadSuccess(SlimReaderWriterLock slimReaderWriterLock);
    };
}

#endif  // SYSTEM_THREADING_SUITE_SLIM_READER_WRITER_WRITER_TESTING_H