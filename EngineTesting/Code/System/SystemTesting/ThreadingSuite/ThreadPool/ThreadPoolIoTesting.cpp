// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.1 (2020/01/14 10:24)

#include "ThreadPoolIoTesting.h"

#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Threading/SyncTools.h"
#include "System/Threading/ThreadPool.h"
#include "System/Threading/Using/WaitableTimerUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <array>

using std::array;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(System, ThreadPoolIoTesting)

void System::ThreadPoolIoTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(UsingThreadPoolTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ClosePoolIOTest);
}

void System::ThreadPoolIoTesting::UsingThreadPoolTest()
{
    ThreadPoolCallbackEnviron callBackEnviron{};

    InitializeThreadPoolEnvironment(&callBackEnviron);

    auto threadPoolPool = CreateThreadPool();
    ASSERT_UNEQUAL_NULL_PTR(threadPoolPool);

    SetThreadPoolMaximumThread(threadPoolPool, 1);
    ASSERT_TRUE(SetThreadPoolMinimumThread(threadPoolPool, 1));

    auto cleanupgroup = CreateThreadPoolCleanupGroup();
    ASSERT_UNEQUAL_NULL_PTR(cleanupgroup);

    SetThreadPoolCallbackCleanupGroup(&callBackEnviron, cleanupgroup, nullptr);

    auto work = CreateThreadPoolWork(ClassType::WorkCallback, this, &callBackEnviron);
    ASSERT_UNEQUAL_NULL_PTR(work);

    SubmitThreadPoolWork(work);

    auto timer = CreateThreadPoolTimer(ClassType::TimerCallback, this, &callBackEnviron);
    ASSERT_UNEQUAL_NULL_PTR(timer);

    WindowLargeInteger dueTime{};
    dueTime.QuadPart = (-1 * 10 * 1000 * 1000);

    FileTime fileDueTime{};
    fileDueTime.dwHighDateTime = dueTime.HighPart;
    fileDueTime.dwLowDateTime = dueTime.LowPart;

    SetThreadPoolTimer(timer, &fileDueTime, 0, 0);

    const String fileMappingName{ SYSTEM_TEXT("Resource/ThreadPoolIoTesting/ThreadPoolIoTest.txt") };

    auto fileHandle = CreateSystemFile(fileMappingName.c_str(), FileHandleDesiredAccess::ReadWrite | FileHandleDesiredAccess::Execute, FileHandleShareMode::Prevents,
                                       FileHandleCreationDisposition::OpenAlways, FileHandleAttributes::Normal,
                                       FileHandleOther::Overlapped, FileHandleSecurity::Default);
    ASSERT_TRUE(IsFileHandleValid(fileHandle));

    auto poolIO = CreateThreadPoolIo(fileHandle, Win32IOCallback, this, &callBackEnviron);
    ASSERT_UNEQUAL_NULL_PTR(poolIO);

    StartThreadPoolIo(poolIO);

    constexpr auto bufferSize = 256;
    uint64_t size{ 0 };
    ASSERT_TRUE(GetFileLength(fileHandle, size));

    if (bufferSize < size)
    {
        size = bufferSize;
    }

    array<char, bufferSize> buffer{};

    WindowDWord inNumber{ 0 };
    WindowOverlapped overlapped{};
    [[maybe_unused]] const auto value = ReadSystemFile(fileHandle, buffer.data(), boost::numeric_cast<WindowDWord>(size), &inNumber, &overlapped);

    SystemSleep(1500);

    WaitForThreadPoolWorkCallbacks(work, false);
    WaitForThreadPoolTimerCallbacks(timer, false);
    WaitForThreadPoolIoCallbacks(poolIO, false);

    ASSERT_TRUE(CloseSystemFile(fileHandle));
    CancelThreadPoolIo(poolIO);
    CloseThreadPoolCleanupGroupMembers(cleanupgroup, false, nullptr);
    CloseThreadPoolCleanupGroup(cleanupgroup);
    CloseThreadPool(threadPoolPool);
    DestroyThreadPoolEnvironment(&callBackEnviron);
}

void System::ThreadPoolIoTesting::WorkCallback([[maybe_unused]] ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context, [[maybe_unused]] ThreadPoolWorkPtr work)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26471)
    auto ptr = reinterpret_cast<ClassType*>(context);

    ptr->GetStream() << "这里进行了WorkCallback回调函数的调用。\n";
#include STSTEM_WARNING_POP
}

void System::ThreadPoolIoTesting::TimerCallback([[maybe_unused]] ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context, [[maybe_unused]] ThreadPoolTimerPtr timer)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26471)
    auto ptr = reinterpret_cast<ClassType*>(context);

    ptr->GetStream() << "这里进行了TimerCallback回调函数的调用。\n";
#include STSTEM_WARNING_POP
}

void System::ThreadPoolIoTesting::Win32IOCallback([[maybe_unused]] ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context, [[maybe_unused]] WindowVoidPtr overlapped,
                                                  [[maybe_unused]] WindowULong ioResult, [[maybe_unused]] WindowPtrULong numberOfBytesTransferred, [[maybe_unused]] ThreadPoolIOPtr io)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26471)
    auto ptr = reinterpret_cast<ClassType*>(context);

    ptr->GetStream() << "这里进行了Win32IOCallback回调函数的调用。结果是：" << ioResult << "\n";

#include STSTEM_WARNING_POP
}

void System::ThreadPoolIoTesting::ClosePoolIOTest()
{
    ThreadPoolCallbackEnviron callBackEnviron{};

    InitializeThreadPoolEnvironment(&callBackEnviron);

    auto threadPoolPool = CreateThreadPool();
    ASSERT_UNEQUAL_NULL_PTR(threadPoolPool);

    SetThreadPoolMaximumThread(threadPoolPool, 1);
    ASSERT_TRUE(SetThreadPoolMinimumThread(threadPoolPool, 1));

    auto cleanupgroup = CreateThreadPoolCleanupGroup();
    ASSERT_UNEQUAL_NULL_PTR(cleanupgroup);

    SetThreadPoolCallbackCleanupGroup(&callBackEnviron, cleanupgroup, nullptr);

    const String fileMappingName{ SYSTEM_TEXT("Resource/ThreadPoolIoTesting/ThreadPoolIoTest.txt") };

    auto fileHandle = CreateSystemFile(fileMappingName.c_str(), FileHandleDesiredAccess::ReadWrite | FileHandleDesiredAccess::Execute, FileHandleShareMode::Prevents,
                                       FileHandleCreationDisposition::OpenAlways, FileHandleAttributes::Normal,
                                       FileHandleOther::Overlapped, FileHandleSecurity::Default);
    ASSERT_TRUE(IsFileHandleValid(fileHandle));

    auto poolIO = CreateThreadPoolIo(fileHandle, Win32IOCallback, this, &callBackEnviron);
    ASSERT_UNEQUAL_NULL_PTR(poolIO);

    constexpr auto bufferSize = 256;
    uint64_t size{ 0 };
    ASSERT_TRUE(GetFileLength(fileHandle, size));

    if (bufferSize < size)
    {
        size = bufferSize;
    }

    array<char, bufferSize> buffer{};

    WindowDWord inNumber{ 0 };
    WindowOverlapped overlapped{};
    [[maybe_unused]] const auto value = ReadSystemFile(fileHandle, buffer.data(), boost::numeric_cast<WindowDWord>(size), &inNumber, &overlapped);

    StartThreadPoolIo(poolIO);

    WaitForThreadPoolIoCallbacks(poolIO, false);

    ASSERT_TRUE(CloseSystemFile(fileHandle));
    CloseThreadPoolIo(poolIO);
    CloseThreadPoolCleanupGroupMembers(cleanupgroup, false, nullptr);
    CloseThreadPoolCleanupGroup(cleanupgroup);
    CloseThreadPool(threadPoolPool);
    DestroyThreadPoolEnvironment(&callBackEnviron);
}
