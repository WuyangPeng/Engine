/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:22)

#include "SignalObjectAndWaitTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Event.h"
#include "System/Threading/Flags/EventFlags.h"
#include "System/Threading/Flags/MutexFlags.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Mutex.h"
#include "System/Threading/SyncTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SignalObjectAndWaitTesting::SignalObjectAndWaitTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SignalObjectAndWaitTesting)

void System::SignalObjectAndWaitTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SignalObjectAndWaitTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SignalObjectAndWaitTest);
}

void System::SignalObjectAndWaitTesting::SignalObjectAndWaitTest()
{
    const auto eventHandle = CreateSystemEvent(nullptr, nullptr, CreateEventType::ManualReset, MutexStandardAccess::Synchronize, EventSpecificAccess::ModifyState);
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, eventHandle);

    ASSERT_TRUE(CloseSystemEvent(eventHandle));
}

void System::SignalObjectAndWaitTesting::WaitForEventTest(WindowsHandle eventHandle)
{
    ASSERT_TRUE(WaitForSystemEvent(eventHandle));
}

void System::SignalObjectAndWaitTesting::WaitForMutexTest(WindowsHandle eventHandle)
{
    const auto mutexHandle = CreateSystemMutex(nullptr, nullptr, MutexCreate::InitialOwner, MutexStandardAccess::Synchronize, MutexSpecificAccess::ModifyState);
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    ASSERT_EQUAL(SystemSignalObjectAndWait(eventHandle, mutexHandle, EnumCastUnderlying(MutexWait::Infinite), false), MutexWaitReturn::Object0);

    ASSERT_TRUE(CloseSystemMutex(mutexHandle));
}

void System::SignalObjectAndWaitTesting::CreateThread(WindowsHandle eventHandle)
{
    boost::thread_group threadGroup{};

    threadGroup.create_thread([this, eventHandle]() {
        this->WaitForEventTest(eventHandle);
    });

    threadGroup.create_thread([this, eventHandle]() {
        this->WaitForMutexTest(eventHandle);
    });

    threadGroup.join_all();
}
