///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 12:23)

#include "CFileOperatorTesting.h"
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

System::CFileOperatorTesting::CFileOperatorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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
    FILE* file{ nullptr };
    ASSERT_TRUE(OpenCFile(file, GetFileName(), SYSTEM_FILE_TEXT("w+")));
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(file, "打开文件失败。"s);

    ASSERT_TRUE(Seek(file, 0, FileSeek::Set));

    ASSERT_FALSE(IsEOF(file));

    Rewind(file);

    const auto putString = CoreTools::Version::GetVersion();
    ASSERT_TRUE(PutString(file, putString.c_str()));

    ASSERT_TRUE(Flush(file));

    const auto length = Tell(file);
    ASSERT_EQUAL(length, boost::numeric_cast<long>(putString.size()));

    ASSERT_TRUE(Seek(file, 0, FileSeek::Set));

    auto position = GetPosition(file);
    ASSERT_EQUAL(position, 0);

    ASSERT_TRUE(SetPosition(file, 1));

    position = GetPosition(file);
    ASSERT_EQUAL(position, 1);
    Rewind(file);

    ASSERT_TRUE(CloseCFile(file));
}

const System::String System::CFileOperatorTesting::GetFileName()
{
    return SYSTEM_FILE_TEXT("Resource/CFileTesting/OperatorTest.txt"s);
}
