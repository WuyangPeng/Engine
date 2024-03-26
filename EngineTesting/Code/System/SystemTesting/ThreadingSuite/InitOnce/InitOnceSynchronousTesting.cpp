/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:30)

#include "InitOnceSynchronousTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Helper/Tools.h"
#include "System/Threading/Event.h"
#include "System/Threading/InitOnce.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::InitOnceSynchronousTesting::InitOnceSynchronousTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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
    ASSERT_NOT_THROW_EXCEPTION_1(SetEnterInitHandleFunctionCount, 0);

    ASSERT_NOT_THROW_EXCEPTION_0(CreateThreadTest);

    ASSERT_EQUAL(GetEnterInitHandleFunctionCount(), 1);

    ASSERT_NOT_THROW_EXCEPTION_0(CloseEventTest);
}

void System::InitOnceSynchronousTesting::ExecuteOnceTest(InitOncePtr initOnce)
{
    WindowsVoidPtr context{ nullptr };
    ASSERT_TRUE(SystemInitOnceExecuteOnce(initOnce, ClassType::InitHandleFunction, GetEnterInitHandleFunctionCountPtr(), &context));

    ASSERT_UNEQUAL(invalidHandleValue, context);

    ASSERT_NOT_THROW_EXCEPTION_1(SetEventHandle, context);
}

System::WindowsBool System::InitOnceSynchronousTesting::InitHandleFunction(InitOncePtr initOnce, WindowsVoidPtr parameter, WindowsVoidPtr* context) noexcept
{
    UnusedFunction(initOnce);

    if (context == nullptr || parameter == nullptr)
    {
        return gFalse;
    }

    ++(*static_cast<int*>(parameter));

    if (const auto event = CreateSystemEvent(true, true);
        event != nullptr)
    {
        *context = event;
        return gTrue;
    }
    else
    {
        *context = invalidHandleValue;
        return gFalse;
    }
}

void System::InitOnceSynchronousTesting::CreateThreadTest()
{
    InitOnce initOnce{};
    SystemInitOnceInitialize(&initOnce);

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread([this, &initOnce]() {
            this->ExecuteOnceTest(&initOnce);
        });
    }

    threadGroup.join_all();
}
