/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:07)

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
        void DoRunUnitTest() override;
        void MainTest();

        void ThreadTest();

        void ReaderThread(SlimReaderWriterLock& slimReaderWriterLock) const noexcept;
        void WriterThread(SlimReaderWriterLock& slimReaderWriterLock) const noexcept;
        void TryReaderThreadFailure(SlimReaderWriterLock& slimReaderWriterLock);
        void TryWriterThreadFailure(SlimReaderWriterLock& slimReaderWriterLock);
        void TryWriterThreadSuccess(SlimReaderWriterLock& slimReaderWriterLock);
        void CreateThread(SlimReaderWriterLock& slimReaderWriterLock) const;
        void CreateTryThread(SlimReaderWriterLock& slimReaderWriterLock);

    private:
        static constexpr auto threadCount = 12;
    };
}

#endif  // SYSTEM_THREADING_SUITE_SLIM_READER_WRITER_WRITER_TESTING_H