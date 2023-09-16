///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:24)

#ifndef SYSTEM_THREADING_SUITE_CONDITION_VARIABLE_TESTING_BASE_H
#define SYSTEM_THREADING_SUITE_CONDITION_VARIABLE_TESTING_BASE_H

#include "System/Threading/Using/ConditionVariableUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <array>

namespace System
{
    class ConditionVariableTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConditionVariableTestingBase;
        using ParentType = UnitTest;

    public:
        explicit ConditionVariableTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        constexpr static auto bufferSize = 10;
        using BufferType = std::array<int, bufferSize>;

    protected:
        void PrintTipsMessage() override;

        void Initialize();
        virtual void DoInitialize() = 0;

        void ThreadTest();

        void ProducerThreadProcedure();
        void ConsumerThreadProcedure();

        NODISCARD virtual bool DoProducerThreadProcedure() = 0;
        NODISCARD virtual bool DoConsumerThreadProcedure() = 0;
        virtual void ThreadPause() = 0;

        void SetStopRequested(bool aStopRequested) noexcept;
        NODISCARD bool IsStopRequested() const noexcept;
        NODISCARD bool IsFull() const noexcept;
        NODISCARD bool IsEmpty() const noexcept;
        NODISCARD int GetQueueSize() const noexcept;

        void PushBuffer();
        void PopBuffer();
        void WakeAllConditionVariable() noexcept;
        void WakeNotEmptyConditionVariable() noexcept;
        void WakeNotFullConditionVariable() noexcept;

        NODISCARD ConditionVariablePtr GetBufferNotEmpty() noexcept;
        NODISCARD ConditionVariablePtr GetBufferNotFull() noexcept;

    private:
        ConditionVariable bufferNotEmpty;
        ConditionVariable bufferNotFull;
        bool stopRequested;
        BufferType buffer;
        int queueSize;
        int queueStartOffset;
    };
}

#endif  // SYSTEM_THREADING_SUITE_CONDITION_VARIABLE_TESTING_BASE_H