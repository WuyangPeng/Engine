///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.3 (2021/09/07 11:10)

#include "FileHandleHelperTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/FileHandleHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <string>
#include <vector>

using std::string;
using std::vector;
using namespace std::literals;

System::String CoreTools::FileHandleHelperTesting::GetFileHandleHelperName()
{
    return SYSTEM_TEXT("Resource/FileHandleTesting/FileHandleHelperTestingText.txt"s);
}

string CoreTools::FileHandleHelperTesting::GetFileHandleHelperContent()
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

    string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, GetFileHandleHelperContent());
}

void CoreTools::FileHandleHelperTesting::AppendToFileTest()
{
    auto content = GetFileHandleHelperContent();
    auto fileHandleHelperName = GetFileHandleHelperName();

    FileHandleHelper::AppendToFile(fileHandleHelperName, boost::numeric_cast<int>(content.size()), content.c_str());

    auto buffer = FileHandleHelper::LoadFromFile(fileHandleHelperName);

    string bufferContent{ buffer.begin(), buffer.end() };

    content += GetFileHandleHelperContent();

    ASSERT_EQUAL(bufferContent, content);
}

void CoreTools::FileHandleHelperTesting::SaveIntoFileTest()
{
    auto content = GetFileHandleHelperContent();
    auto fileHandleHelperName = GetFileHandleHelperName();

    FileHandleHelper::SaveIntoFile(fileHandleHelperName, boost::numeric_cast<int>(content.size()), content.c_str());

    auto buffer = FileHandleHelper::LoadFromFile(fileHandleHelperName);

    string bufferContent{ buffer.begin(), buffer.end() };

    ASSERT_EQUAL(bufferContent, content);
}
