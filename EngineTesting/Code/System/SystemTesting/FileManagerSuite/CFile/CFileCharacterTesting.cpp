///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/18 15:40)

#include "CFileCharacterTesting.h"
#include "System/FileManager/CFile.h"
#include "System/FileManager/Flags/CFileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::vector;
using namespace std::literals;

System::CFileCharacterTesting::CFileCharacterTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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
    FILE* file{ nullptr };
    ASSERT_TRUE(OpenCFile(file, GetFileName(), SYSTEM_FILE_TEXT("w+")));
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(file, "打开文件失败。"s);

    constexpr int putValue{ 'a' };

    ASSERT_TRUE(PutCharacter(file, putValue));
    ASSERT_TRUE(Seek(file, 0, FileSeek::Set));

    const auto value = GetCharacter(file);
    ASSERT_EQUAL(putValue, value);

    ASSERT_TRUE(CloseCFile(file));
}

void System::CFileCharacterTesting::PutStringTest()
{
    FILE* file{ nullptr };
    ASSERT_TRUE(OpenCFile(file, GetFileName(), SYSTEM_FILE_TEXT("w+")));
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(file, "打开文件失败。"s);

    const auto putString = CoreTools::Version::GetVersion();

    ASSERT_TRUE(PutString(file, putString.c_str()));
    ASSERT_TRUE(Seek(file, 0, FileSeek::Set));

    auto value = GetCharacter(file);
    ASSERT_EQUAL(putString.at(0), value);

    ASSERT_TRUE(UnGetCharacter(file, value));

    value = GetCharacter(file);
    ASSERT_EQUAL(putString.at(0), value);

    ASSERT_TRUE(CloseCFile(file));
}

void System::CFileCharacterTesting::GetStringTest()
{
    FILE* file{ nullptr };
    ASSERT_TRUE(OpenCFile(file, GetFileName(), SYSTEM_FILE_TEXT("r")));
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(file, "打开文件失败。"s);

    const auto putString = CoreTools::Version::GetVersion();

    auto result = GetString(file, boost::numeric_cast<int>(putString.size() + 1));
    ASSERT_EQUAL(result, putString);

    ASSERT_TRUE(CloseCFile(file));
}

const System::String System::CFileCharacterTesting::GetFileName()
{
    return SYSTEM_FILE_TEXT("Resource/CFileTesting/CharacterTest.txt"s);
}
