///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/10 20:02)

#include "LibraryDirectoryTesting.h"
#include "System/DynamicLink/LibraryDirectory.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;
using namespace std::literals;

System::LibraryDirectoryTesting::LibraryDirectoryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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

    ResetLibraryDirectory(currentLibraryDirectory);
}

void System::LibraryDirectoryTesting::DllDirectoryAccessTest()
{
    ResetLibraryDirectory(DYNAMIC_LINK_TEXT("D:/"s));

    auto currentLibraryDirectory = GetCurrentLibraryDirectory();

    ASSERT_TRUE(0 < currentLibraryDirectory.size() && currentLibraryDirectory.size() < gMaxPath);

    ResetLibraryDirectory(DYNAMIC_LINK_TEXT(""s));

    currentLibraryDirectory = GetCurrentLibraryDirectory();

    ASSERT_TRUE(currentLibraryDirectory.empty());
}

System::DynamicLinkString System::LibraryDirectoryTesting::GetCurrentLibraryDirectory()
{
    array<DynamicLinkCharType, gMaxPath> directoryName{};
    const auto maxFileNameLength = GetLibraryDirectory(gMaxPath, directoryName.data());
    DynamicLinkString currentLibraryDirectory{ directoryName.data() };

    ASSERT_EQUAL(maxFileNameLength, currentLibraryDirectory.size());

    return currentLibraryDirectory;
}

void System::LibraryDirectoryTesting::ResetLibraryDirectory(const DynamicLinkString& libraryDirectory)
{
    ASSERT_TRUE(SetLibraryDirectory(libraryDirectory.c_str()));
}
