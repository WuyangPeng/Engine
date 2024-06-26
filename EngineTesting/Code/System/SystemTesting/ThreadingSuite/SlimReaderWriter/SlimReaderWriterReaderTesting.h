/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:07)

#ifndef SYSTEM_THREADING_SUITE_SLIM_READER_WRITER_READER_TESTING_H
#define SYSTEM_THREADING_SUITE_SLIM_READER_WRITER_READER_TESTING_H

#include "System/Threading/Using/SlimReaderWriterUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SlimReaderWriterReaderTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SlimReaderWriterReaderTesting;
        using ParentType = UnitTest;

    public:
        explicit SlimReaderWriterReaderTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ThreadTest();

        void CreateThread(SlimReaderWriterLock& slimReaderWriterLock);
        void ReaderThread(SlimReaderWriterLock& slimReaderWriterLock) const noexcept;
        void TryReaderThreadSuccess(SlimReaderWriterLock& slimReaderWriterLock);
        void TryWriterThreadFailure(SlimReaderWriterLock& slimReaderWriterLock);

    private:
        static constexpr auto threadCount = 12;
    };
}

#endif  // SYSTEM_THREADING_SUITE_SLIM_READER_WRITER_READER_TESTING_H