/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 11:26)

#include "FileLengthTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FileLengthTesting::FileLengthTesting(const OStreamShared& stream)
    : ParentType{ stream },
      fileName{ SYSTEM_TEXT("Resource/FileTesting/FileLength.txt") },
      fileContent{ CoreTools::Version::GetVersion() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FileLengthTesting)

void System::FileLengthTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FileLengthTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileLengthTest);
}

void System::FileLengthTesting::CreateFileTest()
{
    const auto handle = CreateSystemFile(fileName, FileHandleDesiredAccess::Write, FileHandleShareMode::ShareWrite, FileHandleCreationDisposition::CreateAlways);

    ASSERT_NOT_THROW_EXCEPTION_1(WriteFileTest, handle);

    ASSERT_TRUE(CloseSystemFile(handle));
}

void System::FileLengthTesting::WriteFileTest(WindowsHandle handle)
{
    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, handle);

    const BufferType buffer{ fileContent.begin(), fileContent.end() };

    WindowsDWord outNumber{ 0 };
    ASSERT_TRUE(WriteSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), &outNumber));
    ASSERT_EQUAL(outNumber, fileContent.size());
}

void System::FileLengthTesting::FileLengthTest()
{
    const auto handle = CreateSystemFile(fileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_NOT_THROW_EXCEPTION_1(DoFileLengthTest, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, handle);
}

void System::FileLengthTesting::DoFileLengthTest(WindowsHandle handle)
{
    ASSERT_TRUE(IsFileHandleValid(handle));

    uint64_t size{ 0 };
    ASSERT_TRUE(GetFileLength(handle, size));
    ASSERT_EQUAL(size, fileContent.size());

    WindowsLargeInteger fileLargeInteger{};
    ASSERT_TRUE(GetFileLength(handle, &fileLargeInteger));

    ASSERT_EQUAL(fileLargeInteger.QuadPart, boost::numeric_cast<int64_t>(fileContent.size()));
}
