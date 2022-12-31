///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/15 16:56)

#include "WriteFileUseOverlappedTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WriteFileUseOverlappedTesting::WriteFileUseOverlappedTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WriteFileUseOverlappedTesting)

void System::WriteFileUseOverlappedTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WriteFileUseOverlappedTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteFileUseOverlappedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteResultTest);
}

void System::WriteFileUseOverlappedTesting::WriteFileUseOverlappedTest()
{
    const auto handle = CreateSystemFile(GetFileName(), FileHandleDesiredAccess::Write, FileHandleShareMode::Prevents, FileHandleCreationDisposition::TruncateExisting);

    ASSERT_NOT_THROW_EXCEPTION_1(DoWriteFileUseOverlappedTest, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, handle);
}

void System::WriteFileUseOverlappedTesting::DoWriteFileUseOverlappedTest(WindowsHandle handle)
{
    ASSERT_TRUE(IsFileHandleValid(handle));

    const auto content = GetFileContent();
    BufferType buffer{ content.begin(), content.end() };

    WindowsDWord outNumber{ 0 };
    ASSERT_TRUE(WriteSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), &outNumber));
    ASSERT_EQUAL(outNumber, content.size());

    WindowOverlapped overlapped{};
    overlapped.Offset = 0xFFFFFFFF;
    overlapped.OffsetHigh = 0xFFFFFFFF;
    outNumber = 0;

    ASSERT_TRUE(WriteSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), &outNumber, &overlapped));
    ASSERT_EQUAL(outNumber, content.size());
}
