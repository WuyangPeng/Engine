///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 18:46)

#include "InitOnceAsynchronousTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Event.h"
#include "System/Threading/Flags/InitOnceFlags.h"
#include "System/Threading/InitOnce.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::InitOnceAsynchronousTesting::InitOnceAsynchronousTesting(const OStreamShared& stream)
    : ParentType{ stream }, eventHandle{ nullptr }, enterInitHandleFunctionCount{ 0 }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, InitOnceAsynchronousTesting)

void System::InitOnceAsynchronousTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::InitOnceAsynchronousTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AsynchronousTest);
}

void System::InitOnceAsynchronousTesting::AsynchronousTest()
{
    constexpr auto threadCount = 12;

    InitOnce initOnce{};

    eventHandle = nullptr;

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::BeginInitializeTest, this, &initOnce));
    }

    threadGroup.join_all();

    ASSERT_TRUE(CloseSystemEvent(eventHandle));
}

void System::InitOnceAsynchronousTesting::BeginInitializeTest(InitOncePtr initOnce)
{
    auto handle = OpenEventHandleAsync(initOnce);
    ASSERT_UNEQUAL(g_InvalidHandleValue, handle);

    if (eventHandle != nullptr)
    {
        ASSERT_EQUAL(handle, eventHandle);
    }
    else
    {
        eventHandle = handle;
    }
}

System::WindowsHandle System::InitOnceAsynchronousTesting::OpenEventHandleAsync(InitOncePtr initOnce)
{
    WindowsBool pending{ gFalse };
    WindowsVoidPtr context{ nullptr };
    auto result = SystemInitOnceBeginInitialize(initOnce, InitOnceBeginInitialize::Async, &pending, &context);

    if (!result)
    {
        return g_InvalidHandleValue;
    }

    if (pending == gFalse)
    {
        return context;
    }

    auto event = CreateSystemEvent(true, true);

    if (event == nullptr)
    {
        return g_InvalidHandleValue;
    }

    result = SystemInitOnceComplete(initOnce, InitOnceBeginInitialize::Async, event);

    if (result)
    {
        return event;
    }

    ASSERT_TRUE(CloseSystemEvent(event));

    result = SystemInitOnceBeginInitialize(initOnce, InitOnceBeginInitialize::CheckOnly, &pending, &context);

    if (result && pending == gFalse)
    {
        return context;
    }
    else
    {
        return g_InvalidHandleValue;
    }
}
