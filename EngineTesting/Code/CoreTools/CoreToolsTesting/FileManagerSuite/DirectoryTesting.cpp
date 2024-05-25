/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/04 22:40)

#include "DirectoryTesting.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/FileManager/Directory.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>
#include <string>

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
    const auto oldDirectoryName = GetDirectory();

    ASSERT_NOT_THROW_EXCEPTION_1(DoDirectoryTest, oldDirectoryName);

    const auto resultDirectoryName = GetDirectory();

    ASSERT_EQUAL(oldDirectoryName, resultDirectoryName);
}

void CoreTools::DirectoryTesting::DoDirectoryTest(const String& oldDirectoryName)
{
    const auto directoryName = oldDirectoryName + SYSTEM_TEXT("/Resource");
    Directory directory{ directoryName };

    const auto newDirectoryName = GetDirectory();
    ASSERT_EQUAL(directoryName, newDirectoryName);
}

System::String CoreTools::DirectoryTesting::GetDirectory()
{
    System::TCharContainer systemCurrentDirectory{};
    const auto result = System::GetSystemCurrentDirectory(System::gMaxPath, systemCurrentDirectory.data());
    ASSERT_LESS(0u, result);

    System::String directoryName{ systemCurrentDirectory.data() };
    boost::algorithm::replace_all(directoryName, SYSTEM_TEXT("\\"), SYSTEM_TEXT("/"));

    return directoryName;
}
