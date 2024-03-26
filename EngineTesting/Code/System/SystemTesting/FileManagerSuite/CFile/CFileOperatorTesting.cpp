/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 11:24)

#include "CFileOperatorTesting.h"
#include "System/FileManager/CFile.h"
#include "System/FileManager/Flags/CFileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CFileOperatorTesting::CFileOperatorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CFileOperatorTesting)

void System::CFileOperatorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CFileOperatorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
}

void System::CFileOperatorTesting::OperatorTest()
{
    auto file = OpenFile(SYSTEM_FILE_TEXT("w+"));

    ASSERT_NOT_THROW_EXCEPTION_1(DoOperatorTest, file);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, file);
}

void System::CFileOperatorTesting::DoOperatorTest(FILE* file)
{
    ASSERT_NOT_THROW_EXCEPTION_1(IsEofTest, file);
    ASSERT_NOT_THROW_EXCEPTION_1(FlushTest, file);
    ASSERT_NOT_THROW_EXCEPTION_1(TellTest, file);
    ASSERT_NOT_THROW_EXCEPTION_1(PositionTest, file);
}

void System::CFileOperatorTesting::IsEofTest(FILE* file)
{
    ASSERT_TRUE(Seek(file, 0, FileSeek::Set));

    ASSERT_FALSE(IsEof(file));
}

void System::CFileOperatorTesting::FlushTest(FILE* file)
{
    const auto fileContent = GetFileContent();
    ASSERT_TRUE(PutString(file, fileContent.c_str()));

    ASSERT_TRUE(Flush(file));
}

void System::CFileOperatorTesting::TellTest(FILE* file)
{
    const auto fileContent = GetFileContent();

    const auto length = Tell(file);
    ASSERT_EQUAL(length, boost::numeric_cast<long>(fileContent.size()));
}

void System::CFileOperatorTesting::PositionTest(FILE* file)
{
    ASSERT_TRUE(Seek(file, 0, FileSeek::Set));

    auto position = GetPosition(file);
    ASSERT_EQUAL(position, 0);

    ASSERT_TRUE(SetPosition(file, 1));

    position = GetPosition(file);
    ASSERT_EQUAL(position, 1);
}

System::CFileString System::CFileOperatorTesting::GetFileName() const
{
    return SYSTEM_FILE_TEXT("Resource/CFileTesting/OperatorTest.txt");
}
