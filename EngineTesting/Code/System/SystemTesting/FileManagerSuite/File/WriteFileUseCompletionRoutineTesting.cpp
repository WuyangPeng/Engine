/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:02)

#include "WriteFileUseCompletionRoutineTesting.h"
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

System::WriteFileUseCompletionRoutineTesting::WriteFileUseCompletionRoutineTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WriteFileUseCompletionRoutineTesting)

void System::WriteFileUseCompletionRoutineTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WriteFileUseCompletionRoutineTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteFileUseCompletionRoutineTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteResultTest);
}

void System::WriteFileUseCompletionRoutineTesting::WriteFileUseCompletionRoutineTest()
{
    const auto handle = CreateSystemFile(GetFileName(), FileHandleDesiredAccess::Write, FileHandleShareMode::Prevents, FileHandleCreationDisposition::TruncateExisting);

    ASSERT_NOT_THROW_EXCEPTION_1(DoWriteFileUseCompletionRoutineTest, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, handle);
}

void System::WriteFileUseCompletionRoutineTesting::DoWriteFileUseCompletionRoutineTest(WindowsHandle handle)
{
    ASSERT_TRUE(IsFileHandleValid(handle));

    const auto content = GetFileContent();
    BufferType buffer{ content.begin(), content.end() };
    buffer.insert(buffer.end(), content.begin(), content.end());

    WindowOverlapped overlapped{};
    ASSERT_TRUE(WriteSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), &overlapped, OverlappedCompletionRoutine));

    ASSERT_EQUAL(SystemSleep(EnumCastUnderlying(MutexWait::Infinite), true), SleepReturn::WaitIOCompletion);
}

void System::WriteFileUseCompletionRoutineTesting::OverlappedCompletionRoutine(WindowsDWord errorCode, WindowsDWord numberOfBytesTransfered, WindowOverlappedPtr overlapped) noexcept
{
    UnusedFunction(errorCode, numberOfBytesTransfered, overlapped);
}
