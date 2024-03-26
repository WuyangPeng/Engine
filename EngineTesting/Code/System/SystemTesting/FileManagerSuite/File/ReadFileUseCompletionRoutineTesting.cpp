/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:01)

#include "ReadFileUseCompletionRoutineTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/Tools.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Flags/SyncToolsFlags.h"
#include "System/Threading/SyncTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ReadFileUseCompletionRoutineTesting::ReadFileUseCompletionRoutineTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ReadFileUseCompletionRoutineTesting)

void System::ReadFileUseCompletionRoutineTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ReadFileUseCompletionRoutineTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReadFileUseCompletionRoutineTest);
}

void System::ReadFileUseCompletionRoutineTesting::ReadFileUseCompletionRoutineTest()
{
    const auto handle = CreateSystemFile(GetFileName(),
                                         FileHandleDesiredAccess::Read,
                                         FileHandleShareMode::ShareRead,
                                         FileHandleCreationDisposition::OpenExisting,
                                         FileHandleAttribute::Normal,
                                         FileHandleOther::Overlapped,
                                         FileHandleSecurity::Default);

    ASSERT_NOT_THROW_EXCEPTION_1(DoReadFileUseCompletionRoutineTest, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, handle);
}

void System::ReadFileUseCompletionRoutineTesting::DoReadFileUseCompletionRoutineTest(WindowsHandle handle)
{
    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, handle);

    const auto size = GetLength(handle);

    BufferType buffer(boost::numeric_cast<size_t>(size));

    WindowOverlapped overlapped{};
    ASSERT_TRUE(ReadSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), &overlapped, OverlappedCompletionRoutine));

    ASSERT_ENUM_EQUAL(SystemSleep(EnumCastUnderlying(MutexWait::Infinite), true), SleepReturn::WaitIOCompletion);
}

void System::ReadFileUseCompletionRoutineTesting::OverlappedCompletionRoutine(WindowsDWord errorCode, WindowsDWord numberOfBytesTransfered, WindowOverlappedPtr overlapped) noexcept
{
    UnusedFunction(errorCode, numberOfBytesTransfered, overlapped);
}