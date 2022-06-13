///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 12:25)

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
