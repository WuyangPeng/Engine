///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/24 14:10)

#include "WriteFileTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/SyncTools.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include "System/Threading/Flags/SyncToolsFlags.h"
#include <vector>

using std::string;
using std::vector;
using namespace std::literals;

System::WriteFileTesting::WriteFileTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WriteFileTesting)

void System::WriteFileTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WriteFileTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteFileUseOverlappedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteFileUseCompletionRoutineTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadTest);
}

void System::WriteFileTesting::WriteTest()
{
    const auto fileName = SYSTEM_TEXT("Resource/FileTesting/FileTestingText.txt"s);
    const auto fileContent = CoreTools::Version::GetVersion();

    auto handle = CreateSystemFile(fileName, FileHandleDesiredAccess::Write, FileHandleShareMode::Prevents, FileHandleCreationDisposition::TruncateExisting);

    ASSERT_TRUE(IsFileHandleValid(handle));

    vector<char> buffer{ fileContent.begin(), fileContent.end() };

    WindowsDWord outNumber{ 0 };
    ASSERT_TRUE(WriteSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), &outNumber));
    ASSERT_EQUAL(outNumber, fileContent.size());

    ASSERT_TRUE(AppendSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), &outNumber));
    ASSERT_EQUAL(outNumber, fileContent.size());

    ASSERT_TRUE(CloseSystemFile(handle));
}

void System::WriteFileTesting::ReadTest()
{
    const auto fileName = SYSTEM_TEXT("Resource/FileTesting/FileTestingText.txt"s);
    const auto fileContent = CoreTools::Version::GetVersion();

    auto handle = CreateSystemFile(fileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_TRUE(IsFileHandleValid(handle));

    uint64_t size{ 0 };
    ASSERT_TRUE(GetFileLength(handle, size));

    vector<char> buffer(boost::numeric_cast<size_t>(size));

    WindowsDWord inNumber{ 0 };
    ASSERT_TRUE(ReadSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(size), &inNumber));

    ASSERT_EQUAL(inNumber, fileContent.size() * 2);

    ASSERT_TRUE(CloseSystemFile(handle));

    vector<char> originalBuffer{ fileContent.begin(), fileContent.end() };
    originalBuffer.insert(originalBuffer.end(), fileContent.begin(), fileContent.end());

    ASSERT_EQUAL_DO_NOT_USE_MESSAGE(buffer, originalBuffer);
}

void System::WriteFileTesting::WriteFileUseOverlappedTest()
{
    const auto fileName = SYSTEM_TEXT("Resource/FileTesting/FileTestingText.txt"s);
    const auto fileContent = CoreTools::Version::GetVersion();

    auto handle = CreateSystemFile(fileName, FileHandleDesiredAccess::Write, FileHandleShareMode::Prevents, FileHandleCreationDisposition::TruncateExisting);
    ASSERT_TRUE(IsFileHandleValid(handle));

    vector<char> buffer{ fileContent.begin(), fileContent.end() };

    WindowsDWord outNumber{ 0 };
    ASSERT_TRUE(WriteSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), &outNumber));
    ASSERT_EQUAL(outNumber, fileContent.size());

    WindowOverlapped overlapped{};
    overlapped.Offset = 0xFFFFFFFF;
    overlapped.OffsetHigh = 0xFFFFFFFF;
    outNumber = 0;

    ASSERT_TRUE(WriteSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), &outNumber, &overlapped));
    ASSERT_EQUAL(outNumber, fileContent.size());

    ASSERT_TRUE(CloseSystemFile(handle));
}

void System::WriteFileTesting::WriteFileUseCompletionRoutineTest()
{
    const auto fileName = SYSTEM_TEXT("Resource/FileTesting/FileTestingText.txt"s);
    const auto fileContent = CoreTools::Version::GetVersion();

    auto handle = CreateSystemFile(fileName, FileHandleDesiredAccess::Write, FileHandleShareMode::Prevents, FileHandleCreationDisposition::TruncateExisting);

    ASSERT_TRUE(IsFileHandleValid(handle));

    vector<char> buffer{ fileContent.begin(), fileContent.end() };
    buffer.insert(buffer.end(), fileContent.begin(), fileContent.end());

    WindowOverlapped overlapped{};

    ASSERT_TRUE(WriteSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), &overlapped, OverlappedCompletionRoutine));

    ASSERT_ENUM_EQUAL(SystemSleep(EnumCastUnderlying(MutexWait::Infinite), true), SleepReturn::WaitIOCompletion);

    ASSERT_TRUE(CloseSystemFile(handle));
}

void System::WriteFileTesting::OverlappedCompletionRoutine(MAYBE_UNUSED WindowsDWord errorCode, MAYBE_UNUSED WindowsDWord numberOfBytesTransfered, MAYBE_UNUSED WindowOverlappedPtr overlapped) noexcept
{
}
