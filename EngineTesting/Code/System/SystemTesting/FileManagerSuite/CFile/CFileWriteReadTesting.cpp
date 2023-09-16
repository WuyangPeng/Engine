///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:24)

#include "CFileWriteReadTesting.h"
#include "System/FileManager/CFile.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

System::CFileWriteReadTesting::CFileWriteReadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CFileWriteReadTesting)

void System::CFileWriteReadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CFileWriteReadTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadTest);
}

void System::CFileWriteReadTesting::WriteTest()
{
    auto file = OpenFile(SYSTEM_FILE_TEXT("w"));

    ASSERT_NOT_THROW_EXCEPTION_1(DoWriteTest, file);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, file);
}

void System::CFileWriteReadTesting::DoWriteTest(FILE* file)
{
    const auto count = WriteFile(file);
    ASSERT_NOT_THROW_EXCEPTION_1(FileContentSizeEqualTest, count);
}

void System::CFileWriteReadTesting::ReadTest()
{
    auto file = OpenFile(SYSTEM_FILE_TEXT("r"));

    ASSERT_NOT_THROW_EXCEPTION_1(DoReadTest, file);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, file);
}

void System::CFileWriteReadTesting::DoReadTest(FILE* file)
{
    const auto length = GetFileLengthTest();

    BufferType buffer(length);
    const auto count = ReadCFile(buffer.data(), 1, buffer.size(), file);

    ASSERT_EQUAL(count, buffer.size());
    ASSERT_NOT_THROW_EXCEPTION_1(OriginalBufferEqualTest, buffer);
}

System::OffType System::CFileWriteReadTesting::GetFileLengthTest()
{
    OffType length{ 0 };
    ASSERT_TRUE(GetFileLength(GetFileName(), &length));
    ASSERT_NOT_THROW_EXCEPTION_1(FileContentSizeEqualTest, boost::numeric_cast<size_t>(length));

    return length;
}
