/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 21:34)

#include "LibraryDirectoryTesting.h"
#include "System/DynamicLink/LibraryDirectory.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

System::LibraryDirectoryTesting::LibraryDirectoryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LibraryDirectoryTesting)

void System::LibraryDirectoryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LibraryDirectoryTesting::MainTest()
{
    const auto currentLibraryDirectory = GetCurrentLibraryDirectory();

    ASSERT_NOT_THROW_EXCEPTION_0(DllDirectoryAccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetEmptyDllDirectoryTest);

    ResetLibraryDirectory(currentLibraryDirectory);
}

void System::LibraryDirectoryTesting::DllDirectoryAccessTest()
{
    ResetLibraryDirectory(DYNAMIC_LINK_TEXT("D:/"));

    const auto currentLibraryDirectory = GetCurrentLibraryDirectory();

    ASSERT_RANGE(currentLibraryDirectory.size(), 0ul, gMaxPath);

    ASSERT_EQUAL(GetLibraryDirectory(), currentLibraryDirectory);
}

void System::LibraryDirectoryTesting::SetEmptyDllDirectoryTest()
{
    ResetLibraryDirectory(DYNAMIC_LINK_TEXT(""));

    const auto currentLibraryDirectory = GetCurrentLibraryDirectory();

    ASSERT_TRUE(currentLibraryDirectory.empty());

    ASSERT_EQUAL(GetLibraryDirectory(), currentLibraryDirectory);
}

System::DynamicLinkString System::LibraryDirectoryTesting::GetCurrentLibraryDirectory()
{
    DynamicLinkCharBufferType directoryName{};
    const auto maxFileNameLength = GetLibraryDirectory(gMaxPath, directoryName.data());
    DynamicLinkString currentLibraryDirectory{ directoryName.data() };

    ASSERT_EQUAL(maxFileNameLength, currentLibraryDirectory.size());

    return currentLibraryDirectory;
}

void System::LibraryDirectoryTesting::ResetLibraryDirectory(const DynamicLinkString& libraryDirectory)
{
    ASSERT_TRUE(SetLibraryDirectory(libraryDirectory.c_str()));
}
