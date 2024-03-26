/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 11:23)

#include "CFileCharacterTesting.h"
#include "System/FileManager/CFile.h"
#include "System/FileManager/Flags/CFileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CFileCharacterTesting::CFileCharacterTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CFileCharacterTesting)

void System::CFileCharacterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CFileCharacterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PutCharacterTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PutStringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetStringTest);
}

void System::CFileCharacterTesting::PutCharacterTest()
{
    auto file = OpenFile(SYSTEM_FILE_TEXT("w+"));

    ASSERT_NOT_THROW_EXCEPTION_1(DoPutCharacterTest, file);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, file);
}

void System::CFileCharacterTesting::DoPutCharacterTest(FILE* file)
{
    constexpr int putValue{ 'a' };

    ASSERT_TRUE(PutCharacter(file, putValue));
    ASSERT_TRUE(Seek(file, 0, FileSeek::Set));

    const auto character = GetCharacter(file);
    ASSERT_EQUAL(putValue, character);
}

void System::CFileCharacterTesting::PutStringTest()
{
    auto file = OpenFile(SYSTEM_FILE_TEXT("w+"));

    ASSERT_NOT_THROW_EXCEPTION_1(DoPutStringTest, file);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, file);
}

void System::CFileCharacterTesting::DoPutStringTest(FILE* file)
{
    const auto fileContent = GetFileContent();

    ASSERT_TRUE(PutString(file, fileContent.c_str()));
    ASSERT_TRUE(Seek(file, 0, FileSeek::Set));

    auto character = GetCharacter(file);
    ASSERT_EQUAL(fileContent.at(0), character);

    ASSERT_TRUE(UnGetCharacter(file, character));

    character = GetCharacter(file);
    ASSERT_EQUAL(fileContent.at(0), character);
}

void System::CFileCharacterTesting::GetStringTest()
{
    auto file = OpenFile(SYSTEM_FILE_TEXT("r"));

    ASSERT_NOT_THROW_EXCEPTION_1(DoGetStringTest, file);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseFile, file);
}

System::CFileString System::CFileCharacterTesting::GetFileName() const
{
    return SYSTEM_FILE_TEXT("Resource/CFileTesting/CharacterTest.txt");
}

void System::CFileCharacterTesting::DoGetStringTest(FILE* file)
{
    const auto fileContent = GetFileContent();

    const auto result = GetString(file, boost::numeric_cast<int>(fileContent.size() + 1));
    ASSERT_EQUAL(result, fileContent);
}
