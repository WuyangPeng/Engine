///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 18:40)

#include "ThreadLocalStorageTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/ThreadLocalStorage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::vector;

System::ThreadLocalStorageTesting::ThreadLocalStorageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ThreadLocalStorageTesting)

void System::ThreadLocalStorageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ThreadLocalStorageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTest);
}

void System::ThreadLocalStorageTesting::ThreadTest()
{
    constexpr auto threadCount = 12;

    const auto threadLocalStorageIndex = ThreadLocalStorageAlloc();
    ASSERT_TRUE(IsThreadLocalStorageValid(threadLocalStorageIndex));

    boost::thread_group threadGroup{};
    for (int i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::ThreadLocalStorageThread, this, threadLocalStorageIndex));
    }

    threadGroup.join_all();

    ASSERT_TRUE(ThreadLocalStorageFree(threadLocalStorageIndex));
}

void System::ThreadLocalStorageTesting::ThreadLocalStorageThread(WindowsDWord threadLocalStorageIndex)
{
    constexpr auto bufferSize = 256;
    vector<char> buffer(bufferSize);

    ASSERT_TRUE(SetThreadLocalStorageValue(threadLocalStorageIndex, buffer.data()));

    auto threadLocalStorgae = GetThreadLocalStorageValue(threadLocalStorageIndex);

    ASSERT_EQUAL(buffer.data(), threadLocalStorgae);
}