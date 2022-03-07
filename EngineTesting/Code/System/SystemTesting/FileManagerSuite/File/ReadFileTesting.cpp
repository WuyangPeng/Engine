///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/24 13:48)

#include "ReadFileTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Flags/SyncToolsFlags.h"
#include "System/Threading/SyncTools.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::string;
using std::vector;
using namespace std::literals;

System::ReadFileTesting::ReadFileTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ReadFileTesting)

void System::ReadFileTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ReadFileTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadFileUseOverlappedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadFileUseCompletionRoutineTest);
}

void System::ReadFileTesting::ReadTest()
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

    ASSERT_EQUAL(buffer, originalBuffer);
}

void System::ReadFileTesting::ReadFileUseOverlappedTest()
{
    const auto fileName = SYSTEM_TEXT("Resource/FileTesting/FileTestingText.txt"s);
    const auto fileContent = CoreTools::Version::GetVersion();
    const auto fileContentCut = fileContent.substr(1, fileContent.size());

    auto handle = CreateSystemFile(fileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_TRUE(IsFileHandleValid(handle));

    uint64_t size{ 0 };

    ASSERT_TRUE(GetFileLength(handle, size));

    vector<char> buffer(boost::numeric_cast<uint32_t>(size - 1));

    WindowOverlapped overlapped{};
    overlapped.Offset = 1;

    WindowsDWord inNumber{ 0 };
    ASSERT_TRUE(ReadSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), &inNumber, &overlapped));

    ASSERT_EQUAL(inNumber, fileContent.size() * 2 - 1);

    ASSERT_TRUE(CloseSystemFile(handle));

    vector<char> originalBuffer{ fileContentCut.begin(), fileContentCut.end() };
    originalBuffer.insert(originalBuffer.end(), fileContent.begin(), fileContent.end());

    ASSERT_EQUAL(buffer, originalBuffer);
}

void System::ReadFileTesting::ReadFileUseCompletionRoutineTest()
{
    const auto fileName = SYSTEM_TEXT("Resource/FileTesting/FileTestingText.txt"s);
    const auto fileContent = CoreTools::Version::GetVersion();

    auto handle = CreateSystemFile(fileName,
                                   FileHandleDesiredAccess::Read,
                                   FileHandleShareMode::ShareRead,
                                   FileHandleCreationDisposition::OpenExisting,
                                   FileHandleAttributes::Normal,
                                   FileHandleOther::Overlapped,
                                   FileHandleSecurity::Default);

    ASSERT_TRUE(IsFileHandleValid(handle));

    uint64_t size{ 0 };
    ASSERT_TRUE(GetFileLength(handle, size));

    vector<char> buffer(boost::numeric_cast<uint32_t>(size));

    WindowOverlapped overlapped{};
    ASSERT_TRUE(ReadSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), &overlapped, OverlappedCompletionRoutine));

    ASSERT_ENUM_EQUAL(SystemSleep(EnumCastUnderlying(MutexWait::Infinite), true), SleepReturn::WaitIOCompletion);

    ASSERT_TRUE(CloseSystemFile(handle));
}

void System::ReadFileTesting::OverlappedCompletionRoutine(MAYBE_UNUSED WindowsDWord errorCode, MAYBE_UNUSED WindowsDWord numberOfBytesTransfered, MAYBE_UNUSED WindowOverlappedPtr overlapped) noexcept
{
}
