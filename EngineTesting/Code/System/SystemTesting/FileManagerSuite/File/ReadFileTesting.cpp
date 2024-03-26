/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:01)

#include "ReadFileTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ReadFileTesting::ReadFileTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ReadFileTesting)

void System::ReadFileTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ReadFileTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReadTest);
}

void System::ReadFileTesting::ReadTest()
{
    const auto handle = CreateSystemFile(GetFileName(), FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);

    ASSERT_NOT_THROW_EXCEPTION_1(DoReadTest, handle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, handle);
}

void System::ReadFileTesting::DoReadTest(WindowsHandle handle)
{
    ASSERT_NOT_THROW_EXCEPTION_1(IsFileHandleValidTest, handle);

    const auto size = GetLength(handle);

    BufferType buffer(boost::numeric_cast<size_t>(size));

    WindowsDWord inNumber{ 0 };
    ASSERT_TRUE(ReadSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(size), &inNumber));

    ASSERT_NOT_THROW_EXCEPTION_2(ReadResultTest, inNumber, buffer);
}
