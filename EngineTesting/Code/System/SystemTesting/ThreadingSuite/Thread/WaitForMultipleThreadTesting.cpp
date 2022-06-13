///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 18:55)

#include "WaitForMultipleThreadTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::vector;

System::WaitForMultipleThreadTesting::WaitForMultipleThreadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WaitForMultipleThreadTesting)

void System::WaitForMultipleThreadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WaitForMultipleThreadTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(WaitMultipleObjectsTest);
}

bool System::WaitForMultipleThreadTesting::WaitMultipleObjectsTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WaitMultipleObjects0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(WaitMultipleObjects1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(WaitMultipleObjects2Test);

    return true;
}

void System::WaitForMultipleThreadTesting::WaitMultipleObjects0Test()
{
    auto threadHandle = CreateThread();

    const auto flag = WaitForSystemThread(boost::numeric_cast<WindowsDWord>(threadHandle.size()), threadHandle.data(), true, EnumCastUnderlying(MutexWait::Infinite));
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    CloseThread(threadHandle);
}

void System::WaitForMultipleThreadTesting::WaitMultipleObjects1Test()
{
    auto threadHandle = CreateThread();

    const auto flag = WaitForSystemThread(boost::numeric_cast<WindowsDWord>(threadHandle.size()), threadHandle.data(), true, EnumCastUnderlying(MutexWait::Infinite), true);
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    CloseThread(threadHandle);
}

void System::WaitForMultipleThreadTesting::WaitMultipleObjects2Test()
{
    auto threadHandle = CreateThread();

    const auto flag = WaitForSystemThread(boost::numeric_cast<WindowsDWord>(threadHandle.size()), threadHandle.data(), true, EnumCastUnderlying(MutexWait::Infinite), false);
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    CloseThread(threadHandle);
}

vector<System::ThreadHandle> System::WaitForMultipleThreadTesting::CreateThread()
{
    constexpr auto mutexSize = 5;
    vector<ThreadHandle> threadHandle{};

    for (auto i = 0; i < mutexSize; ++i)
    {
        WindowsDWord threadId{ 0 };
        auto handle = CreateSystemThread(0, ClassType::ThreadStartRoutine, this, &threadId);

        ASSERT_TRUE(IsThreadHandleValid(handle));
        ASSERT_LESS(0u, threadId);

        threadHandle.emplace_back(handle);
    }

    return threadHandle;
}

void System::WaitForMultipleThreadTesting::CloseThread(const vector<System::ThreadHandle>& threadHandle)
{
    for (auto handle : threadHandle)
    {
        ASSERT_TRUE(CloseSystemThread(handle));
    }
}

System::WindowsDWord System::WaitForMultipleThreadTesting::ThreadStartRoutine(void* threadParameter)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26471)

    auto classType = reinterpret_cast<ClassType*>(threadParameter);

#include STSTEM_WARNING_POP

    if (classType != nullptr)
    {
        classType->GetStream() << "这里进行了回调函数的调用。\n";
    }

    return 0;
}