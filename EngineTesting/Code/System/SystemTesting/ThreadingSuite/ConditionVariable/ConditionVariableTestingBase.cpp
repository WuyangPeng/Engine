///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/30 14:15)

#include "ConditionVariableTestingBase.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/ConditionVariable.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConditionVariableTestingBase::ConditionVariableTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      bufferNotEmpty{},
      bufferNotFull{},
      stopRequested{ false },
      buffer{},
      queueSize{ 0 },
      queueStartOffset{ 0 }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConditionVariableTestingBase)

void System::ConditionVariableTestingBase::PrintTipsMessage()
{
    GetStream() << "这个测试会测试条件变量，需要按任意键继续。\n";

    SystemPause();
}

void System::ConditionVariableTestingBase::ThreadTest()
{
    boost::thread_group threadGroup{};
    threadGroup.create_thread(boost::bind(&ClassType::ProducerThreadProcedure, this));
    threadGroup.create_thread(boost::bind(&ClassType::ConsumerThreadProcedure, this));
    threadGroup.create_thread(boost::bind(&ClassType::ConsumerThreadProcedure, this));

    ASSERT_NOT_THROW_EXCEPTION_0(ThreadPause);

    threadGroup.join_all();
}

void System::ConditionVariableTestingBase::ProducerThreadProcedure()
{
    for (;;)
    {
        if (DoProducerThreadProcedure())
        {
            break;
        }
    }
}

void System::ConditionVariableTestingBase::ConsumerThreadProcedure()
{
    for (;;)
    {
        if (DoConsumerThreadProcedure())
        {
            break;
        }
    }
}

void System::ConditionVariableTestingBase::Initialize()
{
    InitializeSystemConditionVariable(&bufferNotEmpty);
    InitializeSystemConditionVariable(&bufferNotFull);

    DoInitialize();
}

void System::ConditionVariableTestingBase::SetStopRequested(bool aStopRequested) noexcept
{
    stopRequested = aStopRequested;
}

bool System::ConditionVariableTestingBase::IsStopRequested() const noexcept
{
    return stopRequested;
}

void System::ConditionVariableTestingBase::PushBuffer()
{
    const auto offset = queueSize + queueStartOffset;
    const auto index = offset % buffer.size();

    buffer.at(index) = boost::numeric_cast<int>(index);

    ++queueSize;

    GetStream() << "PushBuffer......queueSize = " << queueSize << "\n";
}

void System::ConditionVariableTestingBase::WakeNotEmptyConditionVariable() noexcept
{
    WakeConditionVariable(&bufferNotEmpty);
}

void System::ConditionVariableTestingBase::WakeAllConditionVariable() noexcept
{
    WakeAllSystemConditionVariable(&bufferNotEmpty);
    WakeAllSystemConditionVariable(&bufferNotFull);
}

bool System::ConditionVariableTestingBase::IsFull() const noexcept
{
    return queueSize == bufferSize && !stopRequested;
}

bool System::ConditionVariableTestingBase::IsEmpty() const noexcept
{
    return queueSize == 0 && !stopRequested;
}

void System::ConditionVariableTestingBase::PopBuffer()
{
    auto result = buffer.at(queueStartOffset);

    ASSERT_EQUAL(result, queueStartOffset);

    --queueSize;
    ++queueStartOffset;

    if (queueStartOffset == boost::numeric_cast<int>(buffer.size()))
    {
        queueStartOffset = 0;
    }

    GetStream() << "PopBuffer......queueSize = " << queueSize << "\n";
}

void System::ConditionVariableTestingBase::WakeNotFullConditionVariable() noexcept
{
    WakeConditionVariable(&bufferNotFull);
}

int System::ConditionVariableTestingBase::GetQueueSize() const noexcept
{
    return queueSize;
}

System::ConditionVariablePtr System::ConditionVariableTestingBase::GetBufferNotEmpty() noexcept
{
    return &bufferNotEmpty;
}

System::ConditionVariablePtr System::ConditionVariableTestingBase::GetBufferNotFull() noexcept
{
    return &bufferNotFull;
}
