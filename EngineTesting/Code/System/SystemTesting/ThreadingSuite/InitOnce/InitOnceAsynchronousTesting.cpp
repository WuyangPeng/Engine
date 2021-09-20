///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/06 20:14)

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
    WindowsBool pending{ g_False };
    WindowsVoidPtr context{ nullptr };
    auto result = SystemInitOnceBeginInitialize(initOnce, InitOnceBeginInitialize::Async, &pending, &context);

    if (!result)
    {
        return g_InvalidHandleValue;
    }

    if (pending == g_False)
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

    if (result && pending == g_False)
    {
        return context;
    }
    else
    {
        return g_InvalidHandleValue;
    }
}
