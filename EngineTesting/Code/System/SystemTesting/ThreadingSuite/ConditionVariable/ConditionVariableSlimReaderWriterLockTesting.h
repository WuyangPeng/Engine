/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 16:30)

#ifndef SYSTEM_THREADING_SUITE_CONDITION_VARIABLE_SLIM_READER_WRITER_TESTING_H
#define SYSTEM_THREADING_SUITE_CONDITION_VARIABLE_SLIM_READER_WRITER_TESTING_H

#include "ConditionVariableTestingBase.h"
#include "System/Threading/Using/SlimReaderWriterUsing.h"

namespace System
{
    class ConditionVariableSlimReaderWriterLockTesting final : public ConditionVariableTestingBase
    {
    public:
        using ClassType = ConditionVariableSlimReaderWriterLockTesting;
        using ParentType = ConditionVariableTestingBase;

    public:
        explicit ConditionVariableSlimReaderWriterLockTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ThreadPause() override;
        NODISCARD bool DoProducerThreadProcedure() override;
        NODISCARD bool DoConsumerThreadProcedure() override;

        void DoInitialize() noexcept override;

    private:
        SlimReaderWriterLock bufferLock;
    };
}

#endif  // SYSTEM_THREADING_SUITE_CONDITION_VARIABLE_SLIM_READER_WRITER_TESTING_H