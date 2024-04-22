/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 16:51)

#include "FileHandleHelperTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/FileHandleHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>

System::String CoreTools::FileHandleHelperTesting::GetDirectory()
{
    return SYSTEM_TEXT("Resource/FileHandleTesting/");
}

CoreTools::FileHandleHelperTesting::String CoreTools::FileHandleHelperTesting::GetFileName()
{
    return SYSTEM_TEXT("FileHandleHelperTestingText.txt");
}

System::String CoreTools::FileHandleHelperTesting::GetFileHandleHelperName()
{
    return GetDirectory() + GetFileName();
}

std::string CoreTools::FileHandleHelperTesting::GetFileHandleHelperContent()
{
    return "FileHandleHelp Testing Text";
}

CoreTools::FileHandleHelperTesting::FileHandleHelperTesting(const OStreamShared& stream)
    : ParentType{ stream }, environment{ Environment::Create() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FileHandleHelperTesting)

void CoreTools::FileHandleHelperTesting::DoRunUnitTest()
{
    ASSERT_TRUE(environment.InsertDirectory(GetDirectory()));

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::FileHandleHelperTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SaveIntoFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LoadFromFileUseEnvironmentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LoadFromFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AppendToFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SaveIntoFileTest);
}

void CoreTools::FileHandleHelperTesting::LoadFromFileTest()
{
    auto buffer = FileHandleHelper::LoadFromFile(GetFileHandleHelperName());

    const std::string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, GetFileHandleHelperContent());
}

void CoreTools::FileHandleHelperTesting::LoadFromFileUseEnvironmentTest()
{
    auto buffer = FileHandleHelper::LoadFromFileUseEnvironment(environment, GetFileName());

    const std::string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, GetFileHandleHelperContent());
}

void CoreTools::FileHandleHelperTesting::AppendToFileTest()
{
    auto content = GetFileHandleHelperContent();
    const auto fileHandleHelperName = GetFileHandleHelperName();

    FileHandleHelper::AppendToFile(fileHandleHelperName, boost::numeric_cast<int>(content.size()), content.c_str());

    const auto buffer = FileHandleHelper::LoadFromFile(fileHandleHelperName);

    const std::string bufferContent{ buffer.begin(), buffer.end() };

    content += GetFileHandleHelperContent();

    ASSERT_EQUAL(bufferContent, content);
}

void CoreTools::FileHandleHelperTesting::SaveIntoFileTest()
{
    const auto content = GetFileHandleHelperContent();
    const auto fileHandleHelperName = GetFileHandleHelperName();

    FileHandleHelper::SaveIntoFile(fileHandleHelperName, boost::numeric_cast<int>(content.size()), content.c_str());

    const auto buffer = FileHandleHelper::LoadFromFile(fileHandleHelperName);

    const std::string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, content);
}
