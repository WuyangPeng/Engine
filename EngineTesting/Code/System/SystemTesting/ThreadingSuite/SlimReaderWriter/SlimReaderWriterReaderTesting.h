///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:37)

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

        void ReaderThread(SlimReaderWriterLock& slimReaderWriterLock) noexcept;
        void TryReaderThreadSuccess(SlimReaderWriterLock& slimReaderWriterLock);
        void TryWriterThreadFailure(SlimReaderWriterLock& slimReaderWriterLock);

    private:
        static constexpr auto threadCount = 12;
    };
}

#endif  // SYSTEM_THREADING_SUITE_SLIM_READER_WRITER_READER_TESTING_H