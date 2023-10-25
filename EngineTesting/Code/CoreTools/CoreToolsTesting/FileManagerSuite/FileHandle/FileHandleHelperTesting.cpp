///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 20:28)

#include "FileHandleHelperTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/FileHandleHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>

using namespace std::literals;

System::String CoreTools::FileHandleHelperTesting::GetFileHandleHelperName()
{
    return SYSTEM_TEXT("Resource/FileHandleTesting/FileHandleHelperTestingText.txt"s);
}

std::string CoreTools::FileHandleHelperTesting::GetFileHandleHelperContent()
{
    return "FileHandleHelp Testing Text"s;
}

CoreTools::FileHandleHelperTesting::FileHandleHelperTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FileHandleHelperTesting)

void CoreTools::FileHandleHelperTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::FileHandleHelperTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SaveIntoFileTest);
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
