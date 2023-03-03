///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/03/03 09:39)

#include "DirectoryTesting.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/FileManager/Directory.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>
#include <string>

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
    std::array<System::TChar, System::gMaxPath> systemCurrentDirectory{};
    auto result = System::GetSystemCurrentDirectory(System::gMaxPath, systemCurrentDirectory.data());
    ASSERT_LESS(0u, result);
    System::String oldDirectoryName{ systemCurrentDirectory.data() };
    boost::algorithm::replace_all(oldDirectoryName, SYSTEM_TEXT("\\"), SYSTEM_TEXT("/"));

    {
        const auto directoryName = oldDirectoryName + SYSTEM_TEXT("/Resource"s);
        Directory directory{ directoryName };

        systemCurrentDirectory.fill(0);
        result = System::GetSystemCurrentDirectory(System::gMaxPath, systemCurrentDirectory.data());
        ASSERT_LESS(0u, result);
        System::String resultDirectoryName{ systemCurrentDirectory.data() };
        boost::algorithm::replace_all(resultDirectoryName, SYSTEM_TEXT("\\"), SYSTEM_TEXT("/"));
        ASSERT_EQUAL(directoryName, resultDirectoryName);
    }

    systemCurrentDirectory.fill(0);
    result = System::GetSystemCurrentDirectory(System::gMaxPath, systemCurrentDirectory.data());
    ASSERT_LESS(0u, result);
    System::String resultDirectoryName{ systemCurrentDirectory.data() };
    boost::algorithm::replace_all(resultDirectoryName, SYSTEM_TEXT("\\"), SYSTEM_TEXT("/"));
    ASSERT_EQUAL(oldDirectoryName, resultDirectoryName);
}
