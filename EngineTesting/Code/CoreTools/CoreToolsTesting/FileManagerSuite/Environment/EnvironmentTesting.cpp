/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/30 23:44)

#include "EnvironmentTesting.h"
#include "CoreTools/FileManager/Environment.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::EnvironmentTesting::EnvironmentTesting(const OStreamShared& stream)
    : ParentType{ stream }, environment{ Environment::Create() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EnvironmentTesting)

void CoreTools::EnvironmentTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

System::String CoreTools::EnvironmentTesting::GetEnvironmentFileName()
{
    return SYSTEM_TEXT("EnvironmentTestingText.txt");
}

System::String CoreTools::EnvironmentTesting::GetEnvironmentPathFileName()
{
    return SYSTEM_TEXT("Resource/EnvironmentTesting/EnvironmentTestingText.txt");
}

void CoreTools::EnvironmentTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InsertDirectoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetPathReadingSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetPathWritingSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetPathReadingAndWritingSucceedTest);
    ASSERT_THROW_EXCEPTION_0(GetPathReadingFailureTest);

    ASSERT_NOT_THROW_EXCEPTION_0(InsertDirectoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EraseDirectoryTest);
}

void CoreTools::EnvironmentTesting::InsertDirectoryTest()
{
    ASSERT_EQUAL(environment.GetNumDirectories(), 0);

    ASSERT_TRUE(environment.InsertDirectory(SYSTEM_TEXT("Resource/EnvironmentTesting/")));

    ASSERT_EQUAL(environment.GetNumDirectories(), 1);

    ASSERT_EQUAL(environment.GetDirectory(0), SYSTEM_TEXT("Resource/EnvironmentTesting/"));
}

void CoreTools::EnvironmentTesting::EraseDirectoryTest()
{
    ASSERT_EQUAL(environment.GetNumDirectories(), 1);

    ASSERT_TRUE(environment.EraseDirectory(SYSTEM_TEXT("Resource/EnvironmentTesting/")));

    ASSERT_EQUAL(environment.GetNumDirectories(), 0);
}

void CoreTools::EnvironmentTesting::GetPathReadingSucceedTest()
{
    ASSERT_EQUAL(environment.GetPathReading(GetEnvironmentFileName()), GetEnvironmentPathFileName());
}

void CoreTools::EnvironmentTesting::GetPathWritingSucceedTest()
{
    ASSERT_EQUAL(environment.GetPathWriting(GetEnvironmentFileName()), GetEnvironmentPathFileName());
}

void CoreTools::EnvironmentTesting::GetPathReadingAndWritingSucceedTest()
{
    ASSERT_EQUAL(environment.GetPathReadingAndWriting(GetEnvironmentFileName()), GetEnvironmentPathFileName());
}

void CoreTools::EnvironmentTesting::GetPathReadingFailureTest()
{
    environment.EraseAllDirectories();

    const auto environmentFileName = GetEnvironmentFileName();
    std::ignore = environment.GetPathReading(environmentFileName);
}

void CoreTools::EnvironmentTesting::GetPathWritingFailureTest() const
{
    WriteFileManager manager{ GetEnvironmentPathFileName() };

    const auto environmentFileName = GetEnvironmentFileName();
    std::ignore = environment.GetPathWriting(environmentFileName);
}

void CoreTools::EnvironmentTesting::GetPathReadingAndWritingFailureTest() const
{
    WriteFileManager manager{ GetEnvironmentPathFileName() };

    const auto environmentFileName = GetEnvironmentFileName();
    std::ignore = environment.GetPathReadingAndWriting(environmentFileName);
}
