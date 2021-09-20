///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/24 10:47)

#include "FileLengthTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::vector;
using namespace std::literals;

System::FileLengthTesting::FileLengthTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FileLengthTesting)

void System::FileLengthTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FileLengthTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FileLengthTest);
}

void System::FileLengthTesting::FileLengthTest()
{
    const auto fileName = SYSTEM_TEXT("Resource/FileTesting/FileLength.txt"s);

    auto handle = CreateSystemFile(fileName, FileHandleDesiredAccess::Write, FileHandleShareMode::ShareWrite, FileHandleCreationDisposition::CreateAlways);
    ASSERT_TRUE(IsFileHandleValid(handle));

    const auto fileContent = CoreTools::Version::GetVersion();

    vector<char> buffer{ fileContent.begin(), fileContent.end() };

    WindowsDWord outNumber{ 0 };
    ASSERT_TRUE(WriteSystemFile(handle, buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), &outNumber));

    ASSERT_TRUE(CloseSystemFile(handle));

    handle = CreateSystemFile(fileName, FileHandleDesiredAccess::Read, FileHandleShareMode::ShareRead, FileHandleCreationDisposition::OpenExisting);
    ASSERT_TRUE(IsFileHandleValid(handle));

    uint64_t size{ 0 };
    ASSERT_TRUE(GetFileLength(handle, size));

    WindowsLargeInteger fileLargeInteger{};

    ASSERT_TRUE(GetFileLength(handle, &fileLargeInteger));

    ASSERT_EQUAL(size, fileContent.size());
    ASSERT_EQUAL(fileLargeInteger.QuadPart, boost::numeric_cast<int64_t>(fileContent.size()));

    ASSERT_TRUE(CloseSystemFile(handle));
}
