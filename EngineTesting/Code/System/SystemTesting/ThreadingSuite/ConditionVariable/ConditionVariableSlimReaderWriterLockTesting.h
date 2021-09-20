///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/04/30 15:29)

#ifndef SYSTEM_THREADING_SUITE_CONDITION_VARIABLE_SLIM_READER_WRITER_TESTING_H
#define SYSTEM_THREADING_SUITE_CONDITION_VARIABLE_SLIM_READER_WRITER_TESTING_H

#include "System/Threading/Using/ConditionVariableUsing.h"
#include "System/Threading/Using/SlimReaderWriterUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <array>

namespace System
{
    class ConditionVariableSlimReaderWriterLockTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConditionVariableSlimReaderWriterLockTesting;
        using ParentType = UnitTest;

    public:
        explicit ConditionVariableSlimReaderWriterLockTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ThreadTest();
        void ProducerThreadProcedure();
        void ConsumerThreadProcedure();

        void Initialize() noexcept;

    private:
        constexpr static auto sm_BufferSize = 10;

        using BufferType = std::array<int, sm_BufferSize>;

    private:
        ConditionVariable bufferNotEmpty;
        ConditionVariable bufferNotFull;
        SlimReaderWriterLock bufferLock;
        bool stopRequested;
        BufferType buffer;
        int queueSize;
        int queueStartOffset;
    };
}

#endif  // SYSTEM_THREADING_SUITE_CONDITION_VARIABLE_SLIM_READER_WRITER_TESTING_H