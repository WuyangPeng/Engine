/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:02)

#include "WriteFileTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WriteFileTesting::WriteFileTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WriteFileTesting)

void System::WriteFileTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WriteFileTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteResultTest);
}

void System::WriteFileTesting::WriteTest()
{
    const auto handle = CreateSystemFile(GetFileName(), FileHandleDesiredAccess::Write, FileHandleShareMode::Prevents, FileHandleCreationDisposition::TruncateExisting);

    ASSERT_NOT_THROW_EXCEPTION_1(DoWriteTest, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, handle);
}

void System::WriteFileTesting::DoWriteTest(WindowsHandle handle)
{
    ASSERT_TRUE(IsFileHandleValid(handle));

    const auto content = GetFileContent();
    BufferType buffer{ content.begin(), content.end() };
    buffer.insert(buffer.end(), content.begin(), content.end());

    WindowsDWord outNumber{ 0 };
    ASSERT_TRUE(WriteSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), &outNumber));
    ASSERT_EQUAL(outNumber, content.size() * 2);
}
