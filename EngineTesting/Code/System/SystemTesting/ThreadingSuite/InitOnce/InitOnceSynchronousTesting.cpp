///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 19:27)

#include "InitOnceSynchronousTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Helper/Tools.h"
#include "System/Threading/Event.h"
#include "System/Threading/InitOnce.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::InitOnceSynchronousTesting::InitOnceSynchronousTesting(const OStreamShared& stream)
    : ParentType{ stream }, eventHandle{ nullptr }, enterInitHandleFunctionCount{ 0 }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, InitOnceSynchronousTesting)

void System::InitOnceSynchronousTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::InitOnceSynchronousTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SynchronousTest);
}

void System::InitOnceSynchronousTesting::SynchronousTest()
{
    constexpr auto threadCount = 12;

    InitOnce initOnce{};
    SystemInitOnceInitialize(&initOnce);

    enterInitHandleFunctionCount = 0;

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::ExecuteOnceTest, this, &initOnce));
    }

    threadGroup.join_all();

    ASSERT_EQUAL(enterInitHandleFunctionCount, 1);

    ASSERT_TRUE(CloseSystemEvent(eventHandle));
}

void System::InitOnceSynchronousTesting::ExecuteOnceTest(InitOncePtr initOnce)
{
    WindowsVoidPtr context{ nullptr };
    ASSERT_TRUE(SystemInitOnceExecuteOnce(initOnce, ClassType::InitHandleFunction, &enterInitHandleFunctionCount, &context));

    ASSERT_UNEQUAL(gInvalidHandleValue, context);
    if (eventHandle != nullptr)
    {
        ASSERT_EQUAL(context, eventHandle);
    }
    else
    {
        eventHandle = context;
    }
}

System::WindowsBool System::InitOnceSynchronousTesting::InitHandleFunction(InitOncePtr initOnce, WindowsVoidPtr parameter, WindowsVoidPtr* context) noexcept
{
    UnusedFunction(initOnce);

    if (context == nullptr || parameter == nullptr)
    {
        return gFalse;
    }

    ++(*static_cast<int*>(parameter));
    auto event = CreateSystemEvent(true, true);

    if (event != nullptr)
    {
        *context = event;
        return gTrue;
    }
    else
    {
        *context = gInvalidHandleValue;
        return gFalse;
    }
}
