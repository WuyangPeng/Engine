///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 0:26)

#include "InitOnceAsynchronousTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Event.h"
#include "System/Threading/Flags/InitOnceFlags.h"
#include "System/Threading/InitOnce.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::InitOnceAsynchronousTesting::InitOnceAsynchronousTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    ASSERT_NOT_THROW_EXCEPTION_0(SetEventHandleNull);

    ASSERT_NOT_THROW_EXCEPTION_0(CreateThreadTest);

    ASSERT_NOT_THROW_EXCEPTION_0(CloseEventTest);
}

void System::InitOnceAsynchronousTesting::BeginInitializeTest(InitOncePtr initOnce)
{
    const auto handle = OpenEventHandleAsync(initOnce);
    ASSERT_UNEQUAL(invalidHandleValue, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(SetEventHandle, handle);
}

System::WindowsHandle System::InitOnceAsynchronousTesting::OpenEventHandleAsync(InitOncePtr initOnce)
{
    const auto initOnceBeginInitializeHandle = GetInitOnceBeginInitializeHandle(initOnce);
    if (initOnceBeginInitializeHandle != nullptr)
    {
        return initOnceBeginInitializeHandle;
    }

    const auto initOnceCompleteHandle = GetInitOnceCompleteHandle(initOnce);
    if (initOnceCompleteHandle != nullptr)
    {
        return initOnceCompleteHandle;
    }

    const auto result = GetInitOnceBeginInitializeHandle(initOnce);
    if (result != nullptr)
    {
        return result;
    }

    return nullptr;
}

void System::InitOnceAsynchronousTesting::CreateThreadTest()
{
    InitOnce initOnce{};
    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::BeginInitializeTest, this, &initOnce));
    }

    threadGroup.join_all();
}

System::WindowsHandle System::InitOnceAsynchronousTesting::GetInitOnceBeginInitializeHandle(InitOncePtr initOnce) noexcept
{
    WindowsBool pending{ gFalse };
    WindowsVoidPtr context{ nullptr };
    const auto result = SystemInitOnceBeginInitialize(initOnce, InitOnceBeginInitialize::Async, &pending, &context);

    if (result)
    {
        if (pending == gFalse)
            return context;
        else
            return nullptr;
    }
    else
    {
        return invalidHandleValue;
    }
}

System::WindowsHandle System::InitOnceAsynchronousTesting::GetInitOnceCompleteHandle(InitOncePtr initOnce)
{
    const auto event = CreateSystemEvent(true, true);

    if (event == nullptr)
    {
        return invalidHandleValue;
    }

    const auto result = SystemInitOnceComplete(initOnce, InitOnceBeginInitialize::Async, event);

    if (result)
    {
        return event;
    }

    ASSERT_TRUE(CloseSystemEvent(event));

    return nullptr;
}
