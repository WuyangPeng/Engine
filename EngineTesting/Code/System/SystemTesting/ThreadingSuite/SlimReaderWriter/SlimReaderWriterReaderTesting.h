///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 21:59)

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
        void DoRunUnitTest() final;
        void MainTest();

        void ThreadTest();
        void ReaderThread(SlimReaderWriterLock slimReaderWriterLock) noexcept;
        void TryReaderThreadSuccess(SlimReaderWriterLock slimReaderWriterLock);
        void TryWriterThreadFailure(SlimReaderWriterLock slimReaderWriterLock);
    };
}

#endif  // SYSTEM_THREADING_SUITE_SLIM_READER_WRITER_READER_TESTING_H