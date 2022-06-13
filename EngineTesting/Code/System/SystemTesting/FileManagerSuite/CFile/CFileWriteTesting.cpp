///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 12:23)

#include "CFileWriteTesting.h"
#include "System/FileManager/CFile.h"
#include "System/FileManager/Flags/CFileFlags.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::vector;
using namespace std::literals;

System::CFileWriteTesting::CFileWriteTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CFileWriteTesting)

void System::CFileWriteTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CFileWriteTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteTest);
}

void System::CFileWriteTesting::WriteTest()
{
    const auto cFileContent = CoreTools::Version::GetVersion();

    FILE* file{ nullptr };
    ASSERT_TRUE(OpenCFile(file, GetFileName(), SYSTEM_FILE_TEXT("w"s)));
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(file, "打开文件失败。"s);

    vector<char> originalBuffer{ cFileContent.begin(), cFileContent.end() };
    const auto count = WriteCFile(originalBuffer.data(), 1, originalBuffer.size(), file);
    ASSERT_EQUAL(count, cFileContent.size());

    ASSERT_TRUE(CloseCFile(file));
}

const System::String System::CFileWriteTesting::GetFileName()
{
    return SYSTEM_FILE_TEXT("Resource/CFileTesting/CFileTestingText.txt"s);
}
