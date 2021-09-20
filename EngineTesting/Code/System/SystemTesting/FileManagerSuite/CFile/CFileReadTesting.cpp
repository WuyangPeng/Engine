///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/18 15:40)

#include "CFileReadTesting.h"
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

System::CFileReadTesting::CFileReadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CFileReadTesting)

void System::CFileReadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CFileReadTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReadTest);
}

void System::CFileReadTesting::InitTest()
{
    const auto cFileContent = CoreTools::Version::GetVersion();

    FILE* file{ nullptr };
    ASSERT_TRUE(OpenCFile(file, GetFileName(), SYSTEM_FILE_TEXT("w"s)));
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(file, "���ļ�ʧ�ܡ�"s);

    vector<char> originalBuffer{ cFileContent.begin(), cFileContent.end() };
    const auto count = WriteCFile(originalBuffer.data(), 1, originalBuffer.size(), file);
    ASSERT_EQUAL(count, cFileContent.size());

    ASSERT_TRUE(CloseCFile(file));
}

void System::CFileReadTesting::ReadTest()
{
    const auto cFileContent = CoreTools::Version::GetVersion();

    FILE* file{ nullptr };
    ASSERT_TRUE(OpenCFile(file, GetFileName(), SYSTEM_FILE_TEXT("r"s)));
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(file, "���ļ�ʧ�ܡ�"s);

    OffType length{ 0 };
    ASSERT_TRUE(GetFileLength(GetFileName(), &length));
    ASSERT_EQUAL(boost::numeric_cast<size_t>(length), cFileContent.size());

    vector<char> buffer(length);
    const auto count = ReadCFile(buffer.data(), 1, buffer.size(), file);

    ASSERT_EQUAL(count, buffer.size());

    vector<char> originalBuffer{ cFileContent.begin(), cFileContent.end() };
    ASSERT_EQUAL_DO_NOT_USE_MESSAGE(buffer, originalBuffer);

    ASSERT_TRUE(CloseCFile(file));
}

const System::String System::CFileReadTesting::GetFileName()
{
    return SYSTEM_FILE_TEXT("Resource/CFileTesting/CFileTestingText.txt"s);
}
