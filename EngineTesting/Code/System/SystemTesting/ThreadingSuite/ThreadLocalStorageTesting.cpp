///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/22 19:16)

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
    for (auto i = 0; i < threadCount; ++i)
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