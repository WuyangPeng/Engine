///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:37)

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

        void ReaderThread(SlimReaderWriterLock& slimReaderWriterLock) noexcept;
        void WriterThread(SlimReaderWriterLock& slimReaderWriterLock) noexcept;
        void TryReaderThreadFailure(SlimReaderWriterLock& slimReaderWriterLock);
        void TryWriterThreadFailure(SlimReaderWriterLock& slimReaderWriterLock);
        void TryWriterThreadSuccess(SlimReaderWriterLock& slimReaderWriterLock);
        void CreateThread(SlimReaderWriterLock& slimReaderWriterLock);
        void CreateTryThread(SlimReaderWriterLock& slimReaderWriterLock);

    private:
        static constexpr auto threadCount = 12;
    };
}

#endif  // SYSTEM_THREADING_SUITE_SLIM_READER_WRITER_WRITER_TESTING_H