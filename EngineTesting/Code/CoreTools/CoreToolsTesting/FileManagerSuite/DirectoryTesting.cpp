///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/06 16:47)

#include "DirectoryTesting.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/FileManager/Directory.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>
#include <string>

using std::array;
using std::string;
using namespace std::literals;

CoreTools::DirectoryTesting::DirectoryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DirectoryTesting)

void CoreTools::DirectoryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::DirectoryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DirectoryTest);
}

void CoreTools::DirectoryTesting::DirectoryTest()
{
    array<System::TChar, System::g_MaxPath> systemCurrentDirectory{};
    auto result = System::GetSystemCurrentDirectory(System::g_MaxPath, systemCurrentDirectory.data());
    ASSERT_LESS(0u, result);
    System::String oldDirectoryName{ systemCurrentDirectory.data() };
    boost::algorithm::replace_all(oldDirectoryName, SYSTEM_TEXT("\\"), SYSTEM_TEXT("/"));

    auto directoryName = oldDirectoryName + SYSTEM_TEXT("/Resource"s);

    {
        Directory directory{ directoryName };

        systemCurrentDirectory.fill(0);
        result = System::GetSystemCurrentDirectory(System::g_MaxPath, systemCurrentDirectory.data());
        ASSERT_LESS(0u, result);
        System::String resultDirectoryName{ systemCurrentDirectory.data() };
        boost::algorithm::replace_all(resultDirectoryName, SYSTEM_TEXT("\\"), SYSTEM_TEXT("/"));
        ASSERT_EQUAL(directoryName, resultDirectoryName);
    }

    systemCurrentDirectory.fill(0);
    result = System::GetSystemCurrentDirectory(System::g_MaxPath, systemCurrentDirectory.data());
    ASSERT_LESS(0u, result);
    System::String resultDirectoryName{ systemCurrentDirectory.data() };
    boost::algorithm::replace_all(resultDirectoryName, SYSTEM_TEXT("\\"), SYSTEM_TEXT("/"));
    ASSERT_EQUAL(oldDirectoryName, resultDirectoryName);
}
