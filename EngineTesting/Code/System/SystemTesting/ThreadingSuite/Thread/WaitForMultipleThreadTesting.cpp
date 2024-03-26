/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:21)

#include "WaitForMultipleThreadTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WaitForMultipleThreadTesting::WaitForMultipleThreadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WaitForMultipleThreadTesting)

void System::WaitForMultipleThreadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WaitForMultipleThreadTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WaitMultipleObjectsTest);
}

void System::WaitForMultipleThreadTesting::WaitMultipleObjectsTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WaitMultipleObjects0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(WaitMultipleObjects1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(WaitMultipleObjects2Test);
}

void System::WaitForMultipleThreadTesting::WaitMultipleObjects0Test()
{
    const auto threadHandle = CreateThread();

    const auto flag = WaitForSystemThread(boost::numeric_cast<WindowsDWord>(threadHandle.size()), threadHandle.data(), true, EnumCastUnderlying(MutexWait::Infinite));
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseThread, threadHandle);
}

void System::WaitForMultipleThreadTesting::WaitMultipleObjects1Test()
{
    const auto threadHandle = CreateThread();

    const auto flag = WaitForSystemThread(boost::numeric_cast<WindowsDWord>(threadHandle.size()), threadHandle.data(), true, EnumCastUnderlying(MutexWait::Infinite), true);
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseThread, threadHandle);
}

void System::WaitForMultipleThreadTesting::WaitMultipleObjects2Test()
{
    const auto threadHandle = CreateThread();

    const auto flag = WaitForSystemThread(boost::numeric_cast<WindowsDWord>(threadHandle.size()), threadHandle.data(), true, EnumCastUnderlying(MutexWait::Infinite), false);
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    CloseThread(threadHandle);
}

System::WaitForMultipleThreadTesting::Container System::WaitForMultipleThreadTesting::CreateThread()
{
    constexpr auto mutexSize = 5;
    Container threadHandle{};

    for (auto i = 0; i < mutexSize; ++i)
    {
        WindowsDWord threadId{ 0 };
        const auto handle = CreateSystemThread(0, ClassType::ThreadStartRoutine, this, &threadId);

        ASSERT_TRUE(IsThreadHandleValid(handle));
        ASSERT_LESS(0u, threadId);

        threadHandle.emplace_back(handle);
    }

    return threadHandle;
}

void System::WaitForMultipleThreadTesting::CloseThread(const Container& threadHandle)
{
    for (auto handle : threadHandle)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CloseThreadTest, handle);
    }
}

System::WindowsDWord System::WaitForMultipleThreadTesting::ThreadStartRoutine(void* threadParameter)
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26471)

    const auto classType = reinterpret_cast<ClassType*>(threadParameter);

#include SYSTEM_WARNING_POP

    if (classType != nullptr)
    {
        classType->GetStream() << "这里进行了回调函数的调用。\n";
    }

    return 0;
}