///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:18)

#include "ReadFileUseOverlappedTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Threading/SyncTools.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ReadFileUseOverlappedTesting::ReadFileUseOverlappedTesting(const OStreamShared& stream)
    : ParentType{ stream }, offset{ 1 }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ReadFileUseOverlappedTesting)

void System::ReadFileUseOverlappedTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ReadFileUseOverlappedTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReadFileUseOverlappedTest);
}

void System::ReadFileUseOverlappedTesting::ReadFileUseOverlappedTest()
{
    const auto handle = CreateSystemFile(GetFileName(), FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_NOT_THROW_EXCEPTION_1(DoReadFileUseOverlappedTest, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, handle);
}

void System::ReadFileUseOverlappedTesting::DoReadFileUseOverlappedTest(WindowsHandle handle)
{
    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, handle);

    const auto size = GetLength(handle);

    BufferType buffer(boost::numeric_cast<uint32_t>(size - 1));

    WindowOverlapped overlapped{};
    overlapped.Offset = offset;

    WindowsDWord inNumber{ 0 };
    ASSERT_TRUE(ReadSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), &inNumber, &overlapped));

    ASSERT_NOT_THROW_EXCEPTION_2(ReadResultTest, inNumber, buffer);
}

void System::ReadFileUseOverlappedTesting::ReadResultTest(WindowsDWord inNumber, const BufferType& buffer)
{
    const auto completeContent = GetFileContent();
    const auto fileContentCut = completeContent.substr(offset, completeContent.size());

    ASSERT_EQUAL(inNumber, completeContent.size() + fileContentCut.size());

    BufferType originalBuffer{ fileContentCut.begin(), fileContentCut.end() };
    originalBuffer.insert(originalBuffer.end(), completeContent.begin(), completeContent.end());

    ASSERT_EQUAL(buffer, originalBuffer);
}
