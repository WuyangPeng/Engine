///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 19:29)

#include "ThreadLocalStorageTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/ThreadLocalStorage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

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

    ASSERT_NOT_THROW_EXCEPTION_2(CreateThread, threadCount, threadLocalStorageIndex);

    ASSERT_TRUE(ThreadLocalStorageFree(threadLocalStorageIndex));
}

void System::ThreadLocalStorageTesting::ThreadLocalStorageThread(WindowsDWord threadLocalStorageIndex)
{
    constexpr auto bufferSize = 256;
    std::vector<char> buffer(bufferSize);

    ASSERT_TRUE(SetThreadLocalStorageValue(threadLocalStorageIndex, buffer.data()));

    const auto threadLocalStorgae = GetThreadLocalStorageValue(threadLocalStorageIndex);

    ASSERT_EQUAL(buffer.data(), threadLocalStorgae);
}

void System::ThreadLocalStorageTesting::CreateThread(int threadCount, WindowsDWord threadLocalStorageIndex)
{
    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::ThreadLocalStorageThread, this, threadLocalStorageIndex));
    }

    threadGroup.join_all();
}
